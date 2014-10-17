	
/* all the #include stuff....*/	   
	#include <stdio.h>
	#include <stdlib.h>
	#include <time.h>

/* The Main Function */
	int main(void){
	
/*Declarations */
	int h,j,k;
	int Mat[5][5];
/*	  
/*Assignment of the values to the array 
	for( h = 0; h < 5; h++ ){
		for( j = 0; j < 5; j++){
			
			Mat[h][j] = Rand_Gen( 4 , 1 );
			
		}
	}
	
/*Displaying the Array 
	for ( h = 0; h < 5;	 h++ ){
		for( j = 0; j < 5; j++){
			printf("  %d  " ,Mat[h][j]);
		}
		printf("\n");
	}  
	
	
	*/
	for (h = 0; h < 23; h++){
		k = Rand_Gen(1,4);
		printf("%d\n" , k);
	
	
	return 0;
	}
/* Random Value Generator Function */
	int Rand_Gen( int min, int max ){
		static int init = 0;
		int g;
		
			if ( init == 0 ){
				srand(time(NULL));
			}
			
			g = (rand() % (max - min +1) + min);
			return (g);
	}

