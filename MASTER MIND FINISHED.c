#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<ctype.h>
#define size 4
/*Structure for the scoresheet*/
typedef struct
{
	char N[50];
	int S;
}Score;

Score player[20];
int pl = -1;

char position (char guess[size], char colors[size]);
void letter ( char guess[size], char colors[size]);
void RanL(char colors[size]);
void WIN(void);
void Instr(void);
void in_Game_instruct (int score);
void in_Score(void);
void HELLO(char name[49]);
void welcome(void);
void rock(void);


/* The instruction*/
void welcome(void)
{
	printf("\n");
	printf("\tWelome to MASTERMIND! \n");
	printf("\t(The Guessing Game)\n");

}


void Instr(void)
{
	printf("\n\nInstruction(s):");
	printf("\n----------------");
	printf("\nGuess all the four letters\n");
	printf("Enter just ONE LETTER for each guess.\n\n");
	printf("  $ -- Characters guessed correctly, BUT the wrong position\n");
	printf("  * -- Number of characters guessed correctly\n");
	printf("\n\n\n");
	system("pause");
	system("cls");
}

void in_Game_instruct (int score)
{
	printf("Q: Quit\nI: Instructions\n");
	printf("_________________");
	printf("\n\nNo. of trials:  %i\n\n\n", score);
}

/*Right position, right character*/
char position (char guess[size], char colors[size])
{
	int loop, win = 0;
	for ( loop = 0; loop < size; loop++)
	{
		if ( toupper(guess[loop]) == colors[loop] )
		{
			printf("*");
			win++;
		}
	}
	printf("\n");
	
	if ( win == size )
	{
		return  'T';
	}
	else
	{
		return  'F';
	}
}
/*Right character, wrong position*/
void letter ( char guess[size], char colors[size])
{
	int loop1, loop2, ans = 0;
	for (loop1 = 0; loop1 < size; loop1++)
	{
		for (loop2 = 0; loop2 < size; loop2++)
		{
			if ( toupper(guess[loop1]) == colors[loop2] )
			{
				ans++;
				break;
			}
		}
	}
	for (loop1 = 0;loop1 < ans;loop1++)
	{
		printf("$");
	}
	
	printf("\n\n");
}
/*Generate random letter*/
void RanL(char colors[size])
{
	char letters[6] = {'A', 'B', 'C', 'D', 'E', 'F'};
	int loop;
	srand((unsigned)time(NULL));
	for ( loop = 0; loop < size; loop++)
	{
		colors[loop] = letters[ rand() % 6 ];
	}
}
/*Win display*/
void WIN(void)
{
	printf("\n");
	rock();
	printf("############## CONGRATULATIONS! ##############\n");
	printf("             You've won the game!");
	printf("\n\n\n");
	system("pause");
}
/*Player stats*/
void in_Score(void)
{
	int j, k;
	k = pl;
	if (k >= 0)
	{
		printf("\n%c%c%c%c%c showing Players Stats\n\n", 176,176,176,177,178);
		printf("\t NAME\t  %c\t  SCORE\n\n",287);
			for (j = 0;j < (k+1);j++)
			{
				printf("\t%c %s\t  :\t  %i",16, player[j].N, player[j].S);
				printf("\n");
			}
		
		printf("\n\n\n");
	}
	else
	{
		printf("[No player stats (yet)...]\n\n");
	}
}
/*Main function*/
int main()
{
	int Gloop, Gloop2, loop;
	char guess[size], colors[size], Win = 'F', Q = 'T';
	char Name[49];
	int s = 0;
	welcome();
	Instr ();
	printf("\n\n");
	do
	{
		in_Score();
		s = 0;
		pl++;
		printf("Your name:  ");
		fflush(stdin);
		scanf("%s", &Name);
		strcpy(player[pl].N,Name);
		printf("\n");
		HELLO(Name);
		
		system("pause");
		system("cls");
		RanL(colors);
		/*delete this for loop to hide the answer*/
		for (loop = 0;loop < size;loop++)
		{
			printf("%c", colors[loop]);
		}
		/*delete this for loop to hide the answer*/
		printf("\n");
		
		/*To loop whole guessing*/	  	  
		in_Game_instruct(s);
		do
		{
			printf("\nGuess alphabet range: A to F\n\n");
			
			for (loop = 0; loop < size; loop++)
			{
				printf("Give your guesses %i\t", loop + 1);
				printf("%c  ", 26);
				fflush(stdin);
				scanf("%c", &guess[loop]);
				if (toupper(guess[loop]) == 'Q')
				{
					return 0;
				}
				else if (toupper(guess[loop]) == 'I')
				{
					Instr ();
					s--;
					break;
				}
			}
			
			s++;
			player[pl].S = s;
			printf("\n\n");
			Win = position(guess, colors);
			letter(guess, colors);
			
			if (Win == 'T')
			{
				system("cls");
				WIN();
				/*system("pause");*/
				system("cls");
				printf("\n\nDo you wanna play again? %c\n(Y/N)", 257);
				fflush(stdin);
				scanf("%c", &Q);
				if (toupper(Q) == 'Y')
				{
					system("cls");
					printf("Lets play! ;)\n\n");
					break;
				}
				else if ( toupper(Q) == 'N')
				{
					return 0;
				}
				else
				{
					system("cls");
					printf("\nWhat speaking you le??? %c_%c\n\n%c%c%c%c%c replaying the game ", 147, 147, 176,176,176,177,178);
					printf("\n\n\n");
					break;
				}
			}
		}
		while ( Gloop = 2 );
	}
	while ( Gloop2 = 2 );
}



