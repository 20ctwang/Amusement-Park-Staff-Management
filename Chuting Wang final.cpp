// Chuting Wang final.cpp : Defines the entry point for the console application.
//

/*--------------------------Chuting Wang Final----------------------------------*/
/*  This program uses funtions. Users can determine if they want to follow the 	*/
/*  instruction to set and open their first area of the amusement park called	*/
/*  "PLANET COASTER". After the instructions, users would be prompted to 		*/
/*  the initial username and password '1234'. If user forgets the password		*/
/*  they have chance to try again or view the correct username and password		*/
/*  in order to log in to the main menu.										*/
/*																				*/
/*  Main Menu - area management													*/
/*  Users in area management can open area, close area and determine the payroll*/
/*  budget for all the managers salary. Everything that is valid would be 		*/
/*  printed to screen so that users can know which area is open. Also, if users	*/
/*  follow the instruction before, the area they determine to open is also saved*/
/*  here.																		*/
/*																				*/
/*  Main Menu - manager management												*/
/*  Users in manager management can determine the manager info specifically to 	*/
/*  every area that is open. Users are prompted to enter manager's level, 		*/
/*  manager's name, as well as manager's salary. The manager's salary is related*/
/*  to the payroll budget that user determines in area management, such that if	*/
/*  the total manger's salary is greater than the payroll budget, the money left*/
/*  would turn red																*/
/*																				*/
/*  Main Menu - area development view											*/
/*  Users in area development view can view the development of the open areas 	*/
/*  based on the area and manager management users determine before. Areas would*/
/*  show the relative color based on the manager's level. 						*/
/*																				*/
/*  Main Menu- reset account/initialize acount/exit								*/
/*  Users in reset account can set their new username and password. After that  */
/*  users would be prompted to log in again based upon their new account.       */
/*  Users in initialize account can initialize their account which takes '1234' */
/*  as users' username and password. Users would be prompted to log in again    */
/*  after that. In exit, users would determine if they want to return, log in   */
/*  or exit the program.                                                        */
/*                                                                              */
/*                                                                              */
/*                   PROGRAM ID:Chuting Wang Final                              */ 
/*                   PROGRAMMER:Chuting Wang                                    */
/*                   RUN DATE:June 19th, 2018                                   */ 
/*                                                   						    */
/*------------------------------------------------------------------------------*/
/*---------------------------PREPROCESSING DIRECTIVES---------------------------*/
#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string.h>

/*---------------------------------gotoxy function-------------------------------*/
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
	
/*---------------------------------MAINLINE CONTROL--------------------------------*/
int main(void)
{
/*------------------------------------TITLE---------------------------------------*/

	system("TITLE Chuting Wang final");
	
/*------------------------------DECLARE FUNCTIONS PROTOTYPES----------------------*/
	void  intro          (void);									                   //print program introduction 
	void  guide          (char[10][10],int[10],int[10],char[10][30],float[10]);        //guide user to be familar with the program
	void  login          (char[2][30],char[2][30],int);			       	               //user login
	int   mainMenu       (void);				                                       //mainMenu 
	float areaManage     (int[10],float,char[10][10]);                                 //Area management 
	void  managerManage  (int[10],char[10][30],float[10],int[10],char[10][10],float);  //manager management
	void  viewArea       (char[10][10],int[10],int[10],float,float[10]);               //view area development
	void  resetAccount   (char[2][30],char[2][30],int);                                //reset login infomation and personal infomation
	int   logout         (int);													       //log out 


/*-------------------------------DECLARE LOCAL VARIABLES--------------------------*/
	/*program*/
	char  userName[2][30];            //userName 
	char  userPassword[2][30];        //password
	int   area[10]={0};               //area order
	float areaEstimated=0;            //payroll budget of each area
	char  managerName[10][30]={"0"};  //manager names
	float managerSalary[10]={0};      //salary for each manager
	int   mainMenuChoice=0;           //main menu choice
	char  situation[10][10]={"0"};    //area situation while making situation[0] is 0
	int   star[10]={0};               //manager level

	/*others*/
	int   flag=0;        //do while
	int   row=0;         //for loop
	int   pass=0;        //determine if user reset username and password 

/*set text color*/
	HANDLE h = GetStdHandle (STD_OUTPUT_HANDLE);   
	WORD wOldColorAttrs;                                                        
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;                     
	GetConsoleScreenBufferInfo(h, &csbiInfo);                     
	wOldColorAttrs = csbiInfo.wAttributes;

/*set screen size*/
	HWND foregroundWindow = GetForegroundWindow();

	//set initial value for variables
	for(row=1;row<10;row++)
	{
		area[row]=row;
		strcpy(situation[row],"CLOSED");
		strcpy(managerName[row],"----");
		star[row]=1;		
	}
	strcpy(userPassword[0],"1234"); //set initial password
	strcpy(userName[0],"1234");     //set initial userName
	
/*-------------------------------------FUNCTIONS CALLS-----------------------------------*/
	
	intro();  												 //print animation intro
	guide(situation,area,star,managerName,managerSalary);    //guide user to get familiar with the program
	pass=0;  												 //username and password are initial value at this point
    ShowWindow(foregroundWindow, SW_MAXIMIZE); 				 //full screen

	do
	{
		login(userName,userPassword,pass);  //log in 
		do
		{
			mainMenuChoice=mainMenu();  //main menu 
			switch(mainMenuChoice)
			{		
			case 1:
				areaEstimated=areaManage(area,areaEstimated,situation);  //area management 
				flag=5;  //return to main menu
				break;
				
			case 2:				
				managerManage(area,managerName,managerSalary,star,situation,areaEstimated);  //manager management
				flag=5;  //return to main menu
				break;
			
			case 3:
				viewArea(situation,star,area,areaEstimated,managerSalary);  //view area
				flag=5;  //return to main menu
				break;
				
			case 4:
				resetAccount(userName,userPassword,pass);  //reset password and username
				pass=1;	
				flag=6;	 //return to log in	
				break;
				
			case 5: //initialize account
				pass=0;  //set the username and password '1234'	
				gotoxy(60,5);
				printf("Username and Password have been initialized!");			
				gotoxy(60,7);
				printf("Press <ENTER> to log in again!");
				getch();
				system("cls");  //clear the screen
				flag=6;    //return to log in 
				break;
				
			case 6:
				flag=logout(flag);  //log out
				break;
			
			default:  
				gotoxy(52,21); 
				SetConsoleTextAttribute ( h,  FOREGROUND_RED|FOREGROUND_INTENSITY );
				printf("INVALID INPUT");
				SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
				gotoxy(52,23);
				printf("Press <ENTER> to continue!");
			}//end of switch
		}while(flag<6);
	}while(flag<7); //exit the program when flag is greater than or equal to 7
	gotoxy(60,5);
	printf("Press <ENTER> to continue!");
	getch(); //hold screen
	return 0;
}//end main

/*--------------------FUNCTIONS DEFINITION----------------*/

