// log in first time.cpp : Defines the entry point for the console application.
//
//fix the frame position of manager management 
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

	char tempUserName[30]={" "};
	char tempUserPassword[30]={" "};
	char choice;
	int flag=0;
	int count=0;
	int col1=0;
	int enter=0;
	int level=0;	
	int row=0;
	int starTemp=0; //temperary stored
	float tempSalary=0;

	//old local variable
	char situation[10][10]={"0","CLOSED","CLOSED","CLOSED","CLOSED","CLOSED","CLOSED","CLOSED","CLOSED","CLOSED"};
	int area[10]={0,1,2,3,4,5,6,7,8,9};
	int star[10]={0,1,1,1,1,1,1,1,1,1}; //manager promotion
	char managerName[10][30]={"0","1234","1234","1234","1234","1234","1234","1234","1234","1234"};
	float managerSalary[10]={0};

	SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
	gotoxy(10,3);
	printf("WELCOME TO THE PLANET COASTER! OUR NEW PRESIDENT!");
	gotoxy(10,5);
	printf("Here is your initial username and password.");
	gotoxy(10,7);
	printf("Remember you need them to log in!");
	SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY );
	gotoxy(31,5);
	printf("username");
	gotoxy(44,5);
	printf("password");
	gotoxy(63,4);
	printf("1234");
	gotoxy(76,6);
	printf("1234");
	SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_INTENSITY );	
	gotoxy(35,4);
	printf(",------------------------->");
	gotoxy(48,6);
	printf("'------------------------->");
	SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
	gotoxy(10,9);
	printf("Press <ENTER> to contninue!");
	getch();
	do
	{
		gotoxy(10,9);
		printf("Now let's practice.          ");
		gotoxy(10,11);
		printf("USERNAME: ");
		scanf("%s",&tempUserName);
		fflush(stdin);
		if(strcmp(tempUserName,"1234")==0)
		{
			do
			{
				gotoxy(10,13);
				printf("PASSWORD: ");
				scanf("%s",&tempUserPassword);
				fflush(stdin);
				if(strcmp(tempUserPassword,"1234")==0)
				{
					do
					{
						system("cls");
						SetConsoleTextAttribute ( h, FOREGROUND_GREEN|FOREGROUND_INTENSITY );	
						gotoxy(10,3);
						printf("Excellent!");
						SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
						gotoxy(10,5);
						printf("Notice that you can reset your username and password once you log in!");					
						gotoxy(10,7);
						printf("Do you want the instructions to guide you to open the first area of your planet? (Y/N): ");
						choice=_getch();
						fflush(stdin);
						printf("%c",choice);
						switch(choice)
						{
						case 'y':
						case 'Y':
							do
							{
								system("cls"); 
								SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_INTENSITY );
								gotoxy(15,3);
								printf("PLANET COASTER AREA MANAGEMENT");
								SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE);
								for(col1=0;col1<41;col1++)
								{
									gotoxy(10+col1,5); 
									printf("=");
									gotoxy(10+col1,25);
									printf("=");
								}
								for(col1=0;col1<19;col1++)
								{
									gotoxy(10,6+col1);
									printf("||");
									gotoxy(10,12);
									printf("  ");//print entrance
									gotoxy(49,6+col1);
									printf("||");
									gotoxy(49,18);
									printf("  "); //print exit
								}
								
								for(count=1;count<10;count++)
								{
									if((count>=1)&&(count<=3))
									{
										SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
										gotoxy(13+(count-1)*12,7);
										printf("|---------|");
										gotoxy(13+(count-1)*12,8);
										printf("|         |");
										gotoxy(13+(count-1)*12,9);
										printf("|    %d    |",area[count]);
										gotoxy(13+(count-1)*12,10);
										printf("| %6s  |",situation[count]);
										gotoxy(13+(count-1)*12,11);
										printf("|---------|");
									}
									if((count>=4)&&(count<=6))
									{
										SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
										gotoxy(13+(count-4)*12,13);
										printf("|---------|");
										gotoxy(13+(count-4)*12,14);
										printf("|         |");
										gotoxy(13+(count-4)*12,15);
										printf("|    %d    |",area[count]);
										gotoxy(13+(count-4)*12,16);
										printf("| %6s  |",situation[count]);
										gotoxy(13+(count-4)*12,17);
										printf("|---------|");
									}
									if((count>=7)&&(count<=9))
									{
										SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
										gotoxy(13+(count-7)*12,19);
										printf("|---------|");
										gotoxy(13+(count-7)*12,20);
										printf("|         |");
										gotoxy(13+(count-7)*12,21);
										printf("|    %d    |",area[count]);
										gotoxy(13+(count-7)*12,22);
										printf("| %6s  |",situation[count]);
										gotoxy(13+(count-7)*12,23);
										printf("|---------|");
									}
								}							

								/*indicate short cut between entrace and exit*/
								SetConsoleTextAttribute ( h, FOREGROUND_GREEN|FOREGROUND_INTENSITY );
								gotoxy(1,11);
								printf("Entrance");
								gotoxy(5,12);
								printf("'-->");
								SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_INTENSITY );
								for(count=0;count<7;count++)
								{
									gotoxy(10+count*2,12);
									printf("*");
									Sleep(10);
								}
								for(count=0;count<7;count++)
								{
									gotoxy(24,12+count);
									printf("*");
									Sleep(10);
								}
								for(count=0;count<13;count++)
								{
									gotoxy(26+count*2,18);
									printf("*");
									Sleep(10);
								}
								SetConsoleTextAttribute ( h, FOREGROUND_GREEN|FOREGROUND_INTENSITY );								
								gotoxy(52,18);
								printf("--> Exit");
								SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE );
								gotoxy(10,27);
								printf("ps: *** indicates the short cut from entrance to exit");
								SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_INTENSITY );
								gotoxy(14,27);
								printf("***");
								SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
								gotoxy(60,5);
								printf("Now let's open an area by enetering");
								gotoxy(60,7);
								printf("the corresponding area number!");
								SetConsoleTextAttribute ( h, FOREGROUND_GREEN|FOREGROUND_INTENSITY );
								gotoxy(60,9);
								printf("Area Number: ");
								scanf("%d",&enter);
								fflush(stdin);
								SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
								if((enter>=1)&&(enter<=9))
								{
									strcpy(situation[enter],"OPEN");
									gotoxy(60,11);
									printf("Press <ENTER> to continue!");
									getch();
									SetConsoleTextAttribute ( h, FOREGROUND_GREEN|FOREGROUND_INTENSITY );
									gotoxy(60,11);
									printf("Great! Now you got your first area open!");
									for(count=1;count<4;count++)
									{
										if(strcmp(situation[count],"OPEN")==0)
										{
											SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );					
											gotoxy(13+(count-1)*12,7);
											printf("|---------|");
											gotoxy(13+(count-1)*12,8);
											SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY|BACKGROUND_GREEN);
											printf("|         |");
											gotoxy(13+(count-1)*12,9);
											printf("|    %d    |",area[count]);
											gotoxy(13+(count-1)*12,10);
											printf("| %6s  |",situation[count]);
											gotoxy(13+(count-1)*12,11);
											SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
											printf("|---------|");
										}
									}

									for(count=4;count<7;count++)
									{
										if(strcmp(situation[count],"OPEN")==0)
										{
											SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );					
											gotoxy(13+(count-4)*12,13);
											printf("|---------|");
											gotoxy(13+(count-4)*12,14);
											SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY|BACKGROUND_GREEN);
											printf("|         |");
											gotoxy(13+(count-4)*12,15);
											printf("|    %d    |",area[count]);
											gotoxy(13+(count-4)*12,16);
											printf("| %6s  |",situation[count]);
											gotoxy(13+(count-4)*12,17);
											SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
											printf("|---------|");
										}
									}

									for(count=7;count<10;count++)
									{
										if((strcmp(situation[count],"OPEN")==0))
										{
											SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );					
											gotoxy(13+(count-7)*12,19);
											printf("|---------|");
											gotoxy(13+(count-7)*12,20);
											SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY|BACKGROUND_GREEN);
											printf("|         |");
											gotoxy(13+(count-7)*12,21);
											printf("|    %d    |",area[count]);
											gotoxy(13+(count-7)*12,22);
											printf("| %6s  |",situation[count]);
											gotoxy(13+(count-7)*12,23);
											SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
											printf("|---------|");
										}
									}
									gotoxy(60,13);
									printf("Press <ENTER> to continue!");
									getch();

								for(row=0;row<4;row++)
								{
										system("cls");
										SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_INTENSITY );
										gotoxy(29,1);
										printf("AREA");
										gotoxy(56,1);
										printf("MANAGER");	
										SetConsoleTextAttribute ( h, FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );	
										gotoxy(42,1);
										printf("MANAGE");
										gotoxy(67,1);
										printf("SALARY ($/month)");
										SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
										
										for(count=0;count<62;count++) //print frame
										{
											SetConsoleTextAttribute ( h, FOREGROUND_BLUE| FOREGROUND_GREEN|FOREGROUND_INTENSITY );
											gotoxy(22+count,0);
											printf("-");
											gotoxy(22+count,5);
											printf("-");
											SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
										}	
										SetConsoleTextAttribute ( h, FOREGROUND_GREEN |FOREGROUND_RED|FOREGROUND_INTENSITY );
										gotoxy(28,3);
										printf("Area %d",area[enter]);
										SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
										
										for(count=0;count<5;count++)
										{												
											gotoxy(41+count*2,3);
											printf("*");
										}
										
										/*add color for promotion*/
										for(count=1;count<star[enter]+1;count++)
										{					
											SetConsoleTextAttribute ( h, FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
											gotoxy(41+(count-1)*2,3);
											printf("*");
											SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );	
										}
										
										for(count=0;count<13;count++) //print horizontal frame
										{
											SetConsoleTextAttribute ( h, FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
											gotoxy(39+count,2);
											printf("-");
											gotoxy(39+count,4);
											printf("-");					
											SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );				
										}
										
										SetConsoleTextAttribute ( h, FOREGROUND_RED| FOREGROUND_GREEN|FOREGROUND_INTENSITY );
										gotoxy(58,3);
										printf("%s",managerName[enter]);
										SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );	
										
										SetConsoleTextAttribute ( h, FOREGROUND_BLUE | FOREGROUND_RED|FOREGROUND_INTENSITY );	
										gotoxy(70,3);
										printf("%.2f",managerSalary[enter]);
										SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );	
										
										//print vertical frame			
										SetConsoleTextAttribute ( h, FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
										gotoxy(39,3);
										printf("|");
										gotoxy(51,3);
										printf("|");
										SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );	
										
										if(row==0)
										{
											gotoxy(30,6);
											printf("Frist, let's enter the manager name.");
											gotoxy(30,8);
											printf("Name:");
											scanf("%s",&managerName[enter]);									
											gotoxy(30,10);
											SetConsoleTextAttribute ( h, FOREGROUND_GREEN|FOREGROUND_INTENSITY );
											printf("Great! New manager Name is saved!");
											SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
											gotoxy(30,12);
											printf("Press <ENTER> to continue!!");
											getch();
											
										}
										if(row==1)
										{
											gotoxy(30,6);
											printf("Second, let's promote the manger level.");
											gotoxy(30,8);
											printf("The number of * represents current manager level.");
											gotoxy(30,9);
											printf("             -----------");
											gotoxy(30,10);
											printf("for example,| * * * * * | means that the manager is currently on level 3.");
											gotoxy(30,11);
											printf("             -----------");
											SetConsoleTextAttribute ( h, FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
											gotoxy(30,9);
											printf("             -----------");
											gotoxy(42,10);
											printf("| * * *");
											gotoxy(54,10);
											printf("|");
											gotoxy(30,11);
											printf("             -----------");
											gotoxy(44,8);
											printf("*");
											SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
											gotoxy(30,12);
											printf("The higher level a manager has, the better the area can develop.");
											gotoxy(30,15);
											printf("Now let's enter the level number: ");
											scanf("%d",&starTemp);
											fflush(stdin);
											if((starTemp>1)&&(starTemp<=5))
											{
												star[enter]=starTemp;
												gotoxy(30,16);
												SetConsoleTextAttribute ( h, FOREGROUND_GREEN|FOREGROUND_INTENSITY );
												printf("Great! %s is now promoted to level %d!",managerName[enter],star[enter]);
												SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
												gotoxy(30,18);
												printf("Press <ENTER> to continue!");
											}
											else if(starTemp==1)
											{
												SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_INTENSITY);
												gotoxy(30,16);
												printf("INVALID INPUT. %s is currently on level 1!");			
												SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
												gotoxy(30,18);
												printf("Press <ENTER> to try again!");
												row--;
											}
											else
											{
												SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_INTENSITY);
												gotoxy(30,16);
												printf("INVALID INPUT");			
												SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
												gotoxy(30,18);
												printf("Press <ENTER> to try again!");
												row--;
											}
											getch();
																					
										}
										if(row==2)
										{
											gotoxy(30,6);
											printf("Third, let's determine the manager's salary ($/month).");
											gotoxy(30,8);
											printf("Salary is determined based on manager's current level.");
											gotoxy(30,10);
											printf("Salary ($/month): ");
											scanf("%f",&tempSalary);
											if(tempSalary>0)
											{
												managerSalary[enter]=tempSalary;
												gotoxy(30,12);
												SetConsoleTextAttribute ( h, FOREGROUND_GREEN |FOREGROUND_INTENSITY );
												printf("Great! New manager salary is saved is saved!");
												SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
												gotoxy(30,14);
												printf("Press <ENTER> to continue!!");
											}
											else
											{
												SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_INTENSITY);
												gotoxy(30,12);
												printf("INVALID INPUT");			
												SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
												gotoxy(30,14);
												printf("Press <ENTER> to try again!");
												row--;
											}
											
											getch();
											
										}
										if(row==3)
										{
											gotoxy(30,8);
											SetConsoleTextAttribute ( h, FOREGROUND_GREEN |FOREGROUND_INTENSITY );
											printf("Great! Now you have completed all infomation required to open your first area!");
											SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
											gotoxy(30,10);
											printf("Press <ENTER> to continue and open more areas!");
											getch();										
											flag=4;
										}	
									}//end of for loop
								}//end of if
								else
								{
									SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_INTENSITY);
									gotoxy(60,11);
									printf("INVALID INPUT");			
									SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
									gotoxy(60,13);
									printf("Press <ENTER> to try again!");
									getch();						
									flag=0;
								}
							}while(flag<1);
							break;

						case 'n':
						case 'N':
							gotoxy(10,9);
							printf("Press <ENTER> to continue!");
							getch();
							system("cls");
							flag=4;
							break;
						
						default:
							SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_INTENSITY);
							gotoxy(10,9);
							printf("INVALID INPUT");			
							SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
							gotoxy(10,11);
							printf("Press <ENTER> to try again!");
							getch();						
							flag=1;
							break;
						}
					}while(flag<2);

				}//end of if - password
				else
				{				
					SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_INTENSITY);
					gotoxy(20,13);
					printf("1234                                                                                       ");
					gotoxy(10,15);
					printf("INVALID PASSWORD!");			
					SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
					gotoxy(10,17);
					printf("The right password is shown in red above.");
					gotoxy(10,19);
					printf("Press <ENTER> to try again!");
					getch();
					system("cls");
					flag=2;
					SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
					gotoxy(10,3);
					printf("WELCOME TO THE PLANET COASTER! OUR NEW PRESIDENT!");
					gotoxy(10,5);
					printf("Here is your initial username and password.");
					gotoxy(10,7);
					printf("Remember you need them to log in!");
					SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY );
					gotoxy(31,5);
					printf("username");
					gotoxy(44,5);
					printf("password");
					gotoxy(63,4);
					printf("1234");
					gotoxy(76,6);
					printf("1234");
					SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_INTENSITY );	
					gotoxy(35,4);
					printf(",------------------------->");
					gotoxy(48,6);
					printf("'------------------------->");
					SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
					gotoxy(10,9);
					printf("Now let's practice.          ");
					gotoxy(10,11);
					printf("USERNAME: 1234");
				}
			}while(flag<3);
		}//end of if - username
		else
		{
			SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_INTENSITY);
			gotoxy(20,11);
			printf("1234                                                                                    ");
			gotoxy(10,13);
			printf("INVALID USERNAME!");			
			SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
			gotoxy(10,15);
			printf("The right username is shown in red above.");
			gotoxy(10,17);
			printf("Press <ENTER> to try again!");
			getch();
			system("cls");
			flag=3;
			SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
			gotoxy(10,3);
			printf("WELCOME TO THE PLANET COASTER! OUR NEW PRESIDENT!");
			gotoxy(10,5);
			printf("Here is your initial username and password.");
			gotoxy(10,7);
			printf("Remember you need them to log in!");
			SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY );
			gotoxy(31,5);
			printf("username");
			gotoxy(44,5);
			printf("password");
			gotoxy(63,4);
			printf("1234");
			gotoxy(76,6);
			printf("1234");
			SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_INTENSITY );	
			gotoxy(35,4);
			printf(",------------------------->");
			gotoxy(48,6);
			printf("'------------------------->");
			SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
		}
	}while(flag<4);

	return 0;
}
