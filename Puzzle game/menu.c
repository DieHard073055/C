#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char menu();
char menu_arrange(char menu[4]);
char print_menu(char menu[4]);
int menu_search(char menu[4]);
char user_input(char menu[4]);
char option();
int Color_changer();
char Welcome();
char about();
main()
{
	
	menu();
}
char menu()
{
	char menu[4];
	menu_arrange(menu);
	do
	{
		print_menu(menu);
		user_input(menu);
		system("cls");
	}while(-1);

}
char menu_arrange(char menu[4])
{
	int y;
	for(y = 0;y < 4; y++)
	{
		menu[y] = 'x';
	}
	menu[0] = '+';




}
char print_menu(char menu[4])
{
	
	int y;
	y = menu_search(menu);
	printf("\n\n");
	Welcome();
	printf("\n\n");
	if(y == 0)
	{
		printf("\t%c[ START GAME ]\n\n",16);
	}
	else 
	{
		printf("\tStart Game\n\n");
	}
	if( y == 1)
	{
		printf("\t%c[ OPTION ]\n\n",16);
	}
	else 
	{
		printf("\tOption\n\n");
	}
	if( y == 2)
	{
		printf("\t%c[ ABOUT ]\n\n",16);
	}
	else 
	{
		printf("\tAbout\n\n");
	}
	if( y == 3)
	{
		printf("\t%c[ EXIT ]\n\n",16);
	}
	else
	{
		printf("\tExit\n\n");
	}
	printf("\n\t\t\t\t\t\tPress W and S to navigate.\n\n\t\t\t\t\t\tPress Enter to Select.\n");

}

char Welcome()
{                                                                         
printf("`7MMF'     A     `7MF'     `7MM \n");                                           
printf("  `MA     ,MA     ,V         MM \n");                                             
printf("   VM:   ,VVM:   ,V .gP\"Ya   MM  ,p6\"bo   ,pW\"Wq.`7MMpMMMb.pMMMb.  .gP\"Ya\n");    
printf("    MM.  M' MM.  M',M'   Yb  MM 6M'  OO  6W'   `Wb MM    MM    MM ,M'   Yb\n");   
printf("    `MM A'  `MM A' 8M\"\"\"\"\"\"  MM 8M       8M     M8 MM    MM    MM 8M\"\"\"\"\"\"\n");   
printf("     :MM;    :MM;  YM.    ,  MM YM.    , YA.   ,A9 MM    MM    MM YM.    ,\n");   
printf("      VF      VF    `Mbmmd'.JMML.YMbmd'   `Ybmd9'.JMML  JMML  JMML.`Mbmmd'\n");   
}

int menu_search(char menu[4])
{

	int y;
	for(y=0;y<4;y++)
	{
		if(menu[y] == '+')
		{
			return(y);
		}
		
	}

}