void intro(void) 
{
	HANDLE h = GetStdHandle (STD_OUTPUT_HANDLE);   
	
	//do the animation of intro
	SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY);  //foregrond color
	printf("\n\n\n\n");
	printf("========================================================================================================================");
	SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY|BACKGROUND_BLUE);
	printf("\nWWWWWWWW                           WWWWWWWWEEEEEEEEEEEEEEEEEEEEEELLLLLLLLLLL                    CCCCCCCCCCCCC     OOOOO");
	printf("\nW::::::W                           W::::::WE::::::::::::::::::::EL:::::::::L                 CCC::::::::::::C   OO:::::");
	printf("\nW::::::W                           W::::::WE::::::::::::::::::::EL:::::::::L               CC:::::::::::::::C OO:::::::");
	printf("\nW::::::W                           W::::::WEE::::::EEEEEEEEE::::ELL:::::::LL              C:::::CCCCCCCC::::CO:::::::OO");
	printf("\n W:::::W           WWWWW           W:::::W   E:::::E       EEEEEE  L:::::L               C:::::C       CCCCCCO::::::O  ");
	printf("\n  W:::::W         W:::::W         W:::::W    E:::::E               L:::::L              C:::::C              O:::::O   ");
	printf("\n   W:::::W       W:::::::W       W:::::W     E::::::EEEEEEEEEE     L:::::L              C:::::C              O:::::O   ");
	printf("\n    W:::::W     W:::::::::W     W:::::W      E:::::::::::::::E     L:::::L              C:::::C              O:::::O   ");
	printf("\n     W:::::W   W:::::W:::::W   W:::::W       E:::::::::::::::E     L:::::L              C:::::C              O:::::O   ");
	printf("\n      W:::::W W:::::W W:::::W W:::::W        E::::::EEEEEEEEEE     L:::::L              C:::::C              O:::::O   ");
	printf("\n       W:::::W:::::W   W:::::W:::::W         E:::::E               L:::::L              C:::::C              O:::::O   ");
	printf("\n        W:::::::::W     W:::::::::W          E:::::E       EEEEEE  L:::::L         LLLLLLC:::::C       CCCCCCO::::::O  ");
	printf("\n         W:::::::W       W:::::::W         EE::::::EEEEEEEE:::::ELL:::::::LLLLLLLLL:::::L C:::::CCCCCCCC::::CO:::::::OO");
	printf("\n          W:::::W         W:::::W          E::::::::::::::::::::EL::::::::::::::::::::::L  CC:::::::::::::::C OO:::::::");
	printf("\n           W:::W           W:::W           E::::::::::::::::::::EL::::::::::::::::::::::L    CCC::::::::::::C   OO:::::");
	printf("\n            WWW             WWW            EEEEEEEEEEEEEEEEEEEEEELLLLLLLLLLLLLLLLLLLLLLLL       CCCCCCCCCCCCC     OOOOO");
	SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
	printf("\n========================================================================================================================");
	Sleep(50);
	system("cls"); //clear screen

	printf("\n\n\n\n");
	printf("========================================================================================================================");
	SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY|BACKGROUND_BLUE);
	printf("\n                         WWWWWWWWEEEEEEEEEEEEEEEEEEEEEELLLLLLLLLLL                    CCCCCCCCCCCCC     OOOOOOOOOO     ");
	printf("\n                         W::::::WE::::::::::::::::::::EL:::::::::L                 CCC::::::::::::C   OO::::::::::OO   ");
	printf("\n                         W::::::WE::::::::::::::::::::EL:::::::::L               CC:::::::::::::::C OO::::::::::::::OO ");
	printf("\n                         W::::::WEE::::::EEEEEEEEE::::ELL:::::::LL              C:::::CCCCCCCC::::CO:::::::OOO::::::::O");
	printf("\n         WWWWW           W:::::W   E:::::E       EEEEEE  L:::::L               C:::::C       CCCCCCO::::::O   O:::::::O");
	printf("\n        W:::::W         W:::::W    E:::::E               L:::::L              C:::::C              O:::::O     O::::::O");
	printf("\n       W:::::::W       W:::::W     E::::::EEEEEEEEEE     L:::::L              C:::::C              O:::::O     O::::::O");
	printf("\nW     W:::::::::W     W:::::W      E:::::::::::::::E     L:::::L              C:::::C              O:::::O     O::::::O");
	printf("\n:W   W:::::W:::::W   W:::::W       E:::::::::::::::E     L:::::L              C:::::C              O:::::O     O::::::O");
	printf("\n::W W:::::W W:::::W W:::::W        E::::::EEEEEEEEEE     L:::::L              C:::::C              O:::::O     O::::::O");
	printf("\n:::W:::::W   W:::::W:::::W         E:::::E               L:::::L              C:::::C              O:::::O     O::::::O");
	printf("\n::::::::W     W:::::::::W          E:::::E       EEEEEE  L:::::L         LLLLLLC:::::C       CCCCCCO::::::O   O:::::::O");
	printf("\n:::::::W       W:::::::W         EE::::::EEEEEEEE:::::ELL:::::::LLLLLLLLL:::::L C:::::CCCCCCCC::::CO:::::::OOO::::::::O");
	printf("\nW:::::W         W:::::W          E::::::::::::::::::::EL::::::::::::::::::::::L  CC:::::::::::::::C OO::::::::::::::OO ");
	printf("\n W:::W           W:::W           E::::::::::::::::::::EL::::::::::::::::::::::L    CCC::::::::::::C   OO::::::::::OO   ");
	printf("\n  WWW             WWW            EEEEEEEEEEEEEEEEEEEEEELLLLLLLLLLLLLLLLLLLLLLLL       CCCCCCCCCCCCC     OOOOOOOOOO     ");
	SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
	printf("\n========================================================================================================================");
	Sleep(50);
	system("cls");

	printf("\n\n\n\n");
	printf("========================================================================================================================");
	SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY|BACKGROUND_BLUE);
	printf("\n               WWWWWWWWEEEEEEEEEEEEEEEEEEEEEELLLLLLLLLLL                    CCCCCCCCCCCCC     OOOOOOOOOO     MMMMMMMM  ");
	printf("\n               W::::::WE::::::::::::::::::::EL:::::::::L                 CCC::::::::::::C   OO::::::::::OO   M:::::::M ");
	printf("\n               W::::::WE::::::::::::::::::::EL:::::::::L               CC:::::::::::::::C OO::::::::::::::OO M::::::::M");
	printf("\n               W::::::WEE::::::EEEEEEEEE::::ELL:::::::LL              C:::::CCCCCCCC::::CO:::::::OOO::::::::OM:::::::::");
	printf("\nWWWW           W:::::W   E:::::E       EEEEEE  L:::::L               C:::::C       CCCCCCO::::::O   O:::::::OM:::::::::");
	printf("\n::::W         W:::::W    E:::::E               L:::::L              C:::::C              O:::::O     O::::::OM:::::::::");
	printf("\n:::::W       W:::::W     E::::::EEEEEEEEEE     L:::::L              C:::::C              O:::::O     O::::::OM:::::::M:");
	printf("\n::::::W     W:::::W      E:::::::::::::::E     L:::::L              C:::::C              O:::::O     O::::::OM::::::M M");
	printf("\n:W:::::W   W:::::W       E:::::::::::::::E     L:::::L              C:::::C              O:::::O     O::::::OM::::::M  ");
	printf("\nW W:::::W W:::::W        E::::::EEEEEEEEEE     L:::::L              C:::::C              O:::::O     O::::::OM::::::M  ");
	printf("\n   W:::::W:::::W         E:::::E               L:::::L              C:::::C              O:::::O     O::::::OM::::::M  ");
	printf("\n    W:::::::::W          E:::::E       EEEEEE  L:::::L         LLLLLLC:::::C       CCCCCCO::::::O   O:::::::OM::::::M  ");
	printf("\n     W:::::::W         EE::::::EEEEEEEE:::::ELL:::::::LLLLLLLLL:::::L C:::::CCCCCCCC::::CO:::::::OOO::::::::OM::::::M  ");
	printf("\n      W:::::W          E::::::::::::::::::::EL::::::::::::::::::::::L  CC:::::::::::::::C OO::::::::::::::OO M::::::M  ");
	printf("\n       W:::W           E::::::::::::::::::::EL::::::::::::::::::::::L    CCC::::::::::::C   OO::::::::::OO   M::::::M  ");
	printf("\n        WWW            EEEEEEEEEEEEEEEEEEEEEELLLLLLLLLLLLLLLLLLLLLLLL       CCCCCCCCCCCCC     OOOOOOOOOO     MMMMMMMM  ");
	SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
	printf("\n========================================================================================================================");
	Sleep(50);
	system("cls");

	printf("\n\n\n\n");
	printf("========================================================================================================================");
	SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY|BACKGROUND_BLUE);
	printf("\n     WWWWWWWWEEEEEEEEEEEEEEEEEEEEEELLLLLLLLLLL                    CCCCCCCCCCCCC     OOOOOOOOOO     MMMMMMMM            ");
	printf("\n     W::::::WE::::::::::::::::::::EL:::::::::L                 CCC::::::::::::C   OO::::::::::OO   M:::::::M           ");
	printf("\n     W::::::WE::::::::::::::::::::EL:::::::::L               CC:::::::::::::::C OO::::::::::::::OO M::::::::M          ");
	printf("\n     W::::::WEE::::::EEEEEEEEE::::ELL:::::::LL              C:::::CCCCCCCC::::CO:::::::OOO::::::::OM:::::::::M         ");
	printf("\n     W:::::W   E:::::E       EEEEEE  L:::::L               C:::::C       CCCCCCO::::::O   O:::::::OM::::::::::M       M");
	printf("\n    W:::::W    E:::::E               L:::::L              C:::::C              O:::::O     O::::::OM:::::::::::M     M:");
	printf("\n   W:::::W     E::::::EEEEEEEEEE     L:::::L              C:::::C              O:::::O     O::::::OM:::::::M::::M   M::");
	printf("\n  W:::::W      E:::::::::::::::E     L:::::L              C:::::C              O:::::O     O::::::OM::::::M M::::M M:::");
	printf("\n W:::::W       E:::::::::::::::E     L:::::L              C:::::C              O:::::O     O::::::OM::::::M  M::::M::::");
	printf("\nW:::::W        E::::::EEEEEEEEEE     L:::::L              C:::::C              O:::::O     O::::::OM::::::M   M:::::::M");
	printf("\n:::::W         E:::::E               L:::::L              C:::::C              O:::::O     O::::::OM::::::M    M:::::M ");
	printf("\n::::W          E:::::E       EEEEEE  L:::::L         LLLLLLC:::::C       CCCCCCO::::::O   O:::::::OM::::::M     MMMMM  ");
	printf("\n:::W         EE::::::EEEEEEEE:::::ELL:::::::LLLLLLLLL:::::L C:::::CCCCCCCC::::CO:::::::OOO::::::::OM::::::M            ");
	printf("\n::W          E::::::::::::::::::::EL::::::::::::::::::::::L  CC:::::::::::::::C OO::::::::::::::OO M::::::M            ");
	printf("\n:W           E::::::::::::::::::::EL::::::::::::::::::::::L    CCC::::::::::::C   OO::::::::::OO   M::::::M            ");
	printf("\nW            EEEEEEEEEEEEEEEEEEEEEELLLLLLLLLLLLLLLLLLLLLLLL       CCCCCCCCCCCCC     OOOOOOOOOO     MMMMMMMM            ");
	SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
	printf("\n========================================================================================================================");
	Sleep(50);
	system("cls");

	printf("\n\n\n\n");
	printf("========================================================================================================================");
	SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY|BACKGROUND_BLUE);
	printf("\nWWWEEEEEEEEEEEEEEEEEEEEEELLLLLLLLLLL                    CCCCCCCCCCCCC     OOOOOOOOOO     MMMMMMMM               MMMMMMM");
	printf("\n::WE::::::::::::::::::::EL:::::::::L                 CCC::::::::::::C   OO::::::::::OO   M:::::::M             M:::::::");
	printf("\n::WE::::::::::::::::::::EL:::::::::L               CC:::::::::::::::C OO::::::::::::::OO M::::::::M           M::::::::");
	printf("\n::WEE::::::EEEEEEEEE::::ELL:::::::LL              C:::::CCCCCCCC::::CO:::::::OOO::::::::OM:::::::::M         M:::::::::");
	printf("\n:W   E:::::E       EEEEEE  L:::::L               C:::::C       CCCCCCO::::::O   O:::::::OM::::::::::M       M::::::::::");
	printf("\nW    E:::::E               L:::::L              C:::::C              O:::::O     O::::::OM:::::::::::M     M:::::::::::");
	printf("\n     E::::::EEEEEEEEEE     L:::::L              C:::::C              O:::::O     O::::::OM:::::::M::::M   M::::M:::::::");
	printf("\n     E:::::::::::::::E     L:::::L              C:::::C              O:::::O     O::::::OM::::::M M::::M M::::M M::::::");
	printf("\n     E:::::::::::::::E     L:::::L              C:::::C              O:::::O     O::::::OM::::::M  M::::M::::M  M::::::");
	printf("\n     E::::::EEEEEEEEEE     L:::::L              C:::::C              O:::::O     O::::::OM::::::M   M:::::::M   M::::::");
	printf("\n     E:::::E               L:::::L              C:::::C              O:::::O     O::::::OM::::::M    M:::::M    M::::::");
	printf("\n     E:::::E       EEEEEE  L:::::L         LLLLLLC:::::C       CCCCCCO::::::O   O:::::::OM::::::M     MMMMM     M::::::");
	printf("\n   EE::::::EEEEEEEE:::::ELL:::::::LLLLLLLLL:::::L C:::::CCCCCCCC::::CO:::::::OOO::::::::OM::::::M               M::::::");
	printf("\n   E::::::::::::::::::::EL::::::::::::::::::::::L  CC:::::::::::::::C OO::::::::::::::OO M::::::M               M::::::");
	printf("\n   E::::::::::::::::::::EL::::::::::::::::::::::L    CCC::::::::::::C   OO::::::::::OO   M::::::M               M::::::");
	printf("\n   EEEEEEEEEEEEEEEEEEEEEELLLLLLLLLLLLLLLLLLLLLLLL       CCCCCCCCCCCCC     OOOOOOOOOO     MMMMMMMM               MMMMMMM");
	SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
	printf("\n========================================================================================================================");
	Sleep(50);
	system("cls");

	printf("\n\n\n\n");
	printf("========================================================================================================================");
	SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY|BACKGROUND_BLUE);
	printf("\nEEEEEEEEEEEEEEELLLLLLLLLLL                    CCCCCCCCCCCCC     OOOOOOOOOO     MMMMMMMM               MMMMMMMMEEEEEEEEE");
	printf("\n::::::::::::::EL:::::::::L                 CCC::::::::::::C   OO::::::::::OO   M:::::::M             M:::::::ME::::::::");
	printf("\n::::::::::::::EL:::::::::L               CC:::::::::::::::C OO::::::::::::::OO M::::::::M           M::::::::ME::::::::");
	printf("\n:EEEEEEEEE::::ELL:::::::LL              C:::::CCCCCCCC::::CO:::::::OOO::::::::OM:::::::::M         M:::::::::MEE::::::E");
	printf("\n:E       EEEEEE  L:::::L               C:::::C       CCCCCCO::::::O   O:::::::OM::::::::::M       M::::::::::M  E:::::E");
	printf("\n:E               L:::::L              C:::::C              O:::::O     O::::::OM:::::::::::M     M:::::::::::M  E:::::E");
	printf("\n::EEEEEEEEEE     L:::::L              C:::::C              O:::::O     O::::::OM:::::::M::::M   M::::M:::::::M  E::::::");
	printf("\n:::::::::::E     L:::::L              C:::::C              O:::::O     O::::::OM::::::M M::::M M::::M M::::::M  E::::::");
	printf("\n:::::::::::E     L:::::L              C:::::C              O:::::O     O::::::OM::::::M  M::::M::::M  M::::::M  E::::::");
	printf("\n::EEEEEEEEEE     L:::::L              C:::::C              O:::::O     O::::::OM::::::M   M:::::::M   M::::::M  E::::::");
	printf("\n:E               L:::::L              C:::::C              O:::::O     O::::::OM::::::M    M:::::M    M::::::M  E:::::E");
	printf("\n:E       EEEEEE  L:::::L         LLLLLLC:::::C       CCCCCCO::::::O   O:::::::OM::::::M     MMMMM     M::::::M  E:::::E");
	printf("\n:EEEEEEEE:::::ELL:::::::LLLLLLLLL:::::L C:::::CCCCCCCC::::CO:::::::OOO::::::::OM::::::M               M::::::MEE::::::E");
	printf("\n::::::::::::::EL::::::::::::::::::::::L  CC:::::::::::::::C OO::::::::::::::OO M::::::M               M::::::ME::::::::");
	printf("\n::::::::::::::EL::::::::::::::::::::::L    CCC::::::::::::C   OO::::::::::OO   M::::::M               M::::::ME::::::::");
	printf("\nEEEEEEEEEEEEEEELLLLLLLLLLLLLLLLLLLLLLLL       CCCCCCCCCCCCC     OOOOOOOOOO     MMMMMMMM               MMMMMMMMEEEEEEEEE");
	SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
	printf("\n========================================================================================================================");
	Sleep(50);
	system("cls");

	printf("\n\n\n\n");
	printf("========================================================================================================================");
	SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY|BACKGROUND_BLUE);
	printf("\nEEEEELLLLLLLLLLL                    CCCCCCCCCCCCC     OOOOOOOOOO     MMMMMMMM               MMMMMMMMEEEEEEEEEEEEEEEEEEE");
	printf("\n::::EL:::::::::L                 CCC::::::::::::C   OO::::::::::OO   M:::::::M             M:::::::ME::::::::::::::::::");
	printf("\n::::EL:::::::::L               CC:::::::::::::::C OO::::::::::::::OO M::::::::M           M::::::::ME::::::::::::::::::");
	printf("\n::::ELL:::::::LL              C:::::CCCCCCCC::::CO:::::::OOO::::::::OM:::::::::M         M:::::::::MEE::::::EEEEEEEEE::");
	printf("\nEEEEE  L:::::L               C:::::C       CCCCCCO::::::O   O:::::::OM::::::::::M       M::::::::::M  E:::::E       EEE");
	printf("\n       L:::::L              C:::::C              O:::::O     O::::::OM:::::::::::M     M:::::::::::M  E:::::E          ");
	printf("\nEE     L:::::L              C:::::C              O:::::O     O::::::OM:::::::M::::M   M::::M:::::::M  E::::::EEEEEEEEEE");
	printf("\n:E     L:::::L              C:::::C              O:::::O     O::::::OM::::::M M::::M M::::M M::::::M  E:::::::::::::::E");
	printf("\n:E     L:::::L              C:::::C              O:::::O     O::::::OM::::::M  M::::M::::M  M::::::M  E:::::::::::::::E");
	printf("\nEE     L:::::L              C:::::C              O:::::O     O::::::OM::::::M   M:::::::M   M::::::M  E::::::EEEEEEEEEE");
	printf("\n       L:::::L              C:::::C              O:::::O     O::::::OM::::::M    M:::::M    M::::::M  E:::::E          ");
	printf("\nEEEEE  L:::::L         LLLLLLC:::::C       CCCCCCO::::::O   O:::::::OM::::::M     MMMMM     M::::::M  E:::::E       EEE");
	printf("\n::::ELL:::::::LLLLLLLLL:::::L C:::::CCCCCCCC::::CO:::::::OOO::::::::OM::::::M               M::::::MEE::::::EEEEEEEE:::");
	printf("\n::::EL::::::::::::::::::::::L  CC:::::::::::::::C OO::::::::::::::OO M::::::M               M::::::ME::::::::::::::::::");
	printf("\n::::EL::::::::::::::::::::::L    CCC::::::::::::C   OO::::::::::OO   M::::::M               M::::::ME::::::::::::::::::");
	printf("\nEEEEELLLLLLLLLLLLLLLLLLLLLLLL       CCCCCCCCCCCCC     OOOOOOOOOO     MMMMMMMM               MMMMMMMMEEEEEEEEEEEEEEEEEEE");
	SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
	printf("\n========================================================================================================================");
	Sleep(50);
	system("cls");
	
	printf("\n\n\n\n");
	printf("========================================================================================================================");
	SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY|BACKGROUND_BLUE);
	printf("\nLLLLLL                    CCCCCCCCCCCCC     OOOOOOOOOO     MMMMMMMM               MMMMMMMMEEEEEEEEEEEEEEEEEEEEEE     TT");
	printf("\n:::::L                 CCC::::::::::::C   OO::::::::::OO   M:::::::M             M:::::::ME::::::::::::::::::::E     T:");
	printf("\n:::::L               CC:::::::::::::::C OO::::::::::::::OO M::::::::M           M::::::::ME::::::::::::::::::::E     T:");
	printf("\n::::LL              C:::::CCCCCCCC::::CO:::::::OOO::::::::OM:::::::::M         M:::::::::MEE::::::EEEEEEEEE::::E     T:");
	printf("\n:::L               C:::::C       CCCCCCO::::::O   O:::::::OM::::::::::M       M::::::::::M  E:::::E       EEEEEE     TT");
	printf("\n:::L              C:::::C              O:::::O     O::::::OM:::::::::::M     M:::::::::::M  E:::::E                    ");
	printf("\n:::L              C:::::C              O:::::O     O::::::OM:::::::M::::M   M::::M:::::::M  E::::::EEEEEEEEEE          ");
	printf("\n:::L              C:::::C              O:::::O     O::::::OM::::::M M::::M M::::M M::::::M  E:::::::::::::::E          ");
	printf("\n:::L              C:::::C              O:::::O     O::::::OM::::::M  M::::M::::M  M::::::M  E:::::::::::::::E          ");
	printf("\n:::L              C:::::C              O:::::O     O::::::OM::::::M   M:::::::M   M::::::M  E::::::EEEEEEEEEE          ");
	printf("\n:::L              C:::::C              O:::::O     O::::::OM::::::M    M:::::M    M::::::M  E:::::E                    ");
	printf("\n:::L         LLLLLLC:::::C       CCCCCCO::::::O   O:::::::OM::::::M     MMMMM     M::::::M  E:::::E       EEEEEE       ");
	printf("\n::::LLLLLLLLL:::::L C:::::CCCCCCCC::::CO:::::::OOO::::::::OM::::::M               M::::::MEE::::::EEEEEEEE:::::E       ");
	printf("\n::::::::::::::::::L  CC:::::::::::::::C OO::::::::::::::OO M::::::M               M::::::ME::::::::::::::::::::E       ");
	printf("\n::::::::::::::::::L    CCC::::::::::::C   OO::::::::::OO   M::::::M               M::::::ME::::::::::::::::::::E       ");
	printf("\nLLLLLLLLLLLLLLLLLLL       CCCCCCCCCCCCC     OOOOOOOOOO     MMMMMMMM               MMMMMMMMEEEEEEEEEEEEEEEEEEEEEE       ");
	SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
	printf("\n========================================================================================================================");
	Sleep(50);
	system("cls");
	
	printf("\n\n\n\n");
	printf("========================================================================================================================");
	SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY|BACKGROUND_BLUE);
	printf("\n                CCCCCCCCCCCCC     OOOOOOOOOO     MMMMMMMM               MMMMMMMMEEEEEEEEEEEEEEEEEEEEEE     TTTTTTTTTTTT");
	printf("\n             CCC::::::::::::C   OO::::::::::OO   M:::::::M             M:::::::ME::::::::::::::::::::E     T:::::::::::");
	printf("\n           CC:::::::::::::::C OO::::::::::::::OO M::::::::M           M::::::::ME::::::::::::::::::::E     T:::::::::::");
	printf("\n          C:::::CCCCCCCC::::CO:::::::OOO::::::::OM:::::::::M         M:::::::::MEE::::::EEEEEEEEE::::E     T:::::TT::::");
	printf("\n         C:::::C       CCCCCCO::::::O   O:::::::OM::::::::::M       M::::::::::M  E:::::E       EEEEEE     TTTTTT  T:::");
	printf("\n        C:::::C              O:::::O     O::::::OM:::::::::::M     M:::::::::::M  E:::::E                          T:::");
	printf("\n        C:::::C              O:::::O     O::::::OM:::::::M::::M   M::::M:::::::M  E::::::EEEEEEEEEE                T:::");
	printf("\n        C:::::C              O:::::O     O::::::OM::::::M M::::M M::::M M::::::M  E:::::::::::::::E                T:::");
	printf("\n        C:::::C              O:::::O     O::::::OM::::::M  M::::M::::M  M::::::M  E:::::::::::::::E                T:::");
	printf("\n        C:::::C              O:::::O     O::::::OM::::::M   M:::::::M   M::::::M  E::::::EEEEEEEEEE                T:::");
	printf("\n        C:::::C              O:::::O     O::::::OM::::::M    M:::::M    M::::::M  E:::::E                          T:::");
	printf("\n   LLLLLLC:::::C       CCCCCCO::::::O   O:::::::OM::::::M     MMMMM     M::::::M  E:::::E       EEEEEE             T:::");
	printf("\nLLL:::::L C:::::CCCCCCCC::::CO:::::::OOO::::::::OM::::::M               M::::::MEE::::::EEEEEEEE:::::E           TT::::");
	printf("\n::::::::L  CC:::::::::::::::C OO::::::::::::::OO M::::::M               M::::::ME::::::::::::::::::::E           T:::::");
	printf("\n::::::::L    CCC::::::::::::C   OO::::::::::OO   M::::::M               M::::::ME::::::::::::::::::::E           T:::::");
	printf("\nLLLLLLLLL       CCCCCCCCCCCCC     OOOOOOOOOO     MMMMMMMM               MMMMMMMMEEEEEEEEEEEEEEEEEEEEEE           TTTTTT");
	SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
	printf("\n========================================================================================================================");
	Sleep(50);
	system("cls");
	
	printf("\n\n\n\n");
	printf("========================================================================================================================");
	SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY|BACKGROUND_BLUE);
	printf("\n      CCCCCCCCCCCCC     OOOOOOOOOO     MMMMMMMM               MMMMMMMMEEEEEEEEEEEEEEEEEEEEEE     TTTTTTTTTTTTTTTTTTTTTT");
	printf("\n   CCC::::::::::::C   OO::::::::::OO   M:::::::M             M:::::::ME::::::::::::::::::::E     T:::::::::::::::::::::");
	printf("\n CC:::::::::::::::C OO::::::::::::::OO M::::::::M           M::::::::ME::::::::::::::::::::E     T:::::::::::::::::::::");
	printf("\nC:::::CCCCCCCC::::CO:::::::OOO::::::::OM:::::::::M         M:::::::::MEE::::::EEEEEEEEE::::E     T:::::TT:::::::TT:::::");
	printf("\n:::::C       CCCCCCO::::::O   O:::::::OM::::::::::M       M::::::::::M  E:::::E       EEEEEE     TTTTTT  T:::::T  TTTTT");
	printf("\n::::C              O:::::O     O::::::OM:::::::::::M     M:::::::::::M  E:::::E                          T:::::T       ");
	printf("\n::::C              O:::::O     O::::::OM:::::::M::::M   M::::M:::::::M  E::::::EEEEEEEEEE                T:::::T       ");
	printf("\n::::C              O:::::O     O::::::OM::::::M M::::M M::::M M::::::M  E:::::::::::::::E                T:::::T       ");
	printf("\n::::C              O:::::O     O::::::OM::::::M  M::::M::::M  M::::::M  E:::::::::::::::E                T:::::T       ");
	printf("\n::::C              O:::::O     O::::::OM::::::M   M:::::::M   M::::::M  E::::::EEEEEEEEEE                T:::::T       ");
	printf("\n::::C              O:::::O     O::::::OM::::::M    M:::::M    M::::::M  E:::::E                          T:::::T       ");
	printf("\n:::::C       CCCCCCO::::::O   O:::::::OM::::::M     MMMMM     M::::::M  E:::::E       EEEEEE             T:::::T       ");
	printf("\nC:::::CCCCCCCC::::CO:::::::OOO::::::::OM::::::M               M::::::MEE::::::EEEEEEEE:::::E           TT:::::::TT     ");
	printf("\n CC:::::::::::::::C OO::::::::::::::OO M::::::M               M::::::ME::::::::::::::::::::E           T:::::::::T     ");
	printf("\n   CCC::::::::::::C   OO::::::::::OO   M::::::M               M::::::ME::::::::::::::::::::E           T:::::::::T     ");
	printf("\n      CCCCCCCCCCCCC     OOOOOOOOOO     MMMMMMMM               MMMMMMMMEEEEEEEEEEEEEEEEEEEEEE           TTTTTTTTTTT     ");
	SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
	printf("\n========================================================================================================================");
	Sleep(50);
	system("cls");
	
	printf("\n\n\n\n");
	printf("========================================================================================================================");
	SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY|BACKGROUND_BLUE);
	printf("\nCCCCCCCCC     OOOOOOOOOO     MMMMMMMM               MMMMMMMMEEEEEEEEEEEEEEEEEEEEEE     TTTTTTTTTTTTTTTTTTTTTTT     OOOO");
	printf("\n::::::::C   OO::::::::::OO   M:::::::M             M:::::::ME::::::::::::::::::::E     T:::::::::::::::::::::T   OO::::");
	printf("\n::::::::C OO::::::::::::::OO M::::::::M           M::::::::ME::::::::::::::::::::E     T:::::::::::::::::::::T OO::::::");
	printf("\nCCCC::::CO:::::::OOO::::::::OM:::::::::M         M:::::::::MEE::::::EEEEEEEEE::::E     T:::::TT:::::::TT:::::TO:::::::O");
	printf("\n   CCCCCCO::::::O   O:::::::OM::::::::::M       M::::::::::M  E:::::E       EEEEEE     TTTTTT  T:::::T  TTTTTTO::::::O ");
	printf("\n         O:::::O     O::::::OM:::::::::::M     M:::::::::::M  E:::::E                          T:::::T        O:::::O  ");
	printf("\n         O:::::O     O::::::OM:::::::M::::M   M::::M:::::::M  E::::::EEEEEEEEEE                T:::::T        O:::::O  ");
	printf("\n         O:::::O     O::::::OM::::::M M::::M M::::M M::::::M  E:::::::::::::::E                T:::::T        O:::::O  ");
	printf("\n         O:::::O     O::::::OM::::::M  M::::M::::M  M::::::M  E:::::::::::::::E                T:::::T        O:::::O  ");
	printf("\n         O:::::O     O::::::OM::::::M   M:::::::M   M::::::M  E::::::EEEEEEEEEE                T:::::T        O:::::O  ");
	printf("\n         O:::::O     O::::::OM::::::M    M:::::M    M::::::M  E:::::E                          T:::::T        O:::::O  ");
	printf("\n   CCCCCCO::::::O   O:::::::OM::::::M     MMMMM     M::::::M  E:::::E       EEEEEE             T:::::T        O::::::O ");
	printf("\nCCCC::::CO:::::::OOO::::::::OM::::::M               M::::::MEE::::::EEEEEEEE:::::E           TT:::::::TT      O:::::::O");
	printf("\n::::::::C OO::::::::::::::OO M::::::M               M::::::ME::::::::::::::::::::E           T:::::::::T       OO::::::");
	printf("\n::::::::C   OO::::::::::OO   M::::::M               M::::::ME::::::::::::::::::::E           T:::::::::T         OO::::");
	printf("\nCCCCCCCCC     OOOOOOOOOO     MMMMMMMM               MMMMMMMMEEEEEEEEEEEEEEEEEEEEEE           TTTTTTTTTTT           OOOO");
	SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
	printf("\n========================================================================================================================");
	Sleep(50);
	system("cls");
	
	printf("\n\n\n\n");
	printf("========================================================================================================================");
	SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY|BACKGROUND_BLUE);
	printf("\n    OOOOOOOOOO     MMMMMMMM               MMMMMMMMEEEEEEEEEEEEEEEEEEEEEE     TTTTTTTTTTTTTTTTTTTTTTT     OOOOOOOOO     ");
	printf("\n  OO::::::::::OO   M:::::::M             M:::::::ME::::::::::::::::::::E     T:::::::::::::::::::::T   OO:::::::::OO   ");
	printf("\nOO::::::::::::::OO M::::::::M           M::::::::ME::::::::::::::::::::E     T:::::::::::::::::::::T OO:::::::::::::OO ");
	printf("\n:::::::OOO::::::::OM:::::::::M         M:::::::::MEE::::::EEEEEEEEE::::E     T:::::TT:::::::TT:::::TO:::::::OOO:::::::O");
	printf("\n::::::O   O:::::::OM::::::::::M       M::::::::::M  E:::::E       EEEEEE     TTTTTT  T:::::T  TTTTTTO::::::O   O::::::O");
	printf("\n:::::O     O::::::OM:::::::::::M     M:::::::::::M  E:::::E                          T:::::T        O:::::O     O:::::O");
	printf("\n:::::O     O::::::OM:::::::M::::M   M::::M:::::::M  E::::::EEEEEEEEEE                T:::::T        O:::::O     O:::::O");
	printf("\n:::::O     O::::::OM::::::M M::::M M::::M M::::::M  E:::::::::::::::E                T:::::T        O:::::O     O:::::O");
	printf("\n:::::O     O::::::OM::::::M  M::::M::::M  M::::::M  E:::::::::::::::E                T:::::T        O:::::O     O:::::O");
	printf("\n:::::O     O::::::OM::::::M   M:::::::M   M::::::M  E::::::EEEEEEEEEE                T:::::T        O:::::O     O:::::O");
	printf("\n:::::O     O::::::OM::::::M    M:::::M    M::::::M  E:::::E                          T:::::T        O:::::O     O:::::O");
	printf("\n::::::O   O:::::::OM::::::M     MMMMM     M::::::M  E:::::E       EEEEEE             T:::::T        O::::::O   O::::::O");
	printf("\n:::::::OOO::::::::OM::::::M               M::::::MEE::::::EEEEEEEE:::::E           TT:::::::TT      O:::::::OOO:::::::O");
	printf("\nOO::::::::::::::OO M::::::M               M::::::ME::::::::::::::::::::E           T:::::::::T       OO:::::::::::::OO ");
	printf("\n  OO::::::::::OO   M::::::M               M::::::ME::::::::::::::::::::E           T:::::::::T         OO:::::::::OO   ");
	printf("\n    OOOOOOOOOO     MMMMMMMM               MMMMMMMMEEEEEEEEEEEEEEEEEEEEEE           TTTTTTTTTTT           OOOOOOOOO     ");
	SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
	printf("\n========================================================================================================================");
	Sleep(50);
	system("cls");
	
	printf("\n\n\n\n");
	printf("========================================================================================================================");
	SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY|BACKGROUND_BLUE);
	printf("\nOOOO     MMMMMMMM               MMMMMMMMEEEEEEEEEEEEEEEEEEEEEE     TTTTTTTTTTTTTTTTTTTTTTT     OOOOOOOOO          PPPPP");
	printf("\n::::OO   M:::::::M             M:::::::ME::::::::::::::::::::E     T:::::::::::::::::::::T   OO:::::::::OO        P::::");
	printf("\n::::::OO M::::::::M           M::::::::ME::::::::::::::::::::E     T:::::::::::::::::::::T OO:::::::::::::OO      P::::");
	printf("\n::::::::OM:::::::::M         M:::::::::MEE::::::EEEEEEEEE::::E     T:::::TT:::::::TT:::::TO:::::::OOO:::::::O     PP:::");
	printf("\nO:::::::OM::::::::::M       M::::::::::M  E:::::E       EEEEEE     TTTTTT  T:::::T  TTTTTTO::::::O   O::::::O       P::");
	printf("\n O::::::OM:::::::::::M     M:::::::::::M  E:::::E                          T:::::T        O:::::O     O:::::O       P::");
	printf("\n O::::::OM:::::::M::::M   M::::M:::::::M  E::::::EEEEEEEEEE                T:::::T        O:::::O     O:::::O       P::");
	printf("\n O::::::OM::::::M M::::M M::::M M::::::M  E:::::::::::::::E                T:::::T        O:::::O     O:::::O       P::");
	printf("\n O::::::OM::::::M  M::::M::::M  M::::::M  E:::::::::::::::E                T:::::T        O:::::O     O:::::O       P::");
	printf("\n O::::::OM::::::M   M:::::::M   M::::::M  E::::::EEEEEEEEEE                T:::::T        O:::::O     O:::::O       P::");
	printf("\n O::::::OM::::::M    M:::::M    M::::::M  E:::::E                          T:::::T        O:::::O     O:::::O       P::");
	printf("\nO:::::::OM::::::M     MMMMM     M::::::M  E:::::E       EEEEEE             T:::::T        O::::::O   O::::::O       P::");
	printf("\n::::::::OM::::::M               M::::::MEE::::::EEEEEEEE:::::E           TT:::::::TT      O:::::::OOO:::::::O     PP:::");
	printf("\n::::::OO M::::::M               M::::::ME::::::::::::::::::::E           T:::::::::T       OO:::::::::::::OO      P::::");
	printf("\n::::OO   M::::::M               M::::::ME::::::::::::::::::::E           T:::::::::T         OO:::::::::OO        P::::");
	printf("\nOOOO     MMMMMMMM               MMMMMMMMEEEEEEEEEEEEEEEEEEEEEE           TTTTTTTTTTT           OOOOOOOOO          PPPPP");
	SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
	printf("\n========================================================================================================================");
	Sleep(50);
	system("cls");
	
	printf("\n\n\n\n");
	printf("========================================================================================================================");
	SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY|BACKGROUND_BLUE);
	printf("\nMMMMMMM               MMMMMMMMEEEEEEEEEEEEEEEEEEEEEE     TTTTTTTTTTTTTTTTTTTTTTT     OOOOOOOOO          PPPPPPPPPPPPPPP");
	printf("\n:::::::M             M:::::::ME::::::::::::::::::::E     T:::::::::::::::::::::T   OO:::::::::OO        P::::::::::::::");
	printf("\n::::::::M           M::::::::ME::::::::::::::::::::E     T:::::::::::::::::::::T OO:::::::::::::OO      P::::::PPPPPP::");
	printf("\n:::::::::M         M:::::::::MEE::::::EEEEEEEEE::::E     T:::::TT:::::::TT:::::TO:::::::OOO:::::::O     PP:::::P     P:");
	printf("\n::::::::::M       M::::::::::M  E:::::E       EEEEEE     TTTTTT  T:::::T  TTTTTTO::::::O   O::::::O       P::::P     P:");
	printf("\n:::::::::::M     M:::::::::::M  E:::::E                          T:::::T        O:::::O     O:::::O       P::::P     P:");
	printf("\n:::::::M::::M   M::::M:::::::M  E::::::EEEEEEEEEE                T:::::T        O:::::O     O:::::O       P::::PPPPPP::");
	printf("\n::::::M M::::M M::::M M::::::M  E:::::::::::::::E                T:::::T        O:::::O     O:::::O       P::::::::::::");
	printf("\n::::::M  M::::M::::M  M::::::M  E:::::::::::::::E                T:::::T        O:::::O     O:::::O       P::::PPPPPPPP");
	printf("\n::::::M   M:::::::M   M::::::M  E::::::EEEEEEEEEE                T:::::T        O:::::O     O:::::O       P::::P       ");
	printf("\n::::::M    M:::::M    M::::::M  E:::::E                          T:::::T        O:::::O     O:::::O       P::::P       ");
	printf("\n::::::M     MMMMM     M::::::M  E:::::E       EEEEEE             T:::::T        O::::::O   O::::::O       P::::P       ");
	printf("\n::::::M               M::::::MEE::::::EEEEEEEE:::::E           TT:::::::TT      O:::::::OOO:::::::O     PP::::::PP     ");
	printf("\n::::::M               M::::::ME::::::::::::::::::::E           T:::::::::T       OO:::::::::::::OO      P::::::::P     ");
	printf("\n::::::M               M::::::ME::::::::::::::::::::E           T:::::::::T         OO:::::::::OO        P::::::::P     ");
	printf("\nMMMMMMM               MMMMMMMMEEEEEEEEEEEEEEEEEEEEEE           TTTTTTTTTTT           OOOOOOOOO          PPPPPPPPPP     ");
	SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
	printf("\n========================================================================================================================");
	Sleep(50);
	system("cls");
	
	printf("\n\n\n\n");
	printf("========================================================================================================================");
	SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY|BACKGROUND_BLUE);
	printf("\n            MMMMMMMMEEEEEEEEEEEEEEEEEEEEEE     TTTTTTTTTTTTTTTTTTTTTTT     OOOOOOOOO          PPPPPPPPPPPPPPPPP   LLLLL");
	printf("\n           M:::::::ME::::::::::::::::::::E     T:::::::::::::::::::::T   OO:::::::::OO        P::::::::::::::::P  L::::");
	printf("\n          M::::::::ME::::::::::::::::::::E     T:::::::::::::::::::::T OO:::::::::::::OO      P::::::PPPPPP:::::P L::::");
	printf("\n         M:::::::::MEE::::::EEEEEEEEE::::E     T:::::TT:::::::TT:::::TO:::::::OOO:::::::O     PP:::::P     P:::::PLL:::");
	printf("\nM       M::::::::::M  E:::::E       EEEEEE     TTTTTT  T:::::T  TTTTTTO::::::O   O::::::O       P::::P     P:::::P  L::");
	printf("\n:M     M:::::::::::M  E:::::E                          T:::::T        O:::::O     O:::::O       P::::P     P:::::P  L::");
	printf("\n::M   M::::M:::::::M  E::::::EEEEEEEEEE                T:::::T        O:::::O     O:::::O       P::::PPPPPP:::::P   L::");
	printf("\n:::M M::::M M::::::M  E:::::::::::::::E                T:::::T        O:::::O     O:::::O       P:::::::::::::PP    L::");
	printf("\n::::M::::M  M::::::M  E:::::::::::::::E                T:::::T        O:::::O     O:::::O       P::::PPPPPPPPP      L::");
	printf("\nM:::::::M   M::::::M  E::::::EEEEEEEEEE                T:::::T        O:::::O     O:::::O       P::::P              L::");
	printf("\n M:::::M    M::::::M  E:::::E                          T:::::T        O:::::O     O:::::O       P::::P              L::");
	printf("\n  MMMMM     M::::::M  E:::::E       EEEEEE             T:::::T        O::::::O   O::::::O       P::::P              L::");
	printf("\n            M::::::MEE::::::EEEEEEEE:::::E           TT:::::::TT      O:::::::OOO:::::::O     PP::::::PP          LL:::");
	printf("\n            M::::::ME::::::::::::::::::::E           T:::::::::T       OO:::::::::::::OO      P::::::::P          L::::");
	printf("\n            M::::::ME::::::::::::::::::::E           T:::::::::T         OO:::::::::OO        P::::::::P          L::::");
	printf("\n            MMMMMMMMEEEEEEEEEEEEEEEEEEEEEE           TTTTTTTTTTT           OOOOOOOOO          PPPPPPPPPP          LLLLL");
	SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
	printf("\n========================================================================================================================");
	Sleep(50);
	system("cls");
	
	printf("\n\n\n\n");
	printf("========================================================================================================================");
	SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY|BACKGROUND_BLUE);
	printf("\n            MMMMMMMMEEEEEEEEEEEEEEEEEEEEEE     TTTTTTTTTTTTTTTTTTTTTTT     OOOOOOOOO          PPPPPPPPPPPPPPPPP   LLLLL");
	printf("\n           M:::::::ME::::::::::::::::::::E     T:::::::::::::::::::::T   OO:::::::::OO        P::::::::::::::::P  L::::");
	printf("\n          M::::::::ME::::::::::::::::::::E     T:::::::::::::::::::::T OO:::::::::::::OO      P::::::PPPPPP:::::P L::::");
	printf("\n         M:::::::::MEE::::::EEEEEEEEE::::E     T:::::TT:::::::TT:::::TO:::::::OOO:::::::O     PP:::::P     P:::::PLL:::");
	printf("\nM       M::::::::::M  E:::::E       EEEEEE     TTTTTT  T:::::T  TTTTTTO::::::O   O::::::O       P::::P     P:::::P  L::");
	printf("\n:M     M:::::::::::M  E:::::E                          T:::::T        O:::::O     O:::::O       P::::P     P:::::P  L::");
	printf("\n::M   M::::M:::::::M  E::::::EEEEEEEEEE                T:::::T        O:::::O     O:::::O       P::::PPPPPP:::::P   L::");
	printf("\n:::M M::::M M::::::M  E:::::::::::::::E                T:::::T        O:::::O     O:::::O       P:::::::::::::PP    L::");
	printf("\n::::M::::M  M::::::M  E:::::::::::::::E                T:::::T        O:::::O     O:::::O       P::::PPPPPPPPP      L::");
	printf("\nM:::::::M   M::::::M  E::::::EEEEEEEEEE                T:::::T        O:::::O     O:::::O       P::::P              L::");
	printf("\n M:::::M    M::::::M  E:::::E                          T:::::T        O:::::O     O:::::O       P::::P              L::");
	printf("\n  MMMMM     M::::::M  E:::::E       EEEEEE             T:::::T        O::::::O   O::::::O       P::::P              L::");
	printf("\n            M::::::MEE::::::EEEEEEEE:::::E           TT:::::::TT      O:::::::OOO:::::::O     PP::::::PP          LL:::");
	printf("\n            M::::::ME::::::::::::::::::::E           T:::::::::T       OO:::::::::::::OO      P::::::::P          L::::");
	printf("\n            M::::::ME::::::::::::::::::::E           T:::::::::T         OO:::::::::OO        P::::::::P          L::::");
	printf("\n            MMMMMMMMEEEEEEEEEEEEEEEEEEEEEE           TTTTTTTTTTT           OOOOOOOOO          PPPPPPPPPP          LLLLL");
	SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
	printf("\n========================================================================================================================");
	Sleep(50);
	system("cls");
	
	printf("\n\n\n\n");
	printf("========================================================================================================================");
	SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY|BACKGROUND_BLUE);
	printf("\n  MMMMMMMMEEEEEEEEEEEEEEEEEEEEEE     TTTTTTTTTTTTTTTTTTTTTTT     OOOOOOOOO          PPPPPPPPPPPPPPPPP   LLLLLLLLLLL    ");
	printf("\n M:::::::ME::::::::::::::::::::E     T:::::::::::::::::::::T   OO:::::::::OO        P::::::::::::::::P  L:::::::::L    ");
	printf("\nM::::::::ME::::::::::::::::::::E     T:::::::::::::::::::::T OO:::::::::::::OO      P::::::PPPPPP:::::P L:::::::::L    ");
	printf("\n:::::::::MEE::::::EEEEEEEEE::::E     T:::::TT:::::::TT:::::TO:::::::OOO:::::::O     PP:::::P     P:::::PLL:::::::LL    ");
	printf("\n:::::::::M  E:::::E       EEEEEE     TTTTTT  T:::::T  TTTTTTO::::::O   O::::::O       P::::P     P:::::P  L:::::L      ");
	printf("\n:::::::::M  E:::::E                          T:::::T        O:::::O     O:::::O       P::::P     P:::::P  L:::::L      ");
	printf("\n:M:::::::M  E::::::EEEEEEEEEE                T:::::T        O:::::O     O:::::O       P::::PPPPPP:::::P   L:::::L      ");
	printf("\nM M::::::M  E:::::::::::::::E                T:::::T        O:::::O     O:::::O       P:::::::::::::PP    L:::::L      ");
	printf("\n  M::::::M  E:::::::::::::::E                T:::::T        O:::::O     O:::::O       P::::PPPPPPPPP      L:::::L      ");
	printf("\n  M::::::M  E::::::EEEEEEEEEE                T:::::T        O:::::O     O:::::O       P::::P              L:::::L      ");
	printf("\n  M::::::M  E:::::E                          T:::::T        O:::::O     O:::::O       P::::P              L:::::L      ");
	printf("\n  M::::::M  E:::::E       EEEEEE             T:::::T        O::::::O   O::::::O       P::::P              L:::::L      ");
	printf("\n  M::::::MEE::::::EEEEEEEE:::::E           TT:::::::TT      O:::::::OOO:::::::O     PP::::::PP          LL:::::::LLLLLL");
	printf("\n  M::::::ME::::::::::::::::::::E           T:::::::::T       OO:::::::::::::OO      P::::::::P          L::::::::::::::");
	printf("\n  M::::::ME::::::::::::::::::::E           T:::::::::T         OO:::::::::OO        P::::::::P          L::::::::::::::");
	printf("\n  MMMMMMMMEEEEEEEEEEEEEEEEEEEEEE           TTTTTTTTTTT           OOOOOOOOO          PPPPPPPPPP          LLLLLLLLLLLLLLL");
	SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
	printf("\n========================================================================================================================");
	Sleep(50);
	system("cls");
	
	printf("\n\n\n\n");
	printf("========================================================================================================================");
	SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY|BACKGROUND_BLUE);
	printf("\nEEEEEEEEEEEEEEEEEEEEEE     TTTTTTTTTTTTTTTTTTTTTTT     OOOOOOOOO          PPPPPPPPPPPPPPPPP   LLLLLLLLLLL              ");
	printf("\nE::::::::::::::::::::E     T:::::::::::::::::::::T   OO:::::::::OO        P::::::::::::::::P  L:::::::::L              ");
	printf("\nE::::::::::::::::::::E     T:::::::::::::::::::::T OO:::::::::::::OO      P::::::PPPPPP:::::P L:::::::::L              ");
	printf("\nEE::::::EEEEEEEEE::::E     T:::::TT:::::::TT:::::TO:::::::OOO:::::::O     PP:::::P     P:::::PLL:::::::LL              ");
	printf("\n  E:::::E       EEEEEE     TTTTTT  T:::::T  TTTTTTO::::::O   O::::::O       P::::P     P:::::P  L:::::L                ");
	printf("\n  E:::::E                          T:::::T        O:::::O     O:::::O       P::::P     P:::::P  L:::::L                ");
	printf("\n  E::::::EEEEEEEEEE                T:::::T        O:::::O     O:::::O       P::::PPPPPP:::::P   L:::::L                ");
	printf("\n  E:::::::::::::::E                T:::::T        O:::::O     O:::::O       P:::::::::::::PP    L:::::L                ");
	printf("\n  E:::::::::::::::E                T:::::T        O:::::O     O:::::O       P::::PPPPPPPPP      L:::::L                ");
	printf("\n  E::::::EEEEEEEEEE                T:::::T        O:::::O     O:::::O       P::::P              L:::::L                ");
	printf("\n  E:::::E                          T:::::T        O:::::O     O:::::O       P::::P              L:::::L                ");
	printf("\n  E:::::E       EEEEEE             T:::::T        O::::::O   O::::::O       P::::P              L:::::L         LLLLLL ");
	printf("\nEE::::::EEEEEEEE:::::E           TT:::::::TT      O:::::::OOO:::::::O     PP::::::PP          LL:::::::LLLLLLLLL:::::L ");
	printf("\nE::::::::::::::::::::E           T:::::::::T       OO:::::::::::::OO      P::::::::P          L::::::::::::::::::::::L ");
	printf("\nE::::::::::::::::::::E           T:::::::::T         OO:::::::::OO        P::::::::P          L::::::::::::::::::::::L ");
	printf("\nEEEEEEEEEEEEEEEEEEEEEE           TTTTTTTTTTT           OOOOOOOOO          PPPPPPPPPP          LLLLLLLLLLLLLLLLLLLLLLLLA");
	SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
	printf("\n========================================================================================================================");
	Sleep(50);
	system("cls");
	
	printf("\n\n\n\n");
	printf("========================================================================================================================");
	SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY|BACKGROUND_BLUE);
	printf("\nEEEEEEEEEEEE     TTTTTTTTTTTTTTTTTTTTTTT     OOOOOOOOO          PPPPPPPPPPPPPPPPP   LLLLLLLLLLL                        ");
	printf("\n:::::::::::E     T:::::::::::::::::::::T   OO:::::::::OO        P::::::::::::::::P  L:::::::::L                        ");
	printf("\n:::::::::::E     T:::::::::::::::::::::T OO:::::::::::::OO      P::::::PPPPPP:::::P L:::::::::L                        ");
	printf("\nEEEEEEE::::E     T:::::TT:::::::TT:::::TO:::::::OOO:::::::O     PP:::::P     P:::::PLL:::::::LL                        ");
	printf("\n      EEEEEE     TTTTTT  T:::::T  TTTTTTO::::::O   O::::::O       P::::P     P:::::P  L:::::L                          ");
	printf("\n                         T:::::T        O:::::O     O:::::O       P::::P     P:::::P  L:::::L                         A");
	printf("\nEEEEEEEEE                T:::::T        O:::::O     O:::::O       P::::PPPPPP:::::P   L:::::L                        A:");
	printf("\n::::::::E                T:::::T        O:::::O     O:::::O       P:::::::::::::PP    L:::::L                       A::");
	printf("\n::::::::E                T:::::T        O:::::O     O:::::O       P::::PPPPPPPPP      L:::::L                      A:::");
	printf("\nEEEEEEEEE                T:::::T        O:::::O     O:::::O       P::::P              L:::::L                     A::::");
	printf("\n                         T:::::T        O:::::O     O:::::O       P::::P              L:::::L                    A:::::");
	printf("\n      EEEEEE             T:::::T        O::::::O   O::::::O       P::::P              L:::::L         LLLLLL    A:::::A");
	printf("\nEEEEEE:::::E           TT:::::::TT      O:::::::OOO:::::::O     PP::::::PP          LL:::::::LLLLLLLLL:::::L   A:::::A ");
	printf("\n:::::::::::E           T:::::::::T       OO:::::::::::::OO      P::::::::P          L::::::::::::::::::::::L  A:::::A  ");
	printf("\n:::::::::::E           T:::::::::T         OO:::::::::OO        P::::::::P          L::::::::::::::::::::::L A:::::A   ");
	printf("\nEEEEEEEEEEEE           TTTTTTTTTTT           OOOOOOOOO          PPPPPPPPPP          LLLLLLLLLLLLLLLLLLLLLLLLAAAAAAA    ");
	SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
	printf("\n========================================================================================================================");
	Sleep(50);
	system("cls");
	
	printf("\n\n\n\n");
	printf("========================================================================================================================");
	SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY|BACKGROUND_BLUE);
	printf("\nEE     TTTTTTTTTTTTTTTTTTTTTTT     OOOOOOOOO          PPPPPPPPPPPPPPPPP   LLLLLLLLLLL                            AAA   ");
	printf("\n:E     T:::::::::::::::::::::T   OO:::::::::OO        P::::::::::::::::P  L:::::::::L                           A:::A  ");
	printf("\n:E     T:::::::::::::::::::::T OO:::::::::::::OO      P::::::PPPPPP:::::P L:::::::::L                          A:::::A ");
	printf("\n:E     T:::::TT:::::::TT:::::TO:::::::OOO:::::::O     PP:::::P     P:::::PLL:::::::LL                         A:::::::A");
	printf("\nEE     TTTTTT  T:::::T  TTTTTTO::::::O   O::::::O       P::::P     P:::::P  L:::::L                          A:::::::::");
	printf("\n               T:::::T        O:::::O     O:::::O       P::::P     P:::::P  L:::::L                         A:::::A::::");
	printf("\n               T:::::T        O:::::O     O:::::O       P::::PPPPPP:::::P   L:::::L                        A:::::A A:::");
	printf("\n               T:::::T        O:::::O     O:::::O       P:::::::::::::PP    L:::::L                       A:::::A   A::");
	printf("\n               T:::::T        O:::::O     O:::::O       P::::PPPPPPPPP      L:::::L                      A:::::A     A:");
	printf("\n               T:::::T        O:::::O     O:::::O       P::::P              L:::::L                     A:::::AAAAAAAAA");
	printf("\n               T:::::T        O:::::O     O:::::O       P::::P              L:::::L                    A:::::::::::::::");
	printf("\nEE             T:::::T        O::::::O   O::::::O       P::::P              L:::::L         LLLLLL    A:::::AAAAAAAAAAA");
	printf("\n:E           TT:::::::TT      O:::::::OOO:::::::O     PP::::::PP          LL:::::::LLLLLLLLL:::::L   A:::::A           ");
	printf("\n:E           T:::::::::T       OO:::::::::::::OO      P::::::::P          L::::::::::::::::::::::L  A:::::A            ");
	printf("\n:E           T:::::::::T         OO:::::::::OO        P::::::::P          L::::::::::::::::::::::L A:::::A             ");
	printf("\nEE           TTTTTTTTTTT           OOOOOOOOO          PPPPPPPPPP          LLLLLLLLLLLLLLLLLLLLLLLLAAAAAAA              ");
	SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
	printf("\n========================================================================================================================");
	Sleep(50);
	system("cls");
	
	printf("\n\n\n\n");
	printf("========================================================================================================================");
	SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY|BACKGROUND_BLUE);
	printf("\nTTTTTTTTTTTTTTTTTTTT     OOOOOOOOO          PPPPPPPPPPPPPPPPP   LLLLLLLLLLL                            AAA             ");
	printf("\n:::::::::::::::::::T   OO:::::::::OO        P::::::::::::::::P  L:::::::::L                           A:::A            ");
	printf("\n:::::::::::::::::::T OO:::::::::::::OO      P::::::PPPPPP:::::P L:::::::::L                          A:::::A           ");
	printf("\n:::TT:::::::TT:::::TO:::::::OOO:::::::O     PP:::::P     P:::::PLL:::::::LL                         A:::::::A          ");
	printf("\nTTT  T:::::T  TTTTTTO::::::O   O::::::O       P::::P     P:::::P  L:::::L                          A:::::::::A         ");
	printf("\n     T:::::T        O:::::O     O:::::O       P::::P     P:::::P  L:::::L                         A:::::A:::::A        ");
	printf("\n     T:::::T        O:::::O     O:::::O       P::::PPPPPP:::::P   L:::::L                        A:::::A A:::::A       ");
	printf("\n     T:::::T        O:::::O     O:::::O       P:::::::::::::PP    L:::::L                       A:::::A   A:::::A      ");
	printf("\n     T:::::T        O:::::O     O:::::O       P::::PPPPPPPPP      L:::::L                      A:::::A     A:::::A     ");
	printf("\n     T:::::T        O:::::O     O:::::O       P::::P              L:::::L                     A:::::AAAAAAAAA:::::A    ");
	printf("\n     T:::::T        O:::::O     O:::::O       P::::P              L:::::L                    A:::::::::::::::::::::A   ");
	printf("\n     T:::::T        O::::::O   O::::::O       P::::P              L:::::L         LLLLLL    A:::::AAAAAAAAAAAAA:::::A  ");
	printf("\n   TT:::::::TT      O:::::::OOO:::::::O     PP::::::PP          LL:::::::LLLLLLLLL:::::L   A:::::A             A:::::A ");
	printf("\n   T:::::::::T       OO:::::::::::::OO      P::::::::P          L::::::::::::::::::::::L  A:::::A               A:::::A");
	printf("\n   T:::::::::T         OO:::::::::OO        P::::::::P          L::::::::::::::::::::::L A:::::A                 A:::::");
	printf("\n   TTTTTTTTTTT           OOOOOOOOO          PPPPPPPPPP          LLLLLLLLLLLLLLLLLLLLLLLLAAAAAAA                   AAAAA");
	SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
	printf("\n========================================================================================================================");
	Sleep(50);
	system("cls");
		
	printf("\n\n\n\n");
	printf("========================================================================================================================");
	SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY|BACKGROUND_BLUE);
	printf("\nTTTTTTTTTT     OOOOOOOOO          PPPPPPPPPPPPPPPPP   LLLLLLLLLLL                            AAA               NNNNNNNN");
	printf("\n:::::::::T   OO:::::::::OO        P::::::::::::::::P  L:::::::::L                           A:::A              N:::::::");
	printf("\n:::::::::T OO:::::::::::::OO      P::::::PPPPPP:::::P L:::::::::L                          A:::::A             N:::::::");
	printf("\n::TT:::::TO:::::::OOO:::::::O     PP:::::P     P:::::PLL:::::::LL                         A:::::::A            N:::::::");
	printf("\n:T  TTTTTTO::::::O   O::::::O       P::::P     P:::::P  L:::::L                          A:::::::::A           N:::::::");
	printf("\n:T        O:::::O     O:::::O       P::::P     P:::::P  L:::::L                         A:::::A:::::A          N:::::::");
	printf("\n:T        O:::::O     O:::::O       P::::PPPPPP:::::P   L:::::L                        A:::::A A:::::A         N:::::::");
	printf("\n:T        O:::::O     O:::::O       P:::::::::::::PP    L:::::L                       A:::::A   A:::::A        N::::::N");
	printf("\n:T        O:::::O     O:::::O       P::::PPPPPPPPP      L:::::L                      A:::::A     A:::::A       N::::::N");
	printf("\n:T        O:::::O     O:::::O       P::::P              L:::::L                     A:::::AAAAAAAAA:::::A      N::::::N");
	printf("\n:T        O:::::O     O:::::O       P::::P              L:::::L                    A:::::::::::::::::::::A     N::::::N");
	printf("\n:T        O::::::O   O::::::O       P::::P              L:::::L         LLLLLL    A:::::AAAAAAAAAAAAA:::::A    N::::::N");
	printf("\n::TT      O:::::::OOO:::::::O     PP::::::PP          LL:::::::LLLLLLLLL:::::L   A:::::A             A:::::A   N::::::N");
	printf("\n:::T       OO:::::::::::::OO      P::::::::P          L::::::::::::::::::::::L  A:::::A               A:::::A  N::::::N");
	printf("\n:::T         OO:::::::::OO        P::::::::P          L::::::::::::::::::::::L A:::::A                 A:::::A N::::::N");
	printf("\nTTTT           OOOOOOOOO          PPPPPPPPPP          LLLLLLLLLLLLLLLLLLLLLLLLAAAAAAA                   AAAAAAANNNNNNNN");
	SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
	printf("\n========================================================================================================================");
	Sleep(50);
	system("cls");
	
	printf("\n\n\n\n");
	printf("========================================================================================================================");
	SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY|BACKGROUND_BLUE);
	printf("\n     OOOOOOOOO          PPPPPPPPPPPPPPPPP   LLLLLLLLLLL                            AAA               NNNNNNNN        NN");
	printf("\n   OO:::::::::OO        P::::::::::::::::P  L:::::::::L                           A:::A              N:::::::N       N:");
	printf("\n OO:::::::::::::OO      P::::::PPPPPP:::::P L:::::::::L                          A:::::A             N::::::::N      N:");
	printf("\nO:::::::OOO:::::::O     PP:::::P     P:::::PLL:::::::LL                         A:::::::A            N:::::::::N     N:");
	printf("\nO::::::O   O::::::O       P::::P     P:::::P  L:::::L                          A:::::::::A           N::::::::::N    N:");
	printf("\nO:::::O     O:::::O       P::::P     P:::::P  L:::::L                         A:::::A:::::A          N:::::::::::N   N:");
	printf("\nO:::::O     O:::::O       P::::PPPPPP:::::P   L:::::L                        A:::::A A:::::A         N:::::::N::::N  N:");
	printf("\nO:::::O     O:::::O       P:::::::::::::PP    L:::::L                       A:::::A   A:::::A        N::::::N N::::N N:");
	printf("\nO:::::O     O:::::O       P::::PPPPPPPPP      L:::::L                      A:::::A     A:::::A       N::::::N  N::::N::");
	printf("\nO:::::O     O:::::O       P::::P              L:::::L                     A:::::AAAAAAAAA:::::A      N::::::N   N::::::");
	printf("\nO:::::O     O:::::O       P::::P              L:::::L                    A:::::::::::::::::::::A     N::::::N    N:::::");
	printf("\nO::::::O   O::::::O       P::::P              L:::::L         LLLLLL    A:::::AAAAAAAAAAAAA:::::A    N::::::N     N::::");
	printf("\nO:::::::OOO:::::::O     PP::::::PP          LL:::::::LLLLLLLLL:::::L   A:::::A             A:::::A   N::::::N      N:::");
	printf("\n OO:::::::::::::OO      P::::::::P          L::::::::::::::::::::::L  A:::::A               A:::::A  N::::::N       N::");
	printf("\n   OO:::::::::OO        P::::::::P          L::::::::::::::::::::::L A:::::A                 A:::::A N::::::N        N:");
	printf("\n     OOOOOOOOO          PPPPPPPPPP          LLLLLLLLLLLLLLLLLLLLLLLLAAAAAAA                   AAAAAAANNNNNNNN         N");
	SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
	printf("\n========================================================================================================================");
	Sleep(50);
	system("cls");
	
	printf("\n\n\n\n");
	printf("========================================================================================================================");
	SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY|BACKGROUND_BLUE);
	printf("\nOOOO          PPPPPPPPPPPPPPPPP   LLLLLLLLLLL                            AAA               NNNNNNNN        NNNNNNNNEEEE");
	printf("\n::::OO        P::::::::::::::::P  L:::::::::L                           A:::A              N:::::::N       N::::::NE:::");
	printf("\n::::::OO      P::::::PPPPPP:::::P L:::::::::L                          A:::::A             N::::::::N      N::::::NE:::");
	printf("\nO:::::::O     PP:::::P     P:::::PLL:::::::LL                         A:::::::A            N:::::::::N     N::::::NEE::");
	printf("\n O::::::O       P::::P     P:::::P  L:::::L                          A:::::::::A           N::::::::::N    N::::::N  E:");
	printf("\n  O:::::O       P::::P     P:::::P  L:::::L                         A:::::A:::::A          N:::::::::::N   N::::::N  E:");
	printf("\n  O:::::O       P::::PPPPPP:::::P   L:::::L                        A:::::A A:::::A         N:::::::N::::N  N::::::N  E:");
	printf("\n  O:::::O       P:::::::::::::PP    L:::::L                       A:::::A   A:::::A        N::::::N N::::N N::::::N  E:");
	printf("\n  O:::::O       P::::PPPPPPPPP      L:::::L                      A:::::A     A:::::A       N::::::N  N::::N:::::::N  E:");
	printf("\n  O:::::O       P::::P              L:::::L                     A:::::AAAAAAAAA:::::A      N::::::N   N:::::::::::N  E:");
	printf("\n  O:::::O       P::::P              L:::::L                    A:::::::::::::::::::::A     N::::::N    N::::::::::N  E:");
	printf("\n O::::::O       P::::P              L:::::L         LLLLLL    A:::::AAAAAAAAAAAAA:::::A    N::::::N     N:::::::::N  E:");
	printf("\nO:::::::O     PP::::::PP          LL:::::::LLLLLLLLL:::::L   A:::::A             A:::::A   N::::::N      N::::::::NEE::");
	printf("\n::::::OO      P::::::::P          L::::::::::::::::::::::L  A:::::A               A:::::A  N::::::N       N:::::::NE:::");
	printf("\n::::OO        P::::::::P          L::::::::::::::::::::::L A:::::A                 A:::::A N::::::N        N::::::NE:::");
	printf("\nOOOO          PPPPPPPPPP          LLLLLLLLLLLLLLLLLLLLLLLLAAAAAAA                   AAAAAAANNNNNNNN         NNNNNNNEEEE");
	SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
	printf("\n========================================================================================================================");
	Sleep(50);
	system("cls");	
	
	printf("\n\n\n\n");
	printf("========================================================================================================================");
	SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY|BACKGROUND_BLUE);
	printf("\n    PPPPPPPPPPPPPPPPP   LLLLLLLLLLL                            AAA               NNNNNNNN        NNNNNNNNEEEEEEEEEEEEEE");
	printf("\n    P::::::::::::::::P  L:::::::::L                           A:::A              N:::::::N       N::::::NE:::::::::::::");
	printf("\n    P::::::PPPPPP:::::P L:::::::::L                          A:::::A             N::::::::N      N::::::NE:::::::::::::");
	printf("\n    PP:::::P     P:::::PLL:::::::LL                         A:::::::A            N:::::::::N     N::::::NEE::::::EEEEEE");
	printf("\n      P::::P     P:::::P  L:::::L                          A:::::::::A           N::::::::::N    N::::::N  E:::::E     ");
	printf("\n      P::::P     P:::::P  L:::::L                         A:::::A:::::A          N:::::::::::N   N::::::N  E:::::E     ");
	printf("\n      P::::PPPPPP:::::P   L:::::L                        A:::::A A:::::A         N:::::::N::::N  N::::::N  E::::::EEEEE");
	printf("\n      P:::::::::::::PP    L:::::L                       A:::::A   A:::::A        N::::::N N::::N N::::::N  E:::::::::::");
	printf("\n      P::::PPPPPPPPP      L:::::L                      A:::::A     A:::::A       N::::::N  N::::N:::::::N  E:::::::::::");
	printf("\n      P::::P              L:::::L                     A:::::AAAAAAAAA:::::A      N::::::N   N:::::::::::N  E::::::EEEEE");
	printf("\n      P::::P              L:::::L                    A:::::::::::::::::::::A     N::::::N    N::::::::::N  E:::::E     ");
	printf("\n      P::::P              L:::::L         LLLLLL    A:::::AAAAAAAAAAAAA:::::A    N::::::N     N:::::::::N  E:::::E     ");
	printf("\n    PP::::::PP          LL:::::::LLLLLLLLL:::::L   A:::::A             A:::::A   N::::::N      N::::::::NEE::::::EEEEEE");
	printf("\n    P::::::::P          L::::::::::::::::::::::L  A:::::A               A:::::A  N::::::N       N:::::::NE:::::::::::::");
	printf("\n    P::::::::P          L::::::::::::::::::::::L A:::::A                 A:::::A N::::::N        N::::::NE:::::::::::::");
	printf("\n    PPPPPPPPPP          LLLLLLLLLLLLLLLLLLLLLLLLAAAAAAA                   AAAAAAANNNNNNNN         NNNNNNNEEEEEEEEEEEEEE");
	SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
	printf("\n========================================================================================================================");
	Sleep(50);
	system("cls");	
	
	printf("\n\n\n\n");
	printf("========================================================================================================================");
	SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY|BACKGROUND_BLUE);
	printf("\nPPPPPPPPPPP   LLLLLLLLLLL                            AAA               NNNNNNNN        NNNNNNNNEEEEEEEEEEEEEEEEEEEEEETT");
	printf("\n:::::::::::P  L:::::::::L                           A:::A              N:::::::N       N::::::NE::::::::::::::::::::ET:");
	printf("\n:PPPPPP:::::P L:::::::::L                          A:::::A             N::::::::N      N::::::NE::::::::::::::::::::ET:");
	printf("\n:P     P:::::PLL:::::::LL                         A:::::::A            N:::::::::N     N::::::NEE::::::EEEEEEEEE::::ET:");
	printf("\n:P     P:::::P  L:::::L                          A:::::::::A           N::::::::::N    N::::::N  E:::::E       EEEEEETT");
	printf("\n:P     P:::::P  L:::::L                         A:::::A:::::A          N:::::::::::N   N::::::N  E:::::E               ");
	printf("\n:PPPPPP:::::P   L:::::L                        A:::::A A:::::A         N:::::::N::::N  N::::::N  E::::::EEEEEEEEEE     ");
	printf("\n::::::::::PP    L:::::L                       A:::::A   A:::::A        N::::::N N::::N N::::::N  E:::::::::::::::E     ");
	printf("\n:PPPPPPPPP      L:::::L                      A:::::A     A:::::A       N::::::N  N::::N:::::::N  E:::::::::::::::E     ");
	printf("\n:P              L:::::L                     A:::::AAAAAAAAA:::::A      N::::::N   N:::::::::::N  E::::::EEEEEEEEEE     ");
	printf("\n:P              L:::::L                    A:::::::::::::::::::::A     N::::::N    N::::::::::N  E:::::E               ");
	printf("\n:P              L:::::L         LLLLLL    A:::::AAAAAAAAAAAAA:::::A    N::::::N     N:::::::::N  E:::::E       EEEEEE  ");
	printf("\n::PP          LL:::::::LLLLLLLLL:::::L   A:::::A             A:::::A   N::::::N      N::::::::NEE::::::EEEEEEEE:::::E  ");
	printf("\n:::P          L::::::::::::::::::::::L  A:::::A               A:::::A  N::::::N       N:::::::NE::::::::::::::::::::E  ");
	printf("\n:::P          L::::::::::::::::::::::L A:::::A                 A:::::A N::::::N        N::::::NE::::::::::::::::::::E  ");
	printf("\nPPPP          LLLLLLLLLLLLLLLLLLLLLLLLAAAAAAA                   AAAAAAANNNNNNNN         NNNNNNNEEEEEEEEEEEEEEEEEEEEEE  ");
	SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
	printf("\n========================================================================================================================");
	Sleep(50);
	system("cls");
	
	printf("\n\n\n\n");
	printf("========================================================================================================================");
	SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY|BACKGROUND_BLUE);
	printf("\nP   LLLLLLLLLLL                            AAA               NNNNNNNN        NNNNNNNNEEEEEEEEEEEEEEEEEEEEEETTTTTTTTTTTT");
	printf("\n:P  L:::::::::L                           A:::A              N:::::::N       N::::::NE::::::::::::::::::::ET:::::::::::");
	printf("\n::P L:::::::::L                          A:::::A             N::::::::N      N::::::NE::::::::::::::::::::ET:::::::::::");
	printf("\n:::PLL:::::::LL                         A:::::::A            N:::::::::N     N::::::NEE::::::EEEEEEEEE::::ET:::::TT::::");
	printf("\n:::P  L:::::L                          A:::::::::A           N::::::::::N    N::::::N  E:::::E       EEEEEETTTTTT  T:::");
	printf("\n:::P  L:::::L                         A:::::A:::::A          N:::::::::::N   N::::::N  E:::::E                     T:::");
	printf("\n::P   L:::::L                        A:::::A A:::::A         N:::::::N::::N  N::::::N  E::::::EEEEEEEEEE           T:::");
	printf("\nPP    L:::::L                       A:::::A   A:::::A        N::::::N N::::N N::::::N  E:::::::::::::::E           T:::");
	printf("\n      L:::::L                      A:::::A     A:::::A       N::::::N  N::::N:::::::N  E:::::::::::::::E           T:::");
	printf("\n      L:::::L                     A:::::AAAAAAAAA:::::A      N::::::N   N:::::::::::N  E::::::EEEEEEEEEE           T:::");
	printf("\n      L:::::L                    A:::::::::::::::::::::A     N::::::N    N::::::::::N  E:::::E                     T:::");
	printf("\n      L:::::L         LLLLLL    A:::::AAAAAAAAAAAAA:::::A    N::::::N     N:::::::::N  E:::::E       EEEEEE        T:::");
	printf("\n    LL:::::::LLLLLLLLL:::::L   A:::::A             A:::::A   N::::::N      N::::::::NEE::::::EEEEEEEE:::::E      TT::::");
	printf("\n    L::::::::::::::::::::::L  A:::::A               A:::::A  N::::::N       N:::::::NE::::::::::::::::::::E      T:::::");
	printf("\n    L::::::::::::::::::::::L A:::::A                 A:::::A N::::::N        N::::::NE::::::::::::::::::::E      T:::::");
	printf("\n    LLLLLLLLLLLLLLLLLLLLLLLLAAAAAAA                   AAAAAAANNNNNNNN         NNNNNNNEEEEEEEEEEEEEEEEEEEEEE      TTTTTT");
	SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
	printf("\n========================================================================================================================");
	Sleep(50);
	system("cls");	
	
	printf("\n\n\n\n");
	printf("========================================================================================================================");
	SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY|BACKGROUND_BLUE);
	printf("\nLLLLL                            AAA               NNNNNNNN        NNNNNNNNEEEEEEEEEEEEEEEEEEEEEETTTTTTTTTTTTTTTTTTTTTT");
	printf("\n::::L                           A:::A              N:::::::N       N::::::NE::::::::::::::::::::ET:::::::::::::::::::::");
	printf("\n::::L                          A:::::A             N::::::::N      N::::::NE::::::::::::::::::::ET:::::::::::::::::::::");
	printf("\n:::LL                         A:::::::A            N:::::::::N     N::::::NEE::::::EEEEEEEEE::::ET:::::TT:::::::TT:::::");
	printf("\n::L                          A:::::::::A           N::::::::::N    N::::::N  E:::::E       EEEEEETTTTTT  T:::::T  TTTTT");
	printf("\n::L                         A:::::A:::::A          N:::::::::::N   N::::::N  E:::::E                     T:::::T       ");
	printf("\n::L                        A:::::A A:::::A         N:::::::N::::N  N::::::N  E::::::EEEEEEEEEE           T:::::T       ");
	printf("\n::L                       A:::::A   A:::::A        N::::::N N::::N N::::::N  E:::::::::::::::E           T:::::T       ");
	printf("\n::L                      A:::::A     A:::::A       N::::::N  N::::N:::::::N  E:::::::::::::::E           T:::::T       ");
	printf("\n::L                     A:::::AAAAAAAAA:::::A      N::::::N   N:::::::::::N  E::::::EEEEEEEEEE           T:::::T       ");
	printf("\n::L                    A:::::::::::::::::::::A     N::::::N    N::::::::::N  E:::::E                     T:::::T       ");
	printf("\n::L         LLLLLL    A:::::AAAAAAAAAAAAA:::::A    N::::::N     N:::::::::N  E:::::E       EEEEEE        T:::::T       ");
	printf("\n:::LLLLLLLLL:::::L   A:::::A             A:::::A   N::::::N      N::::::::NEE::::::EEEEEEEE:::::E      TT:::::::TT     ");
	printf("\n:::::::::::::::::L  A:::::A               A:::::A  N::::::N       N:::::::NE::::::::::::::::::::E      T:::::::::T     ");
	printf("\n:::::::::::::::::L A:::::A                 A:::::A N::::::N        N::::::NE::::::::::::::::::::E      T:::::::::T     ");
	printf("\nLLLLLLLLLLLLLLLLLLAAAAAAA                   AAAAAAANNNNNNNN         NNNNNNNEEEEEEEEEEEEEEEEEEEEEE      TTTTTTTTTTT     ");
	SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
	printf("\n========================================================================================================================");
	Sleep(50);
	system("cls");	
	
	printf("\n\n\n\n");
	printf("========================================================================================================================");
	SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY|BACKGROUND_BLUE);
	printf("\n                       AAA               NNNNNNNN        NNNNNNNNEEEEEEEEEEEEEEEEEEEEEETTTTTTTTTTTTTTTTTTTTTTT         ");
	printf("\n                      A:::A              N:::::::N       N::::::NE::::::::::::::::::::ET:::::::::::::::::::::T         ");
	printf("\n                     A:::::A             N::::::::N      N::::::NE::::::::::::::::::::ET:::::::::::::::::::::T        C");
	printf("\n                    A:::::::A            N:::::::::N     N::::::NEE::::::EEEEEEEEE::::ET:::::TT:::::::TT:::::T       C:");
	printf("\n                   A:::::::::A           N::::::::::N    N::::::N  E:::::E       EEEEEETTTTTT  T:::::T  TTTTTT      C::");
	printf("\n                  A:::::A:::::A          N:::::::::::N   N::::::N  E:::::E                     T:::::T             C:::");
	printf("\n                 A:::::A A:::::A         N:::::::N::::N  N::::::N  E::::::EEEEEEEEEE           T:::::T             C:::");
	printf("\n                A:::::A   A:::::A        N::::::N N::::N N::::::N  E:::::::::::::::E           T:::::T             C:::");
	printf("\n               A:::::A     A:::::A       N::::::N  N::::N:::::::N  E:::::::::::::::E           T:::::T             C:::");
	printf("\n              A:::::AAAAAAAAA:::::A      N::::::N   N:::::::::::N  E::::::EEEEEEEEEE           T:::::T             C:::");
	printf("\n             A:::::::::::::::::::::A     N::::::N    N::::::::::N  E:::::E                     T:::::T             C:::");
	printf("\n  LLLLLL    A:::::AAAAAAAAAAAAA:::::A    N::::::N     N:::::::::N  E:::::E       EEEEEE        T:::::T              C::");
	printf("\nLL:::::L   A:::::A             A:::::A   N::::::N      N::::::::NEE::::::EEEEEEEE:::::E      TT:::::::TT             C:");
	printf("\n:::::::L  A:::::A               A:::::A  N::::::N       N:::::::NE::::::::::::::::::::E      T:::::::::T              C");
	printf("\n:::::::L A:::::A                 A:::::A N::::::N        N::::::NE::::::::::::::::::::E      T:::::::::T               ");
	printf("\nLLLLLLLLAAAAAAA                   AAAAAAANNNNNNNN         NNNNNNNEEEEEEEEEEEEEEEEEEEEEE      TTTTTTTTTTT               ");
	SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
	printf("\n========================================================================================================================");
	Sleep(50);
	system("cls");
	
	printf("\n\n\n\n");
	printf("========================================================================================================================");
	SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY|BACKGROUND_BLUE);
	printf("\n             AAA               NNNNNNNN        NNNNNNNNEEEEEEEEEEEEEEEEEEEEEETTTTTTTTTTTTTTTTTTTTTTT             CCCCCC");
	printf("\n            A:::A              N:::::::N       N::::::NE::::::::::::::::::::ET:::::::::::::::::::::T          CCC::::::");
	printf("\n           A:::::A             N::::::::N      N::::::NE::::::::::::::::::::ET:::::::::::::::::::::T        CC:::::::::");
	printf("\n          A:::::::A            N:::::::::N     N::::::NEE::::::EEEEEEEEE::::ET:::::TT:::::::TT:::::T       C:::::CCCCCC");
	printf("\n         A:::::::::A           N::::::::::N    N::::::N  E:::::E       EEEEEETTTTTT  T:::::T  TTTTTT      C:::::C      ");
	printf("\n        A:::::A:::::A          N:::::::::::N   N::::::N  E:::::E                     T:::::T             C:::::C       ");
	printf("\n       A:::::A A:::::A         N:::::::N::::N  N::::::N  E::::::EEEEEEEEEE           T:::::T             C:::::C       ");
	printf("\n      A:::::A   A:::::A        N::::::N N::::N N::::::N  E:::::::::::::::E           T:::::T             C:::::C       ");
	printf("\n     A:::::A     A:::::A       N::::::N  N::::N:::::::N  E:::::::::::::::E           T:::::T             C:::::C       ");
	printf("\n    A:::::AAAAAAAAA:::::A      N::::::N   N:::::::::::N  E::::::EEEEEEEEEE           T:::::T             C:::::C       ");
	printf("\n   A:::::::::::::::::::::A     N::::::N    N::::::::::N  E:::::E                     T:::::T             C:::::C       ");
	printf("\n  A:::::AAAAAAAAAAAAA:::::A    N::::::N     N:::::::::N  E:::::E       EEEEEE        T:::::T              C:::::C      ");
	printf("\n A:::::A             A:::::A   N::::::N      N::::::::NEE::::::EEEEEEEE:::::E      TT:::::::TT             C:::::CCCCCC");
	printf("\nA:::::A               A:::::A  N::::::N       N:::::::NE::::::::::::::::::::E      T:::::::::T              CC:::::::::");
	printf("\n:::::A                 A:::::A N::::::N        N::::::NE::::::::::::::::::::E      T:::::::::T                CCC::::::");
	printf("\nAAAAA                   AAAAAAANNNNNNNN         NNNNNNNEEEEEEEEEEEEEEEEEEEEEE      TTTTTTTTTTT                   CCCCCC");
	SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
	printf("\n========================================================================================================================");
	Sleep(50);
	system("cls");
	
	printf("\n\n\n\n");
	printf("========================================================================================================================");
	SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY|BACKGROUND_BLUE);
	printf("\n   AAA               NNNNNNNN        NNNNNNNNEEEEEEEEEEEEEEEEEEEEEETTTTTTTTTTTTTTTTTTTTTTT             CCCCCCCCCCCCC   ");
	printf("\n  A:::A              N:::::::N       N::::::NE::::::::::::::::::::ET:::::::::::::::::::::T          CCC::::::::::::C   ");
	printf("\n A:::::A             N::::::::N      N::::::NE::::::::::::::::::::ET:::::::::::::::::::::T        CC:::::::::::::::C OO");
	printf("\nA:::::::A            N:::::::::N     N::::::NEE::::::EEEEEEEEE::::ET:::::TT:::::::TT:::::T       C:::::CCCCCCCC::::CO::");
	printf("\n:::::::::A           N::::::::::N    N::::::N  E:::::E       EEEEEETTTTTT  T:::::T  TTTTTT      C:::::C       CCCCCCO::");
	printf("\n::::A:::::A          N:::::::::::N   N::::::N  E:::::E                     T:::::T             C:::::C              O::");
	printf("\n:::A A:::::A         N:::::::N::::N  N::::::N  E::::::EEEEEEEEEE           T:::::T             C:::::C              O::");
	printf("\n::A   A:::::A        N::::::N N::::N N::::::N  E:::::::::::::::E           T:::::T             C:::::C              O::");
	printf("\n:A     A:::::A       N::::::N  N::::N:::::::N  E:::::::::::::::E           T:::::T             C:::::C              O::");
	printf("\nAAAAAAAAA:::::A      N::::::N   N:::::::::::N  E::::::EEEEEEEEEE           T:::::T             C:::::C              O::");
	printf("\n:::::::::::::::A     N::::::N    N::::::::::N  E:::::E                     T:::::T             C:::::C              O::");
	printf("\nAAAAAAAAAAA:::::A    N::::::N     N:::::::::N  E:::::E       EEEEEE        T:::::T              C:::::C       CCCCCCO::");
	printf("\n           A:::::A   N::::::N      N::::::::NEE::::::EEEEEEEE:::::E      TT:::::::TT             C:::::CCCCCCCC::::CO::");
	printf("\n            A:::::A  N::::::N       N:::::::NE::::::::::::::::::::E      T:::::::::T              CC:::::::::::::::C OO");
	printf("\n             A:::::A N::::::N        N::::::NE::::::::::::::::::::E      T:::::::::T                CCC::::::::::::C   ");
	printf("\n              AAAAAAANNNNNNNN         NNNNNNNEEEEEEEEEEEEEEEEEEEEEE      TTTTTTTTTTT                   CCCCCCCCCCCCC   ");
	SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
	printf("\n========================================================================================================================");
	Sleep(50);
	system("cls");
	
	printf("\n\n\n\n");
	printf("========================================================================================================================");
	SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY|BACKGROUND_BLUE);
	printf("\n           NNNNNNNN        NNNNNNNNEEEEEEEEEEEEEEEEEEEEEETTTTTTTTTTTTTTTTTTTTTTT             CCCCCCCCCCCCC     OOOOOOOO");
	printf("\n           N:::::::N       N::::::NE::::::::::::::::::::ET:::::::::::::::::::::T          CCC::::::::::::C   OO::::::::");
	printf("\n           N::::::::N      N::::::NE::::::::::::::::::::ET:::::::::::::::::::::T        CC:::::::::::::::C OO::::::::::");
	printf("\n           N:::::::::N     N::::::NEE::::::EEEEEEEEE::::ET:::::TT:::::::TT:::::T       C:::::CCCCCCCC::::CO:::::::OOO::");
	printf("\n           N::::::::::N    N::::::N  E:::::E       EEEEEETTTTTT  T:::::T  TTTTTT      C:::::C       CCCCCCO::::::O   O:");
	printf("\nA          N:::::::::::N   N::::::N  E:::::E                     T:::::T             C:::::C              O:::::O     O");
	printf("\n:A         N:::::::N::::N  N::::::N  E::::::EEEEEEEEEE           T:::::T             C:::::C              O:::::O     O");
	printf("\n::A        N::::::N N::::N N::::::N  E:::::::::::::::E           T:::::T             C:::::C              O:::::O     O");
	printf("\n:::A       N::::::N  N::::N:::::::N  E:::::::::::::::E           T:::::T             C:::::C              O:::::O     O");
	printf("\n::::A      N::::::N   N:::::::::::N  E::::::EEEEEEEEEE           T:::::T             C:::::C              O:::::O     O");
	printf("\n:::::A     N::::::N    N::::::::::N  E:::::E                     T:::::T             C:::::C              O:::::O     O");
	printf("\nA:::::A    N::::::N     N:::::::::N  E:::::E       EEEEEE        T:::::T              C:::::C       CCCCCCO::::::O   O:");
	printf("\n A:::::A   N::::::N      N::::::::NEE::::::EEEEEEEE:::::E      TT:::::::TT             C:::::CCCCCCCC::::CO:::::::OOO::");
	printf("\n  A:::::A  N::::::N       N:::::::NE::::::::::::::::::::E      T:::::::::T              CC:::::::::::::::C OO::::::::::");
	printf("\n   A:::::A N::::::N        N::::::NE::::::::::::::::::::E      T:::::::::T                CCC::::::::::::C   OO::::::::");
	printf("\n    AAAAAAANNNNNNNN         NNNNNNNEEEEEEEEEEEEEEEEEEEEEE      TTTTTTTTTTT                   CCCCCCCCCCCCC     OOOOOOOO");
	SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
	printf("\n========================================================================================================================");
	Sleep(50);
	system("cls");
	
	printf("\n\n\n\n");
	printf("========================================================================================================================");
	SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY|BACKGROUND_BLUE);
	printf("\n NNNNNNNN        NNNNNNNNEEEEEEEEEEEEEEEEEEEEEETTTTTTTTTTTTTTTTTTTTTTT             CCCCCCCCCCCCC     OOOOOOOOO         ");
	printf("\n N:::::::N       N::::::NE::::::::::::::::::::ET:::::::::::::::::::::T          CCC::::::::::::C   OO:::::::::OO       ");
	printf("\n N::::::::N      N::::::NE::::::::::::::::::::ET:::::::::::::::::::::T        CC:::::::::::::::C OO:::::::::::::OO     ");
	printf("\n N:::::::::N     N::::::NEE::::::EEEEEEEEE::::ET:::::TT:::::::TT:::::T       C:::::CCCCCCCC::::CO:::::::OOO:::::::O    ");
	printf("\n N::::::::::N    N::::::N  E:::::E       EEEEEETTTTTT  T:::::T  TTTTTT      C:::::C       CCCCCCO::::::O   O::::::O    ");
	printf("\n N:::::::::::N   N::::::N  E:::::E                     T:::::T             C:::::C              O:::::O     O:::::O    ");
	printf("\n N:::::::N::::N  N::::::N  E::::::EEEEEEEEEE           T:::::T             C:::::C              O:::::O     O:::::O    ");
	printf("\n N::::::N N::::N N::::::N  E:::::::::::::::E           T:::::T             C:::::C              O:::::O     O:::::O    ");
	printf("\n N::::::N  N::::N:::::::N  E:::::::::::::::E           T:::::T             C:::::C              O:::::O     O:::::O    ");
	printf("\n N::::::N   N:::::::::::N  E::::::EEEEEEEEEE           T:::::T             C:::::C              O:::::O     O:::::O   A");
	printf("\n N::::::N    N::::::::::N  E:::::E                     T:::::T             C:::::C              O:::::O     O:::::O  A:");
	printf("\n N::::::N     N:::::::::N  E:::::E       EEEEEE        T:::::T              C:::::C       CCCCCCO::::::O   O::::::O A::");
	printf("\n N::::::N      N::::::::NEE::::::EEEEEEEE:::::E      TT:::::::TT             C:::::CCCCCCCC::::CO:::::::OOO:::::::OA:::");
	printf("\n N::::::N       N:::::::NE::::::::::::::::::::E      T:::::::::T              CC:::::::::::::::C OO:::::::::::::OOA::::");
	printf("\n N::::::N        N::::::NE::::::::::::::::::::E      T:::::::::T                CCC::::::::::::C   OO:::::::::OO A:::::");
	printf("\nANNNNNNNN         NNNNNNNEEEEEEEEEEEEEEEEEEEEEE      TTTTTTTTTTT                   CCCCCCCCCCCCC     OOOOOOOOO  AAAAAAA");
	SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
	printf("\n========================================================================================================================");
	Sleep(50);
	system("cls");
	
	printf("\n\n\n\n");
	printf("========================================================================================================================");
	SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY|BACKGROUND_BLUE);
	printf("\n       NNNNNNNNEEEEEEEEEEEEEEEEEEEEEETTTTTTTTTTTTTTTTTTTTTTT             CCCCCCCCCCCCC     OOOOOOOOO                 AA");
	printf("\n       N::::::NE::::::::::::::::::::ET:::::::::::::::::::::T          CCC::::::::::::C   OO:::::::::OO              A::");
	printf("\nN      N::::::NE::::::::::::::::::::ET:::::::::::::::::::::T        CC:::::::::::::::C OO:::::::::::::OO           A:::");
	printf("\n:N     N::::::NEE::::::EEEEEEEEE::::ET:::::TT:::::::TT:::::T       C:::::CCCCCCCC::::CO:::::::OOO:::::::O         A::::");
	printf("\n::N    N::::::N  E:::::E       EEEEEETTTTTT  T:::::T  TTTTTT      C:::::C       CCCCCCO::::::O   O::::::O        A:::::");
	printf("\n:::N   N::::::N  E:::::E                     T:::::T             C:::::C              O:::::O     O:::::O       A:::::A");
	printf("\n::::N  N::::::N  E::::::EEEEEEEEEE           T:::::T             C:::::C              O:::::O     O:::::O      A:::::A ");
	printf("\nN::::N N::::::N  E:::::::::::::::E           T:::::T             C:::::C              O:::::O     O:::::O     A:::::A  ");
	printf("\n N::::N:::::::N  E:::::::::::::::E           T:::::T             C:::::C              O:::::O     O:::::O    A:::::A   ");
	printf("\n  N:::::::::::N  E::::::EEEEEEEEEE           T:::::T             C:::::C              O:::::O     O:::::O   A:::::AAAAA");
	printf("\n   N::::::::::N  E:::::E                     T:::::T             C:::::C              O:::::O     O:::::O  A:::::::::::");
	printf("\n    N:::::::::N  E:::::E       EEEEEE        T:::::T              C:::::C       CCCCCCO::::::O   O::::::O A:::::AAAAAAA");
	printf("\n     N::::::::NEE::::::EEEEEEEE:::::E      TT:::::::TT             C:::::CCCCCCCC::::CO:::::::OOO:::::::OA:::::A       ");
	printf("\n      N:::::::NE::::::::::::::::::::E      T:::::::::T              CC:::::::::::::::C OO:::::::::::::OOA:::::A        ");
	printf("\n       N::::::NE::::::::::::::::::::E      T:::::::::T                CCC::::::::::::C   OO:::::::::OO A:::::A         ");
	printf("\n        NNNNNNNEEEEEEEEEEEEEEEEEEEEEE      TTTTTTTTTTT                   CCCCCCCCCCCCC     OOOOOOOOO  AAAAAAA          ");
	SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
	printf("\n========================================================================================================================");
	Sleep(50);
	system("cls");
	
	printf("\n\n\n\n");
	printf("========================================================================================================================");
	SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY|BACKGROUND_BLUE);
	printf("\nNNNNNEEEEEEEEEEEEEEEEEEEEEETTTTTTTTTTTTTTTTTTTTTTT             CCCCCCCCCCCCC     OOOOOOOOO                 AAA         ");
	printf("\n::::NE::::::::::::::::::::ET:::::::::::::::::::::T          CCC::::::::::::C   OO:::::::::OO              A:::A        ");
	printf("\n::::NE::::::::::::::::::::ET:::::::::::::::::::::T        CC:::::::::::::::C OO:::::::::::::OO           A:::::A       ");
	printf("\n::::NEE::::::EEEEEEEEE::::ET:::::TT:::::::TT:::::T       C:::::CCCCCCCC::::CO:::::::OOO:::::::O         A:::::::A      ");
	printf("\n::::N  E:::::E       EEEEEETTTTTT  T:::::T  TTTTTT      C:::::C       CCCCCCO::::::O   O::::::O        A:::::::::A     ");
	printf("\n::::N  E:::::E                     T:::::T             C:::::C              O:::::O     O:::::O       A:::::A:::::A    ");
	printf("\n::::N  E::::::EEEEEEEEEE           T:::::T             C:::::C              O:::::O     O:::::O      A:::::A A:::::A   ");
	printf("\n::::N  E:::::::::::::::E           T:::::T             C:::::C              O:::::O     O:::::O     A:::::A   A:::::A  ");
	printf("\n::::N  E:::::::::::::::E           T:::::T             C:::::C              O:::::O     O:::::O    A:::::A     A:::::A ");
	printf("\n::::N  E::::::EEEEEEEEEE           T:::::T             C:::::C              O:::::O     O:::::O   A:::::AAAAAAAAA:::::A");
	printf("\n::::N  E:::::E                     T:::::T             C:::::C              O:::::O     O:::::O  A:::::::::::::::::::::");
	printf("\n::::N  E:::::E       EEEEEE        T:::::T              C:::::C       CCCCCCO::::::O   O::::::O A:::::AAAAAAAAAAAAA::::");
	printf("\n::::NEE::::::EEEEEEEE:::::E      TT:::::::TT             C:::::CCCCCCCC::::CO:::::::OOO:::::::OA:::::A             A:::");
	printf("\n::::NE::::::::::::::::::::E      T:::::::::T              CC:::::::::::::::C OO:::::::::::::OOA:::::A               A::");
	printf("\n::::NE::::::::::::::::::::E      T:::::::::T                CCC::::::::::::C   OO:::::::::OO A:::::A                 A:");
	printf("\nNNNNNEEEEEEEEEEEEEEEEEEEEEE      TTTTTTTTTTT                   CCCCCCCCCCCCC     OOOOOOOOO  AAAAAAA                   A");
	SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
	printf("\n========================================================================================================================");
	Sleep(50);
	system("cls");
	
	printf("\n\n\n\n");
	printf("========================================================================================================================");
	SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY|BACKGROUND_BLUE);
	printf("\nEEEEEEEEEEEEEEEEETTTTTTTTTTTTTTTTTTTTTTT             CCCCCCCCCCCCC     OOOOOOOOO                 AAA                 SS");
	printf("\n::::::::::::::::ET:::::::::::::::::::::T          CCC::::::::::::C   OO:::::::::OO              A:::A              SS::");
	printf("\n::::::::::::::::ET:::::::::::::::::::::T        CC:::::::::::::::C OO:::::::::::::OO           A:::::A            S::::");
	printf("\n:::EEEEEEEEE::::ET:::::TT:::::::TT:::::T       C:::::CCCCCCCC::::CO:::::::OOO:::::::O         A:::::::A           S::::");
	printf("\n:::E       EEEEEETTTTTT  T:::::T  TTTTTT      C:::::C       CCCCCCO::::::O   O::::::O        A:::::::::A          S::::");
	printf("\n:::E                     T:::::T             C:::::C              O:::::O     O:::::O       A:::::A:::::A         S::::");
	printf("\n::::EEEEEEEEEE           T:::::T             C:::::C              O:::::O     O:::::O      A:::::A A:::::A         S:::");
	printf("\n:::::::::::::E           T:::::T             C:::::C              O:::::O     O:::::O     A:::::A   A:::::A         SS:");
	printf("\n:::::::::::::E           T:::::T             C:::::C              O:::::O     O:::::O    A:::::A     A:::::A          S");
	printf("\n::::EEEEEEEEEE           T:::::T             C:::::C              O:::::O     O:::::O   A:::::AAAAAAAAA:::::A          ");
	printf("\n:::E                     T:::::T             C:::::C              O:::::O     O:::::O  A:::::::::::::::::::::A         ");
	printf("\n:::E       EEEEEE        T:::::T              C:::::C       CCCCCCO::::::O   O::::::O A:::::AAAAAAAAAAAAA:::::A        ");
	printf("\n:::EEEEEEEE:::::E      TT:::::::TT             C:::::CCCCCCCC::::CO:::::::OOO:::::::OA:::::A             A:::::A  SSSSS");
	printf("\n::::::::::::::::E      T:::::::::T              CC:::::::::::::::C OO:::::::::::::OOA:::::A               A:::::A S::::");
	printf("\n::::::::::::::::E      T:::::::::T                CCC::::::::::::C   OO:::::::::OO A:::::A                 A:::::AS::::");
	printf("\nEEEEEEEEEEEEEEEEE      TTTTTTTTTTT                   CCCCCCCCCCCCC     OOOOOOOOO  AAAAAAA                   AAAAAAASSSS");
	SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
	printf("\n========================================================================================================================");
	Sleep(50);
	system("cls");
	
	printf("\n\n\n\n");
	printf("========================================================================================================================");
	SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY|BACKGROUND_BLUE);
	printf("\nEEEEEEETTTTTTTTTTTTTTTTTTTTTTT             CCCCCCCCCCCCC     OOOOOOOOO                 AAA                 SSSSSSSSSSSS");
	printf("\n::::::ET:::::::::::::::::::::T          CCC::::::::::::C   OO:::::::::OO              A:::A              SS::::::::::::");
	printf("\n::::::ET:::::::::::::::::::::T        CC:::::::::::::::C OO:::::::::::::OO           A:::::A            S:::::SSSSSS:::");
	printf("\nEE::::ET:::::TT:::::::TT:::::T       C:::::CCCCCCCC::::CO:::::::OOO:::::::O         A:::::::A           S:::::S     SSS");
	printf("\n EEEEEETTTTTT  T:::::T  TTTTTT      C:::::C       CCCCCCO::::::O   O::::::O        A:::::::::A          S:::::S        ");
	printf("\n               T:::::T             C:::::C              O:::::O     O:::::O       A:::::A:::::A         S:::::S        ");
	printf("\nEEEE           T:::::T             C:::::C              O:::::O     O:::::O      A:::::A A:::::A         S::::SSSS     ");
	printf("\n:::E           T:::::T             C:::::C              O:::::O     O:::::O     A:::::A   A:::::A         SS::::::SSSSS");
	printf("\n:::E           T:::::T             C:::::C              O:::::O     O:::::O    A:::::A     A:::::A          SSS::::::::");
	printf("\nEEEE           T:::::T             C:::::C              O:::::O     O:::::O   A:::::AAAAAAAAA:::::A            SSSSSS::");
	printf("\n               T:::::T             C:::::C              O:::::O     O:::::O  A:::::::::::::::::::::A                S::");
	printf("\n EEEEEE        T:::::T              C:::::C       CCCCCCO::::::O   O::::::O A:::::AAAAAAAAAAAAA:::::A               S::");
	printf("\nE:::::E      TT:::::::TT             C:::::CCCCCCCC::::CO:::::::OOO:::::::OA:::::A             A:::::A  SSSSSSS     S::");
	printf("\n::::::E      T:::::::::T              CC:::::::::::::::C OO:::::::::::::OOA:::::A               A:::::A S::::::SSSSSS::");
	printf("\n::::::E      T:::::::::T                CCC::::::::::::C   OO:::::::::OO A:::::A                 A:::::AS::::::::::::::");
	printf("\nEEEEEEE      TTTTTTTTTTT                   CCCCCCCCCCCCC     OOOOOOOOO  AAAAAAA                   AAAAAAASSSSSSSSSSSSSS");
	SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
	printf("\n========================================================================================================================");
	Sleep(50);
	system("cls");
	
	printf("\n\n\n\n");
	printf("========================================================================================================================");
	SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY|BACKGROUND_BLUE);
	printf("\nTTTTTTTTTTTTTTTTTTTT             CCCCCCCCCCCCC     OOOOOOOOO                 AAA                 SSSSSSSSSSSSSSS TTTTTT");
	printf("\n:::::::::::::::::::T          CCC::::::::::::C   OO:::::::::OO              A:::A              SS:::::::::::::::ST:::::");
	printf("\n:::::::::::::::::::T        CC:::::::::::::::C OO:::::::::::::OO           A:::::A            S:::::SSSSSS::::::ST:::::");
	printf("\n:::TT:::::::TT:::::T       C:::::CCCCCCCC::::CO:::::::OOO:::::::O         A:::::::A           S:::::S     SSSSSSST:::::");
	printf("\nTTT  T:::::T  TTTTTT      C:::::C       CCCCCCO::::::O   O::::::O        A:::::::::A          S:::::S            TTTTTT");
	printf("\n     T:::::T             C:::::C              O:::::O     O:::::O       A:::::A:::::A         S:::::S                  ");
	printf("\n     T:::::T             C:::::C              O:::::O     O:::::O      A:::::A A:::::A         S::::SSSS               ");
	printf("\n     T:::::T             C:::::C              O:::::O     O:::::O     A:::::A   A:::::A         SS::::::SSSSS          ");
	printf("\n     T:::::T             C:::::C              O:::::O     O:::::O    A:::::A     A:::::A          SSS::::::::SS        ");
	printf("\n     T:::::T             C:::::C              O:::::O     O:::::O   A:::::AAAAAAAAA:::::A            SSSSSS::::S       ");
	printf("\n     T:::::T             C:::::C              O:::::O     O:::::O  A:::::::::::::::::::::A                S:::::S      ");
	printf("\n     T:::::T              C:::::C       CCCCCCO::::::O   O::::::O A:::::AAAAAAAAAAAAA:::::A               S:::::S      ");
	printf("\n   TT:::::::TT             C:::::CCCCCCCC::::CO:::::::OOO:::::::OA:::::A             A:::::A  SSSSSSS     S:::::S      ");
	printf("\n   T:::::::::T              CC:::::::::::::::C OO:::::::::::::OOA:::::A               A:::::A S::::::SSSSSS:::::S      ");
	printf("\n   T:::::::::T                CCC::::::::::::C   OO:::::::::OO A:::::A                 A:::::AS:::::::::::::::SS       ");
	printf("\n   TTTTTTTTTTT                   CCCCCCCCCCCCC     OOOOOOOOO  AAAAAAA                   AAAAAAASSSSSSSSSSSSSSS         ");
	SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
	printf("\n========================================================================================================================");
	Sleep(50);
	system("cls");
	
	printf("\n\n\n\n");
	printf("========================================================================================================================");
	SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY|BACKGROUND_BLUE);
	printf("\nTTTTTTTTTT             CCCCCCCCCCCCC     OOOOOOOOO                 AAA                 SSSSSSSSSSSSSSS TTTTTTTTTTTTTTTT");
	printf("\n:::::::::T          CCC::::::::::::C   OO:::::::::OO              A:::A              SS:::::::::::::::ST:::::::::::::::");
	printf("\n:::::::::T        CC:::::::::::::::C OO:::::::::::::OO           A:::::A            S:::::SSSSSS::::::ST:::::::::::::::");
	printf("\n::TT:::::T       C:::::CCCCCCCC::::CO:::::::OOO:::::::O         A:::::::A           S:::::S     SSSSSSST:::::TT:::::::T");
	printf("\n:T  TTTTTT      C:::::C       CCCCCCO::::::O   O::::::O        A:::::::::A          S:::::S            TTTTTT  T:::::T ");
	printf("\n:T             C:::::C              O:::::O     O:::::O       A:::::A:::::A         S:::::S                    T:::::T ");
	printf("\n:T             C:::::C              O:::::O     O:::::O      A:::::A A:::::A         S::::SSSS                 T:::::T ");
	printf("\n:T             C:::::C              O:::::O     O:::::O     A:::::A   A:::::A         SS::::::SSSSS            T:::::T ");
	printf("\n:T             C:::::C              O:::::O     O:::::O    A:::::A     A:::::A          SSS::::::::SS          T:::::T ");
	printf("\n:T             C:::::C              O:::::O     O:::::O   A:::::AAAAAAAAA:::::A            SSSSSS::::S         T:::::T ");
	printf("\n:T             C:::::C              O:::::O     O:::::O  A:::::::::::::::::::::A                S:::::S        T:::::T ");
	printf("\n:T              C:::::C       CCCCCCO::::::O   O::::::O A:::::AAAAAAAAAAAAA:::::A               S:::::S        T:::::T ");
	printf("\n::TT             C:::::CCCCCCCC::::CO:::::::OOO:::::::OA:::::A             A:::::A  SSSSSSS     S:::::S      TT:::::::T");
	printf("\n:::T              CC:::::::::::::::C OO:::::::::::::OOA:::::A               A:::::A S::::::SSSSSS:::::S      T:::::::::");
	printf("\n:::T                CCC::::::::::::C   OO:::::::::OO A:::::A                 A:::::AS:::::::::::::::SS       T:::::::::");
	printf("\nTTTT                   CCCCCCCCCCCCC     OOOOOOOOO  AAAAAAA                   AAAAAAASSSSSSSSSSSSSSS         TTTTTTTTTT");
	SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
	printf("\n========================================================================================================================");
	Sleep(50);
	system("cls");
	
	printf("\n\n\n\n");
	printf("========================================================================================================================");
	SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY|BACKGROUND_BLUE);
	printf("\n             CCCCCCCCCCCCC     OOOOOOOOO                 AAA                 SSSSSSSSSSSSSSS TTTTTTTTTTTTTTTTTTTTTTTEEE");
	printf("\n          CCC::::::::::::C   OO:::::::::OO              A:::A              SS:::::::::::::::ST:::::::::::::::::::::TE::");
	printf("\n        CC:::::::::::::::C OO:::::::::::::OO           A:::::A            S:::::SSSSSS::::::ST:::::::::::::::::::::TE::");
	printf("\n       C:::::CCCCCCCC::::CO:::::::OOO:::::::O         A:::::::A           S:::::S     SSSSSSST:::::TT:::::::TT:::::TEE:");
	printf("\n      C:::::C       CCCCCCO::::::O   O::::::O        A:::::::::A          S:::::S            TTTTTT  T:::::T  TTTTTT  E");
	printf("\n     C:::::C              O:::::O     O:::::O       A:::::A:::::A         S:::::S                    T:::::T          E");
	printf("\n     C:::::C              O:::::O     O:::::O      A:::::A A:::::A         S::::SSSS                 T:::::T          E");
	printf("\n     C:::::C              O:::::O     O:::::O     A:::::A   A:::::A         SS::::::SSSSS            T:::::T          E");
	printf("\n     C:::::C              O:::::O     O:::::O    A:::::A     A:::::A          SSS::::::::SS          T:::::T          E");
	printf("\n     C:::::C              O:::::O     O:::::O   A:::::AAAAAAAAA:::::A            SSSSSS::::S         T:::::T          E");
	printf("\n     C:::::C              O:::::O     O:::::O  A:::::::::::::::::::::A                S:::::S        T:::::T          E");
	printf("\n      C:::::C       CCCCCCO::::::O   O::::::O A:::::AAAAAAAAAAAAA:::::A               S:::::S        T:::::T          E");
	printf("\n       C:::::CCCCCCCC::::CO:::::::OOO:::::::OA:::::A             A:::::A  SSSSSSS     S:::::S      TT:::::::TT      EE:");
	printf("\n        CC:::::::::::::::C OO:::::::::::::OOA:::::A               A:::::A S::::::SSSSSS:::::S      T:::::::::T      E::");
	printf("\n          CCC::::::::::::C   OO:::::::::OO A:::::A                 A:::::AS:::::::::::::::SS       T:::::::::T      E::");
	printf("\n             CCCCCCCCCCCCC     OOOOOOOOO  AAAAAAA                   AAAAAAASSSSSSSSSSSSSSS         TTTTTTTTTTT      EEE");
	SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
	printf("\n========================================================================================================================");
	Sleep(50);
	system("cls");
	
	printf("\n\n\n\n");
	printf("========================================================================================================================");
	SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY|BACKGROUND_BLUE);
	printf("\n   CCCCCCCCCCCCC     OOOOOOOOO                 AAA                 SSSSSSSSSSSSSSS TTTTTTTTTTTTTTTTTTTTTTTEEEEEEEEEEEEE");
	printf("\nCCC::::::::::::C   OO:::::::::OO              A:::A              SS:::::::::::::::ST:::::::::::::::::::::TE::::::::::::");
	printf("\n:::::::::::::::C OO:::::::::::::OO           A:::::A            S:::::SSSSSS::::::ST:::::::::::::::::::::TE::::::::::::");
	printf("\n:::CCCCCCCC::::CO:::::::OOO:::::::O         A:::::::A           S:::::S     SSSSSSST:::::TT:::::::TT:::::TEE::::::EEEEE");
	printf("\n::C       CCCCCCO::::::O   O::::::O        A:::::::::A          S:::::S            TTTTTT  T:::::T  TTTTTT  E:::::E    ");
	printf("\n:C              O:::::O     O:::::O       A:::::A:::::A         S:::::S                    T:::::T          E:::::E    ");
	printf("\n:C              O:::::O     O:::::O      A:::::A A:::::A         S::::SSSS                 T:::::T          E::::::EEEE");
	printf("\n:C              O:::::O     O:::::O     A:::::A   A:::::A         SS::::::SSSSS            T:::::T          E::::::::::");
	printf("\n:C              O:::::O     O:::::O    A:::::A     A:::::A          SSS::::::::SS          T:::::T          E::::::::::");
	printf("\n:C              O:::::O     O:::::O   A:::::AAAAAAAAA:::::A            SSSSSS::::S         T:::::T          E::::::EEEE");
	printf("\n:C              O:::::O     O:::::O  A:::::::::::::::::::::A                S:::::S        T:::::T          E:::::E    ");
	printf("\n::C       CCCCCCO::::::O   O::::::O A:::::AAAAAAAAAAAAA:::::A               S:::::S        T:::::T          E:::::E    ");
	printf("\n:::CCCCCCCC::::CO:::::::OOO:::::::OA:::::A             A:::::A  SSSSSSS     S:::::S      TT:::::::TT      EE::::::EEEEE");
	printf("\n:::::::::::::::C OO:::::::::::::OOA:::::A               A:::::A S::::::SSSSSS:::::S      T:::::::::T      E::::::::::::");
	printf("\nCCC::::::::::::C   OO:::::::::OO A:::::A                 A:::::AS:::::::::::::::SS       T:::::::::T      E::::::::::::");
	printf("\n   CCCCCCCCCCCCC     OOOOOOOOO  AAAAAAA                   AAAAAAASSSSSSSSSSSSSSS         TTTTTTTTTTT      EEEEEEEEEEEEE");
	SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
	printf("\n========================================================================================================================");
	Sleep(50);
	system("cls");
	
	printf("\n\n\n\n");
	printf("========================================================================================================================");
	SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY|BACKGROUND_BLUE);
	printf("\nCCCCCC     OOOOOOOOO                 AAA                 SSSSSSSSSSSSSSS TTTTTTTTTTTTTTTTTTTTTTTEEEEEEEEEEEEEEEEEEEEEER");
	printf("\n:::::C   OO:::::::::OO              A:::A              SS:::::::::::::::ST:::::::::::::::::::::TE::::::::::::::::::::ER");
	printf("\n:::::C OO:::::::::::::OO           A:::::A            S:::::SSSSSS::::::ST:::::::::::::::::::::TE::::::::::::::::::::ER");
	printf("\nC::::CO:::::::OOO:::::::O         A:::::::A           S:::::S     SSSSSSST:::::TT:::::::TT:::::TEE::::::EEEEEEEEE::::ER");
	printf("\nCCCCCCO::::::O   O::::::O        A:::::::::A          S:::::S            TTTTTT  T:::::T  TTTTTT  E:::::E       EEEEEE ");
	printf("\n      O:::::O     O:::::O       A:::::A:::::A         S:::::S                    T:::::T          E:::::E              ");
	printf("\n      O:::::O     O:::::O      A:::::A A:::::A         S::::SSSS                 T:::::T          E::::::EEEEEEEEEE    ");
	printf("\n      O:::::O     O:::::O     A:::::A   A:::::A         SS::::::SSSSS            T:::::T          E:::::::::::::::E    ");
	printf("\n      O:::::O     O:::::O    A:::::A     A:::::A          SSS::::::::SS          T:::::T          E:::::::::::::::E    ");
	printf("\n      O:::::O     O:::::O   A:::::AAAAAAAAA:::::A            SSSSSS::::S         T:::::T          E::::::EEEEEEEEEE    ");
	printf("\n      O:::::O     O:::::O  A:::::::::::::::::::::A                S:::::S        T:::::T          E:::::E              ");
	printf("\nCCCCCCO::::::O   O::::::O A:::::AAAAAAAAAAAAA:::::A               S:::::S        T:::::T          E:::::E       EEEEEE ");
	printf("\nC::::CO:::::::OOO:::::::OA:::::A             A:::::A  SSSSSSS     S:::::S      TT:::::::TT      EE::::::EEEEEEEE:::::ER");
	printf("\n:::::C OO:::::::::::::OOA:::::A               A:::::A S::::::SSSSSS:::::S      T:::::::::T      E::::::::::::::::::::ER");
	printf("\n:::::C   OO:::::::::OO A:::::A                 A:::::AS:::::::::::::::SS       T:::::::::T      E::::::::::::::::::::ER");
	printf("\nCCCCCC     OOOOOOOOO  AAAAAAA                   AAAAAAASSSSSSSSSSSSSSS         TTTTTTTTTTT      EEEEEEEEEEEEEEEEEEEEEER");
	SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
	printf("\n========================================================================================================================");
	Sleep(50);
	system("cls");
	
	printf("\n\n\n\n");
	printf("========================================================================================================================");
	SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY|BACKGROUND_BLUE);
	printf("\n OOOOOOOOO                 AAA                 SSSSSSSSSSSSSSS TTTTTTTTTTTTTTTTTTTTTTTEEEEEEEEEEEEEEEEEEEEEERRRRRRRRRRR");
	printf("\nO:::::::::OO              A:::A              SS:::::::::::::::ST:::::::::::::::::::::TE::::::::::::::::::::ER::::::::::");
	printf("\n::::::::::::OO           A:::::A            S:::::SSSSSS::::::ST:::::::::::::::::::::TE::::::::::::::::::::ER::::::RRRR");
	printf("\n::::OOO:::::::O         A:::::::A           S:::::S     SSSSSSST:::::TT:::::::TT:::::TEE::::::EEEEEEEEE::::ERR:::::R   ");
	printf("\n:::O   O::::::O        A:::::::::A          S:::::S            TTTTTT  T:::::T  TTTTTT  E:::::E       EEEEEE  R::::R   ");
	printf("\n::O     O:::::O       A:::::A:::::A         S:::::S                    T:::::T          E:::::E               R::::R   ");
	printf("\n::O     O:::::O      A:::::A A:::::A         S::::SSSS                 T:::::T          E::::::EEEEEEEEEE     R::::RRRR");
	printf("\n::O     O:::::O     A:::::A   A:::::A         SS::::::SSSSS            T:::::T          E:::::::::::::::E     R::::::::");
	printf("\n::O     O:::::O    A:::::A     A:::::A          SSS::::::::SS          T:::::T          E:::::::::::::::E     R::::RRRR");
	printf("\n::O     O:::::O   A:::::AAAAAAAAA:::::A            SSSSSS::::S         T:::::T          E::::::EEEEEEEEEE     R::::R   ");
	printf("\n::O     O:::::O  A:::::::::::::::::::::A                S:::::S        T:::::T          E:::::E               R::::R   ");
	printf("\n:::O   O::::::O A:::::AAAAAAAAAAAAA:::::A               S:::::S        T:::::T          E:::::E       EEEEEE  R::::R   ");
	printf("\n::::OOO:::::::OA:::::A             A:::::A  SSSSSSS     S:::::S      TT:::::::TT      EE::::::EEEEEEEE:::::ERR:::::R   ");
	printf("\n::::::::::::OOA:::::A               A:::::A S::::::SSSSSS:::::S      T:::::::::T      E::::::::::::::::::::ER::::::R   ");
	printf("\nO:::::::::OO A:::::A                 A:::::AS:::::::::::::::SS       T:::::::::T      E::::::::::::::::::::ER::::::R   ");
	printf("\n OOOOOOOOO  AAAAAAA                   AAAAAAASSSSSSSSSSSSSSS         TTTTTTTTTTT      EEEEEEEEEEEEEEEEEEEEEERRRRRRRR   ");
	SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
	printf("\n========================================================================================================================");
	Sleep(50);
	system("cls");
	
	printf("\n\n\n\n");
	printf("========================================================================================================================");
	SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY|BACKGROUND_BLUE);
	printf("\n                 AAA                 SSSSSSSSSSSSSSS TTTTTTTTTTTTTTTTTTTTTTTEEEEEEEEEEEEEEEEEEEEEERRRRRRRRRRRRRRRRR    ");
	printf("\nOO              A:::A              SS:::::::::::::::ST:::::::::::::::::::::TE::::::::::::::::::::ER::::::::::::::::R   ");
	printf("\n::OO           A:::::A            S:::::SSSSSS::::::ST:::::::::::::::::::::TE::::::::::::::::::::ER::::::RRRRRR:::::R  ");
	printf("\n::::O         A:::::::A           S:::::S     SSSSSSST:::::TT:::::::TT:::::TEE::::::EEEEEEEEE::::ERR:::::R     R:::::R ");
	printf("\n::::O        A:::::::::A          S:::::S            TTTTTT  T:::::T  TTTTTT  E:::::E       EEEEEE  R::::R     R:::::R ");
	printf("\n::::O       A:::::A:::::A         S:::::S                    T:::::T          E:::::E               R::::R     R:::::R ");
	printf("\n::::O      A:::::A A:::::A         S::::SSSS                 T:::::T          E::::::EEEEEEEEEE     R::::RRRRRR:::::R  ");
	printf("\n::::O     A:::::A   A:::::A         SS::::::SSSSS            T:::::T          E:::::::::::::::E     R:::::::::::::RR   ");
	printf("\n::::O    A:::::A     A:::::A          SSS::::::::SS          T:::::T          E:::::::::::::::E     R::::RRRRRR:::::R  ");
	printf("\n::::O   A:::::AAAAAAAAA:::::A            SSSSSS::::S         T:::::T          E::::::EEEEEEEEEE     R::::R     R:::::R ");
	printf("\n::::O  A:::::::::::::::::::::A                S:::::S        T:::::T          E:::::E               R::::R     R:::::R ");
	printf("\n::::O A:::::AAAAAAAAAAAAA:::::A               S:::::S        T:::::T          E:::::E       EEEEEE  R::::R     R:::::R ");
	printf("\n::::OA:::::A             A:::::A  SSSSSSS     S:::::S      TT:::::::TT      EE::::::EEEEEEEE:::::ERR:::::R     R:::::R ");
	printf("\n::OOA:::::A               A:::::A S::::::SSSSSS:::::S      T:::::::::T      E::::::::::::::::::::ER::::::R     R:::::R ");
	printf("\nOO A:::::A                 A:::::AS:::::::::::::::SS       T:::::::::T      E::::::::::::::::::::ER::::::R     R:::::R ");
	printf("\n  AAAAAAA                   AAAAAAASSSSSSSSSSSSSSS         TTTTTTTTTTT      EEEEEEEEEEEEEEEEEEEEEERRRRRRRR     RRRRRRR ");
	SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
	printf("\n========================================================================================================================");
	Sleep(50);
	system("cls");
	

	return;
}//end intro function

