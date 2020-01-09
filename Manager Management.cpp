// Manager Management.cpp : Defines the entry point for the console application.
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
    
	int enter=0;
	int count=0;
	int col1=0;
	char choice;
	int flag=0;
	char managerNameTemp[30]={"0"};
	float managerSalaryTemp=0;
	
	//old local variable in main
	char situation[10][10]={"0","OPEN","OPEN","OPEN","OPEN","OPEN","OPEN","OPEN","OPEN","OPEN"};
	char managerName[10][30]={"0","1234","1234","1234","1234","1234","1234","1234","1234","1234"};
	float managerSalary[10]={0};
	int area[10]={0,1,2,3,4,5,6,7,8,9};
	//new local variable in main
	int star[10]={0,1,1,1,1,1,1,1,1,1}; //manager promotion
	int starTemp=0; //temperary stored
	
	do
	{
		SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_INTENSITY );
		gotoxy(59,1);
		printf("AREA");
		gotoxy(86,1);
		printf("MANAGER");	
		SetConsoleTextAttribute ( h, FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );	
		gotoxy(73,1);
		printf("MANAGE");
		gotoxy(97,1);
		printf("SALARY ($/month)");
		SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
		
		for(count=0;count<62;count++) //print frame
		{
			SetConsoleTextAttribute ( h, FOREGROUND_BLUE| FOREGROUND_GREEN|FOREGROUND_INTENSITY );
			gotoxy(52+count,0);
			printf("-");
			gotoxy(52+count,2);
			printf("-");
			SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
		}
		
		for(col1=1;col1<10;col1++)
		{	
			SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_INTENSITY );
			gotoxy(58,4+(col1-1)*3);
			printf("Area %d: ",area[col1]);
			SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
			
			if(strcmp(situation[col1],"CLOSED")==0)
			{
				SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_INTENSITY );
				for(count=0;count<10;count++)
				{
					gotoxy(66+count,4+(col1-1)*3);
					printf("-");
				}
				gotoxy(77,4+(col1-1)*3);
				printf("C  L  O  S  E  D");
				for(count=0;count<20;count++)
				{
					gotoxy(94+count,4+(col1-1)*3);
					printf("-");
				}
				SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
			}
			if(strcmp(situation[col1],"OPEN")==0)
			{						
				for(count=0;count<5;count++)
				{												
					gotoxy(71+count*2,4+(col1-1)*3);
					printf("*");
				}
				
				/*add color for promotion*/
				for(count=1;count<star[col1]+1;count++)
				{					
					SetConsoleTextAttribute ( h, FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
					gotoxy(71+(count-1)*2,4+(col1-1)*3);
					printf("*");
					SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );	
				}
				
				for(count=0;count<13;count++) //print horizontal frame
				{
					SetConsoleTextAttribute ( h, FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
					gotoxy(69+count,3+(col1-1)*3);
					printf("-");
					gotoxy(69+count,5+(col1-1)*3);
					printf("-");					
					SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );				
				}
				
				SetConsoleTextAttribute ( h, FOREGROUND_RED| FOREGROUND_GREEN|FOREGROUND_INTENSITY );
				gotoxy(88,4+(col1-1)*3);
				printf("%s",managerName[col1]);
				SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );	
				
				SetConsoleTextAttribute ( h, FOREGROUND_BLUE | FOREGROUND_RED|FOREGROUND_INTENSITY );	
				gotoxy(100,4+(col1-1)*3);
				printf("%.2f",managerSalary[col1]);
				SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );	
				
				//print vertical frame				
				SetConsoleTextAttribute ( h, FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
				gotoxy(69,4+(col1-1)*3);
				printf("|");
				gotoxy(81,4+(col1-1)*3);
				printf("|");
				SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
			
			}//end of if
		}//end of for loop 
		
		for(count=0;count<62;count++)
		{
			SetConsoleTextAttribute ( h, FOREGROUND_BLUE| FOREGROUND_GREEN|FOREGROUND_INTENSITY );
			gotoxy(52+count,30);
			printf("-");
			SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
		}
		gotoxy(52,31);
		printf("Enter corresponding area number (promote/demote) or press '0' to return: ");
		scanf("%d",&enter);
		fflush(stdin);
		if((enter>=1)&&(enter<=9)&&(strcmp(situation[enter],"OPEN")==0))
		{
			SetConsoleTextAttribute ( h, FOREGROUND_GREEN|FOREGROUND_INTENSITY );
			gotoxy(52,33);
			printf("Area number accepted!!");
			SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
			gotoxy(52,35);
			printf("Press <ENTER> to contninue!");	
			getch();
			system("cls");
			
			do
			{
				SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_INTENSITY );
				gotoxy(59,1);
				printf("AREA");
				gotoxy(86,1);
				printf("MANAGER");	
				gotoxy(89,2);
				printf("b");
				SetConsoleTextAttribute ( h, FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );	
				gotoxy(72,1);
				printf("MANAGE");
				gotoxy(75,2);
				printf("a");
				gotoxy(97,1);
				printf("SALARY ($/month)");
				gotoxy(102,2);
				printf("c");
				SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
				
				for(count=0;count<62;count++) //print frame
				{
					SetConsoleTextAttribute ( h, FOREGROUND_BLUE| FOREGROUND_GREEN|FOREGROUND_INTENSITY );
					gotoxy(52+count,0);
					printf("-");
					gotoxy(52+count,3);
					printf("-");
					gotoxy(52+count,8);
					printf("-");
					SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
				}	
				SetConsoleTextAttribute ( h, FOREGROUND_GREEN |FOREGROUND_RED|FOREGROUND_INTENSITY );
				gotoxy(58,5);
				printf("Area %d",area[enter]);
				SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
				
				for(count=0;count<5;count++)
				{												
					gotoxy(71+count*2,5);
					printf("*");
				}
				
				/*add color for promotion*/
				for(count=1;count<star[enter]+1;count++)
				{					
					SetConsoleTextAttribute ( h, FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
					gotoxy(71+(count-1)*2,5);
					printf("*");
					SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );	
				}
				
				for(count=0;count<13;count++) //print horizontal frame
				{
					SetConsoleTextAttribute ( h, FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
					gotoxy(69+count,4);
					printf("-");
					gotoxy(69+count,6);
					printf("-");					
					SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );				
				}
				
				SetConsoleTextAttribute ( h, FOREGROUND_RED| FOREGROUND_GREEN|FOREGROUND_INTENSITY );
				gotoxy(88,5);
				printf("%s",managerName[enter]);
				SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );	
				
				SetConsoleTextAttribute ( h, FOREGROUND_BLUE | FOREGROUND_RED|FOREGROUND_INTENSITY );	
				gotoxy(100,5);
				printf("%.2f",managerSalary[enter]);
				SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );	
				
				//print vertical frame			
				SetConsoleTextAttribute ( h, FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
				gotoxy(69,5);
				printf("|");
				gotoxy(81,5);
				printf("|");
				SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );				
								
				gotoxy(52,9);
				printf("Enter Letter (edit manager info) or press '0' to return: ");
				choice=_getch();
				switch(choice)
				{
				case '0':					
					system("cls");
					flag=2;
					break;
					
				case 'a':
				case 'A':
					gotoxy(52,11);
					printf("Enter the manager level (1-5): ");
					scanf("%d",&starTemp);
					fflush(stdin);
					
					if((starTemp>=1)&&(starTemp<=5))
					{
						if(starTemp==star[enter])
						{
							SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_INTENSITY );
							gotoxy(52,13);
							printf("Manager is currentrly at this level!");
							SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
							gotoxy(52,15);
							printf("Press <ENTER> to try again!");
							getch();
							system("cls");
						}//end of if
						else
						{
							star[enter]=starTemp;  //the temp value becomes the actual value
							SetConsoleTextAttribute ( h, FOREGROUND_GREEN|FOREGROUND_INTENSITY );
							gotoxy(52,13);
							printf("Change Saved!");
							SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
							gotoxy(52,15);
							printf("Press <ENTER> to continue!");
							getch();
							system("cls");
							flag=1;
						}
					}//end of if
					else
					{
						SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_INTENSITY );
						gotoxy(52,13);
						printf("INVALID INPUT");
						SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
						gotoxy(52,15);
						printf("Press <ENTER> to try again!!");
						getch();
						system("cls");
						flag=1;
					}//end of else
					break;
					
				case 'b':
				case 'B':
					gotoxy(52,11);
					printf("Enter Manager Name: ");
					scanf("%s",&managerNameTemp);
					fflush(stdin);
					if(strcmp(managerNameTemp,managerName[enter])==0)
					{
						SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_INTENSITY );
						gotoxy(52,13);
						printf("%s is currently on this position!",managerName[enter]);
						SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
						gotoxy(52,15);
						printf("Press <ENTER> to try again!");
						getch();
						system("cls");
						flag=1;
					}
					if(strcmp(managerNameTemp,managerName[enter])!=0)
					{
						strcpy(managerName[enter],managerNameTemp);//the temp name becomes the actual one
						SetConsoleTextAttribute ( h, FOREGROUND_GREEN|FOREGROUND_INTENSITY );
						gotoxy(52,13);
						printf("Change Saved!");
						SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
						gotoxy(52,15);
						printf("Press <ENTER> to continue!");
						getch();
						system("cls");						
						flag=1;
					}
					break;
					
				case 'c':
				case 'C':
					gotoxy(52,11);
					printf("Enter Manager Salary ($/month): ");
					scanf("%f",&managerSalaryTemp);
					fflush(stdin);
					if(managerSalaryTemp>0)
					{
						managerSalary[enter]=managerSalaryTemp;
						SetConsoleTextAttribute ( h, FOREGROUND_GREEN|FOREGROUND_INTENSITY );
						gotoxy(52,13);
						printf("Change Saved!");
						SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
						gotoxy(52,15);
						printf("Press <ENTER> to continue!");
						getch();
						system("cls");						
						flag=1;
					}
					else
					{
						SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_INTENSITY );
						gotoxy(52,13);
						printf("INVALID INPUT");
						SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
						gotoxy(52,15);
						printf("Press <ENTER> to try again!");
						getch();
						system("cls");
						flag=1;
					}
					break;					
					
				default:
					SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_INTENSITY );
					gotoxy(52,11);
					printf("INVALID INPUT");
					SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
					gotoxy(52,13);
					printf("Press <ENTER> to try again!!");
					getch();
					system("cls");
					flag=1;
					break;					
				}//end of switch							
			}while(flag<2); 			
		}//end of if
		
		else if(enter==0)
		{
			flag=3;
			system("cls");
		}
		else
		{
			SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_INTENSITY );
			gotoxy(52,33);
			printf("INVALID INPUT");
			SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
			gotoxy(52,35);
			printf("Press <ENTER> to try again!!");
			getch();
			system("cls");
			flag=2;
		}		
	}while(flag<3);

	getch();
	return 0;
}
