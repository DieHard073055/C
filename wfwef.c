/* simple.c
example 1.0
*/
#include<graphics.h>
#include<conio.h>
void main()
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "c:\\turboc3\\bgi " );
	circle(200, 100, 150);
	getch();
	closegraph();
}

