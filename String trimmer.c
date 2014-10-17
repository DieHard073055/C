/* Yay goto :D */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


char *trim(char *buffer, char *stripchars);


int main()
{
	 
	char buffer[] = "    Hello World     ";
	
	printf("%s", trim(buffer, " "));



	return 0;
}


char *trim(char *buffer, char *stripchars)
{
	int i = 0;
	/* Left Side */
	char *start = buffer;
	
	
	left:
	for (i = 0; i < strlen(stripchars); i++)
	{
		if (*start == stripchars[i])
		{
			start++;
			goto left;
		}
	}
	/* Right Side */
	char *end = start + strlen(start) - 1;
	
	
	right:
	for (i = 0; i < strlen(stripchars); i++)
	{
		if (*end == stripchars[i])
		{
			*end = '\0';
			--end;
			goto right;
		}
	}
	return start;
}

