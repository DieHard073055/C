#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
	char Start_Dest[21];
	char Finish_Dest[21];
	int Distance;
}destination_Data;

destination_Data Places[10];
int MyP = -1;

int askForDistance();
int printDestinations();
int arranger();
main()
{
	
	askForDistance();
	arranger();
	/*printf("%s to %s - %i",Places[MyP].Start_Dest,Places[MyP].Finish_Dest,Places[MyP].Distance);*/
}
int askForDistance()
{
	char Dest[20],Depart[20];
	int dist,i = 0;
	printf("Please Enter the Name of your Starting Destination!\nStarting Destination:\t");
	fflush(stdin);
	scanf("%[^\n]",Depart);
	printf("\n");
	do{
		i++;
		printf("Please Enter the Name of your Destination(%i)!\nDestination(%i):\t",i,i);
		fflush(stdin);
		scanf("%[^\n]",Dest);
		printf("\n");
		fflush(stdin);
		if(strcmp(Dest,"$")==0)
		{	break;	 }
		printf("\n");
		printf("Please Enter the Distance to %s from %s\nDistance (integer)\t",toupper(Dest),toupper(Depart));
		fflush(stdin);
		scanf("%i",&dist);
		printf("\n");
		MyP++;
		strcpy(Places[MyP].Start_Dest,Depart);
		strcpy(Places[MyP].Finish_Dest,Dest);
		Places[MyP].Distance = dist;
	}while(-1);
}
int printDestinations()
{
	int u;
	for( u = 0; u < MyP; u++)
	{
		printf("%s to %s = %i\n",Places[u].Start_Dest,Places[u].Finish_Dest,Places[u].Distance);
	}
}
int arranger()
{
	destination_Data temp[10], temp1[10];
	int i,u;
	
	for( i = 0; i < MyP+1; i++)
	{
		strcpy(temp[i].Start_Dest,Places[i].Start_Dest);
		strcpy(temp[i].Finish_Dest,Places[i].Finish_Dest);
		temp[i].Distance = Places[i].Distance;
	}
	for( i = 0; i < MyP+1; i++)
	{
		temp1[i].Distance = 999999999;
	}
	for( u = 0; u < MyP+1; u++)
	{
		for( i = 0; i < MyP+1; i++)
		{
			if(temp[i].Distance < temp1[u].Distance)
			{
				temp1[u].Distance = temp[i].Distance;
				strcpy(temp1[u].Start_Dest,temp[i].Start_Dest);
				strcpy(temp1[u].Finish_Dest,temp[i].Finish_Dest);	  
			} 
		}
		for ( i =0; i < MyP+1; i++)
		{
			if( temp1[u].Distance == temp[i].Distance )
			{
				temp[i].Distance = 999999999;
				break;
			}
		}
	}
	for( u = 0; u < MyP+1; u++)
	{
		printf("%s to %s = %i\n",temp1[u].Start_Dest,temp1[u].Finish_Dest,temp1[u].Distance);
	}
	
}

