#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define size 4

char position (char guess[size], char colors[size]);
void letter ( char guess[size], char colors[size]);
void RanL(char colors[size]);
void WIN(void);

char position (char guess[size], char colors[size])
	{
		int loop,win = 0;
		for( loop = 0; loop < size; loop++)
			{
				if( toupper(guess[loop]) == colors[loop] )
					{
						printf("*");
						win++;
					}
			}
			printf("\n");
			if( win == size )
			{
				return  'T';
			}
			else
			{
				return  'F';
			}
	}
	
void letter ( char guess[size], char colors[size])
{	
	int loop1,loop2,ans=0;
	
	for (loop1 = 0; loop1 < size; loop1++)
	{
		for (loop2 = 0; loop2 < size; loop2++)
			{
				if( toupper(guess[loop1]) == colors[loop2] )
					{
						ans++;
					}
			}
	}
	for (loop1 = 0;loop1<ans;loop1++)
	{
		printf("-");
	}
	printf("\n");
}
void RanL(char colors[size])
{
	char letters[6] = {'A','B','C','D','E','F'};
	int loop;
	srand((unsigned)time(NULL));
	for( loop = 0; loop < size; loop++)
		{
			colors[loop] = letters[ rand() % 6 ];
		}
}
void WIN(void)
{
	printf("\n\n\n\n\n");
	printf(".:*~*:._.:*~*:._.:*~!!YOU WON!!!~*:._.:*~*:._.:*~*");
	printf("\n\n\n\n\n");
	system("pause");
}
int main()
	{
		int Gloop,Gloop2,loop;
		char guess[size],colors[size],Win = 'F',Q = 'T';
		do{
			RanL(colors);
		/*delete this for loop to hide the answer*/
			for (loop = 0;loop<size;loop++)
			{
			printf("%c",colors[loop]);
			}	
		/*delete this for loop to hide the answer*/  
			printf("\n");	
		
			do
				{
				for (loop = 0; loop < size; loop++)
					{
						printf("Give your guess %i\t",loop+1);
						fflush(stdin);
						scanf("%c",&guess[loop]);
						if(toupper(guess[loop]) == 'Q')
							{
								return 0;
							}
					}
					system("cls");
					Win = position(guess,colors);
					letter(guess,colors);
					if(Win == 'T')
					{
						system("cls");
						WIN();
						system("cls");
						printf("you wanna play again **troll face**\n(Y/N)");
						fflush(stdin);
						scanf("%c",&Q);
						if (toupper(Q) == 'Y'){
							system("cls");
							printf("lets play again :)!!\n\n");
							break;
						}
						else if ( toupper(Q) == 'N'){
							return 0;
						}
						else{
							system("cls");
							printf("what speaking you?\n");
						}
					}
				
		
		
		
		
				}while( Gloop = 2 );
			}while( Gloop2 = 2 );	 
			
	}
	
	
		

