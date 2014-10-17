 #include <stdio.h>
#include <string.h>

#define TEAMS 4 // Defining number of teams
#define HWIN 2	// Defining number of home wins
#define AWIN 3	// Defining number of away wins
#define DRAW 1	// Defining number of draws
#define LOSS -1	// Defining number of loses
#define NAMELEN 20	// Defining name length

struct team
{
	char name[NAMELEN]; // Team name
	int points;			// Total Points
	int played;			// Number of games played
	int scoreHome;		// Gets score from each home win
	int scoreAway;		// Gets score from each away team
};

struct league
{
	struct team table[TEAMS]; // Table for the whole league
};

// Prototype of function that i will create

int main(void)
{
	int i;
	struct league theLeague; // Below shows what will be input onto the screen
	
	puts("Football League");
	puts("=============== \n");
	puts("Enter The Name Of Teams");
	puts("=======================");
	
	for (i=0; i<TEAMS; i++) // i = 0 next time through the loop adds 1 until i reaches 10
	{
		printf("\nTeam %d ", i+1); // Ask for each team
		gets(theLeague.table[i].name); // Gets each team from the keyboard
		fflush(stdin);
	}
	
	for (i=0; i<TEAMS; i++)
	{
		printf("\nTeam %s\n",theLeague.table[i].name); // This then shows the teams entered
	}
	
	for (i=0; i<TEAMS; i++)
	{
		int scoreHome;
		{
		printf("\nEnter Home Score for %s: ", theLeague.table[i].name); // Will enter home score of teams
		scanf("\n&theLeague.table[i].scoreHome");
		fflush(stdin);
		}
	}
	
	for (i=0; i<TEAMS; i++)
	{
		int scoreAway;
		{
		printf("\nEnter Away Score for %s: ", theLeague.table[i].name); // Will enter away score of teams
		scanf("\n&theLeague.table[i].scoreAway");
		fflush(stdin);
		}
	}
	
	return 0;
	
}

