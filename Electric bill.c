#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Electricity Bill Calculation Formula
//Rate A: 1-100 units x 0.29 cents + 5
//Rate B: 101-400 units x 0.29 cents + 5
//Rate C: 401++ x 0.33 cents -11
double RateA(double R);
double RateB(double R);
double RateC(double R);
int main()
{
	double first, Second, Reading,amount;
	printf("\n\n\tPlease Enter the Current Meter Reading\n\tCurrent Reading: ");
	scanf("%lf",&first);
	printf("\n\n\tPlease Enter the Previous Meter Reading\n\tPrevious Reading: ");
	scanf("%lf",&Second);

	Reading = first - Second;
	printf("\n\t--------------------------------\n");
	printf("\tTotal Usage (unit(s)) %06.0f",Reading);
	

	if(Reading < 101)
	{
		amount = RateA(Reading);
		printf("\n\tRate A\n");
	}
	else if(Reading < 401)
	{
		amount = RateB(Reading);
		printf("\n\tRate B\n");
	}
	else if(Reading > 400)
	{
		amount = RateC(Reading);
		printf("\n\tRate C\n");
	}
	printf("\n\n\t--------------------------------\n");
	printf("\tYour Bill is RM %.2f\n",amount);
	printf("\t--------------------------------\n");
	return 0;
}
double RateA(double R)
{
	double amount;
	amount = (R * 0.34);
	return amount;
}
double RateB(double R)
{
	double amount;
	amount = (R * 0.29) + 5; 
	return amount;

}
double RateC(double R)
{
	double amount;
	amount = (R * 0.33) - 11;
	return amount;
}

