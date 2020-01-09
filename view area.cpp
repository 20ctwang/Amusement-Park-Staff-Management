// view area.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string.h>


//gotoxy function
void gotoxy(int x, int y)
{
  static HANDLE hStdout = NULL;
  COORD coord;

  coord.X = x;
  coord.Y = y;

  if(!hStdout)
  {
    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
  }
  
  SetConsoleCursorPosition(hStdout,coord);
}

int main(void)
{
/*set text color*/
	HANDLE h = GetStdHandle (STD_OUTPUT_HANDLE);   
	WORD wOldColorAttrs;                                                        
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;                     
	GetConsoleScreenBufferInfo(h, &csbiInfo);                     
	wOldColorAttrs = csbiInfo.wAttributes;
/*set screen size*/
	HWND foregroundWindow = GetForegroundWindow();

    ShowWindow(foregroundWindow, SW_MAXIMIZE); //full screen
    
	int count=0;
	int col1=0;
	
	//old local variable in main
	char situation[10][10]={"0","OPEN","OPEN","OPEN","OPEN","OPEN","OPEN","OPEN","OPEN","CLOSED"};
	int area[10]={0,1,2,3,4,5,6,7,8,9};

	//new local variable in main
	int star[10]={0,1,2,5,3,4,2,1,1,1}; //manager promotion
	int starTemp=0; //temperary stored

	for(col1=0;col1<41;col1++)
	{
		gotoxy(55+col1,0);
		printf("=");
		gotoxy(55+col1,20);
		printf("=");
	}
	for(col1=0;col1<19;col1++)
	{
		gotoxy(55,1+col1);
		printf("||");
		gotoxy(94,1+col1);
		printf("||");
	}

	//print instructions
	gotoxy(105,3);
	SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );	
	printf("Level 5: ");
	gotoxy(114,3);
	SetConsoleTextAttribute ( h, BACKGROUND_RED|BACKGROUND_INTENSITY );	
	printf("    ");

	gotoxy(105,5);
	SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );	
	printf("Level 4: ");
	gotoxy(114,5);
	SetConsoleTextAttribute ( h, BACKGROUND_RED);	
	printf("    ");

	gotoxy(105,7);
	SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );	
	printf("Level 3: ");
	gotoxy(114,7);
	SetConsoleTextAttribute ( h, BACKGROUND_GREEN|BACKGROUND_RED );	
	printf("    ");

	gotoxy(105,9);
	SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );	
	printf("Level 2: ");
	gotoxy(114,9);
	SetConsoleTextAttribute ( h, BACKGROUND_BLUE|BACKGROUND_INTENSITY );	
	printf("    ");
	
	gotoxy(105,11);
	SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );	
	printf("Level 1: ");
	gotoxy(114,11);
	SetConsoleTextAttribute ( h, BACKGROUND_BLUE );	
	printf("    ");

	gotoxy(105,13);
	SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );	
	printf("Closed: CLOSED");
	for(count=1;count<10;count++)
	{
		if((count>=1)&&(count<=3))
		{			
			SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );	
			gotoxy(58+(count-1)*12,2);
			printf("|---------|");		
			system("color 0");
			gotoxy(58+(count-1)*12,3);
			printf("|         |");
			gotoxy(58+(count-1)*12,4);
			printf("| %6s  |",situation[count]);
			gotoxy(58+(count-1)*12,5);
			printf("|         |");			
			gotoxy(58+(count-1)*12,6);
			printf("|---------|");
		}
		if((count>=4)&&(count<=6))
		{
			SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );	
			gotoxy(58+(count-4)*12,8);
			printf("|---------|");
			gotoxy(58+(count-4)*12,9);
			printf("|         |");
			gotoxy(58+(count-4)*12,10);
			printf("| %6s  |",situation[count]);
			gotoxy(58+(count-4)*12,11);
			printf("|         |");
			gotoxy(58+(count-4)*12,12);
			printf("|---------|");
		}
		if((count>=7)&&(count<=9))
		{
			SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );	
			gotoxy(58+(count-7)*12,14);
			printf("|---------|");
			gotoxy(58+(count-7)*12,15);
			printf("|         |");
			gotoxy(58+(count-7)*12,16);
			printf("| %6s  |",situation[count]);
			gotoxy(58+(count-7)*12,17);
			printf("|         |");
			gotoxy(58+(count-7)*12,18);
			printf("|---------|");
		}
	}//end of closed area printed to screen

	for(count=1;count<4;count++)
	{
		if(strcmp(situation[count],"OPEN")==0)
		{
			if(star[count]==1)
			{
				SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );					
				gotoxy(58+(count-1)*12,2);
				printf("|---------|");
				gotoxy(58+(count-1)*12,3);
				SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY|BACKGROUND_BLUE);
				printf("|         |");
				gotoxy(58+(count-1)*12,4);
				printf("| Area %d  |",area[count]);
				gotoxy(58+(count-1)*12,5);
				printf("|         |");
				gotoxy(58+(count-1)*12,6);
				SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
				printf("|---------|");
			}
			if(star[count]==2)
			{
				SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );					
				gotoxy(58+(count-1)*12,2);
				printf("|---------|");
				gotoxy(58+(count-1)*12,3);
				SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY|BACKGROUND_BLUE|BACKGROUND_INTENSITY);
				printf("|         |");
				gotoxy(58+(count-1)*12,4);
				printf("| Area %d  |",area[count]);
				gotoxy(58+(count-1)*12,5);
				printf("|         |");
				gotoxy(58+(count-1)*12,6);
				SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
				printf("|---------|");
			}
			if(star[count]==3)
			{
				SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );					
				gotoxy(58+(count-1)*12,2);
				printf("|---------|");
				gotoxy(58+(count-1)*12,3);
				SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY|BACKGROUND_GREEN|BACKGROUND_RED);
				printf("|         |");
				gotoxy(58+(count-1)*12,4);
				printf("| Area %d  |",area[count]);
				gotoxy(58+(count-1)*12,5);
				printf("|         |");
				gotoxy(58+(count-1)*12,6);
				SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
				printf("|---------|");
			}
			if(star[count]==4)
			{
				SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );					
				gotoxy(58+(count-1)*12,2);
				printf("|---------|");
				gotoxy(58+(count-1)*12,3);
				SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY|BACKGROUND_RED);
				printf("|         |");
				gotoxy(58+(count-1)*12,4);
				printf("| Area %d  |",area[count]);
				gotoxy(58+(count-1)*12,5);
				printf("|         |");
				gotoxy(58+(count-1)*12,6);
				SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
				printf("|---------|");
			}
			if(star[count]==5)
			{
				SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );					
				gotoxy(58+(count-1)*12,2);
				printf("|---------|");
				gotoxy(58+(count-1)*12,3);
				SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY|BACKGROUND_INTENSITY|BACKGROUND_RED);
				printf("|         |");
				gotoxy(58+(count-1)*12,4);
				printf("| Area %d  |",area[count]);
				gotoxy(58+(count-1)*12,5);
				printf("|         |");
				gotoxy(58+(count-1)*12,6);
				SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
				printf("|---------|");
			}
		}//end of if	
	
	} //end of for
	for(count=4;count<7;count++)
	{
		if(strcmp(situation[count],"OPEN")==0)
		{
			if(star[count]==1)
			{
				SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );					
				gotoxy(58+(count-4)*12,8);
				printf("|---------|");
				gotoxy(58+(count-4)*12,9);
				SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY|BACKGROUND_BLUE);
				printf("|         |");
				gotoxy(58+(count-4)*12,10);
				printf("| Area %d  |",area[count]);
				gotoxy(58+(count-4)*12,11);
				printf("|         |");
				gotoxy(58+(count-4)*12,12);
				SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
				printf("|---------|");
			}
			if(star[count]==2)
			{
				SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );					
				gotoxy(58+(count-4)*12,8);
				printf("|---------|");
				gotoxy(58+(count-4)*12,9);
				SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY|BACKGROUND_BLUE|BACKGROUND_INTENSITY);
				printf("|         |");
				gotoxy(58+(count-4)*12,10);
				printf("| Area %d  |",area[count]);
				gotoxy(58+(count-4)*12,11);
				printf("|         |");
				gotoxy(58+(count-4)*12,12);
				SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
				printf("|---------|");
			}
			if(star[count]==3)
			{
				SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );					
				gotoxy(58+(count-4)*12,8);
				printf("|---------|");
				gotoxy(58+(count-4)*12,9);
				SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY|BACKGROUND_GREEN|BACKGROUND_RED);
				printf("|         |");
				gotoxy(58+(count-4)*12,10);
				printf("| Area %d  |",area[count]);
				gotoxy(58+(count-4)*12,11);
				printf("|         |");
				gotoxy(58+(count-4)*12,12);
				SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
				printf("|---------|");
			}
			if(star[count]==4)
			{
				SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );					
				gotoxy(58+(count-4)*12,8);
				printf("|---------|");
				gotoxy(58+(count-4)*12,9);
				SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY|BACKGROUND_RED);
				printf("|         |");
				gotoxy(58+(count-4)*12,10);
				printf("| Area %d  |",area[count]);
				gotoxy(58+(count-4)*12,11);
				printf("|         |");
				gotoxy(58+(count-4)*12,12);
				SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
				printf("|---------|");
			}
			if(star[count]==5)
			{
				SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );					
				gotoxy(58+(count-4)*12,8);
				printf("|---------|");
				gotoxy(58+(count-4)*12,9);
				SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY|BACKGROUND_INTENSITY|BACKGROUND_RED);
				printf("|         |");
				gotoxy(58+(count-4)*12,10);
				printf("| Area %d  |",area[count]);
				gotoxy(58+(count-4)*12,11);
				printf("|         |");
				gotoxy(58+(count-4)*12,12);
				SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
				printf("|---------|");
			}
		}
	}// end of for

	for(count=7;count<10;count++)
	{
		if((strcmp(situation[count],"OPEN")==0))
		{
			if(star[count]==1)
			{
				SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );					
				gotoxy(58+(count-7)*12,14);
				printf("|---------|");
				gotoxy(58+(count-7)*12,15);
				SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY|BACKGROUND_BLUE);
				printf("|         |");
				gotoxy(58+(count-7)*12,16);
				printf("| Area %d  |",area[count]);
				gotoxy(58+(count-7)*12,17);
				printf("|         |");
				gotoxy(58+(count-7)*12,18);
				SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
				printf("|---------|");
			}
			if(star[count]==2)
			{
				SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );					
				gotoxy(58+(count-7)*12,14);
				printf("|---------|");
				gotoxy(58+(count-7)*12,15);
				SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY|BACKGROUND_BLUE|BACKGROUND_INTENSITY);
				printf("|         |");
				gotoxy(58+(count-7)*12,16);
				printf("| Area %d  |",area[count]);
				gotoxy(58+(count-7)*12,17);
				printf("|         |");
				gotoxy(58+(count-7)*12,18);
				SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
				printf("|---------|");
			}
			if(star[count]==3)
			{
				SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );					
				gotoxy(58+(count-7)*12,14);
				printf("|---------|");
				gotoxy(58+(count-7)*12,15);
				SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY|BACKGROUND_GREEN|BACKGROUND_RED);
				printf("|         |");
				gotoxy(58+(count-7)*12,16);
				printf("| Area %d  |",area[count]);
				gotoxy(58+(count-7)*12,17);
				printf("|         |");
				gotoxy(58+(count-7)*12,18);
				SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
				printf("|---------|");
			}
			if(star[count]==4)
			{
				SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );					
				gotoxy(58+(count-7)*12,14);
				printf("|---------|");
				gotoxy(58+(count-7)*12,15);
				SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY|BACKGROUND_RED);
				printf("|         |");
				gotoxy(58+(count-7)*12,16);
				printf("| Area %d  |",area[count]);
				gotoxy(58+(count-7)*12,17);
				printf("|         |");
				gotoxy(58+(count-7)*12,18);
				SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
				printf("|---------|");
			}
			if(star[count]==5)
			{
				SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );					
				gotoxy(58+(count-7)*12,14);
				printf("|---------|");
				gotoxy(58+(count-7)*12,15);
				SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY|BACKGROUND_RED|BACKGROUND_INTENSITY);
				printf("|         |");
				gotoxy(58+(count-7)*12,16);
				printf("| Area %d  |",area[count]);
				gotoxy(58+(count-7)*12,17);
				printf("|         |");
				gotoxy(58+(count-7)*12,18);
				SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
				printf("|---------|");
			}
		}
	}//end of for loop

	getch();
	return 0;

}