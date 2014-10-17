#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#define length 4

typedef struct
{
	char Name[50];
	int score;
}scorers;
scorers part[20];

int num = -1;
char Menu = 'F';

void RandGen(char color[length]);
char check1(char input[length], char color[length]);
void check2(char input[length], char color[length]);
void Info(void);
void welcome(void);
void options(void);
void options1(int t);
char scan(char input[length],int i, char color[length]);
void congrat(void);
char ask(void);
void print_score(void);
void cheat(char color[length]);
void RandomGreet(void);
int main_menu(void);
void Assign(char D[4]);
void print(int X);
char Scan(char D[4], int *X);
void Look(int *X,char D[4]);
char MchkU (int X );
char MchkD (int X);
void about_(void);
void lost_game(void);

void print(int X)
{
	int G = X;
	
	printf("\n");
	printf("     WELCOME TO MASTERMIND \n");
	printf("    \"=====================\" \n\n ");
	
	
	if(G == 0)
	{
		if(Menu == 'F')
		{
			printf(	"\t%c START GAME \n", 16);
		}
		else{
			printf("\t%c RESUME GAME \n",16);
		}
	}
	else{
		if(Menu == 'F')
		{
			printf(	"\t   Start Game\n");
		}
		else
		{
			printf("\t   Resume Game\n");
		}
	}
	if(G == 1)
	{
		printf(	"\t%c HELP \n", 16);
	}
	else{
		printf(	"\t   Help \n");
	}
	if(G == 2)
	{
		printf(	"\t%c ABOUT \n",16);
	}
	else{
		printf(	"\t   About\n");
	}  
	if(G == 3)
	{
		printf(	"\t%c QUIT \n",16);
	}
	else{
	
		printf("\t   Quit\n");
	} 
	printf("\n\n");
	printf("%c Up    = \tW\n",30);
	printf("%c Down  = \tS \n",31);
	printf("%c Enter = \tE", 4);
	printf("\n\nInput %c   ", 175);
}
char Scan(char D[4], int *X)
	{
		char m_Up,m_Down;
		char input;
		int G = *X;
		
		fflush(stdin);
		scanf("%c",&input);
		system("cls");
		input = toupper(input);
		
		if(input == 'W')
		{
			m_Up = MchkU(G);
			if (m_Up == 'T')
			{
				D[G] = 'A';
				G--;
				D[G] = 'B';
			}
		}
		else if(input == 'S')
		{
			m_Down = MchkD(G);
			if (m_Down == 'T')
			{
				D[G] = 'A';
				G++;
				D[G] = 'B';
			}
		}
		*X = G;
		if(input == 'E')
		{
			if(G == 0)
			{
				return 'S';
			}
			else if(G == 1)
			{
				return 'H';
			}
			else if(G == 2)
			{
				return 'A';
			}
			else if(G == 3)
			{
				return 'Q';
			}
		}

	}
void Look(int *X,char D[4])	
	{   
	int x;
		for (x=0;x<4;x++)
		{
			if(D[x] == 'B')
			{	
				*X=x;
			}
		}
	}
	
char MchkU (int X)
{
	if(X == 0)
	{
		return 'F';
	}
	else{
		return 'T';
	}
}
char MchkD (int X)
{
	if(X == 3)
	{
		return 'F';
	}
	else{
		return 'T';
	}
}
void Assign(char D[4])
{

		char input;
		int x;
		for (x = 0;x < 4;x++)
		{
			D[x] = 'A';
		}
		D[0] = 'B';
}


/*instructions for the game*/
void Info(void)
{
	printf("\n\t_________________________________________________\n");
	printf("\n\tInstructions:\n");
	printf("\t-------------------------------------------------\n");
	printf("\t1. Guess all the four letters.\n");
	printf("\t2. Key in only one letter for each guess you make.\n\n");
	printf("\tFeedback:  %c %c Number of correct letters in the right position.\n",2, 26);
	printf("\t           %c %c Number of correct letters.\n",1, 26);
	printf("\n");
	printf("\tThe highest score you can get in this game is 20\n");
	printf("\n\n");
	system ("pause");
	system ("cls");
}

