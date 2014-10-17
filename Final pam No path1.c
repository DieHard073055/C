/*
	File: 4229665_Philip.c
	Eshan Shafeeq
	A noPath Game.
*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define ROW 5
#define COL 5
#define size 50

typedef struct
{
	char name[11];
	int score;
	int turns;
	
}player_data;

typedef struct
{
	int a;
	char b;
	int c;
}Set;

void randNum(Set board[ROW][COL]);
char disp_arr(Set board[ROW][COL]);
void locator(Set board[ROW][COL], int *x, int *y);
char movement(Set board[ROW][COL]);
char up_able(Set board[ROW][COL], int x, int y);
char down_able(Set board[ROW][COL], int x, int y);
char right_able(Set board[ROW][COL], int x, int y);
char left_able(Set board[ROW][COL], int x, int y);
void win_screen(void);
int menu_screen(void);
char menu_input(int *y, char menulist[4]);
void print_menu(int y);
void info(void);
void welcome(void);
char player(void);
void congratulations(void);
void littleDetails(void);
void High_Score(void);
void player_stats(void);
void In_the_game(Set board[ROW][COL]);
void Write_info(player_data PrintInfo[size]);
void Read_info(void);
player_data P[size];
int Player_num = -1;

int main()
{
	int  t;
	char choice, win;
	Set board[ROW][COL];
	Read_info();	
	do
	{	
		player_stats();
		randNum(board);
		In_the_game(board);
	}
	while (t = 1);
}
void randNum(Set board[ROW][COL])
{
	int max = 4 , min = 1;
	int j, k,g;
	static int start = 0;
	char no1 = 'T', no4 = 'T';
	int No1 = 0;
	if (start == 0)
	{
		srand(time(NULL));
		start = 1;
	}
	for (j = 0; j < ROW; j++)
	{
		for (k = 0; k < COL; k++)
		{
			if (no1 == 'T')
			{
				min = 1;
			}
			else if (no1 == 'F')
			{
				min = 2;
			}
			if (no4 == 'T')
			{
				max = 4;
			}
			else if (no4 == 'F')
			{
				max = 3;
			}
			board[j][k].a = (rand() % (max - min + 1) + min);
			if (board[j][k].a == 4)
			{
				no4 = 'F';
			}
			else if (board[j][k].a == 1)
			{
				No1 ++;
				if (No1 >= 5)
				{
					no1 = 'F';
				}
			}
			board[j][k].b = 'A';
			board[j][k].c = 0;
		}
	}
	board[0][0].b = 'B';
	board[4][4].a = 0;
}
char disp_arr(Set board[ROW][COL])
{
	int c, d;
	littleDetails();
	printf("\n\n");
	printf("---------------------------------\n");
	for (c = 0; c < ROW; c++)
	{
		for (d = 0; d < ROW; d++)
		{
			if (board[c][d].b == 'B')
			{
				if (c == 4 && d == 4)
				{
					return 'W';
				}
				printf("(%i)\t", board[c][d].a);
			}
			else
			{
				printf("%i\t", board[c][d].a);
			}
		}
		printf("\n\n");
	}
	printf("---------------------------------\n");
	
	printf("No. of moves:  %i",P[Player_num].turns);
	printf("    Your move:  ");
	
}
void locator(Set board[ROW][COL], int *x, int *y)
{
	int h, i;
	for (h = 0; h < ROW; h++)
	{
		for (i = 0; i < COL; i++)
		{
			if (board[h][i].b == 'B')
			{
				*x = i;
				*y = h;
			}
		}
	}
}
char movement(Set board[ROW][COL])
{
	int x, y;
	char dir;
	char up, down, left, right;
	locator(board, &x, &y);
	fflush(stdin);
	scanf("%c", &dir);
	dir = toupper(dir);
	if (dir == 'Q')
	{
		return 'Q';
	}
	else if (dir == 'W')
	{
		up = up_able(board, x, y);
		if (up == 'T')
		{
			board[y][x].b = 'A';
			y -= board[y][x].a;
			board[y][x].b = 'B';
			board[y][x].c++;
			if(board[y][x].c == 1)
			{
				P[Player_num].turns++;
			}
			else if( board[y][x].c > 1 )
			{
				P[Player_num].turns += 2;
			
			}
		}
	}
	else if (dir == 'S')
	{
		down = down_able(board, x, y);
		if (down == 'T')
		{
			board[y][x].b = 'A';
			y += board[y][x].a;
			board[y][x].b = 'B';
			board[y][x].c++;
			if(board[y][x].c == 1)
			{
				P[Player_num].turns++;
			}
			else if( board[y][x].c > 1 )
			{
				P[Player_num].turns += 2;
			
			}
		}
	}
	else if (dir == 'A')
	{
		left = left_able(board, x, y);
		if (left == 'T')
		{
			board[y][x].b = 'A';
			x -= board[y][x].a;
			board[y][x].b = 'B';
			board[y][x].c++;
			if(board[y][x].c == 1)
			{
				P[Player_num].turns++;
			}
			else if( board[y][x].c > 1 )
			{
				P[Player_num].turns += 2;
			
			}
		}
	}
	else if (dir == 'D')
	{
		right = right_able(board, x, y);
		if (right == 'T')
		{
			board[y][x].b = 'A';
			x += board[y][x].a;
			board[y][x].b = 'B';
			board[y][x].c++;
			if(board[y][x].c == 1)
			{
				P[Player_num].turns++;
			}
			else if( board[y][x].c > 1 )
			{
				P[Player_num].turns += 2;
			
			}
		}
	}
}
char up_able(Set board[ROW][COL], int x, int y)
{
	if (board[y][x].a == 4)
	{
		if (y == 4)
		{
			return 'T';
		}
		else
		{
			return 'F';
		}
	}
	else if (board[y][x].a == 3)
	{
		if (y >= 3)
		{
			return 'T';
		}
		else if (y < 3)
		{
			return 'F';
		}
	}
	else if (board[y][x].a == 2)
	{
		if (y >= 2)
		{
			return 'T';
		}
		else if (y < 2)
		{
			return 'F';
		}
	}
	else if (board[y][x].a == 1)
	{
		if (y >= 1)
		{
			return 'T';
		}
		else if (y < 1)
		{
			return 'F';
		}
	}
}
char down_able(Set board[ROW][COL], int x, int y)
{
	if (board[y][x].a == 4)
	{
		if (y == 0)
		{
			return 'T';
		}
		else
		{
			return 'F';
		}
	}
	else if (board[y][x].a == 3)
	{
		if (y <= 1)
		{
			return 'T';
		}
		else if (y > 1)
		{
			return 'F';
		}
	}
	else if (board[y][x].a == 2)
	{
		if (y <= 2)
		{
			return 'T';
		}
		else if (y > 2)
		{
			return 'F';
		}
	}
	else if (board[y][x].a == 1)
	{
		if (y <= 3)
		{
			return 'T';
		}
		else if (y > 3)
		{
			return 'F';
		}
	}
}
char left_able(Set board[ROW][COL], int x, int y)
{
	if (board[y][x].a == 4)
	{
		if (x == 4)
		{
			return 'T';
		}
		else
		{
			return 'F';
		}
	}
	else if (board[y][x].a == 3)
	{
		if (x >= 3)
		{
			return 'T';
		}
		else if (x < 3)
		{
			return 'F';
		}
	}
	else if (board[y][x].a == 2)
	{
		if (x >= 2)
		{
			return 'T';
		}
		else if (x < 2)
		{
			return 'F';
		}
	}
	else if (board[y][x].a == 1)
	{
		if (x >= 1)
		{
			return 'T';
		}
		else if (x < 1)
		{
			return 'F';
		}
	}
}
char right_able(Set board[ROW][COL], int x, int y)
{
	if (board[y][x].a == 4)
	{
		if (x == 0)
		{
			return 'T';
		}
		else
		{
			return 'F';
		}
	}
	else if (board[y][x].a == 3)
	{
		if (x <= 1)
		{
			return 'T';
		}
		else if (x > 1)
		{
			return 'F';
		}
	}
	else if (board[y][x].a == 2)
	{
		if (x <= 2)
		{
			return 'T';
		}
		else if (x > 2)
		{
			return 'F';
		}
	}
	else if (board[y][x].a == 1)
	{
		if (x <= 3)
		{
			return 'T';
		}
		else if (x > 3)
		{
			return 'F';
		}
	}
}
void player_stats(void)
{
		++Player_num;
		P[Player_num].turns = 0;
		strcpy(P[Player_num].name,"");
		menu_screen();
		player();
}
void In_the_game(Set board[ROW][COL])
{
	int s;
	char choice,win;
	do
	{
		system("cls");
		win = disp_arr(board);
		if (win == 'W')
		{
			win_screen();
			break;
		}
		choice = movement(board);
		if (choice == 'Q')
		{
			system("cls");
			P[Player_num].turns = 99;
			break;
		}
			if (choice == 'I')
		{
			info();
		}
		
	}while (s = 1);
	


}

void win_screen(void)
{
	system("cls");
	printf("\n\n");
	congratulations();
	printf("\n\n\n");
	system("pause");
}
char player(void)
{
	char name[50];
	int L,m = 0;
	system("cls");
	printf("\n\n%c You are about to play.\n%c First, let me know your name.", 178, 177);
	printf("\n%c ", 176);
	fflush(stdin);
	scanf("%s",name);
	L = strlen(name);
	if(L>7)
	{
		m = L-7;
		name[strlen(name)-m] = '\0';
		fflush(stdin);	
	}
	strcpy( P[Player_num].name,name);
	printf("%c\n%c\n%c Okay %s! Let's begin! %c\n\n", 176, 176, 176,name, 2);
	system("pause");
	info();
	system("cls");
}
int menu_screen(void)
{
	int y = 0, g;
	char menulist[4], go;
	for (g = 0; g < 4; g++)
	{
		menulist[g] = 'N';
	}
	menulist[0] = 'Y';
	print_menu(y);
	do
	{
		for (g = 0; g < 4; g++)
		{
			if (menulist[g] == 'Y')
			{
				y = g;
				break;
			}
		}
		go = menu_input(&y, menulist);
		system("cls");
		print_menu(y);
		if (go == 'Q')
		{
			return 0;
		}
		else if (go == 'B')
		{
			break;
		}
	}
	while (g = 1);
}
char menu_input(int *y, char menulist[4])
{
	char able_up = 'T';
	char able_down = 'T';
	char user_input;
	int H = *y;
	fflush(stdin);
	scanf("%c", &user_input);
	user_input = toupper(user_input);
	if (H == 0)
	{
		able_up = 'F';
	}
	else if (H == 3)
	{
		able_down = 'F';
	}
	else
	{
		able_up = 'T';
		able_down = 'T';
	}
	if (user_input == 'W')
	{
		if (able_up == 'T')
		{
			menulist[H] = 'N';
			H--;
			menulist[H] = 'Y';
		}
	}
	else if (user_input == 'S')
	{
		if (able_down == 'T')
		{
			menulist[H] = 'N';
			H++;
			menulist[H] = 'Y';
		}
	}
	else if (user_input == 'E')
	{
		if (H == 3)
		{
			exit(0);
		}
		else if (H == 0)
		{
			return 'B';
		}
		else if (H == 1)
		{
			info();
		}
		else if (H == 2)
		{
			High_Score();
		}
	}
	if (user_input == 'Q')
	{
		exit(0);
	}
	*y = H;
}
void print_menu(int y)
{
	system("cls");
	welcome();
	system("color 0F");
	printf("\n\n");
	if (y == 0)
	{
		printf("\t%c%c%c%c%c Play\n", 176, 176, 176, 177, 178);
	}
	else
	{
		printf("\t\tPlay\n");
	}
	if (y == 1)
	{
		printf("\t%c%c%c%c%c Info\n", 176, 176, 176, 177, 178);
	}
	else
	{
		printf("\t\tInfo\n");
	}
	if (y == 2)
	{
		printf("\t%c%c%c%c%c Scores\n", 176, 176, 176, 177, 178);
	}
	else
	{
		printf("\t\tScores\n");
	}
	if (y == 3)
	{
		printf("\t%c%c%c%c%c Quit\n", 176, 176, 176, 177, 178);
	}
	else
	{
		printf("\t\tQuit\n");
	}
	printf("\n\n");
	printf("%c Up     w\n", 30);
	printf("%c Down   d\n", 31);
	printf("%c Enter  e\n", 2);
	printf("\nInput %c  ", 240);
}
void info(void)
{
	system("color 0B");
	system("cls");
	printf("\n\n");
	printf("%c INFO:\n\n", 186);
	printf("Get yourself to the number zero(0)!\nGet the least number of steps to be on top!\n");
	printf("\n");
	printf("The numbers that you have \"stepped\" on (brackets as indicator) \n");
	printf("tells how many steps that you will take on your next move. \n");
	printf("Avoid stepping on the same spot, or 2 steps will be added to your score\n\n");
	printf("\n\n");
	printf("\t\t\t..............................\n");
	printf("\t\t\t| Creator: Eshan Shafeeq     |\n");
	printf("\t\t\t| Student ID: 4229665        |\n");
	printf("\t\t\t| Program: noPath Game(2011) |\n");
	printf("\t\t\t..............................\n\n");
	system("pause");
	system("cls");
	system("color 0F");
}
void welcome(void)
{
	printf("\n\n");
	printf("\t\t  .  .   .              \n");
	printf("\t\t  |  | _ | _. _ ._ _  _ \n");
	printf("\t\t  |/\\|(/,|(_.(_)[ | )(/,\n");
	printf("\n");
	printf("\t--.--                   ,---.     |    |    \n");
	printf("\t  |  ,---.    ,---.,---.|---',---.|--- |---.\n");
	printf("\t  |  |   |    |   ||   ||    ,---||    |   |\n");
	printf("\t  `  `---'    `   '`---'`    `---^`---'`   '\n");
}
void congratulations(void)
{
	printf("\n\n");
	printf(",---.                         |         |         |    o               |||\n");
	printf("|    ,---.,---.,---.,---.,---.|--- .   .|    ,---.|--- .,---.,---.,---.|||\n");
	printf("|    |   ||   ||   ||    ,---||    |   ||    ,---||    ||   ||   |`---.   \n");
	printf("`---'`---'`   '`---|`    `---^`---'`---'`---'`---^`---'``---'`   '`---'ooo\n\n");
	printf("          	---'  \n");
	printf("\t\t.   .                             .\n");
	printf("\t\t \\ /                              |\n");
	printf("\t\t  : .-. .  .   .  .    ._.-. .--. |\n");
	printf("\t\t  |(   )|  |    \\  \\  / (   )|  | '\n");
	printf("\t\t  ' `-' `--`     `' `'   `-' '  ' o\n");
}
void littleDetails(void)
{
	printf("\n");
	printf("\t%c W\n", 30);
	printf("%c A", 17);
	printf("\t\t%c D\n", 16);
	printf("\t%c S\n", 31);
	printf("\nQ - Main Menu\nI - Info\n");
	printf("Caution! Be careful where you enter! It counts.\n");
	
}
void High_Score(void)
{
	
	int g, h = Player_num, i;
	player_data temp[size], temp2[size]; /*Temporary storage*/
		
		system("cls");
		system("color 0A");
		
		printf("\n\nNAME\t\tSTEPS TAKEN\n\n");
		if (h == 0)
		{
			if ( P[0].turns == 99)
			{
				printf("%s\t:\t\tQuitted.\n", temp[0].name);
			}
			else if(P[0].turns == 0)
			{
				printf("");
			}
			else
			{
				printf("%s\t:\t\t%i\n", P[0].name, P[0].turns);
			}
		}
		
		else
		{
			for ( g = 0; g < h; g++)
			{
				temp[g].turns = 100;
				temp2[g].turns = P[g].turns;
				strcpy(temp2[g].name, P[g].name);
			}
			for ( g = 0; g < h; g++)
			{
				for ( i = 0; i < h; i++)
				{
					if (temp[g].turns > temp2[i].turns)
					{
						temp[g].turns = temp2[i].turns;
						strcpy(temp[g].name, temp2[i].name);
					}
				}
				for ( i = 0; i < h; i++)
				{
					if (temp[g].turns == temp2[i].turns)
					{
						temp2[i].turns = 100;
						break;
					}
				}
			}
			for ( g = 0; g < h; g++)
			{
				if ( temp[g].turns == 99)
				{
					printf("%s\t:\t\tQuitted.\n", temp[g].name);	   
				}
				else if(P[g].turns == 0)
				{
					printf("");
				}
				else
				{
					printf("%s\t:\t\t%i\n", temp[g].name, temp[g].turns);
				}
			}
			printf("\n\n\n");
		}
		
		system("pause");
		if(Player_num != 0)
		{
			Write_info(temp);
		}
		system("color 0F");
		
}
void Write_info(player_data PrintInfo[size])
{
	
	char Game_stats[] = "GameStats.txt";
	FILE *WriteF;
	int j, h = Player_num;
	
	WriteF = fopen(Game_stats,"w");
	if(WriteF == 0)
	{
		system("cls");
		printf("Cannot Write the data to the file");
		system("pause");
		system("cls");
	}
	else
	{
		if (h == 0)
		{
			if ( P[0].turns == 99)
			{
				fprintf(WriteF,"%s\t\t\tQuitted.\n", PrintInfo[0].name);
			}
			else
			{
				fprintf(WriteF,"%s\t\t\t%i\n", P[0].name, P[0].turns);
			}
		}
		else
		{
			for ( j = 0; j < h; j++)
			{
				if ( PrintInfo[j].turns == 99)
				{
					fprintf(WriteF,"%s\t\t\tQuitted.\n", PrintInfo[j].name);	    
				}
				else
				{
					fprintf(WriteF,"%s\t\t\t%i\n", PrintInfo[j].name, PrintInfo[j].turns);
				}
			}
			fprintf(WriteF,"@");
			fclose(WriteF);
		
		}
	
	
	
	}
}
void Read_info(void)
{	
	char Game_stats[] = "GameStats.txt";
	FILE *ReadF;
	int j= 0,h;
	char D[10],Q[10];
	
	ReadF = fopen(Game_stats,"r");
	if(ReadF == 0)
	{
	
		system("cls");
		printf("No High score's Exists\n\n");
		system("pause");
		system("cls");
	}
	else
	{
		do
		{
			fscanf(ReadF,"%s",D);
			strcpy(P[j].name,D);
			if(strcmp(D,"@")!=0)
			{
				fscanf(ReadF,"%s\n",Q);
				if(strcmp(Q,"Quitted.")== 0)
				{
					P[j].turns = 99;
				}	
				else
				{
					P[j].turns = atoi(Q);
				}
				j++;
			}
		}while (strcmp(D,"@")!=0);
		Player_num = (j-1);
	}
	fclose(ReadF);
}

