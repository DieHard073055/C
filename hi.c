#include<stdio.h>
int main()
{
/*---------Declaration----------*/
int age,i;
char letter;
/*-----------Commands-----------*/
	for(i=0; i < 2;){
	printf("Hi there\nWhats your age?\n");
	scanf( "%d", &age );
	
	if ( age < 18 ){
	
			printf("Your Under Age!!! you noob!!! go home!");
			break;
	}
	else if ( age < 1 ){
		printf ("Thats not a valid answer");
		break;
	}
	else if (( age > 65)&&( age < 100 ) == 0 ){
		printf (" you have to retire now!!");
		break;
	}
	else if ( "%s", letter ){
		printf ( "malibu" );
		break;
	} 
	

	}
}

