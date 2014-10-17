#include<stdio.h>
#include<stdlib.h>

int main()
{
int num;
char str[3];

num=5;

snprintf(str, 3,"%i",num);
printf("%s",str);
return 0;
}