void HELLO(char name[49])
{
	int ran;
	int init = 0;
	
	if(init == 0);
	{
		srand(time(NULL));
		init = 1;
	}
	
	ran = rand() % (5 - 1 + 1) + 1;
	
	if(ran == 1)
	{
		printf("Yo %s! Good luck to the game yo!", name);
	}
	else if(ran == 2)
	{
		printf("Wazzaaaaaaaaaap %s! :D Just enjoy the game!", name);
	} 
	else if(ran == 3)
	{
	 	printf("Hello %s. Let's play the game.  Good luck! :)", name);
	}
	else if(ran == 4)
	{
	 	printf("Good day, old chap, %s!  Care to play the game now?", name);
	}
	else if(ran == 5)
	{
	 	printf("Ah, so it's %s.  We meet again! Or was it...\nAnyways, let's play!.", name);
	}
	
	printf("\n\n\n\n");
}

void rock(void)
{

	printf("_______´$$$$`_______________________________,,,_ \n");
	printf("_______´$$$$$$$`___________________________´$$$` \n");
	printf("________`$$$$$$$`______,,________,,_______´$$$$´ \n");
	printf("_________`$$$$$$$`____´$$`_____´$$`____´$$$$$´ \n");
	printf("__________`$$$$$$$`_´$$$$$`_´$$$$$`__´$$$$$$$´ \n");
	printf("___________`$$$$$$$_$$$$$$$_$$$$$$$_´$$$$$$$´_ \n");
	printf("____________`$$$$$$_$$$$$$$_$$$$$$$`´$$$$$$´ \n");
	printf("___,,,,,,____`$$$$$$_$$$$$$$_$$$$$$$_$$$$$$´_ \n");
	printf("_´$$$$$`____`$$$$$$_$$$$$$$_$$$$$$$_$$$$$$´_ \n");
	printf("´$$$$$$$$$`´$$$$$$$_$$$$$$$_$$$$$$$_$$$$$´_ \n");
	printf("´$$$$$$$$$$$$$$$$$$_$$$$$$$_$$$$$$$_$$$$$´_ \n");
	printf("___`$$$$$$$$$$$$$$$_$$$$$$$_$$$$$$_$$$$$$´_ \n");
	printf("______`$$$$$$$$$$$$$_$$$$$__$$_$$$$$$_$$´_ \n");
	printf("_______`$$$$$$$$$$$$,___,$$$$,_____,$$$$$´_ \n");
	printf("_________`$$$$$$$$$$$$$$$$$$$$$$$$$$$$$´_ \n");
	printf("__________`$$$$$$$$$$$$$$$$$$$$$$$$$$$´_ \n");
	printf("____________`$$$$$$$$$$$$$$$$$$$$$$$$´_ \n");
	printf("_______________`$$$$$$$$$$$$$$$$$$$$´_ \n");
	printf("\n");
	
}

