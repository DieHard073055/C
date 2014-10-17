#include<stdio.h>
	/*
	##################################
	#--------Classified Codes--------#
	##################################
	                                */
	void secret(){
	int i,j,k;
	printf("\nSo you knw the password right (press enter)\n");
	system("pause");
	printf("\n\n\nOkay so the top secret data is gonna be reveled to you only!!!\n okay...(press enter)\n");
	system("pause");
	printf("\n\n\nOkay here it goes\n\n");
	for (i = 0; i < 5; i++){
		for (j = 0; j < 1; j++){
			for( k = 0; k < i; k++){
				printf("xD");
			}
		printf("\n\n");
		}
	}	 
	printf(" ...\n ummm...\n yeah!\n (press enter)\n");
	system("pause");
	printf("\n\n\n\n\n\n\n Did you knw that im 59KG xD \n ._. \n xDDD");
	system("pause");
	}
main()
{
	/*
	###############################
	#---------Declarations--------#
	###############################
	                             */
	char pass[10];
	int v,c,d,f;
	/*
	#############################
	#---------Commands----------#
	#############################
	                            */
		printf("Hello there :) \n<Press Any Key>");
		system("pause");
		for (c = 0; c < 22;c++)
		{
			for (d = 0; d < 3; d++)
			{
				
								
					for (f = 0; f < c;f++)
					{
					
						printf("*");
					}
				printf("\n");
			}
		}
		for (v = 0; v < 5;v++)
			{	 	
				printf("Please Enter The system Password xD\n");
				scanf("%s", pass);
				/*
				####################################
				#--------Password Validation-------#
				####################################
				                                  */
				if( strcmp (pass, "parachute" ) == 0 ){
					printf("your password is valid\n");
					secret();
					break;
				}
				else{
			
					printf("Invalid password\n");}
	
			}
}

