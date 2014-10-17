/*
----------------------#
	Read The House File
   #--------------------------
							*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
	char Name[12];
	char Amount[10];
	char Total[10];
	char Date[31];

}Store;
main()
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
		fclose(OHF);
	}
		
		

}

