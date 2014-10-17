#include<stdio.h>
#include<stdlib.h>

int addition( int num );
char Add();
int suntraction(int num);
char Sub();
main()
{
	
Add();
}
char Add()
{
	int Calc,num;
	printf("How many numbers do you want to add?\nNo.\t");
	scanf("%i",&num);
	Calc = addition(num);
	printf("The result is %i",Calc);

}
int addition( int num )
{
	int l = 0,result = 0,store = 0;
	
	for(l=0;l<num;l++){
		printf("#%i\t",l+1);
		scanf("%i",&store);
		result += store;
		printf("\n");
	}
	return (result);

}
char Sub()
{
	int Calc,num;
	printf("How many numbers do you want to Subtract?\nNo.\t");
	scanf("%i",&num);
	Calc = subtraction(num);
	printf("The result is %i",Calc);

}
int subtraction( int num )
{
	int l = 0,result = 0,store = 0;
	
	for(l=0;l<num;l++){
		printf("#%i\t",l+1);
		scanf("%i",&store);
		if( l == 0 )
		{
			result = store * 2;
		}
		result -= store;
		printf("\n");
	}
	return (result);

}