void guide(char situation[10][10],int area[10],int star[10],char managerName[10][30],float managerSalary[10])
{
	HANDLE h = GetStdHandle (STD_OUTPUT_HANDLE); 
	char tempUserName[30]={" "};      //username user enter
	char tempUserPassword[30]={" "};  //user password user enter
	char choice;                      //user choice
	int flag=0;                       //do while
	int count=0;                      //for loop
	int col1=0; 					  //for loop
	int enter=0; 					  //user enter area name
	int level=0;					  //manager level
	int row=0;  					  //for loop
	int starTemp=0;                   //temperary store the manager level
	float tempSalary=0;

	SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY ); //foreground color
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
		scanf("%s",&tempUserName); //prompt user to enter username
		fflush(stdin);
		if(strcmp(tempUserName,"1234")==0)
		{
			do
			{
				gotoxy(10,13);
				printf("PASSWORD: ");
				scanf("%s",&tempUserPassword);  //prompt user to enter password
				fflush(stdin);
				if(strcmp(tempUserPassword,"1234")==0)
				{
					do
					{
						system("cls"); //clear screen
						SetConsoleTextAttribute ( h, FOREGROUND_GREEN|FOREGROUND_INTENSITY );	
						gotoxy(10,3);
						printf("Excellent!");
						SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
						gotoxy(10,5);
						printf("Notice that you can reset your username and password once you log in!");					
						gotoxy(10,7);
						SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY );
						printf("Do you want to follow the instructions to guide you");
						gotoxy(10,9);
						printf("to open the first area of your planet? (Y/N): ");
						SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
						choice=_getch();  //prompt user determine if they need the guide
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
								for(col1=0;col1<41;col1++) //print the horizontal frame of the planet
								{
									gotoxy(10+col1,5); 
									printf("=");
									gotoxy(10+col1,25);
									printf("=");
								}
								for(col1=0;col1<19;col1++)  //print the vertical frame of the planet
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
								
								for(count=1;count<10;count++) //print the area
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
								scanf("%d",&enter); //prompt user to enter the number corresponding to the area they want to open 
								fflush(stdin);
								SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
								if((enter>=1)&&(enter<=9))
								{
									strcpy(situation[enter],"OPEN"); //set the area open
									gotoxy(60,11);
									printf("Press <ENTER> to continue!");
									getch();
									SetConsoleTextAttribute ( h, FOREGROUND_GREEN|FOREGROUND_INTENSITY );
									gotoxy(60,11);
									printf("Great! Now you got your first area open!");
									//if the area is open
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
										for(count=0;count<62;count++) //print frame
										{
											SetConsoleTextAttribute ( h, FOREGROUND_BLUE| FOREGROUND_GREEN|FOREGROUND_INTENSITY );
											gotoxy(22+count,0);
											printf("-");
											gotoxy(22+count,5);
											printf("-");
											SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE);
										}	
										if(row==0) //prompt user enter manager name
										{																															
											gotoxy(29,1);
											printf("AREA");
											gotoxy(56,1);
											SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_INTENSITY );
											printf("MANAGER");	
											SetConsoleTextAttribute ( h, FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_GREEN);	
											gotoxy(42,1);
											printf("MANAGE");
											gotoxy(67,1);
											printf("SALARY ($/month)");																																								
											gotoxy(28,3);
											printf("Area %d",area[enter]);																						
											for(count=0;count<5;count++)
											{												
												gotoxy(41+count*2,3);
												printf("*");
											}																				
											for(count=0;count<13;count++) //print horizontal frame
											{
												gotoxy(39+count,2);
												printf("-");
												gotoxy(39+count,4);
												printf("-");																			
											}											
											SetConsoleTextAttribute ( h, FOREGROUND_RED| FOREGROUND_GREEN|FOREGROUND_INTENSITY );
											gotoxy(58,3);
											printf("%s",managerName[enter]);
											SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE );																					
											gotoxy(70,3);
											printf("%.2f",managerSalary[enter]);																						
											//print vertical frame													
											gotoxy(39,3);
											printf("|");
											gotoxy(51,3);
											printf("|");
											SetConsoleTextAttribute ( h, FOREGROUND_RED| FOREGROUND_GREEN|FOREGROUND_INTENSITY );												
										}
										if(row==1) //prompt user determine the manager level
										{																															
											gotoxy(29,1);
											printf("AREA");
											gotoxy(56,1);											
											printf("MANAGER");												
											SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY );
											gotoxy(42,1);
											printf("MANAGE");
											SetConsoleTextAttribute ( h, FOREGROUND_RED| FOREGROUND_GREEN|FOREGROUND_BLUE);	
											gotoxy(67,1);
											printf("SALARY ($/month)");																																								
											gotoxy(28,3);
											printf("Area %d",area[enter]);
																																	
											for(count=0;count<5;count++)
											{	
												SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_INTENSITY );											
												gotoxy(41+count*2,3);
												printf("*");
											}		
																													
											/*add color for promotion*/
											for(count=1;count<star[enter]+1;count++)
											{					
												SetConsoleTextAttribute ( h, FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
												gotoxy(41+(count-1)*2,3);
												printf("*");													
											}
											
											for(count=0;count<13;count++) //print horizontal frame
											{
												SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_INTENSITY );	
												gotoxy(39+count,2);
												printf("-");
												gotoxy(39+count,4);
												printf("-");					
												SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE);				
											}																
											gotoxy(58,3);
											printf("%s",managerName[enter]);																																
											gotoxy(70,3);
											printf("%.2f",managerSalary[enter]);																																	
											//print vertical frame													
											SetConsoleTextAttribute ( h, FOREGROUND_RED| FOREGROUND_GREEN|FOREGROUND_INTENSITY );
											gotoxy(39,3);
											printf("|");
											gotoxy(51,3);
											printf("|");
											SetConsoleTextAttribute ( h, FOREGROUND_GREEN| FOREGROUND_RED| FOREGROUND_INTENSITY );													
										}
										if(row==2) //prompt user determine the manager salary
										{	
											SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_BLUE);																														
											gotoxy(29,1);
											printf("AREA");
											gotoxy(56,1);											
											printf("MANAGER");																					
											gotoxy(42,1);
											printf("MANAGE");											
											gotoxy(67,1);
											SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY );
											printf("SALARY ($/month)");	
											SetConsoleTextAttribute ( h, FOREGROUND_RED| FOREGROUND_GREEN|FOREGROUND_BLUE);																																								
											gotoxy(28,3);
											printf("Area %d",area[enter]);
																																	
											for(count=0;count<5;count++)
											{	
												SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_BLUE );											
												gotoxy(41+count*2,3);
												printf("*");
											}		
																													
											/*add color for promotion*/
											for(count=1;count<star[enter]+1;count++)
											{					
												SetConsoleTextAttribute ( h, FOREGROUND_RED| FOREGROUND_GREEN|FOREGROUND_INTENSITY );
												gotoxy(41+(count-1)*2,3);
												printf("*");													
											}
											
											for(count=0;count<13;count++) //print horizontal frame
											{
												SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE);
												gotoxy(39+count,2);
												printf("-");
												gotoxy(39+count,4);
												printf("-");																			
											}																
											gotoxy(58,3);
											printf("%s",managerName[enter]);
											SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_INTENSITY);																													
											gotoxy(70,3);
											printf("%.2f",managerSalary[enter]);
											SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE);																																	
											//print vertical frame
											gotoxy(39,3);
											printf("|");
											gotoxy(51,3);
											printf("|");
											SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_INTENSITY);											
										}
										
										if(row==3)  //print everything
										{										
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
										}
										
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
											SetConsoleTextAttribute ( h, FOREGROUND_RED| FOREGROUND_GREEN|FOREGROUND_INTENSITY );
											gotoxy(30,12);
											printf("Press <ENTER> to continue!!");
											getch();
											
										}
										if(row==1)
										{
											gotoxy(30,6);
											printf("Second, let's promote the manger.");
											gotoxy(30,8);
											printf("The number of * represents current manager level.");
											gotoxy(30,9);
											printf("             -----------");
											gotoxy(30,10);
											printf("for example,| * * * * * | means that the manager is currently on level 3.");
											gotoxy(30,11);
											printf("             -----------");																					
											SetConsoleTextAttribute ( h, FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
											gotoxy(44,10);
											printf("* * *");
											gotoxy(44,8);
											printf("*");	
											SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_INTENSITY );									
											gotoxy(30,12);
											printf("The higher level a manager has, the better the area can develop.");
											gotoxy(30,15);
											printf("Now let's enter the level number: ");
											scanf("%d",&starTemp);
											fflush(stdin);
											if((starTemp>1)&&(starTemp<=5))
											{
												star[enter]=starTemp;
												gotoxy(30,17);
												SetConsoleTextAttribute ( h, FOREGROUND_GREEN|FOREGROUND_INTENSITY );
												printf("Great! %s is now promoted to level %d!",managerName[enter],star[enter]);
												SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_INTENSITY );
												gotoxy(30,19);
												printf("Press <ENTER> to continue!");
											}
											else if(starTemp==1) 
											{
												SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_INTENSITY);
												gotoxy(30,17);
												printf("INVALID INPUT. %s is currently on level 1!",managerName[enter]);			
												SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_INTENSITY );
												gotoxy(30,19);
												printf("Press <ENTER> to try again!");
												row--;
											}
											else
											{
												SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_INTENSITY);
												gotoxy(30,17);
												printf("INVALID INPUT");			
												SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_INTENSITY );
												gotoxy(30,19);
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
											fflush(stdin);
											if(tempSalary>0)
											{
												managerSalary[enter]=tempSalary;
												gotoxy(30,12);
												SetConsoleTextAttribute ( h, FOREGROUND_GREEN |FOREGROUND_INTENSITY );
												printf("Great! New manager salary is saved!");
												SetConsoleTextAttribute ( h,FOREGROUND_RED| FOREGROUND_GREEN|FOREGROUND_INTENSITY );
												gotoxy(30,14);
												printf("Press <ENTER> to continue!!");
											}
											else
											{
												SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_INTENSITY);
												gotoxy(30,12);
												printf("INVALID INPUT");			
												SetConsoleTextAttribute ( h, FOREGROUND_RED| FOREGROUND_GREEN|FOREGROUND_INTENSITY );
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
											printf("Great! Now you have completed all infomation ");
											gotoxy(30,10);
											printf("required to open your first area!");
											SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
											gotoxy(30,12);
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

						case 'n': //if user does not want the guide
						case 'N':
							gotoxy(10,11);
							printf("Press <ENTER> to continue!");
							getch();
							system("cls");
							flag=4;
							break;
						
						default:
							SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_INTENSITY);
							gotoxy(10,11);
							printf("INVALID INPUT");			
							SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
							gotoxy(10,13);
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
	system("cls");  //clear the screen
	return;
}//end of guide function

