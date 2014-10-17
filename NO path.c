#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define R 10
#define C 5
typedef struct
{
	int a;
	char b;
}my_Board;
void ran (my_Board spot[R][C]);
void curb_1(char n4, char n1, int *max, int *min);
void Disp_(my_Board spot[R][C]);
void spot_er(my_Board spot[R][C], int *y, int *x);
char Agent_Bracket(my_Board spot[R][C]);
void shift_up (my_Board spot[R][C]);
void shift_down (my_Board spot[R][C]);
void shift_left (my_Board spot[R][C]);
void shift_right (my_Board spot[R][C]);
char potential_Y_p_incrmnt(my_Board spot[R][C], int y, int x);
char potential_Y_n_incrmnt(my_Board spot[R][C], int y, int x);
char potential_X_p_incrmnt(my_Board spot[R][C], int y, int x);
char potential_X_n_incrmnt(my_Board spot[R][C], int y, int x);
void ran (my_Board spot[R][C])
{
	int y, x;
	static int prelim_ = 0;
	int max = 4, min = 1;
	char n1 = 'T', n4 = 'T';
	int N1 = 0;
	if (prelim_ == 0)
	{
		srand((unsigned)time(NULL));
		prelim_ = 1;
	}
	for ( y = 0; y < R; y++)
	{
		for ( x = 0; x < C; x++)
		{
			curb_1(n4, n1, &max, &min);
			if ( (y % 2) == 0)
			{
				if (y == ((R / 2) - 1) && x == ((C - 1) / 2) )
				{
					spot[y][x].a = (rand() %  (2 - min + 1) + min);
				}
				else
				{
					spot[y][x].a = (rand() %  (max - min + 1) + min);
				}
				if (	spot[y][x].a == 4 )
				{
					n4 = 'F';
				}
				else if ( spot[y][x].a == 1 )
				{
					N1++;
					if (N1 > 4)
					{
						n1 = 'F';
					}
					else if ( N1 <= 4)
					{
						n1 = 'T';
					}
				}
			}
			else if ((y % 2) == 1)
			{
				spot[y][x].a = 0;
			}
			spot[y][x].b = 'O';
		}
	}
	spot[0][0].b = 'I';
	spot[8][4].a = 0;
}
void curb_1(char n4, char n1, int *max, int *min)
{
	if (n4 == 'T')
	{
		*max = 4;
	}
	else
	{
		*max = 3;
	}
	if (n1 == 'T')
	{
		*min = 1;
	}
	else if (n1 == 'F')
	{
		*min = 2;
	}
}
void Disp_(my_Board spot[R][C])
{
	int y = 0, x = 0, j, k;
	spot_er(spot, &y, &x);
	for ( j = 0;j < R;j++)
	{
		for (k = 0;k < C;k++)
		{
			if ((j % 2) == 0)
			{
				if (j == y && k == x)
				{
					printf("[%i]\t", spot[j][k].a);
				}
				else
				{
					printf("%i\t", spot[j][k].a);
				}
			}
			else if ((j % 2) == 1)
			{
				if ( spot[j][k].b == 'O')
				{
					printf(" \t");
				}
				else if ( spot[j][k].b == 'J')
				{
					printf("-\t");
				}
				else if ( spot[j][k].b == 'K')
				{
					printf("=\t");
				}
			}
		}
		printf("\n");
	}
}
void spot_er(my_Board spot[R][C], int *y, int *x)
{
	int j, k;
	for ( j = 0;j < R;j += 2)
	{
		for (k = 0;k < C;k++)
		{
			if (spot[j][k].b == 'I')
			{
				*y = j;
				*x = k;
			}
		}
	}
}
char Agent_Bracket(my_Board spot[R][C])
{
	char fdbck;
	fflush(stdin);
	scanf("%c", &fdbck);
	if (toupper(fdbck) == 'Q')
	{
		return 'Q';
	}
	else if (toupper(fdbck) == 'W')
	{
		shift_up(spot);
	}
	else if (toupper(fdbck) == 'S')
	{
		shift_down(spot);
	}
	else if (toupper(fdbck) == 'A')
	{
		shift_left(spot);
	}
	else if (toupper(fdbck) == 'D')
	{
		shift_right(spot);
	}
	else
	{
		printf("");
	}
}
void shift_up (my_Board spot[R][C])
{
	int y, x;
	char potential = 'F';
	spot_er(spot, &y, &x);
	potential = potential_Y_n_incrmnt(spot, y, x);
	if ( potential == 'T')
	{
		spot[y][x].b = 'O';
		y -= (spot[x][y].a);
		y -= (spot[x][y].a);
		spot[y][x].b = 'I';
	}
	else if ( potential == 'F')
	{
		printf("");
	}
}
char potential_Y_n_incrmnt(my_Board spot[R][C], int y, int x)
{
	if ( spot[y][x].a == 4 )
	{
		if ( y < 4 )
		{
			return ('F');
		}
		else if ( y == 4 )
		{
			return ('T');
		}
	}
	else if ( spot[y][x].a == 3 )
	{
		if ( y < 3 )
		{
			return ('F');
		}
		else if ( y == 3 || y == 4)
		{
			return ('T');
		}
	}
	else if ( spot[y][x].a == 2 )
	{
		if ( y < 2 )
		{
			return ('F');
		}
		else if ( y == 2 || y == 3 || y == 4)
		{
			return ('T');
		}
	}
	else if ( spot[y][x].a == 1 )
	{
		if ( y < 1 )
		{
			return ('F');
		}
		else if ( y == 1 || y == 2 || y == 3 || y == 4)
		{
			return ('T');
		}
	}
}
void shift_down (my_Board spot[R][C])
{
	int y, x;
	char potential = 'T';
	spot_er(spot, &y, &x);
	potential = potential_Y_p_incrmnt(spot, y, x);
	if ( potential == 'T')
	{
		spot[y][x].b = 'O';
		y += (spot[x][y].a );
		y += (spot[x][y].a );
		spot[y][x].b = 'I';
	}
	else if ( potential == 'F')
	{
		printf("");
	}
}
char potential_Y_p_incrmnt(my_Board spot[R][C], int y, int x)
{
	if ( spot[y][x].a == 4 )
	{
		if ( y > 0 )
		{
			return ('F');
		}
		else if ( y == 0 )
		{
			return ('T');
		}
	}
	else if ( spot[y][x].a == 3 )
	{
		if ( y > 1 )
		{
			return ('F');
		}
		else if ( y == 1 || y == 0 )
		{
			return ('T');
		}
	}
	else if ( spot[y][x].a == 2 )
	{
		if ( y > 2 )
		{
			return ('F');
		}
		else if ( y == 2 || y == 1 || y == 0 )
		{
			return ('T');
		}
	}
	else if ( spot[y][x].a == 1 )
	{
		if ( y > 3 )
		{
			return ('F');
		}
		else if ( y == 3 || y == 2 || y == 1 || y == 0 )
		{
			return ('T');
		}
	}
}
void shift_left (my_Board spot[R][C])
{
	int y, x;
	char potential = 'T';
	spot_er(spot, &y, &x);
	potential = potential_X_n_incrmnt(spot, y, x);
	if ( potential == 'T')
	{
		spot[y][x].b = 'O';
		x -= spot[x][y].a;
		spot[y][x].b = 'I';
	}
	else if ( potential == 'F')
	{
		printf("");
	}
}
char potential_X_n_incrmnt(my_Board spot[R][C], int y, int x)
{
	if ( spot[y][x].a == 4 )
	{
		if ( x < 4 )
		{
			return ('F');
		}
		else if ( x == 4 )
		{
			return ('T');
		}
	}
	else if ( spot[y][x].a == 3 )
	{
		if ( x < 3 )
		{
			return ('F');
		}
		else if ( x == 3 || x == 4)
		{
			return ('T');
		}
	}
	else if ( spot[y][x].a == 2 )
	{
		if ( x < 2 )
		{
			return ('F');
		}
		else if ( x == 2 || x == 3 || x == 4)
		{
			return ('T');
		}
	}
	else if ( spot[y][x].a == 1 )
	{
		if ( x < 1 )
		{
			return ('F');
		}
		else if ( x == 1 || x == 2 || x == 3 || x == 4)
		{
			return ('T');
		}
	}
}
void shift_right (my_Board spot[R][C])
{
	int y, x;
	char potential = 'T';
	spot_er(spot, &y, &x);
	potential = potential_X_p_incrmnt(spot, y, x);
	if ( potential == 'T')
	{
		spot[y][x].b = 'O';
		x += spot[x][y].a;
		spot[y][x].b = 'I';
	}
	else if ( potential == 'F')
	{
		printf("");
	}
}
char potential_X_p_incrmnt(my_Board spot[R][C], int y, int x)
{
	if ( spot[y][x].a == 4 )
	{
		if ( x > 0 )
		{
			return ('F');
		}
		else if ( x == 0 )
		{
			return ('T');
		}
	}
	else if ( spot[y][x].a == 3 )
	{
		if ( x > 1 )
		{
			return ('F');
		}
		else if ( x == 1 || x == 0 )
		{
			return ('T');
		}
	}
	else if ( spot[y][x].a == 2 )
	{
		if ( x > 2 )
		{
			return ('F');
		}
		else if ( x == 2 || x == 1 || x == 0 )
		{
			return ('T');
		}
	}
	else if ( spot[y][x].a == 1 )
	{
		if ( x > 3 )
		{
			return ('F');
		}
		else if ( x == 3 || x == 2 || x == 1 || x == 0 )
		{
			return ('T');
		}
	}
}
int main()
{
	int loop;
	char input;
	my_Board spot[R][C];
	ran(spot);
	do
	{
		Disp_(spot);
		input = Agent_Bracket(spot);
		if (input == 'Q')
		{
			return 0;
		}
		else if ( input != 'Q' )
		{
			continue;
		}
		system("cls");
		
	}
	while (loop = 3);
}