/*welcome*/
void welcome(void)
{
	printf("\n");
	printf("\t%c What's your name? %c\n", 259, 259);
	printf("\t\t");
	fflush(stdin);
	scanf("%s", part[num].Name);
	RandomGreet();
	
	
}
void RandomGreet(void)
{
	int j;
	srand((unsigned)time(NULL));
	j = (rand() % (5 - 1 + 1) +1);
	j--;
	
	printf("\n\n");
	printf("\t%c ",259);
	if(j == 0){
	printf("Hey there %s!! Have a nice game :)",part[num].Name);
	}
	else if ( j == 1){
	printf("Good day mr/ms, %s!!! Good luck  beating the game!",part[num].Name);
	}
	else if ( j == 2){
	printf("Yo, %s!! Whatzzzzaaaaaaaaaaap!!!!!!!!",part[num].Name);
	}
	else if ( j == 3){
	printf("Okay %s, lets see what you're made of.. ;)",part[num].Name);
	}
	else if ( j == 4){
	printf("See if u can beat the beat your previous score Mr/Miss %s.",part[num].Name);
	}
	else if ( j == 5){
	printf("YEAH BUDDY!!!! %s, let's play!",part[num].Name);
	}
	printf("\n\n");
}

/*options*/
void options(void)
{
	printf("\t\t%c%c%c Q : Quit\n\t\t%c%c%c I :Instructions\n", 176,177,178,176,177,178);
	printf("\n\n");
}
void options1(int t)
{
	
	printf("No. of trial(s): %i\n",t);
}
/*scanning input from user*/
char scan(char input[length],int i, char color[length])
{

	printf("Guess %i\t%c ", i+1, 175);
	fflush(stdin);
	scanf("%c", &input[i]);
	input[i] = toupper(input[i]);
	if(input[i] == 'Q')
	{
		return 'Q';
	}
	else if(input[i] == 'I')
	{
		Info();
		return 'I';
	}
	else if(input[i] == '*')
	{
		cheat(color);
		return 'I';
	}
}

/*print the congrates board*/
void congrat(void)
{
	system ("cls");
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
	printf("_______`$$$$$$$$$$$$,___,$$$$,_____,$$$$´_ \n");
	printf("_________`$$$$$$$$$$$$$$$$$$$$$$$$$$$$$´_ \n");
	printf("__________`$$$$$$$$$$$$$$$$$$$$$$$$$$$´_ \n");
	printf("____________`$$$$$$$$$$$$$$$$$$$$$$$$´_ \n");
	printf("_______________`$$$$$$$$$$$$$$$$$$$$´_ \n");
	printf("\n\n");
	printf("\t\t  CONGRATULATIONS!\n\t\tYou've won the game! :)\n\n\n");
	system ("pause");
	system ("cls");
}


void lost_game(void)
{
system("cls");
printf("__________uu$$$$$$$$$$$$$$$$$uu__________\n");
printf("_________u$$$$$$$$$$$$$$$$$$$$$u_________\n");
printf("________u$$$$$$$$$$$$$$$$$$$$$$$u________\n");
printf("_______u$$$$$$$$$$$$$$$$$$$$$$$$$u_______\n");
printf("_______u$$$$$$$$$$$$$$$$$$$$$$$$$u_______\n");
printf("_______u$$$$$$”___”$$$”___”$$$$$$u_______\n");
printf("_______”$$$$”______u$u_______$$$$”_______\n");
printf("________$$$—      —u$u—______”u$$$_______\n");
printf("________$$$u______u$$$u______u$$$________\n");
printf("_________”$$$$uu$$$___$$$uu$$$$”_________\n");
printf("__________”$$$$$$$”___”$$$$$$$”__________\n");
printf("____________u$$$$$$$u$$$$$$$u____________\n");
printf("_____________u$”$”$”$”$”$”$u_____________\n");
printf("__uuu________$$u$_$_$_$_$u$$_______uuu___\n");
printf("_u$$$$________$$$$$u$u$u$$$_______u$$$$__\n");
printf("__$$$$$uu______”$$$$$$$$$”_____uu$$$$$$__\n");
printf("u$$$$$$$$$$$uu____”'”'”____uuuu$$$$$$$$$$\n");
printf("$$$$”$”$$$$$$$$$$uuu___uu$$$$$$$$$”$”$$$”\n");
printf("_”$”______” $$$$$$$$$$$uuu”$$ ”___________\n");
printf("___________uuuuu”$$$$$$$$$$$uuu___________\n");
printf("__u$$$uuu$$$$$$$$$uu_”$$$$$$$$$$$$uuu$$$__\n");
printf("__$$$$$$$$$$”$” ___________”$$$$$$$$$$$$”_\n");
printf("___”$$$$$”______________________”$$$$”__\n");

	printf("\n");
	printf("\t    SORRY!!\n\t   You've lost the game! =[\n\n");
	system ("pause");
	system ("cls");

}


