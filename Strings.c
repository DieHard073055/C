#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main()
{
	char mychar,C='T';
	int counter=0;
	char str[100];
	
	printf("Please write a message and this programme will fix the\nCaps lock stuff xD\n\nMessage: ");
	fflush(stdin);
	scanf("%[^\n]",str);
	printf("\n\n\nFixed Message:\n\t");
	while (str[counter])
	{	
		mychar=str[counter];
		if(C=='T')
		{
			printf("%c",toupper(mychar));
		}
		else if( C == 'F' )
		{
			printf("%c",tolower(mychar));
		}
		if (mychar == ' ')
		{	 C='T';}
		else
		{	 C = 'F';}
		counter++;
	}
}

