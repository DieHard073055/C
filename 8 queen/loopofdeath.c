#include <stdio.h>
#define SIZE 8
int main()
{
	int i,j,k,l;
	k=0;
	l=0;
	for(i=0;i<=SIZE;i++)
	{
		printf("\n\t%i",i);
		if(i==SIZE)
		{
			printf("\n\n");
			l++;
			if(l==SIZE)
				l=1;
			
			for(j=0;j<l;j++)
			{
				i--;
				printf("\n\t%i",i);
			}

			
		}
		k++;
		if(k==20)
		{
			getch();
			k=0;
		}
	}
	return 0;
}	
