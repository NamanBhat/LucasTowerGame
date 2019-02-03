#include<iostream>
#include<naman.h>
int score;
using namespace std;
void cursor(){
	CONSOLE_CURSOR_INFO info;
	info.dwSize=100;
	info.bVisible = TRUE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}
class rod{public: 
	struct  disc{
		int data;
		struct disc *next;
	}*head;
	rod()
	{
	  head=NULL;
	}
	disc * create(int value)
	{struct disc *temp, *s;
	temp= new disc;
	temp->data=value;
	temp->next=NULL;
	return temp;
	}
	insert(int value)
	{struct disc *temp,*p;
	temp=create(value);
	if(head==NULL)
	{
		head=temp;
	}
	else
	{
		p=head;
		head=temp;
		head->next=p;
	}
	}
	del(){
		if(head==NULL)
		{return 0;
		}
		int t=(head->data);
		head=head->next;
		return t;
		
	}
	
	display(int a,int b,int n)
	{struct disc *p;
	p=head;
	int i,j=0,c=0;
		while(p!=NULL)
	{p=p->next;j++;}
	i=n-j;
	p=head;
	while(p!=NULL)
	{   
		for(c=p->data;c>0;c--){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15-(p->data)%15);gotoxy(a+i,b-c);printf("%c",254);}
		gotoxy(a+i,b);
		printf("%c",254);
		for(c=1;c<p->data+1;c++){gotoxy(a+i,b+c);printf("%c",254);}
		p=p->next;i++;SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
	}
	}
	headvalue(int n)
	{if(head==NULL)return n+1;
	else return head->data;
	}
	win(int n){	int i=1,flag=0;
	      disc *p;
	      p=head;
	    while(p!=NULL)
	{ 
		if(p->data!=i){flag=1;break;}
		p=p->next;i++;
	}
	 if((flag==0)&&(i==n+1))
	 {gotoxy(10+n+2,30+2*n-7);printf("YOU WIN IN %d MOVES",score);exit(1);}
		
	}
	
	
	friend move(rod &rod1,rod &rod2,int n);friend void disnoi(rod &rod1,rod &rod2,rod &rod3,int n);
};
void disnoi(rod &rod1,rod &rod2,rod &rod3,int n)
{int i;
 gotoxy(5,30);printf("A");for(i=6;i<10+n;i++){int c;for(c=n;c>0;c--){gotoxy(i,30-c);printf(" ");}for(c=1;c<n+1;c++){gotoxy(i,30+c);printf(" ");}gotoxy(i,30);printf("|"); }rod1.display(10,30,n);
 gotoxy(5,30+2*n+2);printf("B");for(i=6;i<10+n;i++){int c;for(c=n;c>0;c--){gotoxy(i,30+2*n+2-c);printf(" ");}for(c=1;c<n+1;c++){gotoxy(i,30+2*n+2+c);printf(" ");}gotoxy(i,30+2*n+2);printf("|"); }rod2.display(10,30+2*n+2,n);
 gotoxy(5,30+4*n+4);printf("C");for(i=6;i<10+n;i++){int c;for(c=n;c>0;c--){gotoxy(i,30+4*n+4-c);printf(" ");}for(c=1;c<n+1;c++){gotoxy(i,30+4*n+4+c);printf(" ");}gotoxy(i,30+4*n+4);printf("|"); }rod3.display(10,30+4*n+4,n); 
 gotoxy(3,30+2*n-14);printf("FOR HINT PRESS KEY 'H' ON YOUR KEYBOARD");
 gotoxy(4,30+2*n+2-15);printf("             MOVES: %d",score);
}
int move(rod &rod1,rod &rod2,int n)
{  if(rod1.headvalue(n)<rod2.headvalue(n))
   {rod2.insert(rod1.del());score++;}}
