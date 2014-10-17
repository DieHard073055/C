#include<stdio.h>
#include<stdlib.h>

int addition( int num );
main()
{
	int Calc,num;
	printf("How many numbers do you want to add?/nNo./t");
	scanf("%i",&num);
	Calc = addition(num);

}
int addition( int num )
{
	int l,result,store;
	
	for(l=0;l<num;l++){
		printf("#%i/t",l+1);
		scanf("%i",&store);
		result += store;
		printf("/n");
	}
	return (result);

}

