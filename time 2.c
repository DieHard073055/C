#include<time.h>
#include<stdio.h>

main(){
	time_t recTime;
	recTime = time(NULL);
	printf(ctime(&recTime));

}