int move2(rod &rod1,rod &rod2,int n)
{  if(rod1.headvalue(n)<rod2.headvalue(n))
   {rod2.insert(rod1.del());}
}
int getkey(){
	long int a=arrow();
	if(a==13) return 5;
    if(a=='h') return 2;
	if(a==224075) return 3;
	if(a==224077) return 4;
	return 0;
}
void solution(rod &rod1,rod &rod2,rod &rod3,int n)
{int a[2],i;
for(i=1;i<(1<<n);i++)
{a[0]=(i&i-1)%3+1;a[1]=((i|i-1)+1)%3+1;
         if(n%2==0)
        {if((a[0]==1)&&(a[1]==2))move2(rod1,rod3,n);
         if((a[0]==1)&&(a[1]==3))move2(rod1,rod2,n);
         if((a[0]==3)&&(a[1]==1))move2(rod2,rod1,n);
         if((a[0]==3)&&(a[1]==2))move2(rod2,rod3,n);
         if((a[0]==2)&&(a[1]==1))move2(rod3,rod1,n);
         if((a[0]==2)&&(a[1]==3))move2(rod3,rod2,n);
		}else {         
         if((a[0]==1)&&(a[1]==2))move2(rod1,rod2,n);
         if((a[0]==1)&&(a[1]==3))move2(rod1,rod3,n);
         if((a[0]==3)&&(a[1]==1))move2(rod3,rod1,n);
         if((a[0]==3)&&(a[1]==2))move2(rod3,rod2,n);
         if((a[0]==2)&&(a[1]==1))move2(rod2,rod1,n);
         if((a[0]==2)&&(a[1]==3))move2(rod2,rod3,n);
		}
		
         // delay(10000);
		 disnoi(rod1,rod2,rod3,n);

}//delay(10000);
}
void solution2(rod &rod1,rod &rod2,rod &rod3,int n)
{int a[2],i;
for(i=1;i<(1<<n);i++)
{a[0]=(i&i-1)%3+1;a[1]=((i|i-1)+1)%3+1;
        if(n%2==0)
         {if((a[0]==1)&&(a[1]==2))move2(rod3,rod1,n);
         if((a[0]==1)&&(a[1]==3))move2(rod3,rod2,n);
         if((a[0]==3)&&(a[1]==1))move2(rod2,rod3,n);
         if((a[0]==3)&&(a[1]==2))move2(rod2,rod1,n);
         if((a[0]==2)&&(a[1]==1))move2(rod1,rod3,n);
         if((a[0]==2)&&(a[1]==3))move2(rod1,rod2,n);
		 }else {         
         if((a[0]==1)&&(a[1]==2))move2(rod3,rod2,n);
         if((a[0]==1)&&(a[1]==3))move2(rod3,rod1,n);
         if((a[0]==3)&&(a[1]==1))move2(rod1,rod3,n);
         if((a[0]==3)&&(a[1]==2))move2(rod1,rod2,n);
         if((a[0]==2)&&(a[1]==1))move2(rod2,rod3,n);
         if((a[0]==2)&&(a[1]==3))move2(rod2,rod1,n);
		 }
		 
         

}
getch();}
int main(){
	int x=1,c=0,a[2]={0,0},n,i;
	
	rod rod1,rod2,rod3;

	rod roda,rodb,rodc;
    gotoxy(16,25);
	printf("Enter no. of rings: ");scanf("%d",&n);gotoxy(16,25);	printf("                          ");
	cursor();
	for(i=n;i>0;i--)
	{roda.insert(i);rod1.insert(i);}
	

    
	disnoi(rod1,rod2,rod3,n);
	gotoxy(5,30+(x-1)*(2*n+2));
		wait:		 if(kbhit){
		 	int v=getkey();
		 	if(v==2)goto hint;
		 	if(v==3)goto left;
		 	if(v==4)goto right;
			if(v==5)goto move;
			  goto wait;}
	hint:
	disnoi(roda,rodb,rodc,n);	
	solution(roda,rodb,rodc,n);
	solution2(roda,rodb,rodc,n);	
	disnoi(rod1,rod2,rod3,n);gotoxy(5,30+(x-1)*(2*n+2));
	if(kbhit){
		 	int v=getkey();
		 	if(v==2)goto hint;
		 	if(v==3)goto left;
		 	if(v==4)goto right;
			if(v==5)goto move;
			  goto wait;}  
	left:
		{if(x!=1)
		 x=x-1;
		 gotoxy(5,30+(x-1)*(2*n+2));
		 if(kbhit){
		 	int v=getkey();
		 	if(v==2)goto hint;
		 	if(v==3)goto left;
		 	if(v==4)goto right;
		 	if(v==5)goto move;
			
		     
;}
		 goto wait;

		}
	
	right:
		{if(x!=3)
		 x=x+1;
		 gotoxy(5,30+(x-1)*(2*n+2));
		 if(kbhit){
		 	int v=getkey();
		 	if(v==2)goto hint;	
		 	if(v==3)goto left;
		 	if(v==4)goto right;
		 	if(v==5)goto move; }
		
		    goto wait;
		}
	
	move:a[c]=x;
         c=(c+1)%2;
         
         if((a[0]==1)&&(a[1]==2))move(rod1,rod2,n);
         if((a[0]==1)&&(a[1]==3))move(rod1,rod3,n);
         if((a[0]==3)&&(a[1]==1))move(rod3,rod1,n);
         if((a[0]==3)&&(a[1]==2))move(rod3,rod2,n);
         if((a[0]==2)&&(a[1]==1))move(rod2,rod1,n);
         if((a[0]==2)&&(a[1]==3))move(rod2,rod3,n);
          disnoi(rod1,rod2,rod3,n);
 		  gotoxy(5,30+(x-1)*(2*n+2));
		   if((a[0]!=0)&&(a[1]!=0))rod3.win(n);
 		  if(c==0)
         {
		  a[0]=0;a[1]=0;}
		if(kbhit){
		 	int v=getkey();
		 	if(v==2)goto hint;
		 	if(v==3)goto left;
		 	if(v==4)goto right;
		 	if(v==5)goto move; }
		 
		    goto wait;
		
	
	
	
}
