	#include<stdio.h>

		struct my_Details
			{
				char name[10];
				int age;
				char gender[6];
			}	
				yourD,fridge;



	main(){
		printf("Please enter your name <10 characters available>\n : ");
			scanf("%s",&yourD.name);
		printf("Please enter you age: ");
			scanf("%i",&yourD.age);
		printf("Please enter your gender <Male/Female>: ");
			scanf("%s",&yourD.gender);
		
		printf("\n\n\n");
		printf("Your Name : %s\nYour age: %i\nYour Gender: %s", yourD.name, yourD.age, yourD.gender);
	
		system("pause");

	}

