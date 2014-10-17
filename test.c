#include<stdio.h>
typedef struct
{
	int g;
	int h;
}gizmo;
void fun1(gizmo);
void fun1(gizmo n)
{
	n[0].g = 42;
}
main()
{

	gizmo f[6];
	fun1(f);
	printf("%i",f[0].g);
}

