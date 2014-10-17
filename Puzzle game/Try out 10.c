#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
typedef struct
{
	char virt; /* Virtual Array Slot */
	int real; /* Real Array Slot*/
}board;

typedef struct
{
	char Name[50];
	char score[10];
	char Diff[10];
}player_data;

player_data Players[60];
int Num_P = -1;
int b_ = 3;
char show_records();
char player_Records(char Name[50], char score[20]);
char Get_Name(char Name[50]);
char read_records();
char write_records(char Name[50], char score[20], char d[10]);
int Get_Ran();
int Array_Setup(board A[b_][b_]);
char Check_for_repeat(int num, board A[b_][b_]);
char V_Array_setup(board A[b_][b_]);
char sx_inc(int axis_x_val_storage, char m_sx[2]);
char sy_inc(int axis_y_val_storage, char m_sy[2]);
char printV(board A[b_][b_]);
char input(board a[b_][b_], board s[b_][b_], char User_Decision, char load);
char menu();
char menu_arrange(char menu[5]);
char print_menu(char menu[5]);
int menu_search(char menu[5]);
char user_input(char menu[5]);
char option();
int Color_changer();
char Welcome();
char about();
char start_game();
char Dev_mode();
char check_win(board A[b_][b_]);
char you_won();
int Master_Colour_Control_System_v_2_0_1();
char colour_Dictionary(int a, int b, char Color_Val_Store[3]);
char colour_machine(char Color_Val_Store[3]);
char Colour_Identifier(char Color_Val_Store[3], char Colour_1[10], char Colour_2[10]);
int main()
{
	printf("\n\n\n\t\tPlease Maximise the Window for this application\n\n\n\n\t\tPress any key to proceed to the game");
	getch();
	system("cls");
	menu();
	return(0);
}
char start_game()
{
	int axis_X, axis_Y;
	int score;
	char timer = 'F', User_Decision;
	char s_score[20];
	time_t start, end;
	board A[b_][b_], s[b_][b_];
	char Player_Won, load = ' ';
	char Name[50];
	system("cls");
	Array_Setup(A);
	Get_Name(Name);
	do
	{
		Player_Won = check_win(A);
		if (Player_Won == 'W')
		{
			if (timer == 'T')
			{
				end = time(NULL);
				timer = 'F';
				score = difftime(end, start);
				snprintf(s_score, 10, "%i sec's", score);
				you_won();
				player_Records(Name, s_score);
			}
			break;
		}
		V_Array_setup(A);
		printf("\n\n\n\t\t");
		for (axis_Y = 0;axis_Y < b_;axis_Y++)
		{
			for (axis_X = 0;axis_X < b_;axis_X++)
			{
				if (A[axis_Y][axis_X].real == (b_ * b_))
				{
					printf("[ ]\t");
				}
				else
				{
					printf("%i\t", A[axis_Y][axis_X].real);
				}
			}
			printf("\n\n\n\t\t");
		}
		printf("\n\n");
		if (User_Decision == 'S')
		{
			printf("\t\t\t%c Game State Saved %c\n\n", 16, 17);
			User_Decision = 'T';
		}
		else if (User_Decision == 'L')
		{
			printf("\t\t%c Previous Game State Loaded %c\n\n", 16, 17);
		}
		else if (User_Decision == 'N')
		{
			printf("\t\t%c No Saved Game State Exists %c\n\n", 16, 17);
		}
		else
		{
			printf("\n\n");
		}
		printf("\t\tMovement\tGame State\n\n\t\t%c  = Up\n\tLeft = %c %c = Right\tCtrl + S = Save Game\n\t\t%c  = Down\tCtrl + L = Load Game\n\n\t\tEsc = Quit\n", 24, 27, 26, 25);
		if (timer == 'F')
		{
			start = time(NULL);
			timer = 'T';
		}
		User_Decision = input(A, s, User_Decision, load);
		if (User_Decision == 'F')
		{
			if (timer == 'T')
			{
				end = time(NULL);
				timer = 'F';
				strcpy(s_score, "Quit");
				system("cls");
				player_Records(Name, s_score);
			}
			break;
		}
		else if (User_Decision == 'S')
		{
			load = 'S';
		}
		system("cls");
		printf("\n\n\n");
	}
	while (-1);
}
char Get_Name(char Name[50])
{
	read_records();
	system("cls");
	printf("\n\n\n\t\t");
	printf("Please Write Your Name\n\t\tName:");
	fflush(stdin);
	scanf("%s", Name);
	system("cls");
}
char player_Records(char Name[50], char score[10])
{
	char d[10];
	if (b_ == 3)
	{
		strcpy(d, "Easy");
	}
	else if (b_ == 5)
	{
		strcpy(d, "Normal");
	}
	else if (b_ == 7)
	{
		strcpy(d, "Hard");
	}
	printf("\n\n\n\t\tName: %s\tDifficulty: %s\tTime:  %s", Name, d, score);
	getch();
	write_records(Name, score, d);
	show_records();
}
char write_records(char Name[50], char score[10], char d[10])
{
	FILE *RF;
	char writeToFile[] = "PuzzleGameRecords.txt";
	int i;
	RF = fopen(writeToFile, "w");
	if (RF == 0)
	{
		printf("Error cannot write to file \"GameRecords.txt\"");
	}
	else
	{
		if (Num_P == 0)
		{
			fprintf(RF, "%s\t%s\t%s\n", Name, d, score);
			fprintf(RF, "#\n");
		}
		else
		{
			for (i = 0;i < Num_P;i++)
			{
				fprintf(RF, "%s\t%s%s\n", Players[i].Name, Players[i].Diff, Players[i].score);
			}
			fprintf(RF, "%s\t%s\t%s\n", Name, d, score);
			fprintf(RF, "#\n");
			getch();
			system("cls");
		}
		fclose(RF);
	}
}
char show_records()
{
	int i;
	read_records();
	system("cls");
	printf("\n\n\t\t   High Scores\n\n");
	printf("\t_,-'2_,-'2_,-'2_,-'2_,-'2_,-'2_,-'2_,-'2_,-'2_,-'2_,-'2_,-'2_,-\n\n");
	printf("\t----------------------------------------------------------------\n");
	printf("\tName\t\t\tDifficulty\t\t\tTime\n");
	printf("\t----------------------------------------------------------------\n\n");
	for (i = 0;i < Num_P;i++)
	{
		printf("\t%s\t\t\t%s\t\t\t%s\n", Players[i].Name, Players[i].Diff, Players[i].score);
	}
	printf("\n\n\t_,-'2_,-'2_,-'2_,-'2_,-'2_,-'2_,-'2_,-'2_,-'2_,-'2_,-'2_,-\n\n");
	getch();
	system("cls");
}
char read_records()
{
	FILE *RF;
	char readFromFile[] = "PuzzleGameRecords.txt";
	int num_p = 0;
	char Name[50];
	char score[30];
	char Diff[30];
	RF = fopen(readFromFile, "r");
	if (RF == 0)
	{
	}
	else
	{
		do
		{
			fscanf(RF, "%s", Name);
			num_p++;
			if (strcmp(Name, "#") == 0)
			{
				break;
			}
			fscanf(RF, "%s", Diff);
			fscanf(RF, "%[^\n]", score);
			strcpy(Players[num_p].Name, Name);
			strcpy(Players[num_p].Diff, Diff);
			strcpy(Players[num_p].score, score);
		}
		while (strcmp(Name, "#") != 0);
		Num_P = num_p;
	}
	fclose(RF);
}
char check_win(board A[b_][b_])
{
	int max, axis_Y, axis_X, a = 0, check = 0;
	char Player_Won = 'F';
	board win[b_][b_];
	max = b_ * b_;
	for (axis_Y = 0;axis_Y < b_;axis_Y++)
	{
		for (axis_X = 0;axis_X < b_;axis_X++)
		{
			a++;
			win[axis_Y][axis_X].real = a;
		}
	}
	for (axis_Y = 0;axis_Y < b_;axis_Y++)
	{
		for (axis_X = 0;axis_X < b_;axis_X++)
		{
			if (A[axis_Y][axis_X].real == win[axis_Y][axis_X].real)
			{
				check++;
				if (check == max)
				{
					Player_Won = 'T';
				}
			}
		}
	}
	if (Player_Won == 'T')
	{
		return('W');
	}
}
char you_won()
{
	printf("\n\n\n\t\tCONGRADULATIONS\n\n\t\tYou Won!\n\n\n");
	system("pause");
}
int Array_Setup(board A[b_][b_])
{
	int num;
	int axis_X, axis_Y;
	char val = 'T';
	for (axis_Y = 0;axis_Y < b_;axis_Y++)
	{
		for (axis_X = 0;axis_X < b_;axis_X++)
		{
			A[axis_Y][axis_X].real = 0;
		}
	}
	for (axis_Y = 0;axis_Y < b_;axis_Y++)
	{
		for (axis_X = 0;axis_X < b_;axis_X++)
		{
			do
			{
				num = Get_Ran();
				val = Check_for_repeat(num, A);
				if (val == 'T')
				{
					A[axis_Y][axis_X].real = num;
					break;
				}
			}
			while (val = 'T');
		}
	}
	V_Array_setup(A);
	printf("\n\n\n\n\n");
}
char Check_for_repeat(int num, board A[b_][b_])
{
	int axis_X, axis_Y;
	for (axis_X = 0;axis_X < b_;axis_X++)
	{
		for (axis_Y = 0;axis_Y < b_;axis_Y++)
		{
			if (A[axis_Y][axis_X].real == num)
				return('F');
		}
	}
	return('T');
}
int Get_Ran()
{
	int i;
	int min = 1, max = b_ * b_;
	static int init = 0;
	if (init == 0)
	{
		srand((unsigned)time(NULL));
		init = 1;
	}
	i = ( rand() % (max - min + 1) + min );
}
char V_Array_setup(board A[b_][b_])
{
	int axis_X, axis_Y, axis_x_val_storage, axis_y_val_storage;
	char m_sx[2] = {"TT"}, m_sy[2] = {"TT"};
	for (axis_Y = 0;axis_Y < b_;axis_Y++)
	{
		for (axis_X = 0;axis_X < b_;axis_X++)
		{
			A[axis_Y][axis_X].virt = 'x';
		}
	}
	for (axis_Y = 0;axis_Y < b_;axis_Y++)
	{
		for (axis_X = 0;axis_X < b_;axis_X++)
		{
			if (A[axis_Y][axis_X].real == (b_ * b_))
			{
				A[axis_Y][axis_X].virt = '-';
				axis_x_val_storage = axis_X;
				axis_y_val_storage = axis_Y;
			}
		}
	}
	sx_inc(axis_x_val_storage, m_sx);
	sy_inc(axis_y_val_storage, m_sy);
	if (m_sx[0] == 'T')
	{
		A[axis_y_val_storage][axis_x_val_storage - 1].virt = 'A';
	}
	if (m_sx[1] == 'T')
	{
		A[axis_y_val_storage][axis_x_val_storage + 1].virt = 'D';
	}
	if (m_sy[0] == 'T')
	{
		A[axis_y_val_storage - 1][axis_x_val_storage].virt = 'W';
	}
	if (m_sy[1] == 'T')
	{
		A[axis_y_val_storage + 1][axis_x_val_storage].virt = 'S';
	}
}
char sx_inc(int axis_x_val_storage, char m_sx[2])
{
	if (axis_x_val_storage == 0)
	{
		m_sx[0] = 'F';
		m_sx[1] = 'T';
	}
	else if (axis_x_val_storage == b_ - 1)
	{
		m_sx[1] = 'F';
		m_sx[0] = 'T';
	}
	else
	{
		m_sx = "TT";
	}
}
char sy_inc(int axis_y_val_storage, char m_sy[2])
{
	if (axis_y_val_storage == 0)
	{
		m_sy[0] = 'F';
		m_sy[1] = 'T';
	}
	else if (axis_y_val_storage == b_ - 1)
	{
		m_sy[1] = 'F';
		m_sy[0] = 'T';
	}
	else
	{
		m_sy = "TT";
	}
}
char printV(board A[b_][b_])
{
	int axis_X, axis_Y;
	printf("\t\t");
	for (axis_Y = 0;axis_Y < b_;axis_Y++)
	{
		for (axis_X = 0;axis_X < b_;axis_X++)
		{
			printf("%c\t", A[axis_Y][axis_X].virt);
		}
		printf("\n\n\n\t\t");
	}
}
/* User input*/
char input(board a[b_][b_], board s[b_][b_], char User_Decision, char load)
{
	char W = 'F', A = 'F', S = 'F', D = 'F';
	int in, axis_X, axis_Y, axis_x_val_storage, axis_y_val_storage, temp;
	fflush(stdin);
	in = getch();
	for (axis_Y = 0;axis_Y < b_;axis_Y++)
	{
		for (axis_X = 0;axis_X < b_;axis_X++)
		{
			if (a[axis_Y][axis_X].virt == '-')
			{
				axis_y_val_storage = axis_Y;
				axis_x_val_storage = axis_X;
			}
			if (a[axis_Y][axis_X].virt == 'W')
			{
				W = 'T';
			}
			if (a[axis_Y][axis_X].virt == 'A')
			{
				A = 'T';
			}
			if (a[axis_Y][axis_X].virt == 'S')
			{
				S = 'T';
			}
			if (a[axis_Y][axis_X].virt == 'D')
			{
				D = 'T';
			}
		}
	}
	if (in == 224)
	{
		in = getch();
		if (in == 72)
		{
			if (W == 'T')
			{
				temp = a[axis_y_val_storage][axis_x_val_storage].real;
				a[axis_y_val_storage][axis_x_val_storage].real = a[axis_y_val_storage - 1][axis_x_val_storage].real;
				a[axis_y_val_storage - 1][axis_x_val_storage].real = temp;
			}
		}
		else if (in == 80)
		{
			if (S == 'T')
			{
				temp = a[axis_y_val_storage][axis_x_val_storage].real;
				a[axis_y_val_storage][axis_x_val_storage].real = a[axis_y_val_storage + 1][axis_x_val_storage].real;
				a[axis_y_val_storage + 1][axis_x_val_storage].real = temp;
			}
		}
		else if (in == 75)
		{
			if (A == 'T')
			{
				temp = a[axis_y_val_storage][axis_x_val_storage].real;
				a[axis_y_val_storage][axis_x_val_storage].real = a[axis_y_val_storage][axis_x_val_storage - 1].real;
				a[axis_y_val_storage][axis_x_val_storage - 1].real = temp;
			}
		}
		else if (in == 77)
		{
			if (D == 'T')
			{
				temp = a[axis_y_val_storage][axis_x_val_storage].real;
				a[axis_y_val_storage][axis_x_val_storage].real = a[axis_y_val_storage][axis_x_val_storage + 1].real;
				a[axis_y_val_storage][axis_x_val_storage + 1].real = temp;
			}
		}
	}
	else if (in == 27)
	{
		return('F');
	}
	else if (in == 19)
	{
		/*Save State*/
		for (axis_Y = 0;axis_Y < b_;axis_Y++)
		{
			for (axis_X = 0;axis_X < b_;axis_X++)
			{
				s[axis_Y][axis_X].real = a[axis_Y][axis_X].real;
			}
		}
		return('S');
	}
	else if (in == 12)
	{
		if (load == 'S')
		{
			/*Load the Saved State*/
			for (axis_Y = 0;axis_Y < b_;axis_Y++)
			{
				for (axis_X = 0;axis_X < b_;axis_X++)
				{
					a[axis_Y][axis_X].real = s[axis_Y][axis_X].real;
				}
			}
			return('L');
		}
		else
		{
			return('N');
		}
	}
	return ('T');
}
char menu()
{
	char menu[5];
	menu_arrange(menu);
	do
	{
		print_menu(menu);
		user_input(menu);
		system("cls");
	}
	while (-1);
}
char menu_arrange(char menu[5])
{
	int axis_Y;
	for (axis_Y = 0;axis_Y < 5; axis_Y++)
	{
		menu[axis_Y] = 'x';
	}
	menu[0] = '+';
}
char print_menu(char menu[5])
{
	int axis_Y;
	axis_Y = menu_search(menu);
	printf("\n\n");
	Welcome();
	printf("\n\n");
	printf("\n\t_,-'2_,-'2_,-'2_,-'2_,-'2_,-'2_,-'2_,-'2_,-'2_,-'2_,-'2_,-'2_,-\n\n\n");
	if (axis_Y == 0)
	{
		printf("\t\t\t%c[ START GAME ]\n\n", 16);
	}
	else
	{
		printf("\t\t\t Start Game\n\n");
	}
	if ( axis_Y == 1)
	{
		printf("\t\t\t%c[ OPTION ]\n\n", 16);
	}
	else
	{
		printf("\t\t\t Option\n\n");
	}
	if ( axis_Y == 2)
	{
		printf("\t\t\t%c[ ABOUT ]\n\n", 16);
	}
	else
	{
		printf("\t\t\t About\n\n");
	}
	if ( axis_Y == 3)
	{
		printf("\t\t\t%c[ SCORES ]\n\n", 16);
	}
	else
	{
		printf("\t\t\t Scores\n\n");
	}
	if ( axis_Y == 4)
	{
		printf("\t\t\t%c[ EXIT ]\n\n", 16);
	}
	else
	{
		printf("\t\t\t Exit\n\n");
	}
	printf("\n\t\t\t\t\t\tPress %c and %c to navigate.\n\n\t\t\t\t\t\tPress Enter to Select.\n",24,25);
	printf("\n\t_,-'2_,-'2_,-'2_,-'2_,-'2_,-'2_,-'2_,-'2_,-'2_,-'2_,-'2_,-'2_,-\n\n\n");
}
char Welcome()
{
	printf("`7MMF'     A     `7MF'     `7MM \n");
	printf("  `MA     ,MA     ,V         MM \n");
	printf("   VM:   ,VVM:   ,V .gP\"Ya   MM  ,p6\"bo   ,pW\"Wq.`7MMpMMMb.pMMMb.  .gP\"Ya\n");
	printf("    MM.  M' MM.  M',M'   Yb  MM 6M'  OO  6W'   `Wb MM    MM    MM ,M'   Yb\n");
	printf("    `MM A'  `MM A' 8M\"\"\"\"\"\"  MM 8M       8M     M8 MM    MM    MM 8M\"\"\"\"\"\"\n");
	printf("     :MM;    :MM;  YM.    ,  MM YM.    , YA.   ,A9 MM    MM    MM YM.    ,\n");
	printf("      VF      VF    `Mbmmd'.JMML.YMbmd'   `Ybmd9'.JMML  JMML  JMML.`Mbmmd'\n");
}
int menu_search(char menu[5])
{
	int axis_Y;
	for (axis_Y = 0;axis_Y < 5;axis_Y++)
	{
		if (menu[axis_Y] == '+')
		{
			return(axis_Y);
		}
	}
}
char user_input(char menu[4])
{
	int User_Input, axis_Y = menu_search(menu);
	User_Input = getch();
	
	if(User_Input == 224)
	{
	User_Input = getch();
	if ( User_Input == 72)
	{
		if ( axis_Y > 0 )
		{
			menu[axis_Y] = 'x';
			menu[axis_Y - 1] = '+';
		}
	}
	else if ( User_Input == 80 )
	{
		if (axis_Y < 4)
		{
			menu[axis_Y] = 'x';
			menu[axis_Y + 1] = '+';
		}
	}
	}
	else if ( User_Input == 27)
	{
		exit(-1);
	}
	else if (User_Input == 96)
	{
		char pass[20];
		system("cls");
		printf("\n\n\n\t\tPlease Enter Password to Enter Developer Mode.\n\n\t\tPass:\t");
		fflush(stdin);
		scanf("%s", pass);
		if (strcmp(pass, "devmode") == 0)
		{
			system("cls");
			printf("\n\n\n\t\tPassword Accepted!\n\n\t\tAccess Granted!\n\n\n");
			system("pause");
			system("cls");
			Dev_mode();
		}
		else
		{
			system("cls");
			printf("\n\n\n\t\tPassword Not Accepted!\n\n\t\tAccess Cannot be Granted!\n\n\n");
			system("pause");
		}
	}
	else if ( User_Input == 13 )
	{
		if ( axis_Y == 0 )
		{
			start_game();
		}
		else if ( axis_Y == 1 )
		{
			option();
		}
		else if ( axis_Y == 2 )
		{
			about();
		}
		else if ( axis_Y == 3 )
		{
			show_records();
		}
		else if ( axis_Y == 4 )
		{
			exit(-1);
		}
	}
}
char option()
{
	char user_Selection[2];
	char User_Input;
	char Dificlty_Choice[30];
	int D = 1, C = 1, symbol;
	user_Selection[1] = 'T';
	user_Selection[0] = 'F';
	if (b_ == 3)
	{
		D = 1;
	}
	else if (b_ == 5)
	{
		D = 2;
	}
	else if (b_ == 7)
	{
		D = 3;
	}
	do
	{
		if (D == 1)
		{
			strcpy(Dificlty_Choice, "Easy - 3 x 3");
			symbol = 176;
			b_ = 3;
		}
		else if (D == 2)
		{
			strcpy(Dificlty_Choice, "Normal - 5 x 5");
			symbol = 177;
			b_ = 5;
		}
		else if (D == 3)
		{
			strcpy(Dificlty_Choice, "Hard - 7 x 7");
			symbol = 178;
			b_ = 7;
		}
		system("cls");
		printf("\n\t_,-'2_,-'2_,-'2_,-'2_,-'2_,-'2_,-'2_,-'2_,-'2_,-'2_,-'2_,-'2_,-\n\n\n");
		printf("\t-------------------\n");
		printf("\t Select Difficulty\n");
		printf("\t-------------------\n\n");
		if (user_Selection[0] == 'F')
		{
			printf("\t %c[ DIFFICULTY ] - %c %s\n\n", 16, symbol, Dificlty_Choice);
		}
		else
		{
			printf("\tDifficulty\n\n");
		}
		if (user_Selection[1] == 'F')
		{
			printf("\t %c[ COLOUR CONTROL SYSTEM ]\n\n", 16);
		}
		else
		{
			printf("\tColour Control System\n\n");
		}
		printf("\t\t\t\t\t\tPress %c and %c to navigate.\n\n\t\t\t\t\t\tPress Enter to Select.\n\n\t\t\t\t\t\tPress Esc to Go Back.\n\n\n\n",24,25);
		printf("\n\n\t_,-'2_,-'2_,-'2_,-'2_,-'2_,-'2_,-'2_,-'2_,-'2_,-'2_,-'2_,-'2_,-\n\n");
		User_Input = getch();
		
			if (User_Input == 72 )
			{
				if ( user_Selection[0] == 'T')
				{
					user_Selection[0] = 'F';
					user_Selection[1] = 'T';
				}
			}
			else if (User_Input == 80)
			{
				if ( user_Selection[1] == 'T' )
				{
					user_Selection[0] = 'T';
					user_Selection[1] = 'F';
				}
			}
		
		else if (User_Input == 27)
		{
			return(' ');
		}
		else if (User_Input == 13)
		{
			if (user_Selection[1] == 'T')
			{
				if (D == 3)
				{
					D = 1;
				}
				else
				{
					D++;
				}
			}
			else if (user_Selection[0] == 'T')
			{
				/*------------------------------------------ */
				system("cls");
				printf("\n\n\t\tWelcome to the \n\t\tMaster Colour Control System v.2.0.1\n\t\tMade by Eshan Shafeeq!\n\n\t\tPress Any Key to continue with the Application");
				Master_Colour_Control_System_v_2_0_1();
			}
		}
	}
	while (-1);
}
char about()
{
	system("cls");
	printf("\n");
	printf("\t  .-----------------------------------------------------------------.\n");
	printf("\t /  .-.                                                         .-.  \\ \n");
	printf("\t|  /   \\                                                       /   \\  |\n");
	printf("\t| |\\_.  | By:Eshan Shafeeq.                                   |    /| |\n");
	printf("\t|\\|  | /| Std ID:*******                                      |\\  | |/|\n");
	printf("\t| `---' |                                                     | `---' |\n");
	printf("\t|       | Introduction to programming                         |       |\n");
	printf("\t|       | Assignment 2011                                     |       |\n");
	printf("\t|       |                                                     |       |\n");
	printf("\t|       |-----------------------------------------------------|       |\n");
	printf("\t\\       |                                                     |       /\n");
	printf("\t \\     /                                                       \\     /\n");
	printf("\t  `---'                                                         `---'\n");
	getch();
	system("cls");
}
char Dev_mode()
{
	int axis_X, axis_Y;
	char in, User_Decision, load;
	board A[b_][b_];
	board s[b_][b_];
	Array_Setup(A);
	do
	{
		V_Array_setup(A);
		printf("\t\t");
		for (axis_Y = 0;axis_Y < b_;axis_Y++)
		{
			for (axis_X = 0;axis_X < b_;axis_X++)
			{
				if (A[axis_Y][axis_X].real == (b_ * b_))
				{
					printf("(%c)\t", 148);
				}
				else
				{
					printf("%i\t", A[axis_Y][axis_X].real);
				}
			}
			printf("\n\n\n\t\t");
		}
		printf("\n\n\n");
		printf("\n\n\n");
		printV(A);
		printf("\n\n\n");
		printf("\n\n\n");
		in = input(A, s, User_Decision, load);
		if (in == 'F')
		{
			break;
		}
		system("cls");
		printf("\n\n\n");
	}
	while (-1);
}
int Master_Colour_Control_System_v_2_0_1()
{
	int input, Color_Bckgrd_Val = 0, Color_Font_Val = 7, temp;
	char Color_Val_Store[3] = "  ";
	char Colour_1[20], Colour_2[20];
	do
	{
		input = getch();
		if (input == 72)
		{
			if (Color_Bckgrd_Val > 0)
			{
				temp = Color_Font_Val;
				temp++;
				if (temp != Color_Bckgrd_Val)
				{
					Color_Bckgrd_Val--;
				}
				else
				{
					if (Color_Bckgrd_Val != 2)
					{
						Color_Bckgrd_Val -= 2;
						if (Color_Bckgrd_Val == -1)
						{
							Color_Bckgrd_Val = 15;
						}
					}
					else
					{
						if (Color_Font_Val != 15)
						{
							Color_Bckgrd_Val = 15;
						}
						else
						{
							Color_Bckgrd_Val = 14;
						}
					}
				}
			}
			else
			{
				if (Color_Font_Val != 15)
				{
					Color_Bckgrd_Val = 15;
				}
				else
				{
					Color_Bckgrd_Val = 14;
				}
			}
		}
		else if (input == 80)
		{
			if (Color_Bckgrd_Val < 15)
			{
				temp = Color_Font_Val;
				temp--;
				if (temp != Color_Bckgrd_Val)
				{
					Color_Bckgrd_Val++;
				}
				else
				{
					if (Color_Bckgrd_Val != 14)
					{
						Color_Bckgrd_Val += 2;
						if (Color_Bckgrd_Val == 16)
						{
							Color_Bckgrd_Val = 0;
						}
					}
					else
					{
						if (Color_Font_Val != 0)
						{
							Color_Bckgrd_Val = 0;
						}
						else
						{
							Color_Bckgrd_Val = 2;
						}
					}
				}
			}
			else
			{
				if (Color_Font_Val != 0)
				{
					Color_Bckgrd_Val = 0;
				}
				else
				{
					Color_Bckgrd_Val = 1;
				}
			}
		}
		else if (input == 75)
		{
			if (Color_Font_Val > 0)
			{
				temp = Color_Bckgrd_Val;
				temp++;
				if (temp != Color_Font_Val)
				{
					Color_Font_Val--;
				}
				else
				{
					if (Color_Font_Val != 2)
					{
						Color_Font_Val -= 2;
						if (Color_Font_Val == -1)
						{
							Color_Font_Val = 15;
						}
					}
					else
					{
						if (Color_Bckgrd_Val != 15)
						{
							Color_Font_Val = 15;
						}
						else
						{
							Color_Font_Val = 14;
						}
					}
				}
			}
			else
			{
				if (Color_Bckgrd_Val != 15)
				{
					Color_Font_Val = 15;
				}
				else
				{
					Color_Font_Val = 14;
				}
			}
		}
		else if (input == 77)
		{
			if (Color_Font_Val < 15)
			{
				temp = Color_Bckgrd_Val;
				temp--;
				if (temp != Color_Font_Val)
				{
					Color_Font_Val++;
				}
				else
				{
					if (Color_Font_Val != 14)
					{
						Color_Font_Val += 2;
						if (Color_Font_Val == 16)
						{
							Color_Font_Val = 0;
						}
					}
					else
					{
						if (Color_Bckgrd_Val != 0)
						{
							Color_Font_Val = 0;
						}
						else
						{
							Color_Font_Val = 1;
						}
					}
				}
			}
			else
			{
				if (Color_Bckgrd_Val != 0)
				{
					Color_Font_Val = 0;
				}
				else
				{
					Color_Font_Val = 1;
				}
			}
		}
		else if (input == 27)
		{
			return (0);
		}
		system("cls");
		printf("\n\n\t\tMaster Colour Control System v.2.0.1\n\n\t\tToggle Between Background Colours using %c And %c\n\t\tToggle Between The Font colour using %c and %c.\n\t\tTo save changes and go back press Esc.\n\n",24,25,27,26);
		colour_Dictionary( Color_Bckgrd_Val, Color_Font_Val, Color_Val_Store);
		Colour_Identifier(Color_Val_Store, Colour_1, Colour_2);
		colour_machine(Color_Val_Store);
	}
	while (input != 81 || input != 113);
	return(0);
}
char Colour_Identifier(char Color_Val_Store[3], char Colour_1[10], char Colour_2[10])
{
	if (Color_Val_Store[0] == '0')
	{
		strcpy(Colour_1, "Black");
	}
	else if (Color_Val_Store[0] == '1')
	{
		strcpy(Colour_1, "Blue");
	}
	else if (Color_Val_Store[0] == '2')
	{
		strcpy(Colour_1, "Green");
	}
	else if (Color_Val_Store[0] == '3')
	{
		strcpy(Colour_1, "Aqua");
	}
	else if (Color_Val_Store[0] == '4')
	{
		strcpy(Colour_1, "Red");
	}
	else if (Color_Val_Store[0] == '5')
	{
		strcpy(Colour_1, "Purple");
	}
	else if (Color_Val_Store[0] == '6')
	{
		strcpy(Colour_1, "Yellow");
	}
	else if (Color_Val_Store[0] == '7')
	{
		strcpy(Colour_1, "White");
	}
	else if (Color_Val_Store[0] == '8')
	{
		strcpy(Colour_1, "Gray");
	}
	else if (Color_Val_Store[0] == '9')
	{
		strcpy(Colour_1, "Light Blue");
	}
	else if (Color_Val_Store[0] == 'A')
	{
		strcpy(Colour_1, "Light Green");
	}
	else if (Color_Val_Store[0] == 'B')
	{
		strcpy(Colour_1, "Light Aqua");
	}
	else if (Color_Val_Store[0] == 'C')
	{
		strcpy(Colour_1, "Light Red");
	}
	else if (Color_Val_Store[0] == 'D')
	{
		strcpy(Colour_1, "Light Purple");
	}
	else if (Color_Val_Store[0] == 'E')
	{
		strcpy(Colour_1, "Light Yellow");
	}
	else if (Color_Val_Store[0] == 'F')
	{
		strcpy(Colour_1, "Bright White");
	}
	/*-----------------------------------*/
	if (Color_Val_Store[1] == '0')
	{
		strcpy(Colour_2, "Black");
	}
	else if (Color_Val_Store[1] == '1')
	{
		strcpy(Colour_2, "Blue");
	}
	else if (Color_Val_Store[1] == '2')
	{
		strcpy(Colour_2, "Green");
	}
	else if (Color_Val_Store[1] == '3')
	{
		strcpy(Colour_2, "Aqua");
	}
	else if (Color_Val_Store[1] == '4')
	{
		strcpy(Colour_2, "Red");
	}
	else if (Color_Val_Store[1] == '5')
	{
		strcpy(Colour_2, "Purple");
	}
	else if (Color_Val_Store[1] == '6')
	{
		strcpy(Colour_2, "Yellow");
	}
	else if (Color_Val_Store[1] == '7')
	{
		strcpy(Colour_2, "White");
	}
	else if (Color_Val_Store[1] == '8')
	{
		strcpy(Colour_2, "Gray");
	}
	else if (Color_Val_Store[1] == '9')
	{
		strcpy(Colour_2, "Light Blue");
	}
	else if (Color_Val_Store[1] == 'A')
	{
		strcpy(Colour_2, "Light Green");
	}
	else if (Color_Val_Store[1] == 'B')
	{
		strcpy(Colour_2, "Light Aqua");
	}
	else if (Color_Val_Store[1] == 'C')
	{
		strcpy(Colour_2, "Light Red");
	}
	else if (Color_Val_Store[1] == 'D')
	{
		strcpy(Colour_2, "Light Purple");
	}
	else if (Color_Val_Store[1] == 'E')
	{
		strcpy(Colour_2, "Light Yellow");
	}
	else if (Color_Val_Store[1] == 'F')
	{
		strcpy(Colour_2, "Bright White");
	}
	printf("\t\tBackground Colour = %s \n\t\tFont Colour = %s\n\n\n", Colour_1, Colour_2);
}
char colour_Dictionary(int a, int b, char Color_Val_Store[3])
{
	if (a == 0)
	{
		Color_Val_Store[0] = '0';
	}
	else if (a == 1)
	{
		Color_Val_Store[0] = '1';
	}
	else if (a == 2)
	{
		Color_Val_Store[0] = '2';
	}
	else if (a == 3)
	{
		Color_Val_Store[0] = '3';
	}
	else if (a == 4)
	{
		Color_Val_Store[0] = '4';
	}
	else if (a == 5)
	{
		Color_Val_Store[0] = '5';
	}
	else if (a == 6)
	{
		Color_Val_Store[0] = '6';
	}
	else if (a == 7)
	{
		Color_Val_Store[0] = '7';
	}
	else if (a == 8)
	{
		Color_Val_Store[0] = '8';
	}
	else if (a == 9)
	{
		Color_Val_Store[0] = '9';
	}
	else if (a == 10)
	{
		Color_Val_Store[0] = 'A';
	}
	else if (a == 11)
	{
		Color_Val_Store[0] = 'B';
	}
	else if (a == 12)
	{
		Color_Val_Store[0] = 'C';
	}
	else if (a == 13)
	{
		Color_Val_Store[0] = 'D';
	}
	else if (a == 14)
	{
		Color_Val_Store[0] = 'E';
	}
	else if (a == 15)
	{
		Color_Val_Store[0] = 'F';
	}
	/*-----------*/
	if (b == 0)
	{
		Color_Val_Store[1] = '0';
	}
	else if (b == 1)
	{
		Color_Val_Store[1] = '1';
	}
	else if (b == 2)
	{
		Color_Val_Store[1] = '2';
	}
	else if (b == 3)
	{
		Color_Val_Store[1] = '3';
	}
	else if (b == 4)
	{
		Color_Val_Store[1] = '4';
	}
	else if (b == 5)
	{
		Color_Val_Store[1] = '5';
	}
	else if (b == 6)
	{
		Color_Val_Store[1] = '6';
	}
	else if (b == 7)
	{
		Color_Val_Store[1] = '7';
	}
	else if (b == 8)
	{
		Color_Val_Store[1] = '8';
	}
	else if (b == 9)
	{
		Color_Val_Store[1] = '9';
	}
	else if (b == 10)
	{
		Color_Val_Store[1] = 'A';
	}
	else if (b == 11)
	{
		Color_Val_Store[1] = 'B';
	}
	else if (b == 12)
	{
		Color_Val_Store[1] = 'C';
	}
	else if (b == 13)
	{
		Color_Val_Store[1] = 'D';
	}
	else if (b == 14)
	{
		Color_Val_Store[1] = 'E';
	}
	else if (b == 15)
	{
		Color_Val_Store[1] = 'F';
	}
}
char colour_machine(char Color_Val_Store[3])
{
	if (strcmp(Color_Val_Store, "01") == 0)
	{
		system("color 01");
	}
	else if (strcmp(Color_Val_Store, "02") == 0)
	{
		system("color 02");
	}
	else if (strcmp(Color_Val_Store, "03") == 0)
	{
		system("color 03");
	}
	else if (strcmp(Color_Val_Store, "04") == 0)
	{
		system("color 04");
	}
	else if (strcmp(Color_Val_Store, "05") == 0)
	{
		system("color 05");
	}
	else if (strcmp(Color_Val_Store, "06") == 0)
	{
		system("color 06");
	}
	else if (strcmp(Color_Val_Store, "07") == 0)
	{
		system("color 07");
	}
	else if (strcmp(Color_Val_Store, "08") == 0)
	{
		system("color 08");
	}
	else if (strcmp(Color_Val_Store, "09") == 0)
	{
		system("color 09");
	}
	else if (strcmp(Color_Val_Store, "0A") == 0)
	{
		system("color 0A");
	}
	else if (strcmp(Color_Val_Store, "0B") == 0)
	{
		system("color 0B");
	}
	else if (strcmp(Color_Val_Store, "0C") == 0)
	{
		system("color 0C");
	}
	else if (strcmp(Color_Val_Store, "0D") == 0)
	{
		system("color 0D");
	}
	else if (strcmp(Color_Val_Store, "0E") == 0)
	{
		system("color 0E");
	}
	else if (strcmp(Color_Val_Store, "0F") == 0)
	{
		system("color 0F");
	}
	else if (strcmp(Color_Val_Store, "10") == 0)
	{
		system("color 10");
	}
	else if (strcmp(Color_Val_Store, "12") == 0)
	{
		system("color 12");
	}
	else if (strcmp(Color_Val_Store, "13") == 0)
	{
		system("color 13");
	}
	else if (strcmp(Color_Val_Store, "14") == 0)
	{
		system("color 14");
	}
	else if (strcmp(Color_Val_Store, "15") == 0)
	{
		system("color 15");
	}
	else if (strcmp(Color_Val_Store, "16") == 0)
	{
		system("color 16");
	}
	else if (strcmp(Color_Val_Store, "17") == 0)
	{
		system("color 17");
	}
	else if (strcmp(Color_Val_Store, "18") == 0)
	{
		system("color 18");
	}
	else if (strcmp(Color_Val_Store, "19") == 0)
	{
		system("color 19");
	}
	else if (strcmp(Color_Val_Store, "1A") == 0)
	{
		system("color 1A");
	}
	else if (strcmp(Color_Val_Store, "1B") == 0)
	{
		system("color 1B");
	}
	else if (strcmp(Color_Val_Store, "1C") == 0)
	{
		system("color 1C");
	}
	else if (strcmp(Color_Val_Store, "1D") == 0)
	{
		system("color 1D");
	}
	else if (strcmp(Color_Val_Store, "1E") == 0)
	{
		system("color 1E");
	}
	else if (strcmp(Color_Val_Store, "1F") == 0)
	{
		system("color 1F");
	}
	else if (strcmp(Color_Val_Store, "20") == 0)
	{
		system("color 20");
	}
	else if (strcmp(Color_Val_Store, "21") == 0)
	{
		system("color 21");
	}
	else if (strcmp(Color_Val_Store, "23") == 0)
	{
		system("color 23");
	}
	else if (strcmp(Color_Val_Store, "24") == 0)
	{
		system("color 24");
	}
	else if (strcmp(Color_Val_Store, "25") == 0)
	{
		system("color 25");
	}
	else if (strcmp(Color_Val_Store, "26") == 0)
	{
		system("color 26");
	}
	else if (strcmp(Color_Val_Store, "27") == 0)
	{
		system("color 27");
	}
	else if (strcmp(Color_Val_Store, "28") == 0)
	{
		system("color 28");
	}
	else if (strcmp(Color_Val_Store, "29") == 0)
	{
		system("color 29");
	}
	else if (strcmp(Color_Val_Store, "2A") == 0)
	{
		system("color 2A");
	}
	else if (strcmp(Color_Val_Store, "2B") == 0)
	{
		system("color 2B");
	}
	else if (strcmp(Color_Val_Store, "2C") == 0)
	{
		system("color 2C");
	}
	else if (strcmp(Color_Val_Store, "2D") == 0)
	{
		system("color 2D");
	}
	else if (strcmp(Color_Val_Store, "2E") == 0)
	{
		system("color 2E");
	}
	else if (strcmp(Color_Val_Store, "2F") == 0)
	{
		system("color 2F");
	}
	else if (strcmp(Color_Val_Store, "30") == 0)
	{
		system("color 30");
	}
	else if (strcmp(Color_Val_Store, "31") == 0)
	{
		system("color 31");
	}
	else if (strcmp(Color_Val_Store, "32") == 0)
	{
		system("color 32");
	}
	else if (strcmp(Color_Val_Store, "34") == 0)
	{
		system("color 34");
	}
	else if (strcmp(Color_Val_Store, "35") == 0)
	{
		system("color 35");
	}
	else if (strcmp(Color_Val_Store, "36") == 0)
	{
		system("color 36");
	}
	else if (strcmp(Color_Val_Store, "37") == 0)
	{
		system("color 37");
	}
	else if (strcmp(Color_Val_Store, "38") == 0)
	{
		system("color 38");
	}
	else if (strcmp(Color_Val_Store, "39") == 0)
	{
		system("color 39");
	}
	else if (strcmp(Color_Val_Store, "3A") == 0)
	{
		system("color 3A");
	}
	else if (strcmp(Color_Val_Store, "3B") == 0)
	{
		system("color 3B");
	}
	else if (strcmp(Color_Val_Store, "3C") == 0)
	{
		system("color 3C");
	}
	else if (strcmp(Color_Val_Store, "3D") == 0)
	{
		system("color 3D");
	}
	else if (strcmp(Color_Val_Store, "3E") == 0)
	{
		system("color 3E");
	}
	else if (strcmp(Color_Val_Store, "3F") == 0)
	{
		system("color 3F");
	}
	else if (strcmp(Color_Val_Store, "40") == 0)
	{
		system("color 40");
	}
	else if (strcmp(Color_Val_Store, "41") == 0)
	{
		system("color 41");
	}
	else if (strcmp(Color_Val_Store, "42") == 0)
	{
		system("color 42");
	}
	else if (strcmp(Color_Val_Store, "43") == 0)
	{
		system("color 43");
	}
	else if (strcmp(Color_Val_Store, "45") == 0)
	{
		system("color 45");
	}
	else if (strcmp(Color_Val_Store, "46") == 0)
	{
		system("color 46");
	}
	else if (strcmp(Color_Val_Store, "47") == 0)
	{
		system("color 47");
	}
	else if (strcmp(Color_Val_Store, "48") == 0)
	{
		system("color 48");
	}
	else if (strcmp(Color_Val_Store, "49") == 0)
	{
		system("color 49");
	}
	else if (strcmp(Color_Val_Store, "4A") == 0)
	{
		system("color 4A");
	}
	else if (strcmp(Color_Val_Store, "4B") == 0)
	{
		system("color 4B");
	}
	else if (strcmp(Color_Val_Store, "4C") == 0)
	{
		system("color 4C");
	}
	else if (strcmp(Color_Val_Store, "4D") == 0)
	{
		system("color 4D");
	}
	else if (strcmp(Color_Val_Store, "4E") == 0)
	{
		system("color 4E");
	}
	else if (strcmp(Color_Val_Store, "4F") == 0)
	{
		system("color 4F");
	}
	else if (strcmp(Color_Val_Store, "50") == 0)
	{
		system("color 50");
	}
	else if (strcmp(Color_Val_Store, "51") == 0)
	{
		system("color 51");
	}
	else if (strcmp(Color_Val_Store, "52") == 0)
	{
		system("color 52");
	}
	else if (strcmp(Color_Val_Store, "53") == 0)
	{
		system("color 53");
	}
	else if (strcmp(Color_Val_Store, "54") == 0)
	{
		system("color 54");
	}
	else if (strcmp(Color_Val_Store, "56") == 0)
	{
		system("color 56");
	}
	else if (strcmp(Color_Val_Store, "57") == 0)
	{
		system("color 57");
	}
	else if (strcmp(Color_Val_Store, "58") == 0)
	{
		system("color 58");
	}
	else if (strcmp(Color_Val_Store, "59") == 0)
	{
		system("color 59");
	}
	else if (strcmp(Color_Val_Store, "5A") == 0)
	{
		system("color 5A");
	}
	else if (strcmp(Color_Val_Store, "5B") == 0)
	{
		system("color 5B");
	}
	else if (strcmp(Color_Val_Store, "5C") == 0)
	{
		system("color 5C");
	}
	else if (strcmp(Color_Val_Store, "5D") == 0)
	{
		system("color 5D");
	}
	else if (strcmp(Color_Val_Store, "5E") == 0)
	{
		system("color 5E");
	}
	else if (strcmp(Color_Val_Store, "5F") == 0)
	{
		system("color 5F");
	}
	else if (strcmp(Color_Val_Store, "60") == 0)
	{
		system("color 60");
	}
	else if (strcmp(Color_Val_Store, "61") == 0)
	{
		system("color 61");
	}
	else if (strcmp(Color_Val_Store, "62") == 0)
	{
		system("color 62");
	}
	else if (strcmp(Color_Val_Store, "63") == 0)
	{
		system("color 63");
	}
	else if (strcmp(Color_Val_Store, "64") == 0)
	{
		system("color 64");
	}
	else if (strcmp(Color_Val_Store, "65") == 0)
	{
		system("color 65");
	}
	else if (strcmp(Color_Val_Store, "67") == 0)
	{
		system("color 67");
	}
	else if (strcmp(Color_Val_Store, "68") == 0)
	{
		system("color 68");
	}
	else if (strcmp(Color_Val_Store, "69") == 0)
	{
		system("color 69");
	}
	else if (strcmp(Color_Val_Store, "6A") == 0)
	{
		system("color 6A");
	}
	else if (strcmp(Color_Val_Store, "6B") == 0)
	{
		system("color 6B");
	}
	else if (strcmp(Color_Val_Store, "6C") == 0)
	{
		system("color 6C");
	}
	else if (strcmp(Color_Val_Store, "6D") == 0)
	{
		system("color 6D");
	}
	else if (strcmp(Color_Val_Store, "6E") == 0)
	{
		system("color 6E");
	}
	else if (strcmp(Color_Val_Store, "6F") == 0)
	{
		system("color 6F");
	}
	else if (strcmp(Color_Val_Store, "70") == 0)
	{
		system("color 70");
	}
	else if (strcmp(Color_Val_Store, "71") == 0)
	{
		system("color 71");
	}
	else if (strcmp(Color_Val_Store, "72") == 0)
	{
		system("color 72");
	}
	else if (strcmp(Color_Val_Store, "73") == 0)
	{
		system("color 73");
	}
	else if (strcmp(Color_Val_Store, "74") == 0)
	{
		system("color 74");
	}
	else if (strcmp(Color_Val_Store, "75") == 0)
	{
		system("color 75");
	}
	else if (strcmp(Color_Val_Store, "76") == 0)
	{
		system("color 76");
	}
	else if (strcmp(Color_Val_Store, "78") == 0)
	{
		system("color 78");
	}
	else if (strcmp(Color_Val_Store, "79") == 0)
	{
		system("color 79");
	}
	else if (strcmp(Color_Val_Store, "7A") == 0)
	{
		system("color 7A");
	}
	else if (strcmp(Color_Val_Store, "7B") == 0)
	{
		system("color 7B");
	}
	else if (strcmp(Color_Val_Store, "7C") == 0)
	{
		system("color 7C");
	}
	else if (strcmp(Color_Val_Store, "7D") == 0)
	{
		system("color 7D");
	}
	else if (strcmp(Color_Val_Store, "7E") == 0)
	{
		system("color 7E");
	}
	else if (strcmp(Color_Val_Store, "7F") == 0)
	{
		system("color 7F");
	}
	else if (strcmp(Color_Val_Store, "80") == 0)
	{
		system("color 80");
	}
	else if (strcmp(Color_Val_Store, "81") == 0)
	{
		system("color 81");
	}
	else if (strcmp(Color_Val_Store, "82") == 0)
	{
		system("color 82");
	}
	else if (strcmp(Color_Val_Store, "83") == 0)
	{
		system("color 83");
	}
	else if (strcmp(Color_Val_Store, "84") == 0)
	{
		system("color 84");
	}
	else if (strcmp(Color_Val_Store, "85") == 0)
	{
		system("color 85");
	}
	else if (strcmp(Color_Val_Store, "86") == 0)
	{
		system("color 86");
	}
	else if (strcmp(Color_Val_Store, "87") == 0)
	{
		system("color 87");
	}
	else if (strcmp(Color_Val_Store, "89") == 0)
	{
		system("color 89");
	}
	else if (strcmp(Color_Val_Store, "8A") == 0)
	{
		system("color 8A");
	}
	else if (strcmp(Color_Val_Store, "8B") == 0)
	{
		system("color 8B");
	}
	else if (strcmp(Color_Val_Store, "8C") == 0)
	{
		system("color 8C");
	}
	else if (strcmp(Color_Val_Store, "8D") == 0)
	{
		system("color 8D");
	}
	else if (strcmp(Color_Val_Store, "8E") == 0)
	{
		system("color 8E");
	}
	else if (strcmp(Color_Val_Store, "8F") == 0)
	{
		system("color 8F");
	}
	else if (strcmp(Color_Val_Store, "90") == 0)
	{
		system("color 90");
	}
	else if (strcmp(Color_Val_Store, "91") == 0)
	{
		system("color 91");
	}
	else if (strcmp(Color_Val_Store, "92") == 0)
	{
		system("color 92");
	}
	else if (strcmp(Color_Val_Store, "93") == 0)
	{
		system("color 93");
	}
	else if (strcmp(Color_Val_Store, "94") == 0)
	{
		system("color 94");
	}
	else if (strcmp(Color_Val_Store, "95") == 0)
	{
		system("color 95");
	}
	else if (strcmp(Color_Val_Store, "96") == 0)
	{
		system("color 96");
	}
	else if (strcmp(Color_Val_Store, "97") == 0)
	{
		system("color 97");
	}
	else if (strcmp(Color_Val_Store, "98") == 0)
	{
		system("color 98");
	}
	else if (strcmp(Color_Val_Store, "9A") == 0)
	{
		system("color 9A");
	}
	else if (strcmp(Color_Val_Store, "9B") == 0)
	{
		system("color 9B");
	}
	else if (strcmp(Color_Val_Store, "9C") == 0)
	{
		system("color 9C");
	}
	else if (strcmp(Color_Val_Store, "9D") == 0)
	{
		system("color 9D");
	}
	else if (strcmp(Color_Val_Store, "9E") == 0)
	{
		system("color 9E");
	}
	else if (strcmp(Color_Val_Store, "9F") == 0)
	{
		system("color 9F");
	}
	else if (strcmp(Color_Val_Store, "A0") == 0)
	{
		system("color A0");
	}
	else if (strcmp(Color_Val_Store, "A1") == 0)
	{
		system("color A1");
	}
	else if (strcmp(Color_Val_Store, "A2") == 0)
	{
		system("color A2");
	}
	else if (strcmp(Color_Val_Store, "A3") == 0)
	{
		system("color A3");
	}
	else if (strcmp(Color_Val_Store, "A4") == 0)
	{
		system("color A4");
	}
	else if (strcmp(Color_Val_Store, "A5") == 0)
	{
		system("color A5");
	}
	else if (strcmp(Color_Val_Store, "A6") == 0)
	{
		system("color A6");
	}
	else if (strcmp(Color_Val_Store, "A7") == 0)
	{
		system("color A7");
	}
	else if (strcmp(Color_Val_Store, "A8") == 0)
	{
		system("color A8");
	}
	else if (strcmp(Color_Val_Store, "A9") == 0)
	{
		system("color A9");
	}
	else if (strcmp(Color_Val_Store, "AA") == 0)
	{
		system("color AA");
	}
	else if (strcmp(Color_Val_Store, "AB") == 0)
	{
		system("color AB");
	}
	else if (strcmp(Color_Val_Store, "AC") == 0)
	{
		system("color AC");
	}
	else if (strcmp(Color_Val_Store, "AD") == 0)
	{
		system("color AD");
	}
	else if (strcmp(Color_Val_Store, "AE") == 0)
	{
		system("color AE");
	}
	else if (strcmp(Color_Val_Store, "AF") == 0)
	{
		system("color AF");
	}
	else if (strcmp(Color_Val_Store, "B0") == 0)
	{
		system("color B0");
	}
	else if (strcmp(Color_Val_Store, "B1") == 0)
	{
		system("color B1");
	}
	else if (strcmp(Color_Val_Store, "B2") == 0)
	{
		system("color B2");
	}
	else if (strcmp(Color_Val_Store, "B3") == 0)
	{
		system("color B3");
	}
	else if (strcmp(Color_Val_Store, "B4") == 0)
	{
		system("color B4");
	}
	else if (strcmp(Color_Val_Store, "B5") == 0)
	{
		system("color B5");
	}
	else if (strcmp(Color_Val_Store, "B6") == 0)
	{
		system("color B6");
	}
	else if (strcmp(Color_Val_Store, "B7") == 0)
	{
		system("color B7");
	}
	else if (strcmp(Color_Val_Store, "B8") == 0)
	{
		system("color B8");
	}
	else if (strcmp(Color_Val_Store, "B9") == 0)
	{
		system("color B9");
	}
	else if (strcmp(Color_Val_Store, "BA") == 0)
	{
		system("color BA");
	}
	else if (strcmp(Color_Val_Store, "BB") == 0)
	{
		system("color BB");
	}
	else if (strcmp(Color_Val_Store, "BC") == 0)
	{
		system("color BC");
	}
	else if (strcmp(Color_Val_Store, "BD") == 0)
	{
		system("color BD");
	}
	else if (strcmp(Color_Val_Store, "BE") == 0)
	{
		system("color BE");
	}
	else if (strcmp(Color_Val_Store, "BF") == 0)
	{
		system("color BF");
	}
	else if (strcmp(Color_Val_Store, "C0") == 0)
	{
		system("color C0");
	}
	else if (strcmp(Color_Val_Store, "C1") == 0)
	{
		system("color C1");
	}
	else if (strcmp(Color_Val_Store, "C2") == 0)
	{
		system("color C2");
	}
	else if (strcmp(Color_Val_Store, "C3") == 0)
	{
		system("color C3");
	}
	else if (strcmp(Color_Val_Store, "C4") == 0)
	{
		system("color C4");
	}
	else if (strcmp(Color_Val_Store, "C5") == 0)
	{
		system("color C5");
	}
	else if (strcmp(Color_Val_Store, "C6") == 0)
	{
		system("color C6");
	}
	else if (strcmp(Color_Val_Store, "C7") == 0)
	{
		system("color C7");
	}
	else if (strcmp(Color_Val_Store, "C8") == 0)
	{
		system("color C8");
	}
	else if (strcmp(Color_Val_Store, "C9") == 0)
	{
		system("color C9");
	}
	else if (strcmp(Color_Val_Store, "CA") == 0)
	{
		system("color CA");
	}
	else if (strcmp(Color_Val_Store, "CB") == 0)
	{
		system("color CB");
	}
	else if (strcmp(Color_Val_Store, "CC") == 0)
	{
		system("color CC");
	}
	else if (strcmp(Color_Val_Store, "CD") == 0)
	{
		system("color CD");
	}
	else if (strcmp(Color_Val_Store, "CE") == 0)
	{
		system("color CE");
	}
	else if (strcmp(Color_Val_Store, "CF") == 0)
	{
		system("color CF");
	}
	else if (strcmp(Color_Val_Store, "D0") == 0)
	{
		system("color D0");
	}
	else if (strcmp(Color_Val_Store, "D1") == 0)
	{
		system("color D1");
	}
	else if (strcmp(Color_Val_Store, "D2") == 0)
	{
		system("color D2");
	}
	else if (strcmp(Color_Val_Store, "D3") == 0)
	{
		system("color D3");
	}
	else if (strcmp(Color_Val_Store, "D4") == 0)
	{
		system("color D4");
	}
	else if (strcmp(Color_Val_Store, "D5") == 0)
	{
		system("color D5");
	}
	else if (strcmp(Color_Val_Store, "D6") == 0)
	{
		system("color D6");
	}
	else if (strcmp(Color_Val_Store, "D7") == 0)
	{
		system("color D7");
	}
	else if (strcmp(Color_Val_Store, "D8") == 0)
	{
		system("color D8");
	}
	else if (strcmp(Color_Val_Store, "D9") == 0)
	{
		system("color D9");
	}
	else if (strcmp(Color_Val_Store, "DA") == 0)
	{
		system("color DA");
	}
	else if (strcmp(Color_Val_Store, "DB") == 0)
	{
		system("color DB");
	}
	else if (strcmp(Color_Val_Store, "DC") == 0)
	{
		system("color DC");
	}
	else if (strcmp(Color_Val_Store, "DD") == 0)
	{
		system("color DD");
	}
	else if (strcmp(Color_Val_Store, "DE") == 0)
	{
		system("color DE");
	}
	else if (strcmp(Color_Val_Store, "DF") == 0)
	{
		system("color DF");
	}
	else if (strcmp(Color_Val_Store, "E0") == 0)
	{
		system("color E0");
	}
	else if (strcmp(Color_Val_Store, "E1") == 0)
	{
		system("color E1");
	}
	else if (strcmp(Color_Val_Store, "E2") == 0)
	{
		system("color E2");
	}
	else if (strcmp(Color_Val_Store, "E3") == 0)
	{
		system("color E3");
	}
	else if (strcmp(Color_Val_Store, "E4") == 0)
	{
		system("color E4");
	}
	else if (strcmp(Color_Val_Store, "E5") == 0)
	{
		system("color E5");
	}
	else if (strcmp(Color_Val_Store, "E6") == 0)
	{
		system("color E6");
	}
	else if (strcmp(Color_Val_Store, "E7") == 0)
	{
		system("color E7");
	}
	else if (strcmp(Color_Val_Store, "E8") == 0)
	{
		system("color E8");
	}
	else if (strcmp(Color_Val_Store, "E9") == 0)
	{
		system("color E9");
	}
	else if (strcmp(Color_Val_Store, "EA") == 0)
	{
		system("color EA");
	}
	else if (strcmp(Color_Val_Store, "EB") == 0)
	{
		system("color EB");
	}
	else if (strcmp(Color_Val_Store, "EC") == 0)
	{
		system("color EC");
	}
	else if (strcmp(Color_Val_Store, "ED") == 0)
	{
		system("color ED");
	}
	else if (strcmp(Color_Val_Store, "EE") == 0)
	{
		system("color EE");
	}
	else if (strcmp(Color_Val_Store, "EF") == 0)
	{
		system("color EF");
	}
	else if (strcmp(Color_Val_Store, "F0") == 0)
	{
		system("color F0");
	}
	else if (strcmp(Color_Val_Store, "F1") == 0)
	{
		system("color F1");
	}
	else if (strcmp(Color_Val_Store, "F2") == 0)
	{
		system("color F2");
	}
	else if (strcmp(Color_Val_Store, "F3") == 0)
	{
		system("color F3");
	}
	else if (strcmp(Color_Val_Store, "F4") == 0)
	{
		system("color F4");
	}
	else if (strcmp(Color_Val_Store, "F5") == 0)
	{
		system("color F5");
	}
	else if (strcmp(Color_Val_Store, "F6") == 0)
	{
		system("color F6");
	}
	else if (strcmp(Color_Val_Store, "F7") == 0)
	{
		system("color F7");
	}
	else if (strcmp(Color_Val_Store, "F8") == 0)
	{
		system("color F8");
	}
	else if (strcmp(Color_Val_Store, "F9") == 0)
	{
		system("color F9");
	}
	else if (strcmp(Color_Val_Store, "FA") == 0)
	{
		system("color FA");
	}
	else if (strcmp(Color_Val_Store, "FB") == 0)
	{
		system("color FB");
	}
	else if (strcmp(Color_Val_Store, "FC") == 0)
	{
		system("color FC");
	}
	else if (strcmp(Color_Val_Store, "FD") == 0)
	{
		system("color FD");
	}
	else if (strcmp(Color_Val_Store, "FE") == 0)
	{
		system("color FE");
	}
	else if (strcmp(Color_Val_Store, "FF") == 0)
	{
		system("color FF");
	}
}

