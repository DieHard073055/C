#include <stdio.h>

typedef struct  
{
	char DataProtoType[150];
	char Data[150];
	
}FileData ;

int GetNum_Modes(FileData GameModes);

main()
{
	int count;
	FileData GameModes;
	count = GetNum_Modes(GameModes);
	printf("No of Games Modes = %i",count);
}
int GetNum_Modes(FileData GameModes)
{
	FILE *MODE_FILE;
	char modeFile[] = "programGameModes.codMapSelector";
	int count = 0;
	char lineReader[300];

	MODE_FILE = fopen(modeFile,"r");

	if(MODE_FILE == 0)
	{
		system("cls");
		printf("\n\n\n\tError #0001\n\t\t\tCannot Open File (Read)\n\t\t\tprogramGameModes.codMapSelector\n\n\n");
	}
	else
	{
		while(fscanf(MODE_FILE,"%[^\n]",lineReader)== 1)
		{
			count++;
		}
	}
	fclose(MODE_FILE);
	return count;
}
