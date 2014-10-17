#include<stdio.h>
#include<string.h>
int main()
{
	char *p,final[90];
	char t[] = "How are you doing today";
	int j;
	
	p = strstr(t,"doing");
	printf("%s\n",p);
	strcpy(final,p);
	printf("%s\n",final);
	return 0;
}

