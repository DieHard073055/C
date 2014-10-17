#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/* Default Board Size*/
int b_ = 4;

typedef struct
{
	char virt; /* Virtual Array Slot */
	int real; /* Real Array Slot*/
	
}board;


int Get_Ran();
int Array_Setup(board A[b_][b_]);
char Check_for_repeat(int num,board A[b_][b_]);
char V_Array_setup(board A[b_][b_]);
char sx_inc(int sx, char m_sx[2]);
char sy_inc(int sy, char m_sx[2]);
char printV(board A[b_][b_]);

main()
{
	int x,y;
	board A[b_][b_];
	
	Array_Setup(A);
	for(y=0;y<b_;y++)
	{
		for(x=0;x<b_;x++)
		{
			if(A[y][x].real == (b_ * b_))
			{
				printf("*\t");
			}
			else
			{
				printf("%i\t",A[y][x].real);
			}
		}
		printf("\n\n\n");
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
	
	V_Array_setup(A);
	printV(A);
	printf("\n\n\n\n\n");	
	
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
char V_Array_setup(board A[b_][b_])
{
	int x,y,sx,sy;
	char m_sx[2]={"TT"},m_sy[2]={"TT"};
	
	for(y=0;y<b_;y++)
	{
		for(x=0;x<b_;x++)
		{
			A[y][x].virt = 'x';
		}
	}
	
	for(y=0;y<b_;y++)
	{
		for(x=0;x<b_;x++)
		{
			if(A[y][x].real == (b_ * b_))
			{
				A[y][x].virt = '-';
				sx = x;
				sy = y;
			}
		}
	}
	sx_inc(sx,m_sx);
	sy_inc(sy,m_sy);
	
	if(m_sx[0] == 'T')
	{
		A[sy][sx - 1].virt = 'A';
	}
	if(m_sx[1] == 'T')
	{
		A[sy][sx + 1].virt = 'D';
	}
	if(m_sy[0] == 'T')
	{
		A[sy - 1][sx].virt = 'W';
	}
	if(m_sy[1] == 'T')
	{
		A[sy + 1][sx].virt = 'S';
	}
	
}
char sx_inc(int sx, char m_sx[2])
{
	if(sx == 0)
	{
		m_sx[0] = 'F';
		m_sx[1] = 'T';
	}
	else if(sx == b_ - 1)
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
	if(sy == 0)
	{
		m_sy[0] = 'F';
		m_sy[1] = 'T';
	}
	else if(sy == b_ - 1)
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
	for(y=0;y<b_;y++)
	{
		for(x=0;x<b_;x++)
		{
			printf("%c\t",A[y][x].virt);
		}
		printf("\n\n\n");
	}

}

