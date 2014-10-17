#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 8

int board();

char C_board[N][N];
int QueenHistory[N*N][3];
int Queens_LOC[N][3];
int QCounter=0;
int QHCounter=0;
char QueenAttackRange[N][2];

int Get_Rand(int max, int min);
char deploy_the_Queen();
void print_Board();
char Queens_Attack_range(int c_Y,int c_X);
int QueenArrayInitialise();
int RemoveQueen();
char BoardRefresh();

int main()
{
	int number,o;
	board();
	QueenArrayInitialise();
	printf("\n\n\n\tHow many loops would you like to try\n\tLoops: ");
	scanf("%i",&number);
	
	for(o=0;o<number;o++)
	{
		deploy_the_Queen();
	}
	
	
	return 0;
}
int QueenArrayInitialise()
{
	int y,x;
	for(y=0;y<(N*N);y++)
	{
		for(x=0;x<3;x++)
		{
			QueenHistory[y][x] = -1;
		}
	
	}
	for(y=0;y<(N);y++)
	{
		for(x=0;x<3;x++)
		{
			Queens_LOC[y][x] = -1;
		}
	
	}
	
}
int board()
{
	int x,y;
	for(y=0;y<N;y++)
	{
		for(x=0;x<N;x++)
		{
			C_board[y][x] = '*';
		}
	}
}
char deploy_the_Queen()
{
	
	int pos_x,pos_y,_x,_y,x,y;
	char AllowDeploy1 = 'F',AllowDeploy2 = 'F',Space = 'F';
	if(QCounter < N)
	{
		for(y=0;y<N;y++)
		{
			for(x=0;x<N;x++)
			{
				if(C_board[y][x] == '*')
				{
					Space = 'T';
					break;
				}
			}
			if(Space == 'T')
			{
				break;
			}
			
		}
		if(Space == 'T')
		{
			do
			{
				pos_x = Get_Rand(7,0);
				pos_y = Get_Rand(7,0);
				
				if(C_board[pos_y][pos_x]=='*')
				{
					AllowDeploy1 = 'T';
				}
				else
				{
					AllowDeploy1 = 'F';
				}
				for(y=0;y<(N*N);y++)
				{
					if(QueenHistory[y][0] != -1 )
					{
						if(QueenHistory[y][1] == pos_y && QueenHistory[y][2] == pos_x)
						{
							AllowDeploy2 = 'F';
						}
						else
						{
							AllowDeploy2 = 'T';
						}
						
					}
					else
					{
						break;
					}
				}
			}while(AllowDeploy1 != 'T' && AllowDeploy2 != 'T');
		
			printf("\n\nx = %i  y = %i\n\n",pos_x,pos_y);
			C_board[pos_y][pos_x] = 'Q';
			Queens_LOC[QCounter][0] = QCounter;
			Queens_LOC[QCounter][1] = pos_y;
			Queens_LOC[QCounter][2] = pos_x;
			QueenHistory[QHCounter][0] = QHCounter;
			QueenHistory[QHCounter][1] = pos_y;
			QueenHistory[QHCounter][2] = pos_x;
			QCounter++;
			QHCounter++;
		
			Queens_Attack_range(pos_y,pos_x);
			print_Board();
			printf("\nQueen Added\n");
			system("pause");
		}
		else
		{
			RemoveQueen();
		}
	}
	else
	{
		RemoveQueen();
		
	}


}
int RemoveQueen()
{
	int pos_y,pos_x;
	
	C_board[Queens_LOC[QCounter][1]][Queens_LOC[QCounter][2]] = '*';
	Queens_LOC[QCounter][0] = -1;
	Queens_LOC[QCounter][1] = -1;
	Queens_LOC[QCounter][2] = -1;
	QCounter--;	
	BoardRefresh();
	print_Board();
	printf("\nQueen Removed\n");
	system("pause");
}
char BoardRefresh()
{
	int x,y;
	for(y=0;y<N;y++)
	{
		for(x=0;x<N;x++)
		{
			if(C_board[y][x]!= 'Q')
			{
				C_board[y][x] = '*';
			}
		}
	}
	for(y=0;y<QCounter;y++)
	{
		Queens_Attack_range(Queens_LOC[y][1],Queens_LOC[y][2]);
	}
}
int Get_Rand(int max, int min)
{
	static int init = 0;
	int ranNum;
	
	if(init == 0)
	{
		srand(time(NULL));
		init =1;
	}
	
	ranNum = (rand() % (max - min +1)+min);
	return ranNum;
}
void print_Board()
{
	int x,y;
	
	for(y=0;y<N;y++)
	{
		for(x=0;x<N;x++)
		{
			printf("%c\t",C_board[y][x]);
		}
		printf("\n\n");
	}
}
char Queens_Attack_range(int c_Y,int c_X)
{
	int x,y,pos_x,pos_y;
	pos_y = c_Y;
	pos_x = c_X;
	/*lower left corner*/
	x = pos_x;
	y = pos_y;
	while(x>-1&&y<8)
	{
		if(x == 0|| y == 7)
		{
			break;
		}
		else
		{
			x = x - 1;
			y = y + 1;
		}
		C_board[y][x] = '_';
	
	}
	/*Upper right corner*/
	x = pos_x;
	y = pos_y;
	while(x<8&&y>-1)
	{
		if(x == 7|| y == 0)
		{
			break;
		}
		else
		{
			x = x + 1;
			y = y - 1;
		}
		C_board[y][x] = '_';
	
	}
	/*Lower right corner*/
	x = pos_x;
	y = pos_y;
	while(x<8&&y<8)
	{
		if(x == 7|| y == 7)
		{
			break;
		}
		else
		{
			x = x + 1;
			y = y + 1;
		}
		C_board[y][x] = '_';
	
	}
	/*Upper Left corner*/
	x = pos_x;
	y = pos_y;
	while(x>-1&&y>-1)
	{
		if(x == 0|| y == 0)
		{
			break;
		}
		else
		{
			x = x - 1;
			y = y - 1;
		}
		C_board[y][x] = '_';
	
	}
	/*right Side*/
	x = pos_x;
	y = pos_y;
	while(x<8)
	{
		if(x == 7)
		{
			break;
		}
		else
		{
			x = x + 1;
			
		}
		C_board[y][x] = '_';
	
	}
		/*Left Side*/
	x = pos_x;
	y = pos_y;
	while(x>-1)
	{
		if(x == 0)
		{
			break;
		}
		else
		{
			x = x - 1;
			
		}
		C_board[y][x] = '_';
	
	}
		/*top Side*/
	x = pos_x;
	y = pos_y;
	while(y<8)
	{
		if(y == 7)
		{
			break;
		}
		else
		{
			y = y + 1;
			
		}
		C_board[y][x] = '_';
	
	}
		/*Left Side*/
	x = pos_x;
	y = pos_y;
	while(y>-1)
	{
		if(y == 0)
		{
			break;
		}
		else
		{
			y = y - 1;
			
		}
		C_board[y][x] = '_';
	
	}
}	

