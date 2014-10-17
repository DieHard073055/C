#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Lockandkey.h"


char AI_Calculations(int * num_key, int * num_locks,char check[20][20]);

int main()
{
	int num_locks, num_key;
	locksAndKeys store[20];
	Read(&num_locks, &num_key,store);
	Lock_Cracker(store,&num_key,&num_locks);
	
	return 0;
}

char Lock_Cracker(locksAndKeys store[20], int * num_key, int * num_locks)
{
	char *ans,final[90],check[20][20] ={'F'};
	int i,x,j,k,num_correct[20]={0};
	
		printf("Number of recorded keys %i\nNumber of recorded Locks %i\n   \t",* num_key,* num_locks);
		for(j=0;j<(* num_key);j++)
		{
			printf("k%i  ",j+1);
		}
		printf("\n");
	for(i=0;i<(* num_locks);i++)
	{
		printf("L%i\t",i+1);
		for(j=0;j<(* num_key);j++)
		{
			ans = strstr(store[i].L,store[j].K);
			if(ans != NULL)
			{
				printf("1   ");
				check[i][j] = 'T';
			}
			else
			{
				printf("0   ");
				check[i][j] = 'F';
			}
			
			
		}printf("\n");
	}
	printf("\n\n\n");
	AI_Calculations(num_key,num_locks,check);
	
}
char AI_Calculations(int * num_key, int * num_locks,char check[20][20])
{
	int num_correct[20] = {0},i,j,highest = 0,pos_sto[20];
	
	for(i=0;i<(*num_key);i++)
	{
		for(j=0;j<(*num_locks);j++)
		{
			if(check[j][i] == 'T')
			{
				num_correct[i]++;
			}
		}
	}
	for(j=0;j<(*num_locks);j++)
	{
		printf("key %i can open %i locks\n",j+1,num_correct[j]);
	}
	j = 0;
	for(i=0;i<(*num_key);i++)
	{
		if(j==0)
		{
			if(highest < num_correct[i])
			{
				highest = num_correct[i];
				pos_sto[j++] = i;
			}
		}
		else
		{
			if(highest <= num_correct[i])
			{
				highest = num_correct[i];
				pos_sto[j++] = i;
			}
		}
	}
	
}
char Read(int * num_locks, int * num_key,locksAndKeys store[20])
{
	FILE *KeyF,*LockF;
	char Keys[] = "key.txt";
	char Locks[] = "lock.txt";
	int i;
	char key[90],lock[90];
	
	KeyF = fopen(Keys, "r");
	LockF = fopen(Locks,"r");
	if (KeyF == 0)
	{
		printf("error openning key file");
		exit(0);
	}
	if (LockF == 0)
	{
		printf("error openning lock file");
		exit(0);
	}
	else
	{
		fscanf(KeyF,"%i",num_key);
		fscanf(LockF,"%i",num_locks);
		
		fscanf(KeyF,"\n");
		fscanf(LockF,"\n");
		for(i=0;i<(*num_key);i++)
		{
			fscanf(KeyF,"%[^\n]",key);
			strcpy(store[i].K,key);
			fscanf(KeyF,"\n");
		}
		for(i=0;i<(*num_locks);i++)
		{
			fscanf(LockF,"%[^\n]",lock);
			strcpy(store[i].L,lock);
			fscanf(LockF,"\n");
		}
		
		
		fclose(KeyF);
		fclose(LockF);
	}
}

