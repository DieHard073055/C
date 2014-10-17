#include <stdlib.h>	// for itoa() call
#include <stdio.h>	// for printf() call
#include <time.h>

int main() {
	int num = 123;
	char buf[5];
	
	int i;
	int min = 1, max = 67;
	static int init = 0;
	char score[5];
	if (init == 0)
	{
		srand((unsigned)time(NULL));
		init = 1;
	}
	i = ( rand() % (max - min + 1) + min );

	// convert 123 to string [buf]
	itoa(i, buf, 10);

	// print our string
	printf("%s\n", buf);

	return 0;
}

