#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/* Default Board Size*/
int b_ = 3;

typedef struct
{
	char virt; /* Virtual Array Slot */
	int real; /* Real Array Slot*/
	
}board;


int Get_Ran();
int Array_Setup(board A[b_][b_]);
char Check_for_repeat(int num,board A[b_][b_]);

main()
{
	int x,y;
	board A[b_][b_];
	
	Array_Setup(A);
	for(y=0;y<b_;y++)
	{
		for(x=0;x<b_;x++)
		{
			if(A[y][x].real == 9)
			{
				printf("*\t");
			}
			else
			{
				printf("%i\t",A[y][x].real);
			}
		}
		printf("\n");
	}

}
int Array_Setup(board A[b_][b_])
{
	int num;
	int x,y;
	char val = 'T';
	
	
	for(y=0;y<b_;y++)
	{
		for(x=0;x<b_;x++)
		{
			
			A[y][x].real = 0;
		}
	}
	A[0][0].real = 9;
	
	for(y=0;y<b_;y++)
	{
		for(x=0;x<b_;x++)
		{
			do{
				num = Get_Ran();
				val = Check_for_repeat(num,A);
				if(val == 'T')
				{
					A[y][x].real = num;
					break;
				}
			}while(val = 'T');
		}
	}



}
char Check_for_repeat(int num,board A[b_][b_])
{
	int x,y;
	for(x=0;x<b_;x++)
	{
		for(y=0;y<b_;y++)
		{
			if(A[y][x].real == num)
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
	
	if(init == 0)
	{
		srand((unsigned)time(NULL));
		init =1;
	}
	
	i = ( rand() % (max - min + 1) + min );
		
}

