


	#include <stdio.h>
	#include <stdlib.h>
	#include <time.h>
	
	
	
	
	int main(void){
	
	int f,g;
	
		for ( f = 0; f < 23; f++ ){
		
		g = Get_Rand(5,30);
		
		printf("Your number is : %d\n" , g);
		
		}
		return (0);
		
	}

	int Get_Rand( int min, int max ){
		
			
			static int Init == 0;
			int rc;	
		
			if (Init == 0){
		
				srand(time(NULL));
				Init = 1;
			}
		
			rc = (rand() % ( max - min + 1) + min);
		
			return (rc);
		
		}

