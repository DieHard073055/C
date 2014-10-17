#include<stdio.h>
#include<stdlib.h>
main(){

	char Rich[] = "Richard.txt";
	FILE *WriteRich;
	int i,k;
	
	WriteRich = fopen(Rich,"w");
	if(WriteRich == 0)
	{
		printf("File open Failed");
		exit(-1);
	}
	else
	{
		printf("File open Successful");
		for(i=0;i<20000;i++){
			fprintf(WriteRich,"I love you sears %i\n",i +1);
		}
		fprintf(WriteRich,"$");
		fclose(WriteRich);
	}
}
	
	
	
	
	

