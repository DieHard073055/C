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

char Get_Ran(char score[10]);
char player_Records(char Name[50],char score[10]);
char Get_Name(char Name[50],char score[10]);
char read_records();
char write_records(char Name[50],char score[10]);
main()
{
	char score[10];
	char Name[50];
	Get_Ran(score);
	Get_Name(Name,score);
	
	
}
char Get_Name(char Name[50],char score[10])
{
	read_records();
	Num_P++;
	
	system("cls");
	printf("\n\n\n\t\t");
	printf("Please Write Your Name\n\t\tName:");
	fflush(stdin);
	scanf("%s",Name);
	player_Records(Name,score);
}
char player_Records(char Name[50],char score[10])
{
	printf("\n\n\n\t\tName: %s\tScore:  %s",Name,score);
	write_records(Name,score);
}
char Get_Ran(char score[10])
{
	int i;
	int min = 1, max = 67;
	static int init = 0;
	char val[5];
	if (init == 0)
	{
		srand((unsigned)time(NULL));
		init = 1;
	}
	i = ( rand() % (max - min + 1) + min );
	itoa(i, score, 10);
}
char write_records(char Name[50],char score[10])
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
			fprintf(RF,"%s\t%s\n",Name,score);
			fprintf(RF,"#\n");
			
		}
		else
		{
			for(i=0;i<Num_P;i++)
			{
				fprintf(RF,"%s\t%s\n",Players[i].Name,Players[i].score);
				printf("\t\t%s\t\t\t%s\n",Players[i].Name,Players[i].score);
				   
			}
			fprintf(RF,"%s\t%s\n",Name,score);	
			printf("\t\t%s\t\t\t%s\n",Name,score);
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