void login(char userName[2][30],char userPassword[2][30],int pass)
{
	HANDLE h = GetStdHandle (STD_OUTPUT_HANDLE); 
	char tempUserName[30]={"0"};         //username user enters 
	char tempUserPassword[30]={"0"};     //password user enters
	char choice;                         //user choice when enter the wrong password
	int flag=0;  						 //for loop

	gotoxy(50,5);
	printf("          o");
	gotoxy(50,6);
	printf("        o |");
	gotoxy(50,7);
	printf("        |");
	gotoxy(50,8);
	printf("  _                     .===.");
	gotoxy(50,9);
	printf(" |H|        .--.      .:'   `:.");
	gotoxy(50,10);
	printf(" |H|`.     '||||\     ||     ||");
	gotoxy(50,11);
	printf(" |\\||:. .'||||||`.   `:.   .:'");
	gotoxy(50,12);
	printf(" |:`:.--'||||||||||`--..`=:='...");
    
	//add color
	SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_INTENSITY );  //foreground color
	gotoxy(50,5);
	printf("          o");
	Sleep(100);
	gotoxy(50,6);
	printf("        o |");
	Sleep(100);
	gotoxy(50,7);
	printf("        |");
	Sleep(100);
	SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_INTENSITY );
	gotoxy(50,8);
	printf("  _                     .===.");
	Sleep(100);
	gotoxy(50,9);
	printf(" |H|        .--.      .:'   `:.");
	Sleep(100);
	gotoxy(50,10);
	printf(" |H|`.     '||||\     ||     ||");
	Sleep(100);
	gotoxy(50,11);
	printf(" |\\||:. .'||||||`.   `:.   .:'");
	Sleep(100);
	gotoxy(50,12);
	printf(" |:`:.--'||||||||||`--..`=:='...");
	Sleep(500);

	do
	{
		SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_INTENSITY );
		gotoxy(50,5);
		printf("          o");
		gotoxy(50,6);
		printf("        o |");
		gotoxy(50,7);
		printf("        |");
		gotoxy(50,8);
		printf("  _                     .===.");
		gotoxy(50,9);
		printf(" |H|        .--.      .:'   `:.");
		gotoxy(50,10);
		printf(" |H|`.     '||||\     ||     ||");
		gotoxy(50,11);
		printf(" |\\||:. .'||||||`.   `:.   .:'");
		gotoxy(50,12);
		printf(" |:`:.--'||||||||||`--..`=:='...");

		SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
		gotoxy(60,30);
		printf("USERNAME: ");
		scanf("%s",tempUserName);  //temporary username
		fflush(stdin);	
		if(strcmp(tempUserName,userName[pass])==0)
		{
			do
			{
				SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY );
				gotoxy(50,5);
				printf("          o");
				gotoxy(50,6);
				printf("        o |");
				gotoxy(50,7);
				printf("        |");
				gotoxy(50,8);
				printf("  _                     .===.");
				gotoxy(50,9);
				printf(" |H|        .--.      .:'   `:.");
				gotoxy(50,10);
				printf(" |H|`.     '||||\     ||     ||");
				gotoxy(50,11);
				printf(" |\\||:. .'||||||`.   `:.   .:'");
				gotoxy(50,12);
				printf(" |:`:.--'||||||||||`--..`=:='...");
				SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
				gotoxy(60,32);
				printf("PASSWORD: ");
				scanf("%s",&tempUserPassword);
				fflush(stdin);	
				if(strcmp(tempUserPassword,userPassword[pass])==0)
				{
					gotoxy(60,34);
					printf("Press <ENTER> to continue!");
					getch();
					system("cls");
					flag=5;	
				}
				else
				{
					SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_INTENSITY);			
					gotoxy(60,34);
					printf("INVALID PASSWORD!");			
					SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
					gotoxy(60,36);
					printf("Forget your password?");							
					gotoxy(60,38);
					printf("Press '1' to try again");
					gotoxy(60,40);
					printf("Press '2' to view your password: ");
					do
					{
						SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY );
						gotoxy(50,5);
						printf("          o");
						gotoxy(50,6);
						printf("        o |");
						gotoxy(50,7);
						printf("        |");
						gotoxy(50,8);
						printf("  _                     .===.");
						gotoxy(50,9);
						printf(" |H|        .--.      .:'   `:.");
						gotoxy(50,10);
						printf(" |H|`.     '||||\     ||     ||");
						gotoxy(50,11);
						printf(" |\\||:. .'||||||`.   `:.   .:'");
						gotoxy(50,12);
						printf(" |:`:.--'||||||||||`--..`=:='...");
						SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
						choice=_getch();
						fflush(stdin);
						switch(choice)
						{
							case '1':
								flag=1;
								system("cls");
								gotoxy(60,30);
								printf("USERNAME: %s",userName[pass]);
								gotoxy(60,32);
								printf("PASSWORD:                ");
								break;
							case '2':						
								system("cls");
								SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY );
								gotoxy(50,5);
								printf("          o");
								gotoxy(50,6);
								printf("        o |");
								gotoxy(50,7);
								printf("        |");
								gotoxy(50,8);
								printf("  _                     .===.");
								gotoxy(50,9);
								printf(" |H|        .--.      .:'   `:.");
								gotoxy(50,10);
								printf(" |H|`.     '||||\     ||     ||");
								gotoxy(50,11);
								printf(" |\\||:. .'||||||`.   `:.   .:'");
								gotoxy(50,12);
								printf(" |:`:.--'||||||||||`--..`=:='...");
								SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
								gotoxy(60,30);
								printf("USERNAME: %s",userName[pass]);
								gotoxy(60,32);
								printf("PASSWORD: ");
								SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_INTENSITY);	
								gotoxy(70,32);
								printf("%s",userPassword[pass]);
								SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
								gotoxy(60,34);
								printf("Press <ENTER> to try again!        ");
								gotoxy(60,36);
								printf("                                   ");
								gotoxy(60,38);
								printf("                                   "); 
								getch();
								system("cls");
								gotoxy(60,30);
								printf("USERNAME: %s",userName[pass]);
								flag=1;
								break;
							default:
								SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_INTENSITY);			
								gotoxy(60,34);
								printf("INVALID INPUT!                  ");			
								SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
								gotoxy(60,36);
								printf("Press <ENTER> to try again!                      ");							
								//clear screen								
								gotoxy(60,38);
								printf("                                        ");
								gotoxy(60,40);
								printf("                                        ");
								getch();
								gotoxy(60,34);
								printf("Press '1' to try again           ");
								gotoxy(60,36);
								printf("Press '2' to view your password: ");							
								flag=0;							
								break;
						}
					}while(flag<1);				
				}						
			}while(flag<2);
		}
		else
		{
			SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_INTENSITY);			
			gotoxy(60,32);
			printf("INVALID USERNAME!");			
			SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
			gotoxy(60,34);
			printf("Forget your username?");							
			gotoxy(60,36);
			printf("Press '1' to try again");
			gotoxy(60,38);
			printf("Press '2' to view your username: ");
			do
			{
				SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY );
				gotoxy(50,5);
				printf("          o");
				gotoxy(50,6);
				printf("        o |");
				gotoxy(50,7);
				printf("        |");
				gotoxy(50,8);
				printf("  _                     .===.");
				gotoxy(50,9);
				printf(" |H|        .--.      .:'   `:.");
				gotoxy(50,10);
				printf(" |H|`.     '||||\     ||     ||");
				gotoxy(50,11);
				printf(" |\\||:. .'||||||`.   `:.   .:'");
				gotoxy(50,12);
				printf(" |:`:.--'||||||||||`--..`=:='...");
				SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
				choice=_getch();
				fflush(stdin);
				switch(choice)
				{
					case '1':
						system("cls");
						gotoxy(60,30);
						printf("USERNAME:                                    ");
						flag=4;
						break;
					case '2':						
						system("cls");
						SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY );
						gotoxy(50,5);
						printf("          o");
						gotoxy(50,6);
						printf("        o |");
						gotoxy(50,7);
						printf("        |");
						gotoxy(50,8);
						printf("  _                     .===.");
						gotoxy(50,9);
						printf(" |H|        .--.      .:'   `:.");
						gotoxy(50,10);
						printf(" |H|`.     '||||\     ||     ||");
						gotoxy(50,11);
						printf(" |\\||:. .'||||||`.   `:.   .:'");
						gotoxy(50,12);
						printf(" |:`:.--'||||||||||`--..`=:='...");
						SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
						gotoxy(60,30);
						printf("USERNAME: ");
						SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_INTENSITY);	
						gotoxy(70,30);
						printf("%s",userName[pass]);
						SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
						gotoxy(60,32);
						printf("Press <ENTER> to try again!        ");
						gotoxy(60,36);
						printf("                               ");
						gotoxy(60,38);
						printf("                            "); 
						getch();
						system("cls");
						flag=4;
						break;
					default:
						SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_INTENSITY);			
						gotoxy(60,32);
						printf("INVALID INPUT!                  ");			
						SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
						gotoxy(60,34);
						printf("Press <ENTER> to try again!                      ");							
						//clear screen					
						gotoxy(60,36);
						printf("                                        ");
						gotoxy(60,38);
						printf("                                        ");
						getch();
						gotoxy(60,32);
						printf("Press '1' to try again           ");
						gotoxy(60,34);
						printf("Press '2' to view your username: ");							
						flag=1;							
						break;
				}
			}while(flag<2);				
		}					
	}while(flag<5);	
	return;
}//end login function

