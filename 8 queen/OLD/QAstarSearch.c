#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 8

typedef struct
{
	char real;
	char virt;
	
} ChessBoard;

typedef struct
{
	int history[N*N][3];
	int OnBoard[N][2];
	int QueenCounter;
	int TotalQueenCounter;
	int QueenRemovalCount;
}QueenData;

char Queens_Attack_Range(ChessBoard board[N][N],int QueenLoc[2]);
char DeployTheQueen(ChessBoard board[N][N],int QueenLoc[2]);
char PreRegulationForDeployment(ChessBoard board[N][N],QueenData Queen);
char PrintChessBoard(ChessBoard board[N][N]);
char GenerateRandomNum(int max, int min);
char BoardCleaner(ChessBoard board[N][N]);
void Initiallization(QueenData Queen);
int co_main(ChessBoard board[N][N],QueenData Queen);



int main()
{
	ChessBoard board[N][N];
	QueenData Queen;
	co_main(board,Queen);
	return 0;

}

int co_main(ChessBoard board[N][N],QueenData Queen)
{
	
	BoardCleaner(board);
	Initiallization(Queen);
	printf("\tafter initialization history %i\n",Queen.history[0][0]);
	system("pause");
	PreRegulationForDeployment(board,Queen);
	PrintChessBoard(board);

}
void Initiallization(QueenData Queen)
{
	int y,x;
	Queen.QueenCounter = 0;
	Queen.TotalQueenCounter = 0;
	Queen.QueenRemovalCount = 0;

	for(y=0;y<(N*N);y++)
	{
		for(x=0;x<3;x++)
		{
			(Queen->history[y][x]) = -1;
			if(y < N && x < 2)
			{
				Queen->(OnBoard[y][x]) = -1;
			}
		}
	}
	printf("\tInitialization history %i\n",Queen.history[0][0]);
	system("pause");
}
char GenerateRandomNum(int max, int min)
{
	static int Initial = 0;
	int RandNum;

	if(Initial == 0)
	{
		srand(time(NULL));
		Initial = 1;
	}
	RandNum = rand() % ((max - min + 1) + min);
	return RandNum;
}
char PrintChessBoard(ChessBoard board[N][N])
{
	int x,y;
	for(y=0;y<N;y++)
	{
		for(x=0;x<N;x++)
		{
			if(board[y][x].real != 'Q')
			{
				printf("\t%c",board[y][x].virt);
			}
			else
			{
				printf("\t{Q}");
			}
		}

		printf("\n\n\n");
	}

}
char PreRegulationForDeployment(ChessBoard board[N][N],QueenData Queen)
{
	int QueenLoc[2];
	int x,y;
	char AllowDeployment = 'F';
	static char FirstTimeRun = 'T';

	printf("\tpre starting history %i\n",Queen.history[0][0]);
	system("pause");
	while(AllowDeployment != 'T')
	{
		QueenLoc[0] = GenerateRandomNum((N-1),(N-N));
		QueenLoc[1] = GenerateRandomNum((N-1),(N-N));
printf("\tpre starting history %i\n",Queen.history[0][0]);
	system("pause");
		for(y=0;y<(Queen.TotalQueenCounter);y++)
		{
	printf("\tpre starting history %i\n",Queen.history[0][0]);
	system("pause");
			if(Queen.history[y][0] != -1)
			{
				if(Queen.history[y][1] != QueenLoc[0] && Queen.history[y][2] != QueenLoc[1])
				{
					if(y = (Queen.QueenCounter - 1))
					{
						if(board[QueenLoc[0]][QueenLoc[1]].virt != '%')
						{
							AllowDeployment = 'T';
						}
					}
				}
			}
			else
			{
				break;
			}
		}
		if(FirstTimeRun == 'T')
		{
			AllowDeployment = 'T';
			FirstTimeRun = 'F';
		}
	}

	
	Queen.history[Queen.TotalQueenCounter][0] = Queen.TotalQueenCounter;
	Queen.history[Queen.TotalQueenCounter][1] = QueenLoc[0];
	Queen.history[Queen.TotalQueenCounter][2] = QueenLoc[1];
	Queen.OnBoard[Queen.QueenCounter][0] = QueenLoc[0];
	Queen.OnBoard[Queen.QueenCounter][1] = QueenLoc[1];

	Queen.TotalQueenCounter++;
	Queen.QueenCounter++;

	DeployTheQueen(board,QueenLoc);


}
char RemoveQueen(ChessBoard board[N][N],QueenData Queen,int y,int x)
{
	int storeX,storeY;
	int QueenLoc[2];
	int tempQueenLoc[N][2];
	if(y==-1&&x==-1)
	{
		for(y=0;y<(Queen.QueenRemovalCount);y++)
		{
			storeY=Queen.OnBoard[y][0];
			storeX=Queen.OnBoard[y][1];

			board[storeY][storeX].real = 'e';
			Queen.QueenCounter--;
		}
	}
	else
	{
		storeY = y;
		storeX = x;

		board[storeY][storeX].real = 'e';
		Queen.QueenCounter--;
		for(y=0;y<(Queen.QueenCounter);y++)
		{
			for(x=0;x<2;x++)
			{
				if(Queen.OnBoard[y][0]!=storeY && Queen.OnBoard[y][1]!= storeX)
				{
					tempQueenLoc[y][x] = Queen.OnBoard[y][x];
				}
			}
		}
		for(y=0;y<(Queen.QueenCounter);y++)
		{
			for(x=0;x<2;x++)
			{
				Queen.OnBoard[y][x] = tempQueenLoc[y][x];
			}
		}

	}

	BoardCleaner(board);
	for(y=0;y<(Queen.QueenCounter);y++)
	{
		QueenLoc[0] = Queen.OnBoard[y][0];
		QueenLoc[1] = Queen.OnBoard[y][1];
		DeployTheQueen(board,QueenLoc);
	}
}
char DeployTheQueen(ChessBoard board[N][N],int QueenLoc[2])
{
	int x, y;
	printf("y = %i, x = %i\n\n",QueenLoc[0],QueenLoc[1]);

	board[QueenLoc[0]][QueenLoc[1]].real = 'Q';
	Queens_Attack_Range(board,QueenLoc);

}
char BoardCleaner(ChessBoard board[N][N])
{
	int x,y;
	for(y=0;y<N;y++)
	{
		for(x=0;x<N;x++)
		{
			board[y][x].real = 'e';
			board[y][x].virt = '_';
		}
	}
}
char Queens_Attack_Range(ChessBoard board[N][N],int QueenLoc[2])
{
	int x,y;

	y = QueenLoc[0] ;
	x = QueenLoc[1] ; 

	/*Right top Corner*/
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
		board[y][x].virt = '%';
	
	}

	y = QueenLoc[0] ;
	x = QueenLoc[1] ; 

	/*Right bottom Corner*/
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
		board[y][x].virt = '%';
	
	}

	y = QueenLoc[0] ;
	x = QueenLoc[1] ; 

	/*Left top Corner*/
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
		board[y][x].virt = '%';
	
	}

	y = QueenLoc[0] ;
	x = QueenLoc[1] ; 

	/*Left bottom Corner*/
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
		board[y][x].virt = '%';
	
	}

	y = QueenLoc[0] ;
	x = QueenLoc[1] ; 

	/*Right Side*/
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
		board[y][x].virt = '%';
	
	}

	y = QueenLoc[0] ;
	x = QueenLoc[1] ; 

	/*Left Side*/
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
		board[y][x].virt = '%';
	
	}


	y = QueenLoc[0] ;
	x = QueenLoc[1] ; 

	/*Top*/
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
		board[y][x].virt = '%';
	
	}

	y = QueenLoc[0] ;
	x = QueenLoc[1] ; 

	/*Bottom*/
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
		board[y][x].virt = '%';
	
	}
	
}

