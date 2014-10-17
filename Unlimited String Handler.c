#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

void write(int input,FILE * SF);
void read();


int main()
{
	int input;
	FILE * SF;
	char fname[] = "storage.fmg";

	SF = fopen(fname,"w");
	if(SF == 0)
	{

	}
	else
	{
		
		write(input,SF);
		read();

		
	}
	
	return 0;
}
void write(int input,FILE * SF)
{
	printf("Please Enter Your message!\n");

		while((input=getch())!=27)
		{
			if(input == 13)
			{
				printf("\n");
			}
			else
			printf("%c",input );
			fprintf(SF, "%c", input);
		}
		fclose(SF);
}
void read()
{
	FILE * SF;
	char fname[] = "storage.fmg";
	char slot[200];
	char  str[200];
	int istr;


	SF = fopen(fname,"r");
	if (SF==0)
	{
				
	}
	else	
	{
		while(fscanf(SF,"%s",slot)==1)
		{
			strcat(str,slot);
		}
		printf("\n\n%s\n", str);
		system ("pause");
		free(slot);
		free(str);

	}
	fclose(SF);
}
