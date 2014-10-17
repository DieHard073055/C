#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i = 0, j = 0;
	double k[21];
	for (i = 0; i < 20; i++)
	{
		printf("%i Value\t", i + 1);
		scanf("%lf", &k[i]);
		
		printf("\n");
		k[i] = 60 * k[i];
	}
	for (i = 0; i < 20; i++)
	{
		printf("%.2f mins \n",k[i]);
	}
}