char user_input(char menu[4])
{
	int in,y = menu_search(menu);
	
	in = getch();
	if( in == 87 || in == 119 )
	{
		if( y > 0 )
		{
			menu[y] = 'x';
			menu[y - 1] = '+';
		}
	
	} 
	else if( in == 83 || in == 115 )
	{
		if(y < 3)
		{
			menu[y] = 'x';
			menu[y + 1] = '+';
		}
	}
	else if( in == 81 || in == 113)
	{
		exit(-1);
	}
	else if( in == 13 )
	{
		if( y == 0 )
		{
			/*start game*/
		}
		else if ( y == 1 )
		{
			option();
		}
		else if ( y == 2 )
		{
			about();
		}
		else if ( y == 3 )
		{
			exit(-1);
		}
	}
}
char option()
{
	char m[2];
	char in;
	char diff[10],color[10];
	int D = 1,C = 1,symbol;
	m[1] = 'T';
	m[0] = 'F';
	
	do
	{	
	
		if(D == 1)
		{
			strcpy(diff,"Easy");
			symbol = 176;
		}
		else if (D == 2)
		{
			strcpy(diff,"Normal");
			symbol = 177;
		}
		else if (D == 3)
		{
			strcpy(diff,"Hard");
			symbol = 178;
		}
		system("cls");
		printf("\n\tSelect Difficulty\n\n");
	
		if(m[0] == 'F')
		{
			printf("\t %c[ DIFFICULTY ] - %c %s\n\n",16,symbol,diff);
		}
		else 
		{
			printf("\tDifficulty\n\n");
		}
		if(m[1] == 'F')
		{
			printf("\t %c[ COLOUR ]\n\n",16);
		}
		else
		{
			printf("\tColour\n\n");
		}
		printf("\t\t\t\t\t\tPress W and S to navigate.\n\n\t\t\t\t\t\tPress Enter to Select.\n\n\n\n");	  
		
		in = getch();
		if(in == 87 || in == 119 )
		{
			if( m[0] == 'T')
			{
				m[0] = 'F';
				m[1] = 'T';
				
			}
		}
		else if(in == 83 || in == 115)
		{
			if( m[1] == 'T' )
			{
				m[0] = 'T';
				m[1] = 'F';
			}
		}
		else if(in == 81 || in == 113)
		{
			return(' ');
		}
		else if(in == 13)
		{
			if(m[1] == 'T')
			{
				if(D == 3)
				{
					D = 1;
				}
				else
				{
					D++;
				}
			}
			else if(m[0] == 'T')
			{
			
				Color_changer();
			}
		}
		
	}while(-1);
}
char about()
{
	system("cls");
	printf("\n");
	
	printf("  .-----------------------------------------------------------------.\n");
 	printf(" /  .-.                                                         .-.  \\ \n");
	printf("|  /   \\                                                       /   \\  |\n");
	printf("| |\\_.  | By:Brendon Goh.                                     |    /| |\n");
	printf("|\\|  | /| Std ID:*******                                      |\\  | |/|\n");
	printf("| `---' |                                                     | `---' |\n");
	printf("|       | Introduction to programming                         |       |\n");
	printf("|       | Assignment 2011                                     |       |\n");
	printf("|       |                                                     |       |\n"); 
	printf("|       |-----------------------------------------------------|       |\n");
	printf("\\       |                                                     |       /\n");
 	printf(" \\     /                                                       \\     /\n");
  	printf("  `---'                                                         `---'\n");
	getch();
	system("cls");
}
int Color_changer()
{

	int c_sel;
	
	
	printf("\tPress anykey to change colour.\n\tIf you like the console color \n\tThen press enter to keep it like that.");
	system("color 00");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 01");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 02");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 03");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 04");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 05");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 06");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 07");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 08");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 09");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 0A");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 0B");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 0C");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 0D");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 0E");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 0F");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 10");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 11");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 12");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 13");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 14");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 15");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 16");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 17");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 18");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 19");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 1A");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 1B");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 1C");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 1D");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 1E");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 1F");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 20");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 21");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 22");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 23");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 24");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 25");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 26");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 27");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 28");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 29");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 2A");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 2B");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 2C");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 2D");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 2E");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 2F");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 30");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 31");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 32");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 33");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 34");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 35");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 36");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 37");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 38");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 39");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 3A");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 3B");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 3C");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 3D");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 3E");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 3F");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 40");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 41");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 42");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 43");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 44");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 45");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 46");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 47");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 48");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 49");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 4A");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 4B");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 4C");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 4D");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 4E");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 4F");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 50");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 51");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 52");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 53");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 54");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 55");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 56");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 57");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 58");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 59");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 5A");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 5B");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 5C");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 5D");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 5E");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 5F");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 60");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 61");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 62");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 63");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 64");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 65");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 66");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 67");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 68");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 69");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 6A");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 6B");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 6C");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 6D");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 6E");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 6F");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 70");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 71");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 72");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 73");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 74");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 75");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 76");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 77");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 78");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 79");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 7A");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 7B");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 7C");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 7D");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 7E");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 7F");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 80");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 81");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 82");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 83");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 84");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 85");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 86");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 87");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 88");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 89");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 8A");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 8B");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 8C");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 8D");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 8E");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 8F");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 90");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 91");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 92");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 93");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 94");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 95");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 96");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 97");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 98");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 99");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 9A");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 9B");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 9C");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 9D");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 9E");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color 9F");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color A0");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color A1");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color A2");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color A3");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color A4");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color A5");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color A6");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color A7");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color A8");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color A9");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color AA");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color AB");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color AC");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color AD");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color AE");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color AF");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color B0");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color B1");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color B2");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color B3");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color B4");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color B5");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color B6");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color B7");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color B8");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color B9");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color BA");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color BB");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color BC");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color BD");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color BE");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color BF");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color C0");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color C1");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color C2");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color C3");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color C4");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color C5");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color C6");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color C7");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color C8");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color C9");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color CA");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color CB");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color CC");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color CD");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color CE");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color CF");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color D0");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color D1");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color D2");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color D3");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color D4");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color D5");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color D6");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color D7");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color D8");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color D9");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color DA");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color DB");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color DC");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color DD");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color DE");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color DF");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color E0");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color E1");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color E2");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color E3");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color E4");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color E5");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color E6");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color E7");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color E8");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color E9");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color EA");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color EB");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color EC");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color ED");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color EE");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color EF");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color F0");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color F1");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color F2");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color F3");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color F4");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color F5");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color F6");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color F7");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color F8");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color F9");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color FA");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color FB");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color FC");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color FD");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color FE");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}
	system("color FF");
	c_sel = getch();
	if (c_sel == 13)
	{
		return(0);
	}


}	 
	





/*
W = 87 || 119 
S = 83 || 115
A = 65 || 97
D = 68 || 100 
Q = 81 || 113


void maxarray(int size, int array[][size])
{

}

int main()
{
	
	int size;
	
	size=5;
	int array[size][size];
	maxarray(size,array);
}
 */

