#include<stdio.h>
#include<stdlib.h>
char Assign(char A[2]);
char Display(char A[2]);
char Choice(char A[2]);
main()
{
	char A[2];
	Assign(A);
	do
	{
		Display(A);
		Choice(A);
			
	}while(-1);
}
char Assign(char A[2])
{
	
	int i;
	
	for( i = 0; i < 2; i++)
	{
		A[i] = 'A';
	}
	A[0] = 'B';
}
char Display(char A[2])
{
	system("cls");
	printf("\n\n\n");
	if(A[0] == 'B')
	{
		printf("\t\t%cCode File Reader\n",26);
		printf("\t\t Message Coder\n");
	}
	else if(A[1] == 'B')
	{
		printf("\t\t Code File Reader\n");
		printf("\t\t%cMessage Coder\n",26);
	}
}
char Choice(char A[2])
{
	char ans;
	int i;
	printf("\n\n");
	printf("Please choose which program you want to use.\n\nW\t To Move the Selection Up\nS \tTo Move the Selection Down");
	printf("\n\nChoice : ");
	fflush(stdin);
	scanf("%c",&ans);
	ans = toupper(ans);
	
	for(i=0;i<2;i++)
	{
		if(A[i] == 'B')
		{break;}
	}
	if(ans == 'W')
	{
		if(i == 1)
		{
			A[i] = 'A';
			i--;
			A[i] = 'B'	 ;
		}
		 
	}
	else if (ans == 'S')
	{
		if(i == 0)
		{
			A[i] = 'A';
			i++;
			A[i] = 'B';
		}
	}
	else if (ans == 'E')
	{
		if(i == 0)
		{
			system("cls");
			printf("Reader\n\n");
			system("pause");
		}
		else if(i == 1)
		{
			system("cls");
			printf("Writer\n\n");
			system("pause");
		}
	}
	else if (ans == 'Q')
	{
		exit(-1);
	}
}

