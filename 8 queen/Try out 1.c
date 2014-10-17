#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#define SIZE 8

typedef struct 
{
	/* data */
	char mark;
	char queen;

} BoardDetails;

char BoardRefresh (BoardDetails B[SIZE][SIZE], char method);
char DeployAttackRange (BoardDetails B[SIZE][SIZE],int st_y,int st_x);
int RandomNumGen (int max , int min);
void printBoard(BoardDetails B[SIZE][SIZE]);

int main()
{
	int y,x;
	BoardDetails B[SIZE][SIZE];

	/*#############################*/
	y=RandomNumGen(SIZE-1,0);
	x=RandomNumGen(SIZE-1,0);

	B[y][x].queen = 'Q';
	BoardRefresh(B,'Q');
	printBoard(B);
	/*##############################*/
	
	return 0;
}
char BoardRefresh (BoardDetails B[SIZE][SIZE], char method)
{
	int y,x;

	for(y=0;y<SIZE;y++)
	{
		for(x=0;x<SIZE;x++)
		{
			B[y][x].mark = '_';
		}
	}
	if(method == 'Q')
	{
		for(y=0;y<SIZE;y++)
		{
			for(x=0;x<SIZE;x++)
			{
				if(B[y][x].queen == 'Q')
				{
					/*Deploy the attack range for the queen*/
					DeployAttackRange (B,y,x);

				}
			}
		}
	}

}
char DeployAttackRange (BoardDetails B[SIZE][SIZE],int st_y,int st_x)
{
	int y,x;

	/*top*/
	for(y=st_y;y>-1;y--)
	{
		B[y][st_x].mark = 'x';
	}
	/*bottom*/
	for(y=st_y;y<SIZE;y++)
	{
		B[y][st_x].mark = 'x';
	}
	/*left*/
	for(x=st_x;x>-1;x--)
	{
		B[st_y][x].mark = 'x';
	}
	/*Right*/
	for(x=st_x;x<SIZE;x++)
	{
		B[st_y][x].mark = 'x';
	}
	/*top left corner*/
	y=st_y;x=st_x;
	while(y > -1 && x > -1)
	{
		
		B[y--][x--].mark = 'c';
	}
	/*top right corner*/
	y=st_y;x=st_x;
	while(y > -1 && x < SIZE)
	{
		B[y--][x++].mark = 'c';
	}
	/*Bottom right corner*/
	y=st_y;x=st_x;
	while(y < SIZE && x < SIZE)
	{
		B[y++][x++].mark = 'c';
	}
	/*Bottom left corner*/
	y=st_y;x=st_x;
	while(y < SIZE && x > -1)
	{
		B[y++][x--].mark = 'c';
	}
}
int RandomNumGen (int max , int min)
{
	static int init = 0;
	int random;

	if (init == 0)
	{
		init = 1;
		srand(time(NULL));
	}
	random = rand() % (max - min + 1) + min;
	printf("\n\tRandom Number = %i\n",random);
	return random;
}
void printBoard(BoardDetails B[SIZE][SIZE])
{
	int y,x;
	for(y=0;y<SIZE;y++)
	{
		for(x=0;x<SIZE;x++)
		{
			if(B[y][x].queen == 'Q')
			{
				printf("\tQ");
			}
			else
			{
				printf("\t%c",B[y][x].mark);
			}
		}printf("\n\n\n");
	}
}