int mainMenu(void)
{	
	HANDLE h = GetStdHandle (STD_OUTPUT_HANDLE);
	int mainMenuChoice=0;  //main menu choice
	int row=0;             //for loop
	SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY ); //foreground color
	gotoxy(60,5);
	printf("1] Area Management");
	gotoxy(60,7);
	printf("2] Manager Management");
	gotoxy(60,9);
	printf("3] Area Development View");
	gotoxy(60,11);
	printf("4] Reset Account");
	gotoxy(60,13);
	printf("5] Initialize Account");
	gotoxy(60,15);
	printf("6] Exit");
	SetConsoleTextAttribute ( h, FOREGROUND_GREEN |FOREGROUND_INTENSITY );
	//print frame
	for(row=0;row<30;row++)
	{
		gotoxy(58+row,3);
		printf("=");
		Sleep(10);
	}
	for(row=0;row<13;row++)
	{
		gotoxy(86,4+row);
		printf("||");
		Sleep(10);
	}
	for(row=0;row<30;row++)
	{
		gotoxy(87-row,17);
		printf("=");
		Sleep(10);
	}
	for(row=0;row<13;row++)
	{
		gotoxy(58,16-row);
		printf("||");
		Sleep(10);
	}
	SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
	gotoxy(60,19);
	printf("Choice: "); //prompt user to select 
	scanf("%d",&mainMenuChoice);
	fflush(stdin);
	system("cls");  //clear the screen
	return(mainMenuChoice);
}//end mainMenu function

