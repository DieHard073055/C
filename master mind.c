#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <dos.h>
#include <ctype.h>
#include <time.h>
typedef struct record
{
	int code[4];
	int controle[4];
	struct record* volg;
} ZET;
void genereer_code(int*, int);
void enqueue(ZET**, ZET**, int*);
void controle(int*, ZET**);
void toon_res(ZET**);
int main(void)
{
	int code[4],  i, pcode[4], mgraad = 0, sw_ok = 1;
	struct time voor[];
	struct time na[];
	
	ZET *kop = NULL, *staart = NULL;
	
	printf("Maak uw keuze uit volgende moeilijkheidsgraden :\n  1)Makkelijk\n  2)Middelmatig\n  3)Moeilijk\n");
	printf("\nUw keuze : ");
	scanf("%d", &mgraad);
	switch (mgraad)
	{
	case 1 :
		mgraad = 3;
		break;
	case 2 :
		mgraad = 6;
		break;
	case 3 :
		mgraad = 9;
		break;
	default :
		printf("Foutieve keuze");
	}
	clrscr();
	gettime(&voor);
	genereer_code(code, mgraad);
	printf("|1 = rood  2 = zwart  3 = blauw |\n");
	if (mgraad >= 6)
	{
		printf("|4 = geel  5 = wit    6 = groen |\n");
	}
	if (mgraad == 9)
	{
		printf("|7 = bruin 8 = paars  9 = oranje|\n");
	}
	printf("---------------------------------\n");
	printf("%d %d %d %d\n", code[0], code[1], code[2], code[3]);
	printf("Geef telkens 4 getallen in gescheiden door een spatie\n");
	printf("**************\n");
	do
	{
		printf("*");
		for (i = 0; i < 4;)
		{
			char c;
			c = getch();
			if (isdigit(c))
			{
				pcode[i] = atoi(&c);
				i++;
			}
			printf("%c", c);
		}
		enqueue(&kop, &staart, pcode);
		getch();
		printf("*");
		controle(code, &kop);
		toon_res(&kop);
	}
	while (sw_ok);
	gettime(&na);
	//printf("U heeft de juiste kleurcombinatie gevonden na %02d uur %02d minuten %02d seconden en %02d honderdste seconden",na.ti_hour - voor.ti_hour, na.ti_min - voor.ti_min, na.ti_sec - voor.ti_sec, na.ti_hund - voor.ti_hund);
	return 0;
}
void genereer_code(int* code, int graad)
{
	int i;
	randomize();
	for (i = 0; i < 4; i++)
	{
		code[i] = ((rand() % graad) + 1);
	}
}
void enqueue(ZET **pkop, ZET **pstaart, int* pcode)
{
	int i;
	ZET *p;
	p = malloc(sizeof(ZET));
	for (i = 0; i < 4; i++)
	{
		p->code[i] = pcode[i];
		printf("%d", p->code[i]);
	}
	p->volg = NULL;
	if (*pkop)
	{
		(*pstaart)->volg = p;
	}
	else
	{
		*pkop = p;
	}
	*pstaart = p;
}
void controle(int* code, ZET **pkop)
{
	int i, j;
	for (i = 0; i < 4;i++)
	{
		printf("%d", (*pkop)->code[i]);
		for (j = 0; j < 4; j++)
		{
			if ((*pkop)->code[i] == code[j])
			{
				if (i == j)
				{
					(*pkop)->controle[i] = 2;
				}
				else
				{
					(*pkop)->controle[i] = 1;
				}
			}
			else
			{
				(*pkop)->controle[i] = 0;
			}
		}
	}
}
void toon_res(ZET** qkop)
{
	int i;
	for (i = 0; i < 4;i++)
	{
		if ((*qkop)->controle[i] == 2)
		{
			printf("x");
		}
		if ((*qkop)->controle[i] == 1)
		{
			printf("o");
		}
		if ((*qkop)->controle[i] == 0)
		{
			printf(" ");
		}
	}
	printf("*\n");
}