/*asking the user if he/she wants to play again.*/
char ask (void)
{
	char a;
	
	printf("\n\n\tYou wanna play again??[Y/N]\n");
	fflush(stdin);
	printf("\t");
	fflush(stdin);
	scanf("%c",&a);
	a = toupper(a);
	
	return a;
}

/*print the scoreboard*/
void print_score(void)
{
	int i;
	char j[10]= "Lost!!";
	
	if(num >= 0)
	{
		printf("\tNAME\t\tSCORE\n");
	
		for( i=0; i<(num+1); i++ )	  
		{
			if(part[i].score == 9999)
			{
				
				printf("\t%s\t\t%s", part[i].Name,j);
			}
			else
			{
				printf("\t%s\t\t%i", part[i].Name,(21 - part[i].score));
			}
					
			printf("\n");
		}
	}	 
}

/*cheat*/
void cheat(char color[length])
{
	int i;
	
	printf("[%c %c%c%c%c%c enabled]\n",173, 128,104,238,142,116);
	
	for( i=0; i<length; i++ )
	{
		printf("\t%c    ", color[i]);
	}
	printf("\n");
	

}
void about_(void)
{

printf(	"  .-----------------------------------------------------------.\n");
printf(	" /   .-.                                                    .-. \\\n");
printf(	"|  /    \\    Firdaus Danial Richard                       /    \\ |\n");
printf(	"| |\\_.   |   422964                                      |  ._/| |\n");
printf(	"|\\|  |  /|   Master Mind v1.00                           |\\ |  |/|\n");
printf(	"| `---'  |   C Programming Assignment                    | `---' |\n");
printf(	"|        |                                               |       |\n");
printf(	"|        |-----------------------------------------------|       |\n");
printf(	"\\        |                                               |       /\n");
printf(	" \\      /                                                 \\     /\n");
printf(	"   `---'                                                   `---'\n");
system("pause");
system("cls");


}
/*generate random characters*/
void RandGen(char color[length])
{
	char characters[6] = {'A', 'B', 'C', 'D', 'E', 'F'};
	int i;
	srand((unsigned)time(NULL));
	
	for( i=0; i<length; i++ )
	{
		color[i] = characters[ rand() % 6 ];
	}
}

/*right color, right pposition*/
char check1(char input[length], char color[length])
{
	int i, correct = 0;
	
	printf("\nYou've got:\n");
	printf("  ");
	for( i=0; i<length; i++ )
	{
		if(toupper(input[i]) == color[i])
		{
			printf("%c",2);
			correct++;
		}
	}
	printf("\n");
	
	if(correct == length)
	{
		return 'T';
	}
	else
	{
		return 'F';
	}
}

