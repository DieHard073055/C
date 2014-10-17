#include<windows.h>
#include<stdio.h>

main(){
	SYSTEMTIME t_y;
	GetSystemTime(&t_y);
	
	printf("This is the year %d\n",t_y.wYear);
	printf("And it's the %d st/nd/th Month\n",t_y.wMonth);
	printf("Which is the %d st/nd/th Day\n",t_y.wDay);
	printf("and also the %d st/nd/th hour\n",t_y.wHour);
	printf("%d min\n",t_y.wMinute);
	printf("%d sec\n",t_y.wSecond);
	
}


