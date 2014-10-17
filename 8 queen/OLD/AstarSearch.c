#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define N 8
typedef struct
{
	char real;
	char virtual;
	
} ChessBoard;

char Queens_Attack_Range(ChessBoard board[N][N],int QueenLoc[2]);
char DeployTheQueen(ChessBoard board[N][N]);
char PrintChessBoard(ChessBoard board[N][N]);
char GenerateRandomNum(int max, int min);
char BoardCleaner(ChessBoard board[N][N]);
int co_main(ChessBoard board[N][N]);

int co_main(ChessBoard board[N][N]);

int main()
{
	ChessBoard board[N][N];
	co_main(board);
	return 0;

}

int co_main(ChessBoard board[N][N])
{

	BoardCleaner(board);
	DeployTheQueen(board);
	PrintChessBoard(board);

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
				printf("\t%c",board[y][x].virtual);
			}
			else
			{
				printf("\t{Q}");
			}
		}

		printf("\n\n\n");
	}

}
char DeployTheQueen(ChessBoard board[N][N])
{
	int x, y;
	int QueenLoc[2];

	QueenLoc[0] = GenerateRandomNum((N-1),(N-N));
	QueenLoc[1] = GenerateRandomNum((N-1),(N-N));
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
			board[y][x].virtual = '_';
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
		board[y][x].virtual = '%';
	
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
		board[y][x].virtual = '%';
	
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
		board[y][x].virtual = '%';
	
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
		board[y][x].virtual = '%';
	
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
		board[y][x].virtual = '%';
	
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
		board[y][x].virtual = '%';
	
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
		board[y][x].virtual = '%';
	
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
		board[y][x].virtual = '%';
	
	}
	
}