float areaManage(int area[10],float areaEstimated,char situation[10][10])
{
	HANDLE h = GetStdHandle (STD_OUTPUT_HANDLE);  
	int row=0;   //for loop
	int enter=0; //user enter the area open
	int count=0; //for loop
	int col1=0; //for loop
	char choice;  //user choice
	int flag=0;  //do while

	do
	{
		SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY ); //foreground color
		//print horizontal frame
		for(col1=0;col1<41;col1++)
		{
			gotoxy(55+col1,0); 
			printf("=");
			gotoxy(55+col1,20);
			printf("=");
		}
		for(col1=0;col1<19;col1++) //print vertical frame
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
		/*print current payroll budget to screen*/
		SetConsoleTextAttribute ( h, FOREGROUND_GREEN|FOREGROUND_INTENSITY );
		gotoxy(105,5);
		printf("Payroll Budget: %.2f",areaEstimated);
		SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );

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

		/*user determine to open new area, close area or manage payroll budget*/
		SetConsoleTextAttribute ( h, FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_INTENSITY);
		gotoxy(50,23);
		printf("a]");
		gotoxy(63,23);
		printf("b]");
		gotoxy(77,23);
		printf("c]");
		gotoxy(102,23);
		printf("0]");
		SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
		gotoxy(53,23);
		printf("Open Area");
		gotoxy(66,23);
		printf("Close Area");
		gotoxy(80,23);
		printf("Manage Payroll Budget");
		gotoxy(105,23);
		printf("Return");
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
				else if(strcmp(situation[enter],"OPEN")==0)
				{
					SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_INTENSITY);
					gotoxy(58,30);
					printf("Area %d is open already!",enter);			
					SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
					gotoxy(58,32);
					printf("Press <ENTER> to try again!");
					getch();
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
					printf("All areas are closed!");
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
				else if(strcmp(situation[enter],"CLOSED")==0)
				{
					SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_INTENSITY);
					gotoxy(58,30);
					printf("Area %d is already closed!",enter);			
					SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
					gotoxy(58,32);
					printf("Press <ENTER> to try again!");
					getch();
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
					printf("You don't need to set your payroll budget!");
					gotoxy(58,32);
					SetConsoleTextAttribute ( h, FOREGROUND_GREEN|FOREGROUND_INTENSITY);
					printf("Current Payroll Budget: %.2f",areaEstimated);					
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
				scanf("%f",&areaEstimated);
				fflush(stdin);
				SetConsoleTextAttribute ( h, FOREGROUND_GREEN|FOREGROUND_INTENSITY);
				gotoxy(50,31);
				printf("Current Payroll Budget: %.2f",areaEstimated);
				SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
				gotoxy(50,33);
				printf("Press <ENTER> to continue!");
				getch();
				system("cls");
				flag=2;
			}			
			break;
		
		case '0': //return to main menu
			flag=3;
			system("cls");
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
	return(areaEstimated);
}//end areaManage function

