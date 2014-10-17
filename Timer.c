
	#include <stdio.h>
	#include <time.h>

	int main(void)
	{
		time_t start,end;
		volatile long unsigned counter;
		int h = 0;
		double score;

		start = time(NULL);

		for(counter = 0; counter < 500000000; counter++)
		{
			h = (30 - 40 + 27 * 96)/(30 - 40 + 27 * 96);
			if (counter % 2 == 1) 
			{
				printf("true\n");
			}
		}
			; /* Do nothing, just loop */

		end = time(NULL);
		score =  difftime(end, start);
		printf("The loop used %f seconds.\n",score);
		return 0;
	}

