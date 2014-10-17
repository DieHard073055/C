/*********Temperature Caluculator*********/

	#include<stdio.h>


	void cal_far(){
	double Cel,far;
	printf("Write the value you want to convert to fahrenheit in celsius\n");
		scanf("%lf",&Cel);
		far = (Cel * 9/5 + 32);
		printf("\n\nThats %.2lf degrees celcius",far);
	
	}

	void cal_cel(){
	double Cel,far;
		printf("Write the value you want to convert to celcius in fahrenheit\n");
		scanf("%lf",&far);
			Cel = (far-32) * 5/9 ;
			printf("\n\nThats %.2lf degrees celcius",Cel);
	
	}

/*********Declarations*********/

	main(){
		char ans[5];	
		printf("If you want calculate fahrenheit please type far.\nif you want to calculate celsius type cel\n");
		scanf("%s",&ans);
			if (strcmp(ans,"cel")==0){
				cal_cel();
			}	 
			else if (strcmp(ans,"far")==0){
				cal_far();
			}
			else{
			printf("I dont understand you language\n");
			system("pause");
			printf("\n\n\n\nhave a nice day\n\n\n\n\n\n\n");
			system("pause");}

	}

