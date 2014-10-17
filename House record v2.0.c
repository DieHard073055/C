#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

char Original();
char Total_out(int number);
int Total_in();

typedef struct
{
	char Name[12];
	char Amount[10];
	char Total[10];
	char Date[31];

}Store;

main(){
FILE *HF;
char recStats[] = "House Records.txt";
char name[20],Date[8],amount[10];
int total;
int n, l = 0;
time_t recTime;
recTime = time(NULL);
	HF = fopen(recStats,"w");
	total = Total_in();
	if (HF == 0)
	{
		printf("Error : Cannot open the file");
		exit(-1);
		
	}
	else
	printf("Please type the name and the amount.\nIf your done then type \"$\" as the name.\nIf you wanna quit then type Q as the name.\n\n\n");
		fprintf(HF,"Name\t\t\tAmount\t\tTotal\t\t\tDate\n");
		do
		{
			l++;
			printf("Name #%i:\t",l);
			fflush(stdin);
			scanf("%[^\n]",name);
			if(strcmp(name,"$")== 0)
			{
				Total_out(total);
				fprintf(HF,"\n@");
				fclose(HF);
				system("cls");
				printf("The data that you've Entered is :\n\n");
				
					Original();
					exit(-1);
			}
			else if (strcmp(name,"Q")==0||strcmp(name,"q")==0)
			{
				fprintf(HF,"\n@");
				fclose(HF);
				exit(-1);
			}
			else{
				if(strlen(name) < 8)
				{
					fprintf(HF,"%s\t\t\t",name);
				}
				else
				{
					fprintf(HF,"%s\t\t",name);
				}
				printf("\n");
				printf("Amount  #%i:\t",l);
				fflush(stdin);
				scanf("%[^\n]",amount);
				fprintf(HF,"%s\t\t",amount);
				printf("\n");
				n = atoi(amount);
				total += n;
				fprintf(HF,"%i\t\t",total);
				fprintf(HF,ctime(&recTime));
				
			}
		}while(-1);
		
		

}
char Original()
{
	
	FILE *RHF,*OHF;
	char recStats[] = "House Records.txt";
	char recStats2[]="House Records Original.txt";
	char Q[20];
	char ans;
	Store Data[20];
	int i = -1,j;
	
	RHF = fopen(recStats,"r");
	OHF = fopen(recStats2,"a+");
	if(RHF == 0||OHF == 0)
	{
		printf("Cannot open the requested file");
	}
	else
	{
		fscanf(RHF,"%s\t",Q);
		fscanf(RHF,"%s\t",Q);
		fscanf(RHF,"%s\t",Q);
		fscanf(RHF,"%s",Q);
		if(strcmp(Q,"Date") == 0)
		{
			do{
				
				fscanf(RHF,"\n");
				fscanf(RHF,"%s",Q);
				if(strcmp(Q,"@")==0)
				{ break; }
				else{
					i++;
					strcpy(Data[i].Name,Q);
					fscanf(RHF,"%s",Data[i].Amount);
					fscanf(RHF,"%s",Data[i].Total);
					fscanf(RHF,"%[^\n]",Data[i].Date);
				}
			}while(strcmp(Q,"@")!=0);
		}
		fclose(RHF);
		for(j=0;j<i+1;j++)
		{
			if(strlen(Data[j].Name) < 8)
				{
					printf("%s\t\t\t",Data[j].Name);
				}
				else
				{
					printf("%s\t\t",Data[j].Name);
				}
			printf("%s\t",Data[j].Amount);
			if(strlen(Data[j].Total) < 8)
				{
					printf("%s\t",Data[j].Total);
				}
				else
				{
					printf("%s\t",Data[j].Total);
				}
			printf("%s\n",Data[j].Date);
		}
		
		printf("Do you want to add these data to the original file?\n(Y/N)");
		fflush(stdin);
		scanf("%c",&ans);
		ans = toupper(ans);
		if (ans == 'Y')
		{
			for(j=0;j<i+1;j++)
			{
				if(strlen(Data[j].Name) < 8)
				{
					fprintf(OHF,"%s\t\t\t",Data[j].Name);
				}
				else
				{
					fprintf(OHF,"%s\t\t",Data[j].Name);
				}
				
				fprintf(OHF,"%s\t",Data[j].Amount);
				
				if(strlen(Data[j].Total) < 8)
				{
					fprintf(OHF,"%s\t\t",Data[j].Total);
				}
				else
				{
					fprintf(OHF,"%s\t",Data[j].Total);
				}
				fprintf(OHF,"%s\n",Data[j].Date);
			}
			system("cls");
			printf("\n\n\n\t\tData written to the file successfully\n\n\n");
			system("pause");
		}
		else
		{
			system("cls");
			printf("\n\n\t\tSystem will now Exit\n\n\n");
			system("pause");
		}
		fclose(OHF);
	}
		
		

}
char Total_out(int number)
{
	FILE *ST;
	char Total[]="Extra info.txt";
	
	ST = fopen(Total,"w");
	if(ST == 0)
	{
		printf("\n\n\t\tError with the file Extra info.txt\n\n");
	}
	else
	{
		fprintf(ST,"%i",number);
		fclose(ST);
	}
	

}
int Total_in()
{
	FILE *ST;
	char Total[] = "Extra info.txt";
	int number;
	
	ST = fopen(Total,"r");
	if(ST == 0)
	{
		printf("\n\n\t\tError reading data from the Extra info.txt\n\n");
		return (0);
	}
	else
	{
		fscanf(ST,"%i",&number);
		fclose(ST);
		return (number);
	}
}

