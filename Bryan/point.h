#ifndef POINT_H
#define POINT_H

#include <stdio.h>
#include <stdlib.h>

typedef struct points{
	int y;
	int x;
}points;

void setBoth(struct points * p, int y, int x){
	p->x = x;
	p->y = y;
}
void printBoth(struct points * p){
	printf("%i %i\n", p->x, p->y);
}
#endif
