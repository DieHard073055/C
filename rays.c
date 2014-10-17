#include<stdio.h>
main()
{
	/* Declarations */
	int j, k, l, m, n, o;
	int a, b, c;
	b = 15;
	a = b + 1; /* Number of lines u wanna have in the thing thing */
	for ( j = a; j > 0; j--)
	{
		/*	  printf(" "); */
		for ( l = 1; l < 2; l++)
		{
			for ( k = 0; k < j ; k++)
			{
				printf(" ");
			}
			for ( m = j; m > 0 ; m--)
			{
				printf("*");
			}
			for ( o = 0; o < j ; o++)
			{
				printf(" ");
			}
			for ( n = j; n > 0 ; n--)
			{
				printf("*");
			}
			printf("\n");
		}
	}
}