void managerManage (int area[10],char managerName[10][30],float managerSalary[10],int star[10],char situation[10][10],float areaEstimated)
{
	HANDLE h = GetStdHandle (STD_OUTPUT_HANDLE);   
	int enter=-1;                    //user enter area number they want to manage
	int count=0;					 //for loop
	int col1=0;						 //for loop
	char choice;					 //user choice
	int flag=0;						 //do while
	char managerNameTemp[30]={"0"};  //temporary store manager name
	float managerSalaryTemp=0;       //temporary store manager salary
	int starTemp=0; 				 //temperary store manager level 
	float sum=0;                     //sum of the manager salary
	float left=0;                    //money left
	int row=1;                       //for loop
	
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
				for(count=0;count<46;count++)
				{
					gotoxy(66+count,4+(col1-1)*3);
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
		
		//calculate sum of manager salary
		sum=0;
		for(row=1;row<10;row++)
		{
			sum=sum+managerSalary[row];
		}
		left=areaEstimated-sum;
		
		/*print current payroll budget to screen*/
		SetConsoleTextAttribute ( h, FOREGROUND_GREEN|FOREGROUND_INTENSITY );
		gotoxy(15,5);
		printf("Payroll Budget: %.2f",areaEstimated);
		SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
		gotoxy(15,7);
		SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_INTENSITY );
		printf("Salary Cost: %.2f",sum);
		if(left>=0)//if the money left is greater than 0
		{
			gotoxy(15,9);
			SetConsoleTextAttribute ( h, FOREGROUND_GREEN|FOREGROUND_INTENSITY );
			printf("Money left: %.2f",left);
		}
		if(left<0)
		{
			gotoxy(15,9);
			SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_INTENSITY );
			printf("Money left: %.2f",left);
		}
		
		
		for(count=0;count<62;count++)
		{
			SetConsoleTextAttribute ( h, FOREGROUND_BLUE| FOREGROUND_GREEN|FOREGROUND_INTENSITY );
			gotoxy(52+count,30);
			printf("-");
			SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
		}	
			
		gotoxy(52,31);
		printf("Enter corresponding");
		SetConsoleTextAttribute ( h, FOREGROUND_RED| FOREGROUND_GREEN|FOREGROUND_INTENSITY );
		gotoxy(72,31);
		printf("Area Number");
		SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );	
		gotoxy(84,31);
		printf("to edit or press '0' to return: ");	
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
				
				/*print current payroll budget to screen*/
				sum=0;
				for(row=1;row<10;row++)
				{
					sum=sum+managerSalary[row];
				}
				left=areaEstimated-sum;
				SetConsoleTextAttribute ( h, FOREGROUND_GREEN|FOREGROUND_INTENSITY );
				gotoxy(15,5);
				printf("Payroll Budget: %.2f",areaEstimated);
				SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
				gotoxy(15,7);
				SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_INTENSITY );
				printf("Salary Cost: %.2f",sum);
				if(left>=0)//if the money left is greater than 0
				{
					gotoxy(15,9);
					SetConsoleTextAttribute ( h, FOREGROUND_GREEN|FOREGROUND_INTENSITY );
					printf("Money left: %.2f",left);
				}
				if(left<0)
				{
					gotoxy(15,9);
					SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_INTENSITY );
					printf("Money left: %.2f",left);
				}		
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

		else if(strcmp(situation[enter],"CLOSED")==0)
		{
			SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_INTENSITY );
			gotoxy(52,33);
			printf("Area %d is currently closed!",enter);
			SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
			gotoxy(52,35);
			printf("Press <ENTER> to try again!!");
			getch();
			system("cls");
			flag=2;
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
	return;
}//end managerManage function

