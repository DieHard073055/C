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

void print(int X)
{
	int G = X;
	
	printf("\n\t\tWelcome to Mastermind!\n\n");
	if(G == 0)
	{
		if(Menu == 'F')
		{
			printf(	"\t[\tStart Game\t]\n");
		}
		else{
			printf("\t[\tResume Game\t]\n");
		}
	}
	else{
		if(Menu == 'F')
		{
			printf(	"\t\tStart Game\n");
		}
		else
		{
			printf("\t\tResume Game\n");
		}
	}
	if(G == 1)
	{
		printf(	"\t[\t  Help  \t]\n");
	}
	else{
		printf(	"\t\t  Help  \t\n");
	}
	if(G == 2)
	{
		printf(	"\t[\t  About  \t]\n");
	}
	else{
		printf(	"\t\t  About\n");
	} 
	if(G == 3)
	{
		printf(	"\t[\t  Quit  \t]\n");
	}
	else{
	
		printf("\t\t  Quit\n");
	} 
	printf("\n\n");
	printf("%c Up = \t\tW\n",24);
	printf("%c Down = \tS \n",25);
	printf(" Enter = \tE");
	printf("\n\nInput %c",26);
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
//no return value	}
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
//no return value}
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
	printf("\n\tInstructions:\n");
	printf("\t-------------------------------------------------\n");
	printf("\t1.Guess all the four letters.\n");
	printf("\t2.Key in only one letter for each guess you make.\n\n");
	printf("\tFeedback:%c %c Correct letter in the right position.\n",2, 16);
	printf("\t         %c %c Correct letter in the wrong position.\n",1, 16);
	printf("\n");
	printf("\tThe highest score you can get in this game is 20\n");
	printf("\n\n");
	system ("pause");
	system ("cls");
}

/*welcome*/
void welcome(void)
{
	printf("\t%c What's your name? %c\n", 259, 259);
	printf("\t");
	fflush(stdin);
	scanf("%s", part[num].Name);
	RandomGreet();
	
	
}
void RandomGreet(void)
{
	int j;
	srand((unsigned)time(NULL));
	j = (rand() % (4 - 1 + 1) +1);
	j--;
	printf("\t");
	if(j == 0){
	printf("Hey there %s!! Have a nice game :)",part[num].Name);
	}
	else if ( j == 1){
	printf("Good day mr/ms, %s!!! Enjoy",part[num].Name);
	}
	else if ( j == 2){
	printf("Yo! %s whatzzzzaaaaaaaaaaap!!!!!!!!",part[num].Name);
	}
	else if ( j == 3){
	printf("Hi %s, Lets see what your made of.. ;)",part[num].Name);
	}
	else if ( j == 4){
	printf("See if u can beat the beat your previous score mr/ms %s",part[num].Name);
	}
	printf("\n\n");
}

/*options*/
void options(void)
{
	printf("Q : Quit\nI :Instructions\n");
	printf("*************************\n");
}
void options1(int t)
{
	
	printf("No. of trial(s): %i\n\n",t);
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
	printf("_______`$$$$$$$$$$$$,___,$$$$,_____,$$$$$´_ \n");
	printf("_________`$$$$$$$$$$$$$$$$$$$$$$$$$$$$$´_ \n");
	printf("__________`$$$$$$$$$$$$$$$$$$$$$$$$$$$´_ \n");
	printf("____________`$$$$$$$$$$$$$$$$$$$$$$$$´_ \n");
	printf("_______________`$$$$$$$$$$$$$$$$$$$$´_ \n");
	printf("\n");
	printf("\n\n");
	printf("########Congratulation!You've won the game! :)#########\n\n");
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
		printf("\tName\tScore\n");
	
		for( i=0; i<(num+1); i++ )	  
		{
			if(part[i].score == 9999)
			{
				
				printf("\t%s\t%s", part[i].Name,j);
			}
			else
			{
				printf("\t%s\t%i", part[i].Name,(21 - part[i].score));
			}
					
			printf("\n");
		}
	}	 
}

/*cheat*/
void cheat(char color[length])
{
	int i;
	
	for( i=0; i<length; i++ )
	{
		printf("\t%c\t", color[i]);
	}
	printf("\n");
}
void about_(void)
{

printf(	"  .-----------------------------------------------------------------.\n");
printf(	" /  .-.                                                          .-.  \\\n");
printf(	"|  /   \\    Firdaus Danial Richard                             /   \\  |\n");
printf(	"| |\\_.  |   422964                                            |    /| |\n");
printf(	"|\\|  | /|   Master Mind v1.00                                 |\\  | |/|\n");
printf(	"| `---' |    C Programming Assignment                         | `---' |\n");
printf(	"|       |                                                     |       | *\n");
printf(	"|       |-----------------------------------------------------|       |\n");
printf(	"\\       |                                                     |       /\n");
printf(	"  \\     /                                                       \\     /\n");
printf(	"  `---'                                                         `---'\n");
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
				printf("\tEnjoy the game. :)\n\n");
				system ("pause");
				system ("cls");
			}
			else
			{
				continue;
			}
		}
		
		x=0;
		welcome();
		Info();
		
		printf("\n\n");
	
		RandGen(color);
	
		printf("\n");
		
		options();
		
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








*/

