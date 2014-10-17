#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct  
{
	char DataProtoType[150];
	char Data[150];
	
}FileData ;


int mapNum = 0;
int modeNum = 0;

int program_Secondary_main();
char GameModeDataPrint(FileData GameModes[modeNum]);
char GetGameModeDetails(FileData GameModes[modeNum]);
char GameModeDataScan(FileData GameModes[modeNum]);
char printGameModeStruct(FileData GameModes[modeNum]);
char GameMapDataPrint(FileData GameMaps[mapNum]);
char MainMenu_main(FileData GameModes[modeNum],FileData GameMaps[mapNum]);
char GameMapDataScan(FileData GameMaps[mapNum]);
char GetGameMapDetails(FileData GameMaps[mapNum]);
char PrintMainMenu(FileData GameModes[modeNum],FileData GameMaps[mapNum]);
char InitializeStructsData(FileData GameModes[modeNum],FileData GameMaps[mapNum]);
char ManualGameModesMaps(FileData GameModes[modeNum],FileData GameMaps[mapNum]);
char ReadTempStorage(FileData GameModes[modeNum],FileData GameMaps[mapNum]);
char GameMapUserSelection(FileData GameModes[modeNum],FileData GameMaps[mapNum],int S1);
char RandomGameModesAndMaps(FileData GameModes[mapNum],FileData GameMaps[modeNum]);
int GetRandomNum(int max,int min);
char console(FileData GameModes[modeNum], FileData GameMaps[mapNum]);
char consoleLogo();
char GameModeUserSelection(FileData GameModes[modeNum],FileData GameMaps[mapNum]);
char MakeDSPLFile(FileData GameModes[modeNum],FileData GameMaps[mapNum],char Name[100],int mode,int map);
char TempStorage(int S1,int S2);
char MW3_Logo();

int main()
{
	program_Secondary_main();
	return 0;
}

