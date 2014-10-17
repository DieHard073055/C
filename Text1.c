/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~~
~$#$#$#$#$#$#$#$#$#$#$#$#$#~
~$#                      $#~
~$#	  MY   CALCULATOR    $#~
~$#                      $#~
~$#$#$#$#$#$#$#$#$#$##$#$#$~
~~~~~~~~~~~~~~~~~~~~~~~~~~~~
~by Eshan Shafeeq
All rights reserved
xD
 
 
 
*/
 
 
	#include<stdio.h>
/*
======||Welcome Thingy Thingy||======
    */
 
	void welCome()
	{
		printf("Welcome to The Calculator 4000 v1.0.0.0\n\n");
		printf("Choose an option you want:\n\n");
		printf("1)Addition\t\t2)Subtraction\n3)Multiplication\t4)Division\n\n");
	}
/*
======||Addition||======
 	  */
	void addition(){
		int n1,n2,ans;
		printf("    ############\n----# Addition #----\n    ############\n\n\n");
		printf("Write down the two value you want to Add.\n\n(\"After Each Value Press Enter\")\n");
		scanf("%d%d",&n1,&n2);
		ans = n1 + n2;
		printf("The answer is %d\n",ans);
		system("pause");
		printf("\n\n\n\n\n\n\n\n\n\n");
	}
/*
======||Subtraction||======
 	     */
	void subtraction(){
		int n1,n2,ans;
		printf("    ###############\n----# Subtraction #----\n    ###############\n\n\n");
		printf("Write down the two values you want to Subtract.\n\n(\"After Each Value Press Enter\")\n");
		scanf("%d%d",&n1,&n2);
		ans = n1 - n2;
		printf("The answer is %d\n",ans);
		system("pause");
		printf("\n\n\n\n\n\n\n\n\n\n");
		}
/*
======||Multiplication||======
 	        */
	void times(){
		int n1,n2,ans;
		printf("    ##################\n----# Multiplication #----\n    ##################\n\n\n");
		printf("Write down the two values you want to Multiply.\n\n(\"After Each Value Press Enter\")\n");
		scanf("%d%d",&n1,&n2);
		ans = n1 * n2;
		printf("The answer is %d\n",ans);
		system("pause");
		printf("\n\n\n\n\n\n\n\n\n\n");
	}
/*
======||Division||======
 	        */
	void david(){
		int n1,n2,ans;
		printf("    ############\n----# Division #----\n    ############\n\n\n");
		printf("Write down the two values you want to Divide.\n\n(\"After Each Value Press Enter\")\n");
		scanf("%d%d",&n1,&n2);
		ans = n1 / n2;
		printf("The answer is %d\n",ans);
		system("pause");
		printf("\n\n\n\n\n\n\n\n\n\n");
	}
/*
###############################
#======||Main Commands||======#
###############################
          */
	main()
		{
		int choice = 1;
		while ((choice >= 1) && (choice <= 4)){
		welCome();
		scanf("%d",&choice);
			if (choice == 1){
				addition();
			}
			else if (choice == 2){
				subtraction();
			}
			else if (choice == 3){
				times();
			}
			else if (choice == 4){
				david();
			}
			else{
				break;
			}
		}
 
	}

