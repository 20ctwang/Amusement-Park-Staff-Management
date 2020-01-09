// logout.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>

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
	int flag=0;
	char choice;

	do
	{
		SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_INTENSITY );
		gotoxy(60,11);
		printf("     .-""""""-.       ");
		gotoxy(60,12);
		printf("   .'          '.    ");
		gotoxy(60,13);
		printf("  ,   O      O   ,   ");
		gotoxy(60,14);
		printf(" :           `    :  ");
		gotoxy(60,15);
		printf(" |                |  ");
		gotoxy(60,16);
		printf(" :    .------.    :  ");
		gotoxy(60,17);
		printf("  ,  '        '  ,   ");
		gotoxy(60,18);
		printf("   '.          .'    ");
		gotoxy(60,19);
		printf("     '-......-'      ");
		SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
		gotoxy(60,23);
		printf("Are you sure you want to exit?");
		gotoxy(60,25);
		printf("Press '1' to exit, press '2' to return.");
		scanf("%c",&choice);
		fflush(stdin);
		switch(choice)
		{
		case '1':
			flag=5;
			break;
		case '2':
			flag=7;
			break;
		default:			
			SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_INTENSITY);
			gotoxy(60,27);
			printf("INVALID INPUT");			
			SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
			gotoxy(60,29);
			printf("Press <ENTER> to try again!");
			getch();
			system("cls");
			flag=1;
		}
	}while(flag<2);


	getch();
	return 0;
}
