#include<stdio.h>
#include<stdlib.h>
main(){

	char Rich[] = "Richard.txt";
	FILE *WriteRich;
	int i,k;
	
	WriteRich = fopen(Rich,"w");
	if(WriteRich == 0)
	{
		exit(-1);
	}
	else
	{
		for(i=0;i<20;i++){
			fprintf(WriteRich,"I love you sears %i\n",i);
		}
		fclose(WriteRich);
	}
}
	
	
	
	
	

