#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int a, b, c, d, e;
	char m[2];
	FILE *REC;
	char rec[] = "Colour Change Codes.txt";
	REC = fopen(rec, "w");
	if (REC == 0)
	{
	}
	else
	{
		for (a = 0;a < 16;a++)
		{
			for (b = 0;b < 16;b++)
			{
				for (d = 0; d < 2; d++)
				{
					if (a < 10)
					{
						c = a;
						if (d == 1)
						{
							fprintf(REC,"{ \nsystem(\"color %i", c);
						}
						else
						{
							fprintf(REC,"else if(strcmp(m,\"%i", c);
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
						if (d == 1)
						{
							fprintf(REC,"{ \nsystem(\"color %c", m[0]);
						}
						else
						{
							fprintf(REC,"else if(strcmp(m,\"%c", m[0]);
						}
					}
					if (b < 10)
					{
						c = b;
						if (d == 1)
						{
							fprintf(REC,"%i\");\n}", c);
						}
						else
						{
							fprintf(REC,"%i\")==0)\n", c);
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
						if (d == 1)
						{
							fprintf(REC,"%c\");\n}", m[1]);
						}
						else
						{
							fprintf(REC,"%c\")==0)\n", m[1]);
						}
					}
					fprintf(REC,"\n");
				}
			}
		}
	}
	fclose(REC);
	return 0;
}
/*
system("color C4")
}
else if(strcmp(m," C5")==0);
{
system("color C5")
}
else if(strcmp(m," C6")==0);
{
system("color C6")
}
else if(strcmp(m," C7")==0);
{
system("color C7")
}
else if(strcmp(m," C8")==0);
{
system("color C8")
}
else if(strcmp(m," C9")==0);
{
system("color C9")
}
else if(strcmp(m," CA")==0)
{
system("color CA")
}
else if(strcmp(m," CB")==0)
{
system("color CB")
}
else if(strcmp(m," CC")==0)
{
system("color CC")
}
else if(strcmp(m," CD")==0)
{
system("color CD")
}
else if(strcmp(m," CE")==0)
{
system("color CE")
}
else if(strcmp(m," CF")==0)
{
system("color CF")
}
else if(strcmp(m," D0")==0);
{
system("color D0")
}
else if(strcmp(m," D1")==0);
{
system("color D1")
}
else if(strcmp(m," D2")==0);
{
system("color D2")
}
else if(strcmp(m," D3")==0);
{
system("color D3")
}
else if(strcmp(m," D4")==0);
{
system("color D4")
}
else if(strcmp(m," D5")==0);
{
system("color D5")
}
else if(strcmp(m," D6")==0);
{
system("color D6")
}
else if(strcmp(m," D7")==0);
{
system("color D7")
}
else if(strcmp(m," D8")==0);
{
system("color D8")
}
else if(strcmp(m," D9")==0);
{
system("color D9")
}
else if(strcmp(m," DA")==0)
{
system("color DA")
}
else if(strcmp(m," DB")==0)
{
system("color DB")
}
else if(strcmp(m," DC")==0)
{
system("color DC")
}
else if(strcmp(m," DD")==0)
{
system("color DD")
}
else if(strcmp(m," DE")==0)
{
system("color DE")
}
else if(strcmp(m," DF")==0)
{
system("color DF")
}
else if(strcmp(m," E0")==0);
{
system("color E0")
}
else if(strcmp(m," E1")==0);
{
system("color E1")
}
else if(strcmp(m," E2")==0);
{
system("color E2")
}
else if(strcmp(m," E3")==0);
{
system("color E3")
}
else if(strcmp(m," E4")==0);
{
system("color E4")
}
else if(strcmp(m," E5")==0);
{
system("color E5")
}
else if(strcmp(m," E6")==0);
{
system("color E6")
}
else if(strcmp(m," E7")==0);
{
system("color E7")
}
else if(strcmp(m," E8")==0);
{
system("color E8")
}
else if(strcmp(m," E9")==0);
{
system("color E9")
}
else if(strcmp(m," EA")==0)
{
system("color EA")
}
else if(strcmp(m," EB")==0)
{
system("color EB")
}
else if(strcmp(m," EC")==0)
{
system("color EC")
}
else if(strcmp(m," ED")==0)
{
system("color ED")
}
else if(strcmp(m," EE")==0)
{
system("color EE")
}
else if(strcmp(m," EF")==0)
{
system("color EF")
}
else if(strcmp(m," F0")==0);
{
system("color F0")
}
else if(strcmp(m," F1")==0);
{
system("color F1")
}
else if(strcmp(m," F2")==0);
{
system("color F2")
}
else if(strcmp(m," F3")==0);
{
system("color F3")
}
else if(strcmp(m," F4")==0);
{
system("color F4")
}
else if(strcmp(m," F5")==0);
{
system("color F5")
}
else if(strcmp(m," F6")==0);
{
system("color F6")
}
else if(strcmp(m," F7")==0);
{
system("color F7")
}
else if(strcmp(m," F8")==0);
{
system("color F8")
}
else if(strcmp(m," F9")==0);
{
system("color F9")
}
else if(strcmp(m," FA")==0)
{
system("color FA")
}
else if(strcmp(m," FB")==0)
{
system("color FB")
}
else if(strcmp(m," FC")==0)
{
system("color FC")
}
else if(strcmp(m," FD")==0)
{
system("color FD")
}
else if(strcmp(m," FE")==0)
{
system("color FE")
}
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

