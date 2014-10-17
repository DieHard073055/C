#include<stdio.h>
#include<ctype.h>

int main()
{
	int counter = 0;
	char mychar;
	char str[] = "TeSt thIS SenTENce.\n";
	
	printf("\n\n%s",str);
	printf("\n\nPress Enter to turn the sentece to ALL CAPS\n\n");
	getchar();
	while (str[counter])
	{
		mychar=str[counter];
		putchar (toupper(mychar));
		counter++;
	}
	return 0;
}

