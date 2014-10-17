#include<stdlib.h>
#include<string.h>
#include<stdio.h>

typedef struct
{
	char Name[50];
	char score[10];
}player_data;

player_data Players[10];
int Num_P = -1;

int Get_Ran();
char player_Records(char Name[50],int score);
char Get_Name(char Name[50],int score);
char read_records();
char write_records(char Name[50],int score);
main()
{
	int score;
	char Name[50];
	score = Get_Ran();
	Get_Name(Name,score);
	
	
}
char Get_Name(char Name[50],int score)
{
	int test;
	read_records();
	Num_P++;
	
	system("cls");
	printf("\n\n\n\t\t");
	printf("Please Write Your Name\n\t\tName:");
	fflush(stdin);
	scanf("%s",Name);
	player_Records(Name,score);
}
char player_Records(char Name[50],int score)
{
	printf("\n\n\n\t\tName: %s\tScore:  %i",Name,score);
	write_records(Name,score);
}
int Get_Ran()
{
	int i;
	int min = 1, max = 67;
	static int init = 0;
	if (init == 0)
	{
		srand((unsigned)time(NULL));
		init = 1;
	}
	i = ( rand() % (max - min + 1) + min );
}
char write_records(char Name[50],int score)
{
	FILE *RF;
	char writeToFile[] = "GameRecords.txt";
	int i;
	RF = fopen(writeToFile,"w");
	if(RF == 0)
	{
		printf("Error cannot write to file \"GameRecords.txt\"");
	}
	else
	{
		if(Num_P == 0)
		{
			fprintf(RF,"%s\t%i\n",Name,score);
			fprintf(RF,"#\n");
			
		}
		else
		{
			for(i=0;i<Num_P;i++)
			{
				fprintf(RF,"%s\t%s\n",Players[i].Name,Players[i].score);
				printf("\t\t%s\t\t\t%s\n",Players[i].Name,Players[i].score);
				   
			}
			fprintf(RF,"%s\t%i\n",Name,score);	
			printf("\t\t%s\t\t\t%i\n",Name,score);
			fprintf(RF,"#\n");
		}
		fclose(RF);
	}

}
char read_records()
{
	FILE *RF;
	char readFromFile[] = "GameRecords.txt";
	int num_p = 0;
	char Name[50];
	char score[30];
	
	RF = fopen(readFromFile,"r");
	if(RF == 0)
	{
	
	}
	else
	{
		do
		{
			fscanf(RF,"%s",Name);
			if(strcmp(Name,"#")==0)
			{
				break;
			}
			fscanf(RF,"%s",score);
			num_p++;
			strcpy(Players[num_p].Name,Name);
			strcpy(Players[num_p].score,score);
		}while(strcmp(Name,"#")!=0);
		Num_P = num_p;
	}fclose(RF);
}

