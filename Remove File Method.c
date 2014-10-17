/*0198292233000
0198292233000*/
#include <stdio.h>
char MakeFile();
main()
{
	MakeFile();
	system("pause");
	printf("Delete File");
	remove("MyCoolFile");
}
char MakeFile()
{
	FILE *MF;
	char fileName[] = "MyCoolFile";

	MF = fopen(fileName,"a+");
	if(MF == 0)
	{

	}
	else
	{
		fprintf(MF,"So Cool THis file is gonna be deleted Big time!!!");

		fclose(MF);
	}
}
