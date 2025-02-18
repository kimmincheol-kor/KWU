// 고급C프로그래밍 1차프로젝트

#include <stdio.h>
#include <time.h>
#include <Windows.h>
#include <stdlib.h>

void gotoxy(int x, int y)
{
COORD Pos = {x-1, y-1};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

int main()
{
	int hour=0, min=0, sec=0;
	int hour2=0, min2=0, sec2=0; // 십의자리 숫자를 입력할곳
	int hour1=0, min1=0, sec1=0; // 일의자리 숫자를 입력할곳
	int a,b,c,d,e,f;

	int digit[10][20]=
	{
		{1,1,1,1,
		1,0,0,1,
		1,0,0,1,
		1,0,0,1,
		1,1,1,1}, // 0

		{0,0,1,0,
		0,0,1,0,
		0,0,1,0,
		0,0,1,0,
		0,0,1,0,}, // 1
		
		{1,1,1,1,
		0,0,0,1,
		1,1,1,1,
		1,0,0,0,
		1,1,1,1}, // 2
		
		{1,1,1,1,
		0,0,0,1,
		1,1,1,1,
		0,0,0,1,
		1,1,1,1}, // 3
		
		{1,0,1,0,
		1,0,1,0,
		1,1,1,1,
		0,0,1,0,
		0,0,1,0}, // 4
		
		{1,1,1,1,
		1,0,0,0,
		1,1,1,1,
		0,0,0,1,
		1,1,1,1}, // 5
		
		{1,0,0,0,
		1,0,0,0,
		1,1,1,1,
		1,0,0,1,
		1,1,1,1}, // 6
		
		{1,1,1,1,
		1,0,0,1,
		1,0,0,1,
		0,0,0,1,
		0,0,0,1}, // 7
		
		{1,1,1,1,
		1,0,0,1,
		1,1,1,1,
		1,0,0,1,
		1,1,1,1},  // 8

		{1,1,1,1,
		1,0,0,1,
		1,1,1,1,
		0,0,0,1,
		0,0,0,1} // 9
	};

	while(1) // 시계
	{
		

		for(sec=0; sec<=100; sec++)  //초 증가
		{
				hour2=hour/10; // hour의 십의자리
				hour1=hour%10; // hour의 일의자리

				min2=min/10;
				min1=min%10;

				sec2=sec/10;
				sec1=sec%10;

			
// 시단위 출력
			for(a=0; a<20; a++)
				{
				if(a%4==0)
				{gotoxy(1,2+(a/4));}
				if(digit[hour2][a]==1)
				printf("■");
				else if(digit[hour2][a]==0)
				printf("  ");
				}
			for(b=0; b<20; b++)
				{
				if(b%4==0)
				{gotoxy(10,2+(b/4));}
				if(digit[hour1][b]==1)
				printf("■");
				else if(digit[hour1][b]==0)
				printf("  ");
				}

// : 출력
			gotoxy(19,3);
			printf("■");
			gotoxy(19,5);
			printf("■");
			
				
// 분단위 출력
			for(c=0; c<20; c++)
				{
				if(c%4==0)
				{gotoxy(22,2+(c/4));}
				if(digit[min2][c]==1)
				printf("■");
				else if(digit[min2][c]==0)
				printf("  ");
				}
			for(d=0; d<20; d++)
				{
				if(d%4==0)
				{gotoxy(31,2+(d/4));}
				if(digit[min1][d]==1)
				printf("■");
				else if(digit[min1][d]==0)
				printf("  ");
				}

// : 출력
			gotoxy(40,3);
			printf("■");
			gotoxy(40,5);
			printf("■");


// 초단위 출력
			for(e=0; e<20; e++)
				{
				if(e%4==0)
				{gotoxy(43,2+(e/4));}
				if(digit[sec2][e]==1)
				printf("■");
				else if(digit[sec2][e]==0)
				printf("  ");
				}
			for(f=0; f<20; f++)
				{
				if(f%4==0)
				{gotoxy(52,2+(f/4));}
				if(digit[sec1][f]==1)
				printf("■");
				else if(digit[sec1][f]==0)
				printf("  ");
				}




			Sleep(1000); // 1초 지연

			if((hour!=99)&&(min!=60)&&(sec!=59))
				system("cls"); // 창 지움

			if(sec==59){ // sec가 59 가 되고, 1초가 지연된후 if문을 실행하기때문에 59일때 min++
				min++;
				break;} // (sec)For문 탈출
		
		} // (sec)For문 끝

		if((hour==99)&&(min==60)&&(sec==59))
		{
			break; // (시계)while문 탈출
		}
		
		
		if(min==60){
			hour++;
			min=0;}
				
	} // 시계 끝

} // 메인함수 끝