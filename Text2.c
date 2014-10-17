#include<stdio.h>
main(){
	int ID;
	double u1,u2;
	char grd1,grd2;

		printf("Enter your student ID:");
		scanf("%i",&ID);
		printf("Enter your marks for biology ");
		scanf("%lf",&u1);
		printf("Enter your marks for physics ");
		scanf("%lf",&u2);
		printf("\nYour student ID is: %i\nyour bio result is %5.1lf\nyour physic result is %5.1lf\n\n\n\n\n",ID,u1,u2);
		system("pause");

		if (u1 >= 75){
		printf("Your Marks for biology is %5.1lf\tD\n",u1);
		}
		else if (u1 < 75 && u1 >= 50){
		printf("Your Marks for biology is %5.1lf\tP\n",u1);
		}
		else if (u1 < 50 && u1 >= 0){
		printf("Your Marks for biology is %5.1lf\tN\n",u1);
		}
		else {
		("Your an ideot\n");
		}
		
		if (u2 >= 75){
		printf("Your Marks for physic is %5.1lf\tD\n",u2);
		}
		else if (u2 < 75 && u2 >= 50){
		printf("Your Marks for physic is %5.1lf\tP\n",u2);
		}
		else if (u2 < 50 && u2 >= 0){
		printf("Your Marks for physic is %5.1lf\tN\n",u2);
		}
		else {
		("Your an ideot\n");
		}
		



}