int program_Secondary_main()
{
	FileData GameMaps[mapNum + 20];
	FileData GameModes[modeNum + 20];

	InitializeStructsData(GameModes,GameMaps);

	GameModeDataScan(GameModes);
	GameMapDataScan(GameMaps);
	getch();

	MainMenu_main(GameModes,GameMaps);

}
char MainMenu_main(FileData GameModes[modeNum],FileData GameMaps[mapNum])
{
	PrintMainMenu(GameModes,GameMaps);
}
char InitializeStructsData(FileData GameModes[modeNum],FileData GameMaps[mapNum])
{
	int y;
	int loopValue;
	
	loopValue = mapNum + 20;
	for(y=0;y<loopValue;y++)
	{
		strcpy(GameMaps[y].Data,"EMPTY");
	}
	loopValue = modeNum + 20;
	for(y=0;y<loopValue;y++)
	{
		strcpy(GameModes[y].Data,"EMPTY");
	}
}
char PrintMainMenu(FileData GameModes[modeNum],FileData GameMaps[mapNum])
{
	char Options[2] = {'T','F'};
	int UserIn;

	do{
		system("cls");
		MW3_Logo();
		printf("\n\n\n\t\tWELCOME TO MW3 GAME MODE & MAP SELECTOR V2.0\n\n\t\t\t\tBy: Eshan Shafeeq\n\n\n");
		printf("\t\tSelect an Option\n");
		printf("\t\t================\n\n\n");

		if(Options[0] == 'T')
		{
			printf("\t\t%c Manually Select The Maps and Game Modes %c\n\n",16,17);
			printf("\t\t  Generate Random Game Modes & Maps\n\n\n");
		}
		else if(Options[1] == 'T')
		{
			printf("\t\t  Manually Select The Maps and Game Modes \n\n");
			printf("\t\t%c Generate Random Game Modes & Maps       %c\n\n\n",16,17);
		}
		UserIn = getch();
		
		if(UserIn == 224)
		{
			UserIn = getch();
			if(UserIn == 72)
			{
				Options[0] = 'T';
				Options[1] = 'F';
			}
			else if(UserIn == 80)
			{
				Options[1] = 'T';
				Options[0] = 'F';
			}
		}
		else if(UserIn == 13)
		{
			if(Options[0] == 'T')
			{
				/*Manual Game Modes and Maps Selection*/
				ManualGameModesMaps(GameModes,GameMaps);
			}
			else if(Options[1] == 'T')
			{
				/*Random Game Modes and maps*/

			}
		}
		else if(UserIn == 96)
		{
			console(GameModes,GameMaps);
		}
		else if(UserIn == 27)
		{
			break;
		}

	}while(UserIn != 27);
}
char RandomGameModesAndMaps(FileData GameModes[mapNum],FileData GameMaps[modeNum])
{
	return ' ';
}
int GetRandomNum(int max,int min)
{
	static int initial = 0;
	int Number;
	if(initial == 0)
	{
		initial = 1;
		srand(time(NULL));
	}
		Number = (rand() % (max - min + 1) + min );
		return Number;
}
char ManualGameModesMaps(FileData GameModes[modeNum],FileData GameMaps[mapNum])
{
	char UserDecission = 'T';
	while(UserDecission != 'F')
	{
		UserDecission = GameModeUserSelection(GameModes,GameMaps);
	}
}
char GameModeUserSelection(FileData GameModes[modeNum],FileData GameMaps[mapNum])
{
	int Sel = 0;
	int y;
	int UserIn;
	char UserDecission = 'T';
	do
	{
		system("cls");
		printf("\n\n\n");
		printf("Please Select A Game Mode\n");
		printf("=========================\n\n");
		for(y=0;y<modeNum;y++)
		{
			if(y == Sel)
			{
				printf("\t%c %s \n",16,GameModes[y].DataProtoType);
			}
			else
			{
				printf("\t %s\n",GameModes[y].DataProtoType);
			}
		}
		printf("\t\t\t\t\tonce your done press ctrl + s\n\n\n\n");
		UserIn = getch();
		if(UserIn == 224)
		{

			UserIn = getch();
			if(UserIn == 72)
			{
				if(Sel != 0)
				{
					Sel--;
				}
			}
			else if(UserIn == 80)
			{
				if(Sel != modeNum -1)
				{
					Sel++;
				}
			}
		}
		else if(UserIn == 13)
		{
			UserDecission = GameMapUserSelection(GameModes,GameMaps,Sel);
			if(UserDecission == 'F')
			{
				return 'F';
			}
		}
		else if(UserIn == 19)
		{
			/*Confirm The Recorded Maps*/
			ReadTempStorage(GameModes,GameMaps);
		}
		else if(UserIn == 27)
		{
			return 'F';
		}
	}while(UserIn != 27 || UserIn != 13);
}
char GameMapUserSelection(FileData GameModes[modeNum],FileData GameMaps[mapNum],int S1)
{
	int Sel = 0;
	int y;
	int UserIn;
	do
	{
		system ("cls");
		printf("\n\n\n");
		printf("Please Select A Game Map\n");
		printf("========================\n\n");
		for(y=0;y<mapNum;y++)
		{
			if(y == Sel)
			{
				printf("\t%c %s %c\n",16,GameMaps[y].DataProtoType);
			}
			else
			{
				printf("\t %s\n",GameMaps[y].DataProtoType);
			}
		}
		UserIn = getch();
		if(UserIn == 224)
		{

			UserIn = getch();
			if(UserIn == 72)
			{
				if(Sel != 0)
				{
					Sel--;
				}
			}
			else if(UserIn == 80)
			{
				if(Sel != mapNum -1)
				{
					Sel++;
				}
			}
		}
		else if(UserIn == 13)
		{
			TempStorage(S1,Sel);
			return 'T';
		}
		else if(UserIn == 27)
		{
			return 'F';
		}
	}while(UserIn != 27 || UserIn != 13);
}
char TempStorage(int S1,int S2)
{
	FILE *TPS;
	char fileName[] = "codMapSelector.poopfile";

	TPS = fopen(fileName,"a+");
	if(TPS == 0)
	{
		printf("\n\n\n\t\tCannot Write data to the .poopfile\n\n");
	}
	else
	{
		fprintf(TPS,"%i %i\n",S1,S2);
		
	}
	fclose(TPS);

}
char ReadTempStorage(FileData GameModes[modeNum],FileData GameMaps[mapNum])
{
	FILE *TPS;
	char fileName[] = "codMapSelector.poopfile";
	int S1,S2,count = 0;
	int UserIn;
	char Name[100];

	system("cls");
	TPS = fopen(fileName,"r");
	if(TPS == 0)
	{
		printf("\n\n\n\t\tError Reading data from .poopfile\n\n");
	}
	else
	{
		
		while(fscanf(TPS,"%i\t%i\n",&S1,&S2) == 2)
		{
			printf("Game # %i %s\t%s\n",count,GameModes[S1].DataProtoType,GameMaps[S2].DataProtoType);
			count++;
		}
		
		
		system("pause");
	}
	fclose(TPS);
	printf("\n\n\tConfirm this is the games you want?\n\tpress y to confirm and exit,\n\tpress n to go back and do it again.");
	UserIn = getch();
	if(UserIn == 89 || UserIn == 121)
	{
		/* Yes*/
		system("cls");
		printf("\tPlease Enter a Name for your file\n\tFile Name: ");
		fflush(stdin);
		scanf("%[^\n]",Name);
		TPS = fopen(fileName,"r");
		if(TPS == 0)
		{
			printf("\n\n\n\t\tError Reading data from .poopfile\n\n");
		}
		else
		{
			
			while(fscanf(TPS,"%i\t%i\n",&S1,&S2) == 2)
			{
				 MakeDSPLFile(GameModes,GameMaps,Name,S1,S2);
			}
			
		}
		fclose(TPS);
		remove("codMapSelector.poopfile");
		system("cls");
		printf("\n\n\n\t\tEnjoy The Game %c\n\n\n\n\n\n\n\n",2);
		system("pause");
		exit(0);
		

	}
	else if(UserIn == 110 || UserIn == 78)
	{
		/* No */
		remove("codMapSelector.poopfile");
	} 
}
char MakeDSPLFile(FileData GameModes[modeNum],FileData GameMaps[mapNum],char Name[100],int mode,int map)
{
	FILE *MKD;
	char DsplFileName[150];

	sprintf(DsplFileName,"%s.dspl",Name);
	MKD = fopen(DsplFileName,"a+");
	if(MKD == 0)
	{

	}
	else
	{
		fprintf(MKD,"%s%s\n",GameMaps[map].Data,GameModes[mode].Data);
	}
}
char GameModeDataPrint(FileData GameModes[modeNum])
{
	FILE *MODE_FILE;
	char modeFile[] = "programGameModes.codMapSelector";

	MODE_FILE = fopen(modeFile,"a+");
	if(MODE_FILE == 0)
	{
		system("cls");
		printf("\n\n\n\t\t\tError #0001\n\t\t\tCannot Open File (Write) \n\t\t\tprogramGameModes.codMapSelector\n\n\n");
	}
	else
	{
		
		fprintf(MODE_FILE,"MODE\t%s\tPROTOTYPE\t%s\n",GameModes[modeNum].DataProtoType,GameModes[modeNum].Data);
		modeNum++;
	}
	fclose(MODE_FILE);
}
char GameModeDataScan(FileData GameModes[modeNum])
{
	FILE *MODE_FILE;
	char modeFile[] = "programGameModes.codMapSelector";
	char data[100],temp_data[100],temp_data1[100];

	MODE_FILE = fopen(modeFile,"r");
	if(MODE_FILE == 0)
	{
		system("cls");
		printf("\n\n\n\tError #0001\n\t\t\tCannot Open File (Read)\n\t\t\tprogramGameModes.codMapSelector\n\n\n");
	}
	else
	{
		printf("\n\tprogramGameModes.codModesSelector File Sucessfully Opened!\n");
		do
		{
			fscanf(MODE_FILE,"%s\t",data);
			if(strcmp(data,"MODE") != 0)
			{
				
				break;
			}
			else
			{

				do
				{
					fscanf(MODE_FILE,"%s\t",data);
					if(strcmp(data,"PROTOTYPE")!=0)
					{
						sprintf(temp_data1," %s",data);
						strcat(temp_data,temp_data1);
					}
					else
					{
						break;
					}
				}while(strcmp(data," PROTOTYPE")!= 0);
				strcpy(GameModes[modeNum].DataProtoType,temp_data);
				strcpy(temp_data,"");
				fscanf(MODE_FILE,"%s\n",data);
				strcpy(GameModes[modeNum].Data,data);
				modeNum++;
			}

		}while(data != NULL);
		printf("\n\tGame Modes Sucessfully Loaded!\n");
		
	}
	fclose(MODE_FILE);
}

