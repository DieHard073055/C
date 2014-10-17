#include <stdio.h>
#include <conio.h>

char Dream_function(int *DreamCount, int *DreamNum);
void herp(void);
int Getran(int max, int min);
void derp(int i);
int main()
{
	int Dreams =0;
	int DreamNum = 0;
	Dream_function(&Dreams,&DreamNum);
	system("pause");

}
char Dream_function(int *DreamCount, int *DreamNum)
{
	int Dream,Num,i;
	Dream = *DreamCount;
	printf("Your in Dream Layer %i\n",*DreamNum);
	Dream++;
	Num = *DreamNum;
	Num++;
	*DreamCount = Dream;

	if(*DreamCount == 25)
	{
		printf("Press any key to get out of the dreams\n\n");
		getch();
		printf("\n\n\tChurchill's KICK; Function Deployed.\n");
		fflush(stdin);
		getch();
		printf("\nSelecting a Random KICK; Method\n");
		
		herp();
		printf("\n");
		return'O';
	}
	else
	{
		*DreamNum = Num;
		Dream_function(DreamCount,DreamNum);
	}
		printf("Going out of Dream %i\n",*DreamNum);
		Num--;
		*DreamNum = Num;
}
void herp(void)
{
	int i, j, k, l;
	int method;

	for (i = 0; i < 30 ;i++)
	{
		l = i;
		for ( j = 0;j < 30;j++)
		{
			derp(l);
			printf("Data files.\n");
			
			printf(".....");
			system("cls");
		}
		for ( k = 0;k < 30;k++)
		{
			
			derp(l);
			printf("Itching the head.\n");
			
			printf("..");
			system("cls");
		}
		for ( k = 0;k <30;k++)
		{
			derp(l);
			printf("Reading.\n");
			
			printf("...");
			system("cls");
		}
		for ( k = 0;k < 30;k++)
		{
			
			derp(l);
			printf("Taking a mini break\n");
			
			printf("...");
			system("cls");
		}
	}
	method = Getran(4,1);
	if(method == 1)
	{
		printf("\n\n\tSelected Method \n\tFall of a chair\n\n");
	}
	else if(method == 2)
	{
		printf("\n\n\tSelected Method \n\tFall of a cliff\n\n");
	}
	else if(method == 3)
	{
		printf("\n\n\tSelected Method \n\tShoot the Head\n\n");
	}
	else if(method == 4)
	{
		printf("\n\n\tSelected Method \n\tDrown Your self\n\n");
	}
	getch();

}
int Getran(int max, int min)
{
	static int h = 0;
	int random;

	if (h==0)
	{
		h=1;
		srand(time(NULL));
	}
	random = rand() % (max - min + 1) + min;
	return random;
}
void derp(int i)
{
	if (i <= 10)
	{
		printf("Loading a KICK; method.\n");
		
	}
	else if (i > 10 && i <= 18)
	{
		printf("Serching for a better KICK; method..\n");
	}
	else if (i > 18 && i <= 29)
	{
		printf("Checking if the KICK; method makes any sense...\n");
	}
	else if (i > 29 && i <= 30)
	{
		printf("Calculating the mass of the sun.....\n");
	}
	else printf("Done.");
}
