#include<stdio.h>
#include<time.h>
char CCRP (char input[4], char code[4]);
void CCWP (char input[4], char code[4]);
void CA(char code[4]);
void Congrat(void);
void ins (void);
char CCRP (char input[4], char code[4])
{
	int j,k = 0;
	for (j=0;j<4;j++)
	{	
		if(input[j] == code[j])
		{
			printf("#");
			k++;
		}
	}
	printf("\n");
	
	if(k==4)
	{
		return('T');
	}
	
}
void CCWP (char input[4], char code[4])
{
	int j,k;
	char ch[4];
	for (j=0;j<4;j++)
	{	
		for(k=0;k<4;k++)
		{
			if (code[j] == input[k])
			{	
				ch[j] = 'T';
			}
		}
	}

	for(k=0;k<4;k++)
		{
			if (ch[k] == 'T')
			{	
				printf("@");
			}
		}
		printf("\n");
}

void CA(char code[4])
{
	int j;
	char color[6] = {'A', 'B', 'C', 'D', 'E', 'F'};
	srand((unsigned)time(NULL));
	
	for (j=0;j<4;j++)
	{
		code[j] = color[rand() % 6];
	}
}
void Congrat(void)
{
printf("Congratulations You've Won the game!!!\n");
}
void ins (void)
{
	printf("Welcome to Mastermind\n");
	printf("Guess the Letters!!\n\n");
}
int main()
{
	int j,loop = 0,trial = 0;
	char code[4],input[4],GF = 'F';
	CA(code);
	for (j=0;j<4;j++)
		{printf("%c\t",code[j]);}
		printf("\n\n\n");
	do
	{
		ins();
		printf("Your number of trials = %i\n\n",trial);
		for (j=0;j<4;j++)
		{
			printf("Guess %i\t",j+1);
			fflush(stdin);
			scanf("%c",&input[j]);
			if(toupper(input[j]) == 'Q')
			{
				return 0;
			}
		}
		GF = CCRP(input,code);
		CCWP(input,code);
		if(GF == 'T')
		{
		Congrat();
		system("pause");
		return 0;
		}
		trial++;
		system("pause");
		system("cls");
	}while (loop = 2);
}

