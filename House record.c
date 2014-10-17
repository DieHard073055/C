#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

char Original();

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
int total = 0, n, l = 0;
char ans;
time_t recTime;
recTime = time(NULL);
	HF = fopen(recStats,"w");
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
				fprintf(HF,"\n@");
				fclose(HF);
				system("cls");
				printf("Are you sure you want to save the data \nyou just placed into the original text file? \n(Y/N)");
				fflush(stdin);
				scanf("%c",&ans);
				ans = toupper(ans);
				if(ans == 'Y')
				{
					Original();
					fclose(HF);
					exit(-1);
				}
				else
				break;
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
			fprintf(OHF,"%s\t",Data[j].Name);
			fprintf(OHF,"%s\t",Data[j].Amount);
			fprintf(OHF,"%s\t",Data[j].Total);
			fprintf(OHF,"%s\n",Data[j].Date);
		}
		system("cls");
		printf("data written to the file successfully");
		fclose(OHF);
	}
		
		

}

