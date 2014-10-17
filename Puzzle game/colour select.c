#include<stdio.h>
#include<stdlib.h>

char colour_select();
char colour_control();
main()
{
	colour_control();

}
char colour_control()
{
	char colour_list[16][2];
	int input, selector_A = 0, selector_B = 7,x,y;
	
	for(x=0;x<2;x++)
	{
		for(y = 0; y < 16;y++)
		{
			colour_list[y][x] = y;
		}
	}
	
	printf("Switch Between Colours with the Keys \nW A S D\n\n\n");
	input = getch();
	if( input == 87 || input == 119)
	{
		if(selector_A > 0)
		{
			selector_A--;
		}
	}
	else if( input == 83 || input == 115)
	{
		if(selector_A < 16)
		{
			selector_A++;
		}
	}
	if( input == 65 || input == 97)
	{
		if(selector_B > 0)
		{
			selector_B--;
		}
	}
	else if( input == 68 || input == 100)
	{
		if(selector_B < 16)
		{
			selector_B++;
		}
	}
	else if(input == 81|| input == 113)
	{
		return('O');
	}
}
char colour_select(char select_[1][2];)
{
	
	else if(select_ == 01)
	system("color 01");
}
/*	  if (a < 10)
		{
			c = a;
					
			printf("{ \nsystem(\"color %i", c);
					
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
			
			
				printf("{ \nsystem(\"color %c", m[0]);
			
			
			
			
			
			
			if (b < 10)
			{
				c = b;
				
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
					
					printf("%c\");\n}", m[1]);
					
				}
				
				
				
				
				
				
				
if(select_ == 00)
{
system("color 00");
}
else if(select_ == 01)
{
system("color 01");
}
else if(select_ == 02)
{
system("color 02");
}
else if(select_ == 03)
{
system("color 03");
}
else if(select_ == 04)
{
system("color 04");
}
else if(select_ == 05)
{
system("color 05");
}
else if(select_ == 06)
{
system("color 06");
}
else if(select_ == 07)
{
system("color 07");
}
else if(select_ == 08)
{
system("color 08");
}
else if(select_ == 09)
{
system("color 09");
}
else if(select_ == 0A)
{
system("color 0A");
}
else if(select_ == 0B)
{
system("color 0B");
}
else if(select_ == 0C)
{
system("color 0C");
}
else if(select_ == 0D)
{
system("color 0D");
}
else if(select_ == 0E)
{
system("color 0E");
}
else if(select_ == 0F)
{
system("color 0F");
}
else if(select_ == 10)
{
system("color 10");
}
else if(select_ == 11)
{
system("color 11");
}
else if(select_ == 12)
{
system("color 12");
}
else if(select_ == 13)
{
system("color 13");
}
else if(select_ == 14)
{
system("color 14");
}
else if(select_ == 15)
{
system("color 15");
}
else if(select_ == 16)
{
system("color 16");
}
else if(select_ == 17)
{
system("color 17");
}
else if(select_ == 18)
{
system("color 18");
}
else if(select_ == 19)
{
system("color 19");
}
else if(select_ == 1A)
{
system("color 1A");
}
else if(select_ == 1B)
{
system("color 1B");
}
else if(select_ == 1C)
{
system("color 1C");
}
else if(select_ == 1D)
{
system("color 1D");
}
else if(select_ == 1E)
{
system("color 1E");
}
else if(select_ == 1F)
{
system("color 1F");
}
else if(select_ == 20)
{
system("color 20");
}
else if(select_ == 21)
{
system("color 21");
}
else if(select_ == 22)
{
system("color 22");
}
else if(select_ == 23)
{
system("color 23");
}
else if(select_ == 24)
{
system("color 24");
}
else if(select_ == 25)
{
system("color 25");
}
else if(select_ == 26)
{
system("color 26");
}
else if(select_ == 27)
{
system("color 27");
}
else if(select_ == 28)
{
system("color 28");
}
else if(select_ == 29)
{
system("color 29");
}
else if(select_ == 2A)
{
system("color 2A");
}
else if(select_ == 2B)
{
system("color 2B");
}
else if(select_ == 2C)
{
system("color 2C");
}
else if(select_ == 2D)
{
system("color 2D");
}
else if(select_ == 2E)
{
system("color 2E");
}
else if(select_ == 2F)
{
system("color 2F");
}
else if(select_ == 30)
{
system("color 30");
}
else if(select_ == 31)
{
system("color 31");
}
else if(select_ == 32)
{
system("color 32");
}
else if(select_ == 33)
{
system("color 33");
}
else if(select_ == 34)
{
system("color 34");
}
else if(select_ == 35)
{
system("color 35");
}
else if(select_ == 36)
{
system("color 36");
}
else if(select_ == 37)
{
system("color 37");
}
else if(select_ == 38)
{
system("color 38");
}
else if(select_ == 39)
{
system("color 39");
}
else if(select_ == 3A)
{
system("color 3A");
}
else if(select_ == 3B)
{
system("color 3B");
}
else if(select_ == 3C)
{
system("color 3C");
}
else if(select_ == 3D)
{
system("color 3D");
}
else if(select_ == 3E)
{
system("color 3E");
}
else if(select_ == 3F)
{
system("color 3F");
}
else if(select_ == 40)
{
system("color 40");
}
else if(select_ == 41)
{
system("color 41");
}
else if(select_ == 42)
{
system("color 42");
}
else if(select_ == 43)
{
system("color 43");
}
else if(select_ == 44)
{
system("color 44");
}
else if(select_ == 45)
{
system("color 45");
}
else if(select_ == 46)
{
system("color 46");
}
else if(select_ == 47)
{
system("color 47");
}
else if(select_ == 48)
{
system("color 48");
}
else if(select_ == 49)
{
system("color 49");
}
else if(select_ == 4A)
{
system("color 4A");
}
else if(select_ == 4B)
{
system("color 4B");
}
else if(select_ == 4C)
{
system("color 4C");
}
else if(select_ == 4D)
{
system("color 4D");
}
else if(select_ == 4E)
{
system("color 4E");
}
else if(select_ == 4F)
{
system("color 4F");
}
else if(select_ == 50)
{
system("color 50");
}
else if(select_ == 51)
{
system("color 51");
}
else if(select_ == 52)
{
system("color 52");
}
else if(select_ == 53)
{
system("color 53");
}
else if(select_ == 54)
{
system("color 54");
}
else if(select_ == 55)
{
system("color 55");
}
else if(select_ == 56)
{
system("color 56");
}
else if(select_ == 57)
{
system("color 57");
}
else if(select_ == 58)
{
system("color 58");
}
else if(select_ == 59)
{
system("color 59");
}
else if(select_ == 5A)
{
system("color 5A");
}
else if(select_ == 5B)
{
system("color 5B");
}
else if(select_ == 5C)
{
system("color 5C");
}
else if(select_ == 5D)
{
system("color 5D");
}
else if(select_ == 5E)
{
system("color 5E");
}
else if(select_ == 5F)
{
system("color 5F");
}
else if(select_ == 60)
{
system("color 60");
}
else if(select_ == 61)
{
system("color 61");
}
else if(select_ == 62)
{
system("color 62");
}
else if(select_ == 63)
{
system("color 63");
}
else if(select_ == 64)
{
system("color 64");
}
else if(select_ == 65)
{
system("color 65");
}
else if(select_ == 66)
{
system("color 66");
}
else if(select_ == 67)
{
system("color 67");
}
else if(select_ == 68)
{
system("color 68");
}
else if(select_ == 69)
{
system("color 69");
}
else if(select_ == 6A)
{
system("color 6A");
}
else if(select_ == 6B)
{
system("color 6B");
}
else if(select_ == 6C)
{
system("color 6C");
}
else if(select_ == 6D)
{
system("color 6D");
}
else if(select_ == 6E)
{
system("color 6E");
}
else if(select_ == 6F)
{
system("color 6F");
}
else if(select_ == 70)
{
system("color 70");
}
else if(select_ == 71)
{
system("color 71");
}
else if(select_ == 72)
{
system("color 72");
}
else if(select_ == 73)
{
system("color 73");
}
else if(select_ == 74)
{
system("color 74");
}
else if(select_ == 75)
{
system("color 75");
}
else if(select_ == 76)
{
system("color 76");
}
else if(select_ == 77)
{
system("color 77");
}
else if(select_ == 78)
{
system("color 78");
}
else if(select_ == 79)
{
system("color 79");
}
else if(select_ == 7A)
{
system("color 7A");
}
else if(select_ == 7B)
{
system("color 7B");
}
else if(select_ == 7C)
{
system("color 7C");
}
else if(select_ == 7D)
{
system("color 7D");
}
else if(select_ == 7E)
{
system("color 7E");
}
else if(select_ == 7F)
{
system("color 7F");
}
else if(select_ == 80)
{
system("color 80");
}
else if(select_ == 81)
{
system("color 81");
}
else if(select_ == 82)
{
system("color 82");
}
else if(select_ == 83)
{
system("color 83");
}
else if(select_ == 84)
{
system("color 84");
}
else if(select_ == 85)
{
system("color 85");
}
else if(select_ == 86)
{
system("color 86");
}
else if(select_ == 87)
{
system("color 87");
}
else if(select_ == 88)
{
system("color 88");
}
else if(select_ == 89)
{
system("color 89");
}
else if(select_ == 8A)
{
system("color 8A");
}
else if(select_ == 8B)
{
system("color 8B");
}
else if(select_ == 8C)
{
system("color 8C");
}
else if(select_ == 8D)
{
system("color 8D");
}
else if(select_ == 8E)
{
system("color 8E");
}
else if(select_ == 8F)
{
system("color 8F");
}
else if(select_ == 90)
{
system("color 90");
}
else if(select_ == 91)
{
system("color 91");
}
else if(select_ == 92)
{
system("color 92");
}
else if(select_ == 93)
{
system("color 93");
}
else if(select_ == 94)
{
system("color 94");
}
else if(select_ == 95)
{
system("color 95");
}
else if(select_ == 96)
{
system("color 96");
}
else if(select_ == 97)
{
system("color 97");
}
else if(select_ == 98)
{
system("color 98");
}
else if(select_ == 99)
{
system("color 99");
}
else if(select_ == 9A)
{
system("color 9A");
}
else if(select_ == 9B)
{
system("color 9B");
}
else if(select_ == 9C)
{
system("color 9C");
}
else if(select_ == 9D)
{
system("color 9D");
}
else if(select_ == 9E)
{
system("color 9E");
}
else if(select_ == 9F)
{
system("color 9F");
}
else if(select_ == A0)
{
system("color A0");
}
else if(select_ == A1)
{
system("color A1");
}
else if(select_ == A2)
{
system("color A2");
}
else if(select_ == A3)
{
system("color A3");
}
else if(select_ == A4)
{
system("color A4");
}
else if(select_ == A5)
{
system("color A5");
}
else if(select_ == A6)
{
system("color A6");
}
else if(select_ == A7)
{
system("color A7");
}
else if(select_ == A8)
{
system("color A8");
}
else if(select_ == A9)
{
system("color A9");
}
else if(select_ == AA)
{
system("color AA");
}
else if(select_ == AB)
{
system("color AB");
}
else if(select_ == AC)
{
system("color AC");
}
else if(select_ == AD)
{
system("color AD");
}
else if(select_ == AE)
{
system("color AE");
}
else if(select_ == AF)
{
system("color AF");
}
else if(select_ == B0)
{
system("color B0");
}
else if(select_ == B1)
{
system("color B1");
}
else if(select_ == B2)
{
system("color B2");
}
else if(select_ == B3)
{
system("color B3");
}
else if(select_ == B4)
{
system("color B4");
}
else if(select_ == B5)
{
system("color B5");
}
else if(select_ == B6)
{
system("color B6");
}
else if(select_ == B7)
{
system("color B7");
}
else if(select_ == B8)
{
system("color B8");
}
else if(select_ == B9)
{
system("color B9");
}
else if(select_ == BA)
{
system("color BA");
}
else if(select_ == BB)
{
system("color BB");
}
else if(select_ == BC)
{
system("color BC");
}
else if(select_ == BD)
{
system("color BD");
}
else if(select_ == BE)
{
system("color BE");
}
else if(select_ == BF)
{
system("color BF");
}
else if(select_ == C0)
{
system("color C0");
}
else if(select_ == C1)
{
system("color C1");
}
else if(select_ == C2)
{
system("color C2");
}
else if(select_ == C3)
{
system("color C3");
}
else if(select_ == C4)
{
system("color C4");
}
else if(select_ == C5)
{
system("color C5");
}
else if(select_ == C6)
{
system("color C6");
}
else if(select_ == C7)
{
system("color C7");
}
else if(select_ == C8)
{
system("color C8");
}
else if(select_ == C9)
{
system("color C9");
}
else if(select_ == CA)
{
system("color CA");
}
else if(select_ == CB)
{
system("color CB");
}
else if(select_ == CC)
{
system("color CC");
}
else if(select_ == CD)
{
system("color CD");
}
else if(select_ == CE)
{
system("color CE");
}
else if(select_ == CF)
{
system("color CF");
}
else if(select_ == D0)
{
system("color D0");
}
else if(select_ == D1)
{
system("color D1");
}
else if(select_ == D2)
{
system("color D2");
}
else if(select_ == D3)
{
system("color D3");
}
else if(select_ == D4)
{
system("color D4");
}
else if(select_ == D5)
{
system("color D5");
}
else if(select_ == D6)
{
system("color D6");
}
else if(select_ == D7)
{
system("color D7");
}
else if(select_ == D8)
{
system("color D8");
}
else if(select_ == D9)
{
system("color D9");
}
else if(select_ == DA)
{
system("color DA");
}
else if(select_ == DB)
{
system("color DB");
}
else if(select_ == DC)
{
system("color DC");
}
else if(select_ == DD)
{
system("color DD");
}
else if(select_ == DE)
{
system("color DE");
}
else if(select_ == DF)
{
system("color DF");
}
else if(select_ == E0)
{
system("color E0");
}
else if(select_ == E1)
{
system("color E1");
}
else if(select_ == E2)
{
system("color E2");
}
else if(select_ == E3)
{
system("color E3");
}
else if(select_ == E4)
{
system("color E4");
}
else if(select_ == E5)
{
system("color E5");
}
else if(select_ == E6)
{
system("color E6");
}
else if(select_ == E7)
{
system("color E7");
}
else if(select_ == E8)
{
system("color E8");
}
else if(select_ == E9)
{
system("color E9");
}
else if(select_ == EA)
{
system("color EA");
}
else if(select_ == EB)
{
system("color EB");
}
else if(select_ == EC)
{
system("color EC");
}
else if(select_ == ED)
{
system("color ED");
}
else if(select_ == EE)
{
system("color EE");
}
else if(select_ == EF)
{
system("color EF");
}
else if(select_ == F0)
{
system("color F0");
}
else if(select_ == F1)
{
system("color F1");
}
else if(select_ == F2)
{
system("color F2");
}
else if(select_ == F3)
{
system("color F3");
}
else if(select_ == F4)
{
system("color F4");
}
else if(select_ == F5)
{
system("color F5");
}
else if(select_ == F6)
{
system("color F6");
}
else if(select_ == F7)
{
system("color F7");
}
else if(select_ == F8)
{
system("color F8");
}
else if(select_ == F9)
{
system("color F9");
}
else if(select_ == FA)
{
system("color FA");
}
else if(select_ == FB)
{
system("color FB");
}
else if(select_ == FC)
{
system("color FC");
}
else if(select_ == FD)
{
system("color FD");
}
else if(select_ == FE)
{
system("color FE");
}
else if(select_ == FF)
{
system("color FF");
}


*/

