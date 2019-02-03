#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
void swap(int*a,int*b){
	int temp=*a;
	*a=*b;
	*b=temp;
	
}
int get2c(){
	char c;
	static int d;
	c=getch();
	fflush(stdin);
	d=c;
	return 256+d;
}
int arrowonly(){long int a=(get2c());
    if(a==224)
	a=(a)*1000+(get2c()-256);
	else a=a-256;

	return 0;

}
int arrow(){long int a=(get2c());
    if(a==224)
	a=(a)*1000+(get2c()-256);
	else a=a-256;

	return a;

}void hidecursor(){
	CONSOLE_CURSOR_INFO info;
	info.dwSize=100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}
void gotoxy(int col,int row)
{
	COORD position ={row,col};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);	}
	
void delay(int a){
	int i,j;
	for(i=0;i<a;i++){
		for(j=0;j<20000;j++){
			i-j;	}}}	

