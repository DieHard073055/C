#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 8



char C_board[N][N];


int board();
int Get_Rand(int max, int min);
char deploy_the_Queen();
void print_Board();
char Queens_Attack_range();
char Empty_Slot_Checker();

int main()
{
	board();
	
	
	
	deploy_the_Queen();
	print_Board();
	
	
	
	return 0;
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
	for(y=0;y<N;y++)
	{
		for(x=0;x<N;x++)
		{
			if(C_board[y][x] == '_')
			{
				_x = x;
				_y = y;
			}
		}
		
	}
	do
	{
		pos_x = Get_Rand(7,0);
		pos_y = Get_Rand(7,0);
	}while(pos_x == _x && pos_y == _y);
	printf("\n\nx = %i  y = %i\n\n",pos_x,pos_y);
	C_board[pos_y][pos_x] = 'Q';
	Queens_Attack_range();



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
char Queens_Attack_range()
{
	int x,y,pos_x,pos_y;
	for(y=0;y<N;y++)
	{
		for(x=0;x<N;x++)
		{
			if(C_board[y][x] == 'Q')
			{
				pos_x = x;
				pos_y = y;
				printf("x = %i y = %i\n\n",pos_x,pos_y);
			}
		}
		
	}
	/*lower left corner*/
	x = pos_x;
	y = pos_y;
	printf("x = %i y = %i\n\n",x,y);
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
	printf("x = %i y = %i\n\n",x,y);
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
	printf("x = %i y = %i\n\n",x,y);
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
	printf("x = %i y = %i\n\n",x,y);
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
	printf("x = %i y = %i\n\n",x,y);
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
	printf("x = %i y = %i\n\n",x,y);
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
	printf("x = %i y = %i\n\n",x,y);
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
	printf("x = %i y = %i\n\n",x,y);
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

