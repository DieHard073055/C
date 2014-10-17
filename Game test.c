#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int Get_rand (int min, int max );





int main(void)
	{
		int i, j;
		struct Array_for_the_Board
		{
			int ran;
			char Valid;	

		} spot[5][5];
	
	
	
		for ( i = 0; i < 5; i++){
			for (j = 0; j < 5; j++){
				spot[i][j].ran = Get_rand(0,5);
			}
		}
		
		
		for ( i = 0; i < 5; i++){
			for (j = 0; j < 5; j++){
				printf("%i\t" , spot[i][j].ran);
			}
			printf("\n");
		}
		
		







		return(0);
		
	}

		int Get_rand (int min, int max)
		{
			static int initial = 0;
			int Num = 0;
			if (initial == 0)
			{
				srand(time(NULL));
				initial = 1;
			}
			Num = ( rand() % ( max - min + 1 ) + min );
			return (Num);
		}

