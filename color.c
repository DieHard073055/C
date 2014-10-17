#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()

{

  int a,b,c;
  char m[2];

 system("color 10");

  a=1; b=1; c=a+b;

  printf("a+b=%d\n",c);


/*
0 = Black
1 = Blue
2 = Green
3 = Aqua
4 = Red
5 = Purple
6 = Yellow
7 = White
8 = Gray
9 = Light Blue
A = Light Green
B = Light Aqua
C = Light Red
D = Light Purple
E = Light Yellow
F = Bright White
*/

  printf("Press a key to finish.printf(Press a key to finish.);\n");
  for(a=0;a<16;a++)
  {
  	for(b=0;b<16;b++)
	{
		if(a<10)
		{
			m[0] = a;
		}
		else
		{
			if(a = 10)
			{
				m[0] = 'A';
			}
			if(a = 11)
			{
				m[0] = 'B';
			}
			if(a = 12)
			{
				m[0] = 'C';
			}
			if(a = 13)
			{
				m[0] = 'D';
			}
			if(a = 14)
			{
				m[0] = 'E';
			}
			if(a = 15)
			{
				m[0] = 'F';
			}
			
		}
		if(b<10)
		{
			m[0] = b;
		}
		else
		{
			if(b = 10)
			{
				m[0] = 'A';
			}
			if(b = 11)
			{
				m[0] = 'B';
			}
			if(b = 12)
			{
				m[0] = 'C';
			}
			if(b = 13)
			{
				m[0] = 'D';
			}
			if(b = 14)
			{
				m[0] = 'E';
			}
			if(b = 15)
			{
				m[0] = 'F';
			}
			
		}
		printf("system(\"color %s\")\n",m);
	}
  }
}

