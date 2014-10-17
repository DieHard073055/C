#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int Get_rand (int min, int max );
void Welcome_to_NoPath ( void );
int main(void)
	{
		int i, j, k, x, y;
		char check;
		static char sorry = 'T';
		char move_up = 'P';
		char move_down = 'P';
		char move_left = 'P';
		char move_right = 'P';
		char ans;
		struct Array_for_the_Board
		{
			int ran;
			char Valid;	

		} spot[5][5];
	
/*
		#############################################
		##   Assigning random numbers to matrix    ## 
		##   Assigning the letter N to the matrix  ##
		#############################################
		
*/
	
	
		for ( i = 0; i < 5; i++){
			for (j = 0; j < 5; j++){
				spot[i][j].ran = Get_rand(1,5);
				spot[i][j].Valid ='N' ;
			}
		}
		spot[0][0].Valid = 'Y';
		spot[0][0].ran = 0;
	do{	
	if ( sorry == 'F' ){
		printf("Sorry you cannot move to that Direction.\nWhy not try another Direction.\n\n");
		system("pause");
		sorry = 'T';
	}
	/* Welcome Message and the Instructions*/
		Welcome_to_NoPath();
/*
		#####################################
		##       Find the position of      ## 
		##         of the char Y           ##
		##       And printing the whole    ##
		##             Array               ##
		#####################################
*/
		
		for ( i = 0; i < 5; i++){
			for (j = 0; j < 5; j++){
				check = spot[i][j].Valid;
					if (check =='Y'){
		/************************************************************
		 ****** Capture the x and y coordinate of the position ******
		 ************************************************************/
					y = j;
					x = i;
					printf("{%i " , spot[i][j].ran);
					printf("%c}\t" , spot[i][j].Valid);
					continue ;
					}
				
				printf("%i " , spot[i][j].ran);
				printf("%c\t" , spot[i][j].Valid);
			}
			printf("\n\n");
		}	
		
/*
		#####################################
		##       Restricting Movement      ## 
		##         Out of the Array        ##
		#####################################
*/
		 
		if( y == 0 ){
			move_left = 'I';
		}
		else{
			move_left = 'P';
		}
		if( y == 4 ){
			move_right = 'I';
		}
		else{
			move_right = 'P';
		}
		if ( x == 0 ){ 
			move_up = 'I';
		}
		else{
			move_up = 'P';
		}
		if( x == 4 ){ 
			move_down = 'I';
		}
		else{
			move_down = 'P';
		}
		
		
		
		/************************************************************
		******       Prompt the user for the Direction        *******
		*************************************************************/
	  
		scanf("%c",&ans);
		system("cls"); 
		 
		/************************************************************
		******                 Press Q to quit                *******
		*************************************************************/
		if ( ans == 'Q'){
			k = 3;
		}
		/************************************************************
		******               Press S to move down             *******
		*************************************************************/
		else if ( ans == 'S'){
			if ( move_down == 'P' ){
				spot[x][y].Valid = 'N';
				x ++;
				spot[x][y].Valid = 'Y';
			}
			else if ( move_down == 'I' ){
				sorry = 'F';
			}
			
		}
		/************************************************************
		******               Press D to move right            *******
		*************************************************************/
		
		else if ( ans == 'D'){
			if ( move_right == 'P' ){
				spot[x][y].Valid = 'N';
				y ++;
				spot[x][y].Valid = 'Y';
			}
			else if ( move_right == 'I' ){
				sorry = 'F';
			}
		
		}
		/************************************************************
		******               Press A to move left             *******
		*************************************************************/
		else if ( ans == 'A'){
			if ( move_left == 'P' ){
				spot[x][y].Valid = 'N';
				y --;
				spot[x][y].Valid = 'Y';
			}
			else if ( move_left == 'I' ){
				sorry = 'F';
			}
		
		}
		/************************************************************
		******                Press W to move up              *******
		*************************************************************/	     
		else if ( ans == 'W'){
			if ( move_up == 'P' ){
				spot[x][y].Valid = 'N';
				x --;
				spot[x][y].Valid = 'Y';
			}
			else if ( move_up == 'I' ){
				sorry = 'F';
			}
		
		}	   	     
		
		
		
		
	}while (k < 2);

	return(0);
	 
	}
			/*
		#####################################
		##          Random Number          ## 
		##             Generator           ##
		#####################################
		*/
	

		int Get_rand (int min, int max)
		{
			static int initial = 0;
			int Num = 0;
			if (initial == 0)
			{
				srand(time(NULL));
				initial = 1;
			}
			Num = ( rand() % ( max - min + 1 ) + min );
			return (Num);
		}
	
	
	/*
		#####################################
		##           Welcome               ## 
		##       And instructions          ##
		#####################################
*/
	void Welcome_to_NoPath ( void ){
	int i;
	for ( i = 0; i < 37 + 6; i++){
		printf("#");
	}
	printf("\n");
	printf("##");
	for ( i = 0; i < 11; i++){
		printf(" ");
	}
	printf("Welcome to NoPath");
	for ( i = 0; i < 11; i++){
		printf(" ");
	}
	printf("##");
	printf("\n");
	for ( i = 0; i < 37 + 6; i++){
		printf("#");
	}
	printf("\n\n");
	printf("     ~");
	for ( i = 0; i < 9; i++){
		printf("*");
	}
	printf("Instructions");
	for ( i = 0; i < 9; i++){
		printf("*");
	}
	printf("~");
	printf("\n\n\n");
	printf("\t\tW = UP\nA = Left\tS = Down\tD = Right\n\t\tQ = Quit\n\n\n");
	
	}