/*right color, wrong position*/
void check2(char input[length], char color[length])
{
	int i, j, ans = 0;
	char temp[length];
	
	for( i=0; i<length; i++ )
	{
		temp[i] = color[i];
	}
	
	for( i=0; i<length; i++ )
	{
		for( j=0; j<length; j++ )
		{
			if(toupper(input[i]) == temp[j])
			{
				ans++;
				temp[j] = '!';
				break;
			}
		}
	}
	printf("  ");
	for( i=0; i<ans; i++ )
	{
		printf("%c",1);
	}
	
	printf("\n\n");
}
int main_menu(void)
{
	char D[4],Ans;
	int X,f;
	
	Assign(D);
	do{
		Look(&X,D);
		print(X);
		Ans = Scan(D,&X);
		if(Ans == 'Q')
		{
			return 0;
		}
		else if( Ans == 'S')
		{
			break;
		}
		else if(Ans == 'H')
		{
			Info();
		}
		else if(Ans == 'A')
		{
			about_();
		}
	}while(f = 2);
	
	
}	 
/*main function*/
int main()
{
	int menu = 1,a = 0, b = 0,  c = 0;
	char input[length], color[length], correct = 'F', Q = 'T';
	char player[50];
	char victory,ans;
	int x = 0;
	
	do{	 
		c =0;
		menu = main_menu();
		Menu ='T';
		if(menu == 0)
			{
				return 0;
			}
		print_score();  
		num++;
		if(x>0)/*only after one trial, then ask.*/
		{
			ans = ask();
			if(ans == 'N')
			{ 
				return 0;
			}
			else if( ans == 'Y')
			{
				printf("\n\tEnjoy the game again! :)\n\n");
				system ("pause");
				system ("cls");
			}
			else
			{
				num--;
				system("cls");
				continue;
			}
		}
		
		x=0;
		welcome();
		Info();
		
		printf("\n");
	
		RandGen(color);
	
		printf("\n");
		
		options();
		printf("Playing... Start Guessing!\nGuess the 4 hidden alphabets (from A to F)!\n\n");
		printf("\t?\t?\t?\t?\n\n");
		
		do
		{
			options1(x);
		
			for( a=0; a<length; a++)
			{
			
				ans = scan(input,a, color);
			
				if(ans == 'Q')
				{
					return 0;
				}
				else if(ans == 'I')
				{
					x--;
					break;
				}
			}
			
			x++;	
			
			victory = check1(input, color);
			check2(input, color);
		
			if(victory == 'T')
			{
				part[num].score = x;
				congrat();
				break;	  
			}
		
			c++;
			
			if(c == 20)
			{
				part[num].score = 9999;
				lost_game();
				break;
			}
		}while(c < 21);
	}while(b = 1);
}	 

	
/*

printf(	"  .-----------------------------------------------------------------.\n");
 printf(	"/  .-.                                                         .-.  \\\n");
printf(	"|  /   \\                                                       /   \\  |\n");
printf(	"| |\\_.  |                                                     |    /| |\n");
printf(	"|\\|  | /|                                                     |\\  | |/|\n");
printf(	"| `---' |                                                     | `---' |\n");
printf(	"|       |                                                     |       | *\n");
printf(	"|       |-----------------------------------------------------|       |\n");
printf(	"\\       |                                                     |       /\n");
 printf(	"\\     /                                                       \\     /\n");
  printf(	"`---'                                                         `---'\n");




printf("__________uu$$$$$$$$$$$$$$$$$uu__________");
printf("_________u$$$$$$$$$$$$$$$$$$$$$u_________");
printf("________u$$$$$$$$$$$$$$$$$$$$$$$u________");
printf("_______u$$$$$$$$$$$$$$$$$$$$$$$$$u_______");
printf("_______u$$$$$$$$$$$$$$$$$$$$$$$$$u_______");
printf("_______u$$$$$$”___”$$$”___”$$$$$$u________");
printf("_______”$$$$”______u$u_______$$$$”________");
printf("________$$$—      —u$u—______”u$$$________");
printf("________$$$u______u$$$u______u$$$________");
printf("_________”$$$$uu$$$___$$$uu$$$$”_________");
printf("__________”$$$$$$$”___”$$$$$$$”__________");
printf("____________u$$$$$$$u$$$$$$$u____________");
printf("_____________u$”$”$”$”$”$”$u______________");
printf("__uuu________$$u$_$_$_$_$u$$_______uuu__");
printf("_u$$$$________$$$$$u$u$u$$$_______u$$$$_");
printf("__$$$$$uu______”$$$$$$$$$”_____uu$$$$$$__");
printf("u$$$$$$$$$$$uu____”"”"”____uuuu$$$$$$$$$$");
printf("$$$$”"”$$$$$$$$$$uuu___uu$$$$$$$$$”"”$$$”");
printf("_”"”______”"$$$$$$$$$$$uu_”"$”"”___________");
printf("___________uuuu_”"$$$$$$$$$$uuu___________");
printf("__u$$$uuu$$$$$$$$$uu_”"$$$$$$$$$$$uuu$$$__");
printf("__$$$$$$$$$$”"”"___________”"$$$$$$$$$$$”__");
printf("___”$$$$$”______________________”"$$$$”"__");












*/