char GetGameModeDetails(FileData GameModes[modeNum])
{
	char data[150];
	do
	{
		system("cls");
		printf("\n\n\n");
		printf("\tPlease Enter the Name of the New Game Mode\n\tIf Your Done with Entering New Game Modes Enter \"$\"\n\tNew Game Mode: ");
		fflush(stdin);
		scanf("%[^\n]",data);
		if(strcmp(data,"$")!= 0)
		{
			strcpy(GameModes[modeNum].DataProtoType,data);
		}
		else
		{
			break;
		}
		printf("\tPlease Enter the dsr file Name of the New Game Mode\n\tDSR File Name: ");
		fflush(stdin);
		scanf("%[^\n]",GameModes[modeNum].Data);
		sprintf(GameModes[modeNum].Data,"%s,1",GameModes[modeNum].Data);
		GameModeDataPrint(GameModes);
		printf("\n\n\tGame Mode Added!\n\n");
	}while(strcmp(data,"$")!= 0);

	
}
char GetGameMapDetails(FileData GameMaps[mapNum])
{
	char data[150];
	do
	{
		system("cls");
		printf("\n\n\n");
		printf("\tPlease Enter the Name of the New Game Map\n\tIf Your Done with Entering New Game Map Enter \"$\"\n\tNew Game Map: ");
		fflush(stdin);
		scanf("%[^\n]",data);
		if(strcmp(data,"$")!= 0)
		{
			strcpy(GameMaps[mapNum].DataProtoType,data);
		}
		else
		{
			break;
		}
		printf("\tPlease Enter the map file Name of the New Game Map\n\tMap File Name: ");
		fflush(stdin);
		scanf("%[^\n]",GameMaps[mapNum].Data);
		GameMapDataPrint(GameMaps);
		printf("\n\n\tGame Map Added!\n\n");
	}while(strcmp(data,"$")!= 0);

	
}
char printGameModeStruct(FileData GameModes[modeNum])
{
	int y;
	printf("\n\n");
	for(y=0;y<modeNum;y++)
	{
		printf("%s\t%s\n",GameModes[y].DataProtoType,GameModes[y].Data);
	}
}
char printGameMapStruct(FileData GameMaps[mapNum])
{
	int y;
	printf("\n\n");
	for(y=0;y<mapNum;y++)
	{
		printf("%s\t%s\n",GameMaps[y].DataProtoType,GameMaps[y].Data);
	}
}
char GameMapDataScan(FileData GameMaps[mapNum])
{
	FILE *MAPS_FILE;
	char mapFile[] = "programGameMaps.codMapSelector";
	char data[100],temp_data[100],temp_data1[100];

	MAPS_FILE = fopen(mapFile,"r");
	if(MAPS_FILE == 0)
	{
		system("cls");
		printf("\n\n\n\tError #0001\n\t\t\tCannot Open File (Read)\n\t\t\tprogramGameMaps.codMapSelector\n\n\n");
	}
	else
	{
		printf("\n\n\n\tprogramGameMaps.codMapSelector File Sucessfully Opened!\n");
		do
		{
			strcpy(temp_data,"");
			fscanf(MAPS_FILE,"%s\t",data);
			if(strcmp(data,"MAPS") != 0)
			{
				
				break;
			}
			else
			{

				do
				{
					fscanf(MAPS_FILE,"%s\t",data);
					if(strcmp(data,"PROTOTYPE")!=0)
					{
						sprintf(temp_data1," %s",data);
						strcat(temp_data,temp_data1);
					}
					else
					{
						break;
					}
				}while(strcmp(data," PROTOTYPE")!= 0);
				strcpy(GameMaps[mapNum].DataProtoType,temp_data);
				strcpy(temp_data,"");
				fscanf(MAPS_FILE,"%s\n",data);
				strcpy(GameMaps[mapNum].Data,data);
				mapNum++;
			}

		}while(data != NULL);
		printf("\n\tMaps Sucessfully Loaded!\n");
		fclose(MAPS_FILE);
	}
}
char GameMapDataPrint(FileData GameMaps[mapNum])
{
	FILE *MAPS_FILE;
	char mapFile[] = "programGameMaps.codMapSelector";

	MAPS_FILE = fopen(mapFile,"a+");
	if(MAPS_FILE == 0)
	{
		system("cls");
		printf("\n\n\n\t\t\tError #0001\n\t\t\tCannot Open File (Write) \n\t\t\tprogramGameMaps.codMapSelector\n\n\n");
	}
	else
	{
		
		fprintf(MAPS_FILE,"MAPS\t%s\tPROTOTYPE\t%s\n",GameMaps[mapNum].DataProtoType,GameMaps[mapNum].Data);
		mapNum++;
		fclose(MAPS_FILE);
	}

}

