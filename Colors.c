#include<stdio.h>
#include<stdlib.h>
#include<string.h>
main()
{
	int a, b, c, d, e;
	char m[2];
	for (a = 0;a < 16;a++)
	{
		for (b = 0;b < 16;b++)
		{
			for (d = 0; d < 2; d++)
			{
				if (a < 10)
				{
					c = a;
					
					if(d == 1)
					{
						printf("{ \nsystem(\"color %i", c);
					}
					else
					{
						printf("else if(select_ == %i", c);
					}
				}
				else
				{
					if (a == 10)
					{
						m[0] = 'A';
					}
					if (a == 11)
					{
						m[0] = 'B';
						
					}
					if (a == 12)
					{
						m[0] = 'C';
					}
					if (a == 13)
					{
						m[0] = 'D';
					}
					if (a == 14)
					{
						m[0] = 'E';
					}
					if (a == 15)
					{
						m[0] = 'F';
					}
						if(d == 1)
						{
							printf("{ \nsystem(\"color %c", m[0]);
						}
						else
						{
							printf("else if(select_ == %c", m[0]);
						}
				}
				if (b < 10)
				{
					c = b;
					if(d == 1)
					{
						printf("%i\");\n}", c);
					}
					else
					{
						printf("%i)",c);
					}
					
				}
				else
				{
					if (b == 10)
					{
						m[1] = 'A';
					}
					if (b == 11)
					{
						m[1] = 'B';
					}
					if (b == 12)
					{
						m[1] = 'C';
					}
					if (b == 13)
					{
						m[1] = 'D';
					}
					if (b == 14)
					{
						m[1] = 'E';
					}
					if (b == 15)
					{
						m[1] = 'F';
					}
					if(d == 1)
					{
						printf("%c\");\n}", m[1]);
					}
					else
					{
						printf("%c)",m[1]);
					}
				}
				printf("\n");
			}
		}
	}
}
/*
system("color 00");
getch();
system("color 01");
getch();
system("color 02");
getch();
system("color 03");
getch();
system("color 04");
getch();
system("color 05");
getch();
system("color 06");
getch();
system("color 07");
getch();
system("color 08");
getch();
system("color 09");
getch();
system("color 0F");
getch();
system("color 10");
getch();
system("color 11");
getch();
system("color 12");
getch();
system("color 13");
getch();
system("color 14");
getch();
system("color 15");
getch();
system("color 16");
getch();
system("color 17");
getch();
system("color 18");
getch();
system("color 19");
getch();
system("color 1F");
getch();
system("color 20");
getch();
system("color 21");
getch();
system("color 22");
getch();
system("color 23");
getch();
system("color 24");
getch();
system("color 25");
getch();
system("color 26");
getch();
system("color 27");
getch();
system("color 28");
getch();
system("color 29");
getch();
system("color 2F");
getch();
system("color 30");
getch();
system("color 31");
getch();
system("color 32");
getch();
system("color 33");
getch();
system("color 34");
getch();
system("color 35");
getch();
system("color 36");
getch();
system("color 37");
getch();
system("color 38");
getch();
system("color 39");
getch();
system("color 3F");
getch();
system("color 40");
getch();
system("color 41");
getch();
system("color 42");
getch();
system("color 43");
getch();
system("color 44");
getch();
system("color 45");
getch();
system("color 46");
getch();
system("color 47");
getch();
system("color 48");
getch();
system("color 49");
getch();
system("color 4F");
getch();
system("color 50");
getch();
system("color 51");
getch();
system("color 52");
getch();
system("color 53");
getch();
system("color 54");
getch();
system("color 55");
getch();
system("color 56");
getch();
system("color 57");
getch();
system("color 58");
getch();
system("color 59");
getch();
system("color 5F");
getch();
system("color 60");
getch();
system("color 61");
getch();
system("color 62");
getch();
system("color 63");
getch();
system("color 64");
getch();
system("color 65");
getch();
system("color 66");
getch();
system("color 67");
getch();
system("color 68");
getch();
system("color 69");
getch();
system("color 6F");
getch();
system("color 70");
getch();
system("color 71");
getch();
system("color 72");
getch();
system("color 73");
getch();
system("color 74");
getch();
system("color 75");
getch();
system("color 76");
getch();
system("color 77");
getch();
system("color 78");
getch();
system("color 79");
getch();
system("color 7F");
getch();
system("color 80");
getch();
system("color 81");
getch();
system("color 82");
getch();
system("color 83");
getch();
system("color 84");
getch();
system("color 85");
getch();
system("color 86");
getch();
system("color 87");
getch();
system("color 88");
getch();
system("color 89");
getch();
system("color 8F");
getch();
system("color 90");
getch();
system("color 91");
getch();
system("color 92");
getch();
system("color 93");
getch();
system("color 94");
getch();
system("color 95");
getch();
system("color 96");
getch();
system("color 97");
getch();
system("color 98");
getch();
system("color 99");
getch();
system("color 9F");
getch();
system("color F0");
getch();
system("color F1");
getch();
system("color F2");
getch();
system("color F3");
getch();
system("color F4");
getch();
system("color F5");
getch();
system("color F6");
getch();
system("color F7");
getch();
system("color F8");
getch();
system("color F9");
getch();
system("color FF");
getch();
Press Enter to return to Quincy...
*/

