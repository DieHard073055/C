#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<conio.h>
typedef struct
{
	char virt; /* Virtual Array Slot */
	int real; /* Real Array Slot*/
}board;
int b_ = 3;
int Get_Ran();
int Array_Setup(board A[b_][b_]);
char Check_for_repeat(int num, board A[b_][b_]);
char V_Array_setup(board A[b_][b_]);
char sx_inc(int sx, char m_sx[2]);
char sy_inc(int sy, char m_sx[2]);
char printV(board A[b_][b_]);
char input(board a[b_][b_]);
char menu();
char menu_arrange(char menu[4]);
char print_menu(char menu[4]);
int menu_search(char menu[4]);
char user_input(char menu[4]);
char option();
int Color_changer();
char Welcome();
char about();
char start_game();
char Dev_mode();
char check_win(board A[b_][b_]);
char you_won();
int Master_Colour_Control_System_v_2_0_1();
char colour_Dictionary(int a, int b, char m[3]);
char colour_machine(char m[3]);
char Colour_Identifier(char m[3], char Colour_1[10], char Colour_2[10]);
int main()
{
	menu();
	return(0);
}
char start_game()
{
	int x, y, in;
	board A[b_][b_];
	char win;
	system("cls");
	Array_Setup(A);
	do
	{
		win = check_win(A);
		if (win == 'W')
		{
			you_won();
			break;
		}
		V_Array_setup(A);
		printf("\n\n\n\t\t");
		for (y = 0;y < b_;y++)
		{
			for (x = 0;x < b_;x++)
			{
				if (A[y][x].real == (b_ * b_))
				{
					printf("[ ]\t");
				}
				else
				{
					printf("%i\t", A[y][x].real);
				}
			}
			printf("\n\n\n\t\t");
		}
		printf("\n\n\n");
		printf("\n\n\n");
		in = input(A);
		if (in == 'F')
		{
			break;
		}
		system("cls");
		printf("\n\n\n");
	}
	while (-1);
}
char check_win(board A[b_][b_])
{
	int max, y, x, a = 0, check = 0;
	char winn = 'F';
	board win[b_][b_];
	max = b_ * b_;
	for (y = 0;y < b_;y++)
	{
		for (x = 0;x < b_;x++)
		{
			a++;
			win[y][x].real = a;
		}
	}
	for (y = 0;y < b_;y++)
	{
		for (x = 0;x < b_;x++)
		{
			if (A[y][x].real == win[y][x].real)
			{
				check++;
				if (check == max)
				{
					winn = 'T';
				}
			}
		}
	}
	if (winn == 'T')
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
	int x, y;
	char val = 'T';
	for (y = 0;y < b_;y++)
	{
		for (x = 0;x < b_;x++)
		{
			A[y][x].real = 0;
		}
	}
	for (y = 0;y < b_;y++)
	{
		for (x = 0;x < b_;x++)
		{
			do
			{
				num = Get_Ran();
				val = Check_for_repeat(num, A);
				if (val == 'T')
				{
					A[y][x].real = num;
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
	int x, y;
	for (x = 0;x < b_;x++)
	{
		for (y = 0;y < b_;y++)
		{
			if (A[y][x].real == num)
				return('F');
		}
	}
	return('T');
}
int Get_Ran(board A[b_][b_])
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
	int x, y, sx, sy;
	char m_sx[2] = {"TT"}, m_sy[2] = {"TT"};
	for (y = 0;y < b_;y++)
	{
		for (x = 0;x < b_;x++)
		{
			A[y][x].virt = 'x';
		}
	}
	for (y = 0;y < b_;y++)
	{
		for (x = 0;x < b_;x++)
		{
			if (A[y][x].real == (b_ * b_))
			{
				A[y][x].virt = '-';
				sx = x;
				sy = y;
			}
		}
	}
	sx_inc(sx, m_sx);
	sy_inc(sy, m_sy);
	if (m_sx[0] == 'T')
	{
		A[sy][sx - 1].virt = 'A';
	}
	if (m_sx[1] == 'T')
	{
		A[sy][sx + 1].virt = 'D';
	}
	if (m_sy[0] == 'T')
	{
		A[sy - 1][sx].virt = 'W';
	}
	if (m_sy[1] == 'T')
	{
		A[sy + 1][sx].virt = 'S';
	}
}
char sx_inc(int sx, char m_sx[2])
{
	if (sx == 0)
	{
		m_sx[0] = 'F';
		m_sx[1] = 'T';
	}
	else if (sx == b_ - 1)
	{
		m_sx[1] = 'F';
		m_sx[0] = 'T';
	}
	else
	{
		m_sx = "TT";
	}
}
char sy_inc(int sy, char m_sy[2])
{
	if (sy == 0)
	{
		m_sy[0] = 'F';
		m_sy[1] = 'T';
	}
	else if (sy == b_ - 1)
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
	int x, y;
	printf("\t\t");
	for (y = 0;y < b_;y++)
	{
		for (x = 0;x < b_;x++)
		{
			printf("%c\t", A[y][x].virt);
		}
		printf("\n\n\n\t\t");
	}
}
/* User input*/
char input(board a[b_][b_])
{
	char W = 'F', A = 'F', S = 'F', D = 'F';
	int in, x, y, sx, sy, temp;
	fflush(stdin);
	in = getch();
	for (y = 0;y < b_;y++)
	{
		for (x = 0;x < b_;x++)
		{
			if (a[y][x].virt == '-')
			{
				sy = y;
				sx = x;
			}
			if (a[y][x].virt == 'W')
			{
				W = 'T';
			}
			if (a[y][x].virt == 'A')
			{
				A = 'T';
			}
			if (a[y][x].virt == 'S')
			{
				S = 'T';
			}
			if (a[y][x].virt == 'D')
			{
				D = 'T';
			}
		}
	}
	if (in == 87 || in == 119)
	{
		if (W == 'T')
		{
			temp = a[sy][sx].real;
			a[sy][sx].real = a[sy - 1][sx].real;
			a[sy - 1][sx].real = temp;
		}
	}
	else if (in == 83 || in == 115)
	{
		if (S == 'T')
		{
			temp = a[sy][sx].real;
			a[sy][sx].real = a[sy + 1][sx].real;
			a[sy + 1][sx].real = temp;
		}
	}
	else if (in == 65 || in == 97)
	{
		if (A == 'T')
		{
			temp = a[sy][sx].real;
			a[sy][sx].real = a[sy][sx - 1].real;
			a[sy][sx - 1].real = temp;
		}
	}
	else if (in == 68 || in == 100)
	{
		if (D == 'T')
		{
			temp = a[sy][sx].real;
			a[sy][sx].real = a[sy][sx + 1].real;
			a[sy][sx + 1].real = temp;
		}
	}
	else if (in == 81 || in == 113)
	{
		return('F');
	}
}
char menu()
{
	char menu[4];
	menu_arrange(menu);
	do
	{
		print_menu(menu);
		user_input(menu);
		system("cls");
	}
	while (-1);
}
char menu_arrange(char menu[4])
{
	int y;
	for (y = 0;y < 4; y++)
	{
		menu[y] = 'x';
	}
	menu[0] = '+';
}
char print_menu(char menu[4])
{
	int y;
	y = menu_search(menu);
	printf("\n\n");
	Welcome();
	printf("\n\n");
	if (y == 0)
	{
		printf("\t%c[ START GAME ]\n\n", 16);
	}
	else
	{
		printf("\tStart Game\n\n");
	}
	if ( y == 1)
	{
		printf("\t%c[ OPTION ]\n\n", 16);
	}
	else
	{
		printf("\tOption\n\n");
	}
	if ( y == 2)
	{
		printf("\t%c[ ABOUT ]\n\n", 16);
	}
	else
	{
		printf("\tAbout\n\n");
	}
	if ( y == 3)
	{
		printf("\t%c[ EXIT ]\n\n", 16);
	}
	else
	{
		printf("\tExit\n\n");
	}
	printf("\n\t\t\t\t\t\tPress W and S to navigate.\n\n\t\t\t\t\t\tPress Enter to Select.\n");
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
int menu_search(char menu[4])
{
	int y;
	for (y = 0;y < 4;y++)
	{
		if (menu[y] == '+')
		{
			return(y);
		}
	}
}
char user_input(char menu[4])
{
	int in, y = menu_search(menu);
	in = getch();
	if ( in == 87 || in == 119 )
	{
		if ( y > 0 )
		{
			menu[y] = 'x';
			menu[y - 1] = '+';
		}
	}
	else if ( in == 83 || in == 115 )
	{
		if (y < 3)
		{
			menu[y] = 'x';
			menu[y + 1] = '+';
		}
	}
	else if ( in == 81 || in == 113)
	{
		exit(-1);
	}
	else if (in == 96)
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
	else if ( in == 13 )
	{
		if ( y == 0 )
		{
			start_game();
		}
		else if ( y == 1 )
		{
			option();
		}
		else if ( y == 2 )
		{
			about();
		}
		else if ( y == 3 )
		{
			exit(-1);
		}
	}
}
char option()
{
	char m[2];
	char in;
	char diff[10], color[10];
	int D = 1, C = 1, symbol;
	m[1] = 'T';
	m[0] = 'F';
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
			strcpy(diff, "Easy");
			symbol = 176;
			b_ = 3;
		}
		else if (D == 2)
		{
			strcpy(diff, "Normal");
			symbol = 177;
			b_ = 5;
		}
		else if (D == 3)
		{
			strcpy(diff, "Hard");
			symbol = 178;
			b_ = 7;
		}
		system("cls");
		printf("\n\tSelect Difficulty\n\n");
		if (m[0] == 'F')
		{
			printf("\t %c[ DIFFICULTY ] - %c %s\n\n", 16, symbol, diff);
		}
		else
		{
			printf("\tDifficulty\n\n");
		}
		if (m[1] == 'F')
		{
			printf("\t %c[ COLOUR CONTROL SYSTEM ]\n\n", 16);
		}
		else
		{
			printf("\tColour Control System\n\n");
		}
		printf("\t\t\t\t\t\tPress W and S to navigate.\n\n\t\t\t\t\t\tPress Enter to Select.\n\n\t\t\t\t\t\tPress Q to Go Back.\n\n\n\n");
		in = getch();
		if (in == 87 || in == 119 )
		{
			if ( m[0] == 'T')
			{
				m[0] = 'F';
				m[1] = 'T';
			}
		}
		else if (in == 83 || in == 115)
		{
			if ( m[1] == 'T' )
			{
				m[0] = 'T';
				m[1] = 'F';
			}
		}
		else if (in == 81 || in == 113)
		{
			return(' ');
		}
		else if (in == 13)
		{
			if (m[1] == 'T')
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
			else if (m[0] == 'T')
			{
				/*------------------------------------------ */
				system("cls");
				printf("\n\n\t\tWelcome to the \n\t\tMaster Colour Control System v.2.0.1\n\t\tSpecial Thanks to Eshan Shafeeq!\n\n\t\tPress Any Key to continue with the Application");
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
	printf("  .-----------------------------------------------------------------.\n");
	printf(" /  .-.                                                         .-.  \\ \n");
	printf("|  /   \\                                                       /   \\  |\n");
	printf("| |\\_.  | By:Brendon Goh.                                     |    /| |\n");
	printf("|\\|  | /| Std ID:*******                                      |\\  | |/|\n");
	printf("| `---' |                                                     | `---' |\n");
	printf("|       | Introduction to programming                         |       |\n");
	printf("|       | Assignment 2011                                     |       |\n");
	printf("|       |                                                     |       |\n");
	printf("|       |-----------------------------------------------------|       |\n");
	printf("\\       |                                                     |       /\n");
	printf(" \\     /                                                       \\     /\n");
	printf("  `---'                                                         `---'\n");
	getch();
	system("cls");
}
char Dev_mode()
{
	int x, y;
	char in;
	board A[b_][b_];
	Array_Setup(A);
	do
	{
		V_Array_setup(A);
		printf("\t\t");
		for (y = 0;y < b_;y++)
		{
			for (x = 0;x < b_;x++)
			{
				if (A[y][x].real == (b_ * b_))
				{
					printf("(%c)\t", 148);
				}
				else
				{
					printf("%i\t", A[y][x].real);
				}
			}
			printf("\n\n\n\t\t");
		}
		printf("\n\n\n");
		printf("\n\n\n");
		printV(A);
		printf("\n\n\n");
		printf("\n\n\n");
		in = input(A);
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
	int input, Sel_A = 0, Sel_B = 7, temp;
	char m[3] = "  ";
	char Colour_1[20], Colour_2[20];
	do
	{
		input = getch();
		if (input == 87 || input == 119)
		{
			if (Sel_A > 0)
			{
				temp = Sel_B;
				temp++;
				if (temp != Sel_A)
				{
					Sel_A--;
				}
				else
				{
					if (Sel_A != 2)
					{
						Sel_A -= 2;
						if (Sel_A == -1)
						{
							Sel_A = 15;
						}
					}
					else
					{
						if (Sel_B != 15)
						{
							Sel_A = 15;
						}
						else
						{
							Sel_A = 14;
						}
					}
				}
			}
			else
			{
				if (Sel_B != 15)
				{
					Sel_A = 15;
				}
				else
				{
					Sel_A = 14;
				}
			}
		}
		else if (input == 83 || input == 115)
		{
			if (Sel_A < 15)
			{
				temp = Sel_B;
				temp--;
				if (temp != Sel_A)
				{
					Sel_A++;
				}
				else
				{
					if (Sel_A != 14)
					{
						Sel_A += 2;
						if (Sel_A == 16)
						{
							Sel_A = 0;
						}
					}
					else
					{
						if (Sel_B != 0)
						{
							Sel_A = 0;
						}
						else
						{
							Sel_A = 2;
						}
					}
				}
			}
			else
			{
				if (Sel_B != 0)
				{
					Sel_A = 0;
				}
				else
				{
					Sel_A = 1;
				}
			}
		}
		else if (input == 65 || input == 97)
		{
			if (Sel_B > 0)
			{
				temp = Sel_A;
				temp++;
				if (temp != Sel_B)
				{
					Sel_B--;
				}
				else
				{
					if (Sel_B != 2)
					{
						Sel_B -= 2;
						if (Sel_B == -1)
						{
							Sel_B = 15;
						}
					}
					else
					{
						if (Sel_A != 15)
						{
							Sel_B = 15;
						}
						else
						{
							Sel_B = 14;
						}
					}
				}
			}
			else
			{
				if (Sel_A != 15)
				{
					Sel_B = 15;
				}
				else
				{
					Sel_B = 14;
				}
			}
		}
		else if (input == 68 || input == 100)
		{
			if (Sel_B < 15)
			{
				temp = Sel_A;
				temp--;
				if (temp != Sel_B)
				{
					Sel_B++;
				}
				else
				{
					if (Sel_B != 14)
					{
						Sel_B += 2;
						if (Sel_B == 16)
						{
							Sel_B = 0;
						}
					}
					else
					{
						if (Sel_A != 0)
						{
							Sel_B = 0;
						}
						else
						{
							Sel_B = 1;
						}
					}
				}
			}
			else
			{
				if (Sel_A != 0)
				{
					Sel_B = 0;
				}
				else
				{
					Sel_B = 1;
				}
			}
		}
		else if (input == 81 || input == 113)
		{
			return (0);
		}
		system("cls");
		printf("\n\n\t\tMaster Colour Control System v.2.0.1\n\n\t\tToggle Between Background Colours using W And S\n\t\tToggle Between The Font colour using A and D.\n\t\tTo save changes and go back press Q.\n\n");
		colour_Dictionary( Sel_A, Sel_B, m);
		Colour_Identifier(m, Colour_1, Colour_2);
		colour_machine(m);
	}
	while (input != 81 || input != 113);
	return(0);
}
char Colour_Identifier(char m[3], char Colour_1[10], char Colour_2[10])
{
	if (m[0] == '0')
	{
		strcpy(Colour_1, "Black");
	}
	else if (m[0] == '1')
	{
		strcpy(Colour_1, "Blue");
	}
	else if (m[0] == '2')
	{
		strcpy(Colour_1, "Green");
	}
	else if (m[0] == '3')
	{
		strcpy(Colour_1, "Aqua");
	}
	else if (m[0] == '4')
	{
		strcpy(Colour_1, "Red");
	}
	else if (m[0] == '5')
	{
		strcpy(Colour_1, "Purple");
	}
	else if (m[0] == '6')
	{
		strcpy(Colour_1, "Yellow");
	}
	else if (m[0] == '7')
	{
		strcpy(Colour_1, "White");
	}
	else if (m[0] == '8')
	{
		strcpy(Colour_1, "Gray");
	}
	else if (m[0] == '9')
	{
		strcpy(Colour_1, "Light Blue");
	}
	else if (m[0] == 'A')
	{
		strcpy(Colour_1, "Light Green");
	}
	else if (m[0] == 'B')
	{
		strcpy(Colour_1, "Light Aqua");
	}
	else if (m[0] == 'C')
	{
		strcpy(Colour_1, "Light Red");
	}
	else if (m[0] == 'D')
	{
		strcpy(Colour_1, "Light Purple");
	}
	else if (m[0] == 'E')
	{
		strcpy(Colour_1, "Light Yellow");
	}
	else if (m[0] == 'F')
	{
		strcpy(Colour_1, "Bright White");
	}
	/*-----------------------------------*/
	if (m[1] == '0')
	{
		strcpy(Colour_2, "Black");
	}
	else if (m[1] == '1')
	{
		strcpy(Colour_2, "Blue");
	}
	else if (m[1] == '2')
	{
		strcpy(Colour_2, "Green");
	}
	else if (m[1] == '3')
	{
		strcpy(Colour_2, "Aqua");
	}
	else if (m[1] == '4')
	{
		strcpy(Colour_2, "Red");
	}
	else if (m[1] == '5')
	{
		strcpy(Colour_2, "Purple");
	}
	else if (m[1] == '6')
	{
		strcpy(Colour_2, "Yellow");
	}
	else if (m[1] == '7')
	{
		strcpy(Colour_2, "White");
	}
	else if (m[1] == '8')
	{
		strcpy(Colour_2, "Gray");
	}
	else if (m[1] == '9')
	{
		strcpy(Colour_2, "Light Blue");
	}
	else if (m[1] == 'A')
	{
		strcpy(Colour_2, "Light Green");
	}
	else if (m[1] == 'B')
	{
		strcpy(Colour_2, "Light Aqua");
	}
	else if (m[1] == 'C')
	{
		strcpy(Colour_2, "Light Red");
	}
	else if (m[1] == 'D')
	{
		strcpy(Colour_2, "Light Purple");
	}
	else if (m[1] == 'E')
	{
		strcpy(Colour_2, "Light Yellow");
	}
	else if (m[1] == 'F')
	{
		strcpy(Colour_2, "Bright White");
	}
	printf("\t\tBackground Colour = %s \n\t\tFont Colour = %s\n\n\n", Colour_1, Colour_2);
}
char colour_Dictionary(int a, int b, char m[3])
{
	if (a == 0)
	{
		m[0] = '0';
	}
	else if (a == 1)
	{
		m[0] = '1';
	}
	else if (a == 2)
	{
		m[0] = '2';
	}
	else if (a == 3)
	{
		m[0] = '3';
	}
	else if (a == 4)
	{
		m[0] = '4';
	}
	else if (a == 5)
	{
		m[0] = '5';
	}
	else if (a == 6)
	{
		m[0] = '6';
	}
	else if (a == 7)
	{
		m[0] = '7';
	}
	else if (a == 8)
	{
		m[0] = '8';
	}
	else if (a == 9)
	{
		m[0] = '9';
	}
	else if (a == 10)
	{
		m[0] = 'A';
	}
	else if (a == 11)
	{
		m[0] = 'B';
	}
	else if (a == 12)
	{
		m[0] = 'C';
	}
	else if (a == 13)
	{
		m[0] = 'D';
	}
	else if (a == 14)
	{
		m[0] = 'E';
	}
	else if (a == 15)
	{
		m[0] = 'F';
	}
	/*-----------*/
	if (b == 0)
	{
		m[1] = '0';
	}
	else if (b == 1)
	{
		m[1] = '1';
	}
	else if (b == 2)
	{
		m[1] = '2';
	}
	else if (b == 3)
	{
		m[1] = '3';
	}
	else if (b == 4)
	{
		m[1] = '4';
	}
	else if (b == 5)
	{
		m[1] = '5';
	}
	else if (b == 6)
	{
		m[1] = '6';
	}
	else if (b == 7)
	{
		m[1] = '7';
	}
	else if (b == 8)
	{
		m[1] = '8';
	}
	else if (b == 9)
	{
		m[1] = '9';
	}
	else if (b == 10)
	{
		m[1] = 'A';
	}
	else if (b == 11)
	{
		m[1] = 'B';
	}
	else if (b == 12)
	{
		m[1] = 'C';
	}
	else if (b == 13)
	{
		m[1] = 'D';
	}
	else if (b == 14)
	{
		m[1] = 'E';
	}
	else if (b == 15)
	{
		m[1] = 'F';
	}
}
char colour_machine(char m[3])
{
	if (strcmp(m, "01") == 0)
	{
		system("color 01");
	}
	else if (strcmp(m, "02") == 0)
	{
		system("color 02");
	}
	else if (strcmp(m, "03") == 0)
	{
		system("color 03");
	}
	else if (strcmp(m, "04") == 0)
	{
		system("color 04");
	}
	else if (strcmp(m, "05") == 0)
	{
		system("color 05");
	}
	else if (strcmp(m, "06") == 0)
	{
		system("color 06");
	}
	else if (strcmp(m, "07") == 0)
	{
		system("color 07");
	}
	else if (strcmp(m, "08") == 0)
	{
		system("color 08");
	}
	else if (strcmp(m, "09") == 0)
	{
		system("color 09");
	}
	else if (strcmp(m, "0A") == 0)
	{
		system("color 0A");
	}
	else if (strcmp(m, "0B") == 0)
	{
		system("color 0B");
	}
	else if (strcmp(m, "0C") == 0)
	{
		system("color 0C");
	}
	else if (strcmp(m, "0D") == 0)
	{
		system("color 0D");
	}
	else if (strcmp(m, "0E") == 0)
	{
		system("color 0E");
	}
	else if (strcmp(m, "0F") == 0)
	{
		system("color 0F");
	}
	else if (strcmp(m, "10") == 0)
	{
		system("color 10");
	}
	else if (strcmp(m, "12") == 0)
	{
		system("color 12");
	}
	else if (strcmp(m, "13") == 0)
	{
		system("color 13");
	}
	else if (strcmp(m, "14") == 0)
	{
		system("color 14");
	}
	else if (strcmp(m, "15") == 0)
	{
		system("color 15");
	}
	else if (strcmp(m, "16") == 0)
	{
		system("color 16");
	}
	else if (strcmp(m, "17") == 0)
	{
		system("color 17");
	}
	else if (strcmp(m, "18") == 0)
	{
		system("color 18");
	}
	else if (strcmp(m, "19") == 0)
	{
		system("color 19");
	}
	else if (strcmp(m, "1A") == 0)
	{
		system("color 1A");
	}
	else if (strcmp(m, "1B") == 0)
	{
		system("color 1B");
	}
	else if (strcmp(m, "1C") == 0)
	{
		system("color 1C");
	}
	else if (strcmp(m, "1D") == 0)
	{
		system("color 1D");
	}
	else if (strcmp(m, "1E") == 0)
	{
		system("color 1E");
	}
	else if (strcmp(m, "1F") == 0)
	{
		system("color 1F");
	}
	else if (strcmp(m, "20") == 0)
	{
		system("color 20");
	}
	else if (strcmp(m, "21") == 0)
	{
		system("color 21");
	}
	else if (strcmp(m, "23") == 0)
	{
		system("color 23");
	}
	else if (strcmp(m, "24") == 0)
	{
		system("color 24");
	}
	else if (strcmp(m, "25") == 0)
	{
		system("color 25");
	}
	else if (strcmp(m, "26") == 0)
	{
		system("color 26");
	}
	else if (strcmp(m, "27") == 0)
	{
		system("color 27");
	}
	else if (strcmp(m, "28") == 0)
	{
		system("color 28");
	}
	else if (strcmp(m, "29") == 0)
	{
		system("color 29");
	}
	else if (strcmp(m, "2A") == 0)
	{
		system("color 2A");
	}
	else if (strcmp(m, "2B") == 0)
	{
		system("color 2B");
	}
	else if (strcmp(m, "2C") == 0)
	{
		system("color 2C");
	}
	else if (strcmp(m, "2D") == 0)
	{
		system("color 2D");
	}
	else if (strcmp(m, "2E") == 0)
	{
		system("color 2E");
	}
	else if (strcmp(m, "2F") == 0)
	{
		system("color 2F");
	}
	else if (strcmp(m, "30") == 0)
	{
		system("color 30");
	}
	else if (strcmp(m, "31") == 0)
	{
		system("color 31");
	}
	else if (strcmp(m, "32") == 0)
	{
		system("color 32");
	}
	else if (strcmp(m, "34") == 0)
	{
		system("color 34");
	}
	else if (strcmp(m, "35") == 0)
	{
		system("color 35");
	}
	else if (strcmp(m, "36") == 0)
	{
		system("color 36");
	}
	else if (strcmp(m, "37") == 0)
	{
		system("color 37");
	}
	else if (strcmp(m, "38") == 0)
	{
		system("color 38");
	}
	else if (strcmp(m, "39") == 0)
	{
		system("color 39");
	}
	else if (strcmp(m, "3A") == 0)
	{
		system("color 3A");
	}
	else if (strcmp(m, "3B") == 0)
	{
		system("color 3B");
	}
	else if (strcmp(m, "3C") == 0)
	{
		system("color 3C");
	}
	else if (strcmp(m, "3D") == 0)
	{
		system("color 3D");
	}
	else if (strcmp(m, "3E") == 0)
	{
		system("color 3E");
	}
	else if (strcmp(m, "3F") == 0)
	{
		system("color 3F");
	}
	else if (strcmp(m, "40") == 0)
	{
		system("color 40");
	}
	else if (strcmp(m, "41") == 0)
	{
		system("color 41");
	}
	else if (strcmp(m, "42") == 0)
	{
		system("color 42");
	}
	else if (strcmp(m, "43") == 0)
	{
		system("color 43");
	}
	else if (strcmp(m, "45") == 0)
	{
		system("color 45");
	}
	else if (strcmp(m, "46") == 0)
	{
		system("color 46");
	}
	else if (strcmp(m, "47") == 0)
	{
		system("color 47");
	}
	else if (strcmp(m, "48") == 0)
	{
		system("color 48");
	}
	else if (strcmp(m, "49") == 0)
	{
		system("color 49");
	}
	else if (strcmp(m, "4A") == 0)
	{
		system("color 4A");
	}
	else if (strcmp(m, "4B") == 0)
	{
		system("color 4B");
	}
	else if (strcmp(m, "4C") == 0)
	{
		system("color 4C");
	}
	else if (strcmp(m, "4D") == 0)
	{
		system("color 4D");
	}
	else if (strcmp(m, "4E") == 0)
	{
		system("color 4E");
	}
	else if (strcmp(m, "4F") == 0)
	{
		system("color 4F");
	}
	else if (strcmp(m, "50") == 0)
	{
		system("color 50");
	}
	else if (strcmp(m, "51") == 0)
	{
		system("color 51");
	}
	else if (strcmp(m, "52") == 0)
	{
		system("color 52");
	}
	else if (strcmp(m, "53") == 0)
	{
		system("color 53");
	}
	else if (strcmp(m, "54") == 0)
	{
		system("color 54");
	}
	else if (strcmp(m, "56") == 0)
	{
		system("color 56");
	}
	else if (strcmp(m, "57") == 0)
	{
		system("color 57");
	}
	else if (strcmp(m, "58") == 0)
	{
		system("color 58");
	}
	else if (strcmp(m, "59") == 0)
	{
		system("color 59");
	}
	else if (strcmp(m, "5A") == 0)
	{
		system("color 5A");
	}
	else if (strcmp(m, "5B") == 0)
	{
		system("color 5B");
	}
	else if (strcmp(m, "5C") == 0)
	{
		system("color 5C");
	}
	else if (strcmp(m, "5D") == 0)
	{
		system("color 5D");
	}
	else if (strcmp(m, "5E") == 0)
	{
		system("color 5E");
	}
	else if (strcmp(m, "5F") == 0)
	{
		system("color 5F");
	}
	else if (strcmp(m, "60") == 0)
	{
		system("color 60");
	}
	else if (strcmp(m, "61") == 0)
	{
		system("color 61");
	}
	else if (strcmp(m, "62") == 0)
	{
		system("color 62");
	}
	else if (strcmp(m, "63") == 0)
	{
		system("color 63");
	}
	else if (strcmp(m, "64") == 0)
	{
		system("color 64");
	}
	else if (strcmp(m, "65") == 0)
	{
		system("color 65");
	}
	else if (strcmp(m, "67") == 0)
	{
		system("color 67");
	}
	else if (strcmp(m, "68") == 0)
	{
		system("color 68");
	}
	else if (strcmp(m, "69") == 0)
	{
		system("color 69");
	}
	else if (strcmp(m, "6A") == 0)
	{
		system("color 6A");
	}
	else if (strcmp(m, "6B") == 0)
	{
		system("color 6B");
	}
	else if (strcmp(m, "6C") == 0)
	{
		system("color 6C");
	}
	else if (strcmp(m, "6D") == 0)
	{
		system("color 6D");
	}
	else if (strcmp(m, "6E") == 0)
	{
		system("color 6E");
	}
	else if (strcmp(m, "6F") == 0)
	{
		system("color 6F");
	}
	else if (strcmp(m, "70") == 0)
	{
		system("color 70");
	}
	else if (strcmp(m, "71") == 0)
	{
		system("color 71");
	}
	else if (strcmp(m, "72") == 0)
	{
		system("color 72");
	}
	else if (strcmp(m, "73") == 0)
	{
		system("color 73");
	}
	else if (strcmp(m, "74") == 0)
	{
		system("color 74");
	}
	else if (strcmp(m, "75") == 0)
	{
		system("color 75");
	}
	else if (strcmp(m, "76") == 0)
	{
		system("color 76");
	}
	else if (strcmp(m, "78") == 0)
	{
		system("color 78");
	}
	else if (strcmp(m, "79") == 0)
	{
		system("color 79");
	}
	else if (strcmp(m, "7A") == 0)
	{
		system("color 7A");
	}
	else if (strcmp(m, "7B") == 0)
	{
		system("color 7B");
	}
	else if (strcmp(m, "7C") == 0)
	{
		system("color 7C");
	}
	else if (strcmp(m, "7D") == 0)
	{
		system("color 7D");
	}
	else if (strcmp(m, "7E") == 0)
	{
		system("color 7E");
	}
	else if (strcmp(m, "7F") == 0)
	{
		system("color 7F");
	}
	else if (strcmp(m, "80") == 0)
	{
		system("color 80");
	}
	else if (strcmp(m, "81") == 0)
	{
		system("color 81");
	}
	else if (strcmp(m, "82") == 0)
	{
		system("color 82");
	}
	else if (strcmp(m, "83") == 0)
	{
		system("color 83");
	}
	else if (strcmp(m, "84") == 0)
	{
		system("color 84");
	}
	else if (strcmp(m, "85") == 0)
	{
		system("color 85");
	}
	else if (strcmp(m, "86") == 0)
	{
		system("color 86");
	}
	else if (strcmp(m, "87") == 0)
	{
		system("color 87");
	}
	else if (strcmp(m, "89") == 0)
	{
		system("color 89");
	}
	else if (strcmp(m, "8A") == 0)
	{
		system("color 8A");
	}
	else if (strcmp(m, "8B") == 0)
	{
		system("color 8B");
	}
	else if (strcmp(m, "8C") == 0)
	{
		system("color 8C");
	}
	else if (strcmp(m, "8D") == 0)
	{
		system("color 8D");
	}
	else if (strcmp(m, "8E") == 0)
	{
		system("color 8E");
	}
	else if (strcmp(m, "8F") == 0)
	{
		system("color 8F");
	}
	else if (strcmp(m, "90") == 0)
	{
		system("color 90");
	}
	else if (strcmp(m, "91") == 0)
	{
		system("color 91");
	}
	else if (strcmp(m, "92") == 0)
	{
		system("color 92");
	}
	else if (strcmp(m, "93") == 0)
	{
		system("color 93");
	}
	else if (strcmp(m, "94") == 0)
	{
		system("color 94");
	}
	else if (strcmp(m, "95") == 0)
	{
		system("color 95");
	}
	else if (strcmp(m, "96") == 0)
	{
		system("color 96");
	}
	else if (strcmp(m, "97") == 0)
	{
		system("color 97");
	}
	else if (strcmp(m, "98") == 0)
	{
		system("color 98");
	}
	else if (strcmp(m, "9A") == 0)
	{
		system("color 9A");
	}
	else if (strcmp(m, "9B") == 0)
	{
		system("color 9B");
	}
	else if (strcmp(m, "9C") == 0)
	{
		system("color 9C");
	}
	else if (strcmp(m, "9D") == 0)
	{
		system("color 9D");
	}
	else if (strcmp(m, "9E") == 0)
	{
		system("color 9E");
	}
	else if (strcmp(m, "9F") == 0)
	{
		system("color 9F");
	}
	else if (strcmp(m, "A0") == 0)
	{
		system("color A0");
	}
	else if (strcmp(m, "A1") == 0)
	{
		system("color A1");
	}
	else if (strcmp(m, "A2") == 0)
	{
		system("color A2");
	}
	else if (strcmp(m, "A3") == 0)
	{
		system("color A3");
	}
	else if (strcmp(m, "A4") == 0)
	{
		system("color A4");
	}
	else if (strcmp(m, "A5") == 0)
	{
		system("color A5");
	}
	else if (strcmp(m, "A6") == 0)
	{
		system("color A6");
	}
	else if (strcmp(m, "A7") == 0)
	{
		system("color A7");
	}
	else if (strcmp(m, "A8") == 0)
	{
		system("color A8");
	}
	else if (strcmp(m, "A9") == 0)
	{
		system("color A9");
	}
	else if (strcmp(m, "AA") == 0)
	{
		system("color AA");
	}
	else if (strcmp(m, "AB") == 0)
	{
		system("color AB");
	}
	else if (strcmp(m, "AC") == 0)
	{
		system("color AC");
	}
	else if (strcmp(m, "AD") == 0)
	{
		system("color AD");
	}
	else if (strcmp(m, "AE") == 0)
	{
		system("color AE");
	}
	else if (strcmp(m, "AF") == 0)
	{
		system("color AF");
	}
	else if (strcmp(m, "B0") == 0)
	{
		system("color B0");
	}
	else if (strcmp(m, "B1") == 0)
	{
		system("color B1");
	}
	else if (strcmp(m, "B2") == 0)
	{
		system("color B2");
	}
	else if (strcmp(m, "B3") == 0)
	{
		system("color B3");
	}
	else if (strcmp(m, "B4") == 0)
	{
		system("color B4");
	}
	else if (strcmp(m, "B5") == 0)
	{
		system("color B5");
	}
	else if (strcmp(m, "B6") == 0)
	{
		system("color B6");
	}
	else if (strcmp(m, "B7") == 0)
	{
		system("color B7");
	}
	else if (strcmp(m, "B8") == 0)
	{
		system("color B8");
	}
	else if (strcmp(m, "B9") == 0)
	{
		system("color B9");
	}
	else if (strcmp(m, "BA") == 0)
	{
		system("color BA");
	}
	else if (strcmp(m, "BB") == 0)
	{
		system("color BB");
	}
	else if (strcmp(m, "BC") == 0)
	{
		system("color BC");
	}
	else if (strcmp(m, "BD") == 0)
	{
		system("color BD");
	}
	else if (strcmp(m, "BE") == 0)
	{
		system("color BE");
	}
	else if (strcmp(m, "BF") == 0)
	{
		system("color BF");
	}
	else if (strcmp(m, "C0") == 0)
	{
		system("color C0");
	}
	else if (strcmp(m, "C1") == 0)
	{
		system("color C1");
	}
	else if (strcmp(m, "C2") == 0)
	{
		system("color C2");
	}
	else if (strcmp(m, "C3") == 0)
	{
		system("color C3");
	}
	else if (strcmp(m, "C4") == 0)
	{
		system("color C4");
	}
	else if (strcmp(m, "C5") == 0)
	{
		system("color C5");
	}
	else if (strcmp(m, "C6") == 0)
	{
		system("color C6");
	}
	else if (strcmp(m, "C7") == 0)
	{
		system("color C7");
	}
	else if (strcmp(m, "C8") == 0)
	{
		system("color C8");
	}
	else if (strcmp(m, "C9") == 0)
	{
		system("color C9");
	}
	else if (strcmp(m, "CA") == 0)
	{
		system("color CA");
	}
	else if (strcmp(m, "CB") == 0)
	{
		system("color CB");
	}
	else if (strcmp(m, "CC") == 0)
	{
		system("color CC");
	}
	else if (strcmp(m, "CD") == 0)
	{
		system("color CD");
	}
	else if (strcmp(m, "CE") == 0)
	{
		system("color CE");
	}
	else if (strcmp(m, "CF") == 0)
	{
		system("color CF");
	}
	else if (strcmp(m, "D0") == 0)
	{
		system("color D0");
	}
	else if (strcmp(m, "D1") == 0)
	{
		system("color D1");
	}
	else if (strcmp(m, "D2") == 0)
	{
		system("color D2");
	}
	else if (strcmp(m, "D3") == 0)
	{
		system("color D3");
	}
	else if (strcmp(m, "D4") == 0)
	{
		system("color D4");
	}
	else if (strcmp(m, "D5") == 0)
	{
		system("color D5");
	}
	else if (strcmp(m, "D6") == 0)
	{
		system("color D6");
	}
	else if (strcmp(m, "D7") == 0)
	{
		system("color D7");
	}
	else if (strcmp(m, "D8") == 0)
	{
		system("color D8");
	}
	else if (strcmp(m, "D9") == 0)
	{
		system("color D9");
	}
	else if (strcmp(m, "DA") == 0)
	{
		system("color DA");
	}
	else if (strcmp(m, "DB") == 0)
	{
		system("color DB");
	}
	else if (strcmp(m, "DC") == 0)
	{
		system("color DC");
	}
	else if (strcmp(m, "DD") == 0)
	{
		system("color DD");
	}
	else if (strcmp(m, "DE") == 0)
	{
		system("color DE");
	}
	else if (strcmp(m, "DF") == 0)
	{
		system("color DF");
	}
	else if (strcmp(m, "E0") == 0)
	{
		system("color E0");
	}
	else if (strcmp(m, "E1") == 0)
	{
		system("color E1");
	}
	else if (strcmp(m, "E2") == 0)
	{
		system("color E2");
	}
	else if (strcmp(m, "E3") == 0)
	{
		system("color E3");
	}
	else if (strcmp(m, "E4") == 0)
	{
		system("color E4");
	}
	else if (strcmp(m, "E5") == 0)
	{
		system("color E5");
	}
	else if (strcmp(m, "E6") == 0)
	{
		system("color E6");
	}
	else if (strcmp(m, "E7") == 0)
	{
		system("color E7");
	}
	else if (strcmp(m, "E8") == 0)
	{
		system("color E8");
	}
	else if (strcmp(m, "E9") == 0)
	{
		system("color E9");
	}
	else if (strcmp(m, "EA") == 0)
	{
		system("color EA");
	}
	else if (strcmp(m, "EB") == 0)
	{
		system("color EB");
	}
	else if (strcmp(m, "EC") == 0)
	{
		system("color EC");
	}
	else if (strcmp(m, "ED") == 0)
	{
		system("color ED");
	}
	else if (strcmp(m, "EE") == 0)
	{
		system("color EE");
	}
	else if (strcmp(m, "EF") == 0)
	{
		system("color EF");
	}
	else if (strcmp(m, "F0") == 0)
	{
		system("color F0");
	}
	else if (strcmp(m, "F1") == 0)
	{
		system("color F1");
	}
	else if (strcmp(m, "F2") == 0)
	{
		system("color F2");
	}
	else if (strcmp(m, "F3") == 0)
	{
		system("color F3");
	}
	else if (strcmp(m, "F4") == 0)
	{
		system("color F4");
	}
	else if (strcmp(m, "F5") == 0)
	{
		system("color F5");
	}
	else if (strcmp(m, "F6") == 0)
	{
		system("color F6");
	}
	else if (strcmp(m, "F7") == 0)
	{
		system("color F7");
	}
	else if (strcmp(m, "F8") == 0)
	{
		system("color F8");
	}
	else if (strcmp(m, "F9") == 0)
	{
		system("color F9");
	}
	else if (strcmp(m, "FA") == 0)
	{
		system("color FA");
	}
	else if (strcmp(m, "FB") == 0)
	{
		system("color FB");
	}
	else if (strcmp(m, "FC") == 0)
	{
		system("color FC");
	}
	else if (strcmp(m, "FD") == 0)
	{
		system("color FD");
	}
	else if (strcmp(m, "FE") == 0)
	{
		system("color FE");
	}
	else if (strcmp(m, "FF") == 0)
	{
		system("color FF");
	}
}