char MW3_Logo()
{
	printf("\n");
	printf("	\t  .::       .::.::        .::         \n");
	printf("	\t  .: .::   .:::.::        .:: ..:::::  \n" );
	printf("	\t  .:: .:: . .::.::   .:   .::     .::  \n" );
	printf("	\t  .::  .::  .::.::  .::   .::  .::     \n" );
	printf("	\t  .::   .:  .::.:: .: .:: .::     ::.  \n" );
	printf("	\t  .::       .::.: .:    .::::      :::.\n" );
	printf("	\t  .::       .::.::        .:: .::::::  \n");
	
}
char console(FileData GameModes[modeNum], FileData GameMaps[mapNum])
{
	char cmd[100];
	system("cls");
	consoleLogo();
	printf("\tWELCOME TO THE GAME MODES AND MAPS SELECTOR CONSOLE\n\n");
	printf("\tPlease Enter Command : ");
	fflush(stdin);
	scanf("%[^\n]",cmd);
	if(strcmp(cmd,"New GameMode") == 0)
	{
		GetGameModeDetails(GameModes);
	}
	else if(strcmp(cmd,"New GameMap") == 0)
	{
		GetGameMapDetails(GameMaps);
	}
	system("pause");

}
char consoleLogo()
{
	printf("\t\t\t+------------------+\n");
	printf("\t\t\t|       ___        |\n");
	printf("\t\t\t|   _  (,~ |   _   |\n");
	printf("\t\t\t|  (____/  |____)  |\n");
	printf("\t\t\t|  |||||    |||||  |\n");
	printf("\t\t\t|  |||||    |||||  |\n");
	printf("\t\t\t|  |||||\\  /|||||  |\n");
	printf("\t\t\t|  |||'//\\/\\`|||  |\n");
	printf("\t\t\t|  |' m' /\\ `m `|  |\n");
	printf("\t\t\t|       /||\\       |\n");
	printf("\t\t\t \\_              _/ \n");
	printf("\t\t\t   `-----92-KSR-'   \n");
}