void viewArea (char situation[10][10],int star[10],int area[10],float areaEstimated,float managerSalary[10])
{	
	HANDLE h = GetStdHandle (STD_OUTPUT_HANDLE);   
	int count=0;  //for loop
	int col1=0;   //for loop
	int row=0;    //for loop
	float sum=0;  //sum of the manager salary
	float left=0; //money left 

	for(col1=0;col1<41;col1++) //print horizontal frame
	{
		gotoxy(55+col1,0);
		printf("=");
		gotoxy(55+col1,20);
		printf("=");
	}
	for(col1=0;col1<19;col1++) //print vertical frame
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
	
	//calculate sum of manager salary
	sum=0;
	for(row=1;row<10;row++)
	{
		sum=sum+managerSalary[row];
	}
	left=areaEstimated-sum;
	/*print current payroll budget to screen*/
	gotoxy(60,22);
	SetConsoleTextAttribute ( h, FOREGROUND_GREEN|FOREGROUND_INTENSITY);
	printf("Payroll Budget: %.2f",areaEstimated);
	SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );	
	gotoxy(60,24);
	SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_INTENSITY );
	printf("Salary Cost: %.2f",sum);
	if(left>=0)//if the money left is greater than 0
	{
		gotoxy(60,26);
		SetConsoleTextAttribute ( h, FOREGROUND_GREEN|FOREGROUND_INTENSITY );
		printf("Money left: %.2f",left);
	}
	if(left<0)
	{
		gotoxy(60,26);
		SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_INTENSITY );
		printf("Money left: %.2f",left);
	}
	SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );	
	gotoxy(60,28);
	printf("Press <ENTER> to return.");
	getch();
	system("cls");

	return;
}//end viewArea function

void resetAccount (char userName[2][30],char userPassword[2][30],int pass)
{
	HANDLE h = GetStdHandle (STD_OUTPUT_HANDLE); 
	char tempUserPassword[30];  //temporary store user password
	int flag=0;                 //for loop
	
	do
	{
		gotoxy(60,5);
		printf("Welcome! %s",userName[pass]);
		gotoxy(60,7);
		printf("To set your new username and password");
		gotoxy(60,9);
		printf("first please enter your old password:");
		gotoxy(60,11);
		printf("OLD PASSWORD: ");
		scanf("%s",&tempUserPassword); //prompt user to enter the old password
		fflush(stdin);
		if(strcmp(tempUserPassword,userPassword[pass])==0)
		{
			gotoxy(60,13);
			printf("Following please enter your new username and password");
			gotoxy(60,15);
			printf("new USERNAME: ");
			scanf("%s",&userName[1]); //prompt user to enter their new username
			fflush(stdin);
			do
			{
				gotoxy(60,17);
				printf("new PASSWORD: ");
				scanf("%s",&tempUserPassword);  //prompt user to enter their new password
				if(strcmp(tempUserPassword,userPassword[pass])==0)
				{
					SetConsoleTextAttribute ( h,  FOREGROUND_RED|FOREGROUND_INTENSITY );
					gotoxy(60,19);
					printf("New password cannot be the same as the old one!");
					SetConsoleTextAttribute ( h,  FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_INTENSITY );
					gotoxy(60,21);
					printf("Press <ENTER> to try again!");	
					getch();
					//clear the following area
					gotoxy(60,19);
					printf("                                                       ");
					gotoxy(60,21);
					printf("                                                        ");
					gotoxy(60,17);
					printf("NEW PASSWORD:                                    ");
					flag=1;
				}
				if(strcmp(tempUserPassword,userPassword[pass])!=0) //if new password is equal to the new one
				{
					strcpy(userPassword[1],tempUserPassword);
					SetConsoleTextAttribute ( h,  FOREGROUND_GREEN|FOREGROUND_INTENSITY );
					gotoxy(60,19);
					printf("GREAT! New username and password are saved!");
					SetConsoleTextAttribute ( h,  FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_INTENSITY );
					gotoxy(60,21);
					printf("Press <ENTER> to log in again!");
					getch();
					system("cls");
					flag=3;
				}
			}while(flag<2);		
		}
		else
		{
			SetConsoleTextAttribute ( h,  FOREGROUND_RED|FOREGROUND_INTENSITY );
			gotoxy(60,13);
			printf("WRONG PASSWORD!");
			SetConsoleTextAttribute ( h,  FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_INTENSITY );
			gotoxy(60,15);
			printf("Press <ENTER> to try again!");
			getch();
			system("cls");
			flag=2;
		}	
	}while(flag<3);
	return;
}//end resetAccount function 

int logout (int flag)
{
	HANDLE h = GetStdHandle (STD_OUTPUT_HANDLE); 
	char choice;    //user determine if log out
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
		printf("1] return 2] log in 3] exit");
		choice=_getch(); //prompt user to select
		fflush(stdin);
		switch(choice)
		{
		case '1': //return to main menu
			flag=5;
			break;
		case '2': //return to log in page
			flag=6;
			break;
		case '3': //exit the program
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
	system("cls"); 
	return(flag);
}//end logout function 

//This program has sucessfully run


