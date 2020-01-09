// gotoxy color test.cpp : Defines the entry point for the console application.
//
//close area when no area is open

#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
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
	int area[10]={0,1,2,3,4,5,6,7,8,9};
	int row=0;
	int col=0;
	int enter=0;
	int count=0;
	int col1=0;
	char choice;
	int flag=0;
	char situation[10][10]={"0","CLOSED","CLOSED","CLOSED","CLOSED","CLOSED","CLOSED","CLOSED","CLOSED","CLOSED"};
	
	
	do
	{
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
			gotoxy(55,7);
			printf("  ");//print entrance
			gotoxy(94,1+col1);
			printf("||");
			gotoxy(94,13);
			printf("  "); //print exit
		}
		
		for(count=1;count<10;count++)
		{
			if((count>=1)&&(count<=3))
			{
				SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
				gotoxy(58+(count-1)*12,2);
				printf("|---------|");
				gotoxy(58+(count-1)*12,3);
				printf("|         |");
				gotoxy(58+(count-1)*12,4);
				printf("|    %d    |",area[count]);
				gotoxy(58+(count-1)*12,5);
				printf("| %6s  |",situation[count]);
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
				printf("|    %d    |",area[count]);
				gotoxy(58+(count-4)*12,11);
				printf("| %6s  |",situation[count]);
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
				printf("|    %d    |",area[count]);
				gotoxy(58+(count-7)*12,17);
				printf("| %6s  |",situation[count]);
				gotoxy(58+(count-7)*12,18);
				printf("|---------|");
			}
		}


		for(count=1;count<4;count++)
		{
			if(strcmp(situation[count],"OPEN")==0)
			{
				SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );					
				gotoxy(58+(count-1)*12,2);
				printf("|---------|");
				gotoxy(58+(count-1)*12,3);
				SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY|BACKGROUND_GREEN);
				printf("|         |");
				gotoxy(58+(count-1)*12,4);
				printf("|    %d    |",area[count]);
				gotoxy(58+(count-1)*12,5);
				printf("| %6s  |",situation[count]);
				gotoxy(58+(count-1)*12,6);
				SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
				printf("|---------|");
			}
		}

		for(count=4;count<7;count++)
		{
			if(strcmp(situation[count],"OPEN")==0)
			{
				SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );					
				gotoxy(58+(count-4)*12,8);
				printf("|---------|");
				gotoxy(58+(count-4)*12,9);
				SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY|BACKGROUND_GREEN);
				printf("|         |");
				gotoxy(58+(count-4)*12,10);
				printf("|    %d    |",area[count]);
				gotoxy(58+(count-4)*12,11);
				printf("| %6s  |",situation[count]);
				gotoxy(58+(count-4)*12,12);
				SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
				printf("|---------|");
			}
		}

		for(count=7;count<10;count++)
		{
			if((strcmp(situation[count],"OPEN")==0))
			{
				SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );					
				gotoxy(58+(count-7)*12,14);
				printf("|---------|");
				gotoxy(58+(count-7)*12,15);
				SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY|BACKGROUND_GREEN);
				printf("|         |");
				gotoxy(58+(count-7)*12,16);
				printf("|    %d    |",area[count]);
				gotoxy(58+(count-7)*12,17);
				printf("| %6s  |",situation[count]);
				gotoxy(58+(count-7)*12,18);
				SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
				printf("|---------|");
			}
		}

		/*indicate short cut between entrace and exit*/
		gotoxy(52,7);
		printf("IN");
		SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_INTENSITY );
		for(count=0;count<7;count++)
		{
			gotoxy(55+count*2,7);
			printf("*");
			Sleep(10);
		}
		for(count=0;count<7;count++)
		{
			gotoxy(69,7+count);
			printf("*");
			Sleep(10);
		}
		for(count=0;count<13;count++)
		{
			gotoxy(71+count*2,13);
			printf("*");
			Sleep(10);
		}
		SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
		gotoxy(97,13);
		printf("OUT");

		/*user determine to open new area or not*/
		SetConsoleTextAttribute ( h, FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_INTENSITY);
		gotoxy(50,23);
		printf("a]");
		gotoxy(63,23);
		printf("b]");
		gotoxy(77,23);
		printf("c]");
		SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
		gotoxy(53,23);
		printf("Open Area");
		gotoxy(66,23);
		printf("Close Area");
		gotoxy(80,23);
		printf("Manage Payroll Budget");
		gotoxy(58,26);
		printf("Your Choice: ");
		scanf("%c",&choice);
		fflush(stdin);
		switch(choice)
		{
		case 'a': /*if user opens new area*/
		case 'A':
			row=0;
			flag=0;
			do
			{
				for(col1=1;col1<10;col1++)
				{
					if(strcmp(situation[col1],"CLOSED")==0) //if there is still area not open
					{	
						col1=10;
						flag=2;
					}
					else
						flag=1;
				}
				if(flag==1) //if all area situation is open
				{
					SetConsoleTextAttribute ( h, FOREGROUND_GREEN|FOREGROUND_INTENSITY);
					gotoxy(58,28);
					printf("All Areas are open!");
					SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
					gotoxy(58,30);
					printf("Press <ENTER> to continue");
					getch(); 
					system("cls");
					flag=2;
					row=1;
				}
			}while(flag<2);

			if(row!=1)
			{
				gotoxy(58,28);
				printf("Enter Area #(open): ");
				scanf("%d",&enter);  //user enter area number to open corresponding area
				fflush(stdin);
				if((enter>=1)&&(enter<=9)&&(strcmp(situation[enter],"CLOSED")==0))  
				{
					strcpy(situation[enter],"OPEN");
					system("cls");
				}
				else //if user enter invalid area number or area that is already open 
				{
					SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_INTENSITY);
					gotoxy(58,30);
					printf("INVALID INPUT");			
					SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
					gotoxy(58,32);
					printf("Press <ENTER> to try again!");
					getch();
					system("cls");				
				}
			}
			break;

		case 'b':
		case 'B':
			flag=0;
			row=0;
			do
			{
				for(col1=1;col1<10;col1++)
				{
					if(strcmp(situation[col1],"OPEN")==0)
					{
						col1=10;
						flag=2;
					}
					else
						flag=1;						
				}
				if(flag==1)
				{
					SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_INTENSITY);
					gotoxy(58,28);
					printf("No Area is open!");
					SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
					gotoxy(58,30);
					printf("Press <ENTER> to continue");
					getch(); 
					system("cls");
					flag=2;
					row=1;
				}
			}while(flag<2);
			
			if(row!=1)
			{			
				gotoxy(58,28);
				printf("Enter Area #(close): ");
				scanf("%d",&enter);
				fflush(stdin);
				if((enter>=1)&&(enter<=9)&&(strcmp(situation[enter],"OPEN")==0))
				{
					strcpy(situation[enter],"CLOSED");
					system("cls");
				}
				else //if user enter invalid area number or area that is already closed 
				{
					SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_INTENSITY);
					gotoxy(58,30);
					printf("INVALID INPUT");			
					SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
					gotoxy(58,32);
					printf("Press <ENTER> to try again!");
					getch();
					system("cls");
				}				
			}//end of if
			flag=2;
			break;

		case 'c': /*if user wants to manage payroll budget*/
		case 'C':	
			flag=0;
			row=0;
			do
			{
				for(col1=1;col1<10;col1++)
				{
					if(strcmp(situation[col1],"OPEN")==0)
					{
						col1=10;
						flag=2;
					}
					else
						flag=1;						
				}
				if(flag==1)
				{
					SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_INTENSITY);
					gotoxy(58,28);
					printf("No Area is open!");
					SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
					gotoxy(58,30);
					printf("Press <ENTER> to continue");
					getch(); 
					system("cls");
					flag=2;
					row=1;
				}
			}while(flag<2);
			if(row!=1)
			{
				gotoxy(50,28);
				SetConsoleTextAttribute ( h, FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);
				printf("---------------------------------------------------");
				SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
				gotoxy(50,29);
				printf("Enter your Payroll Budget for your open areas:");
				flag=3;
			}			
			break;

		default: 
			SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_INTENSITY);
			gotoxy(58,28);
			printf("INVALID INPUT");			
			SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
			gotoxy(58,30);
			printf("Press <ENTER> to try again!");
			getch();
			system("cls");
			flag=2;
			break;
		}//end of switch		
	}while(flag<3);

	getch();
	return 0;
}
