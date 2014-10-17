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

int program_Secondary_main(int mapSize,int modeSize);
char GameModeDataPrint(FileData GameModes[modeNum]);
int GetNum_Modes();
int GetNum_Maps();
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
char RandomGameModesAndMaps();
char RandomGameModesAndMapsGenerator();
int DetailAnalyser(int map, int mode);
char printRandomMap(char mapName[40],char gameMode[40]);
char ScanRandomMap();
char StringChopper(char data[50]);
int DetailScanningAnalyser(char mapName[100], char gameMode[100]);
int GetRandomNum(int max,int min);
char console(FileData GameModes[modeNum], FileData GameMaps[mapNum]);
char consoleLogo();
char GameModeUserSelection(FileData GameModes[modeNum],FileData GameMaps[mapNum]);
char MakeDSPLFile(FileData GameModes[modeNum],FileData GameMaps[mapNum],char Name[100],int mode,int map);
char TempStorage(int S1,int S2);
char MW3_Logo();

int main()
{
	int modeSize;
	int mapSize;
	
	modeSize = GetNum_Modes();
	mapSize = 120;
	program_Secondary_main(mapSize,modeSize);
	return 0;
}

int program_Secondary_main(int mapSize,int modeSize)
{
	FileData GameMaps[mapSize];
	FileData GameModes[modeSize];

	InitializeStructsData(GameModes,GameMaps);

	GameModeDataScan(GameModes);
	GameMapDataScan(GameMaps);
	getch();

	MainMenu_main(GameModes,GameMaps);

}
int GetNum_Modes()
{
	FILE *MODE_FILE;
	char modeFile[] = "programGameModes.codMapSelector";
	int count = 0;
	char lineReader[200];

	MODE_FILE = fopen(modeFile,"r");

	if(MODE_FILE == 0)
	{
		system("cls");
		printf("\n\n\n\tError #0001\n\t\t\tCannot Open File (Read)\n\t\t\tprogramGameModes.codMapSelector\n\n\n");
		system("pause");
	}
	else
	{
		while(fscanf(MODE_FILE,"%[^\n]\n",lineReader)== 1)
		{
			count++;
		}
	}
	fclose(MODE_FILE);
	return count;
}
int GetNum_Maps()
{
	FILE *MAP_FILE;
	char mapFile[] = "programGameMaps.codMapSelector";
	int count = 0;
	char lineReader[200];

	MAP_FILE = fopen(mapFile,"r");

	if(MAP_FILE == 0)
	{
		system("cls");
		printf("\n\n\n\tError #0001\n\t\t\tCannot Open File (Read)\n\t\t\tprogramGameMaps.codMapSelector\n\n\n");
		system("pause");
	}
	else
	{
		while(fscanf(MAP_FILE,"%[^\n]\n",lineReader)== 1)
		{
			count++;
		}
	}
	fclose(MAP_FILE);
	return count;
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
				RandomGameModesAndMaps();
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
char RandomGameModesAndMaps()
{
	char UserIn,Name[50],FileName[100];
	do
	{
		system("cls");

		printf("\n\n\n\n\tPlease Select one of the Random Map Generators\n\n");
		printf("\tctrl + F\tRandom Free For All\n");
		printf("\tctrl + T\tRandom Team Death Match\n");
		printf("\tctrl + A\tRandom All Team Games\n");
		printf("\tctrl + D\tRandom Maps + Random Game Modes\n");

	
		RandomGameModesAndMapsGenerator();
		ScanRandomMap();
		printf("\n\tConfirm These are the maps You want?\n\tEnter y to save and quit, Enter N to generate another one\n\n");
		UserIn = getch();
		if(UserIn == 89|| UserIn == 121)
		{
			system("cls");
			printf("\n\n\n\tPlease Enter a Name for your File\n\tFile Name: ");
			fflush(stdin);
			scanf("%[^\n]",Name);
			sprintf(FileName,"%s.dspl",Name);
			rename("codMapSelectorRandom.poopfile",FileName);
			system("cls");
			printf("\n\n\n\t\tEnjoy The Game %c\n\n\n\n\n\n\n\n",2);
			system("pause");
			exit(0);
		}
		else if(UserIn == 110|| UserIn == 78)
		{
			remove("codMapSelectorRandom.poopfile");
			continue;
		}
	}while(UserIn != 110 || UserIn != 78);

	return ' ';
}

char RandomGameModesAndMapsGenerator()
{
	
	int NoGames,UserSelection,x,map,mode;

	


	UserSelection = getch();
	printf("\n\nPlease Enter the number of Games you want\n\t");
	scanf("%i",&NoGames);
	switch(UserSelection)
	{
		case(6):
			for(x=0;x<NoGames;x++)
			{
				map =	GetRandomNum(112,97);
				printf("Game# %i\t",x+1);
				DetailAnalyser(map,101);
				printf("\n");
			}
		break;
		case(20):
			for(x=0;x<NoGames;x++)
			{
				map =	GetRandomNum(112,97);
				printf("Game# %i\t",x+1);
				DetailAnalyser(map,97);
				printf("\n");
			}
		break;
		case(1):
			for(x=0;x<NoGames;x++)
			{
				mode =	 GetRandomNum(112,97);
				map =	GetRandomNum(112,97);

				if(mode == 101||mode == 102||mode == 104||mode == 105||mode == 107)
				{
					--x;
				}
				else
				{
					printf("Game# %i\t",x+1);
					DetailAnalyser(map,mode);
					printf("\n");
				}
			}
		break;
		case(4):
			for(x=0;x<NoGames;x++)
			{
				map =	GetRandomNum(112,97);
				mode = GetRandomNum(111,97),
				printf("Game# %i\t",x+1);
				DetailAnalyser(map,mode);
				printf("\n");
			}
		break;
	}

}

int DetailAnalyser(int map, int mode)
{
	char mapName[40],gameMode[40];
	switch(map)
	{
		case 97:printf("Map Arkaden");
		strcpy(mapName,"mp_plaza2");
		break;
		case 98:printf("Map Bakaraa");
		strcpy(mapName,"mp_mogadishu,");
		break;
		case 99:printf("Map Bootleg");
		strcpy(mapName,"mp_bootleg,");
		break;
		case 100:printf("Map Carbon");
		strcpy(mapName,"mp_carbon,");
		break;
		case 101:printf("Map Dome");
		strcpy(mapName,"mp_dome,");
		break;
		case 102:printf("Map DownTown");
		strcpy(mapName,"mp_exchange,");
		break;
		case 103:printf("Map Fallen");
		strcpy(mapName,"mp_lambeth,");
		break;
		case 104:printf("Map Hardhat");
		strcpy(mapName,"mp_hardhat,");
		break;
		case 105:printf("Map Interchange");
		strcpy(mapName,"mp_interchange,");
		break;
		case 106:printf("Map Lockdown");
		strcpy(mapName,"mp_alpha,");
		break;
		case 107:printf("Map Mission");
		strcpy(mapName,"mp_bravo,");
		break;
		case 108:printf("Map Outpost");
		strcpy(mapName,"mp_radar,");
		break;
		case 109:printf("Map Ressistance");
		strcpy(mapName,"mp_paris,");
		break;
		case 110:printf("Map Seatown");
		strcpy(mapName,"mp_seatown,");
		break;
		case 111:printf("Map Underground");
		strcpy(mapName,"mp_underground,");
		break;
		case 112:printf("Map Village");
		strcpy(mapName,"mp_village,");
		break;
		default:printf("Map Dome");
		strcpy(mapName,"mp_dome,");
		break;
		
	}
	switch(mode)
	{
		case 97:printf("\tMode Team Death Match");
		strcpy(gameMode,"TDM_default,1");
		break;
		case 98:printf("\tMode Domination");
		strcpy(gameMode,"DOM_default,1");
		break;
		case 99:printf("\tMode Capture The Flag");
		strcpy(gameMode,"CTF_default,1");
		break;
		case 100:printf("\tMode Drop Zone");
		strcpy(gameMode,"DZ_default,1");
		break;
		case 101:printf("\tMode Free For All");
		strcpy(gameMode,"FFA_default,1");
		break;
		case 102:printf("\tMode GunGame");
		strcpy(gameMode,"GG_default,1");
		break;
		case 103:printf("\tMode Headquaters");
		strcpy(gameMode,"HQ_default,1");
		break;
		case 104:printf("\tMode Infected");
		strcpy(gameMode,"INF_default,1");
		break;
		case 105:printf("\tMode Juggernaut");
		strcpy(gameMode,"JUG_default,1");
		break;
		case 106:printf("\tMode Kill Confirmed");
		strcpy(gameMode,"KC_default,1");
		break;
		case 107:printf("\tMode One in The Chamber");
		strcpy(gameMode,"OIC_default,1");
		break;
		case 108:printf("\tMode Sabotage");
		strcpy(gameMode,"SAB_default,1");
		break;
		case 109:printf("\tMode Serch and Destroy");
		strcpy(gameMode,"SD_default,1");
		break;
		case 110:printf("\tMode Team Defender");
		strcpy(gameMode,"DEF_default,1");
		break;
		case 111:printf("\tMode Team Juggernaut");
		strcpy(gameMode,"TJ_default,1");
		break;
		default: printf("\tMode Team Death Match");
		strcpy(gameMode,"TDM_default,1");
		break;
	}
	printRandomMap(mapName,gameMode);
}
char printRandomMap(char mapName[40],char gameMode[40])
{
	FILE *WTM;	  
	char mapFile[105]= "codMapSelectorRandom.poopfile";
	
	WTM = fopen(mapFile,"a+");
	if(WTM == 0)
	{
	
	}
	else
	{
		
		fprintf(WTM,"%s%s\n",mapName,gameMode);	 
		
		fclose(WTM);
	}
}
char ScanRandomMap()
{
	FILE *WTM;	  
	char mapFile[105]= "codMapSelectorRandom.poopfile";
	char data[50];
	int y;
	
	WTM = fopen(mapFile,"r");
	if(WTM == 0)
	{
	
	}
	else
	{
		while(fscanf(WTM,"%s\n",data)!= 1)
		{
			StringChopper(data);
		}
		
				 
		
		
	}
	fclose(WTM);
}
char StringChopper(char data[50])
{
	char map[50],mode[50];
	int y = 0,x = 0,j,bufleng;
	bufleng = strlen(data);
	printf("%i\n",bufleng);
	while(y != bufleng)
	{
		if(data[y] == ',')
		{
			x = y + 1;
			for(j=0;j<x;j++)
			{
				map[j] = data[j];
			}
			y=0;
			for(j=x;j<(bufleng+1);j++)
			{
			
				mode[y] = data[j];
				printf("%c",data[j]);
				y++;
				
			}
			printf("\n\n");
			break;
		}
		y++;
	}
	DetailScanningAnalyser(map,mode);
}

int DetailScanningAnalyser(char mapName[100], char gameMode[100])
	{
		if(strcmp(mapName,"mp_plaza2") == 0)
		{
			printf("Map Arkaden");
		}
		else if (strcmp(mapName,"mp_mogadishu,"))
		{
			printf("Map Bakaraa");
		}
		
		else if(strcmp(mapName,"mp_bootleg,") == 0)
		{
			printf("Map Bootleg");
		}
		
		else if(strcmp(mapName,"mp_carbon,") == 0)
		{
			printf("Map Carbon");
		}
		
		else if(strcmp(mapName,"mp_dome,") == 0)
		{
			printf("Map Dome");
		}
		
		else if(strcmp(mapName,"mp_exchange,") == 0)
		{
			printf("Map DownTown");
		}
		
		else if(strcmp(mapName,"mp_lambeth,") == 0)
		{
			printf("Map Fallen");
		}
		
		else if(strcmp(mapName,"mp_hardhat,") == 0)
		{
			printf("Map Hardhat");
		}
		
		else if(strcmp(mapName,"mp_interchange,") == 0)
		{
			printf("Map Interchange");
		}
		
		else if(strcmp(mapName,"mp_alpha,") == 0)
		{
			printf("Map Lockdown");
		}
		
		else if(strcmp(mapName,"mp_bravo,") == 0)
		{
			printf("Map Mission");
		}
		
		else if(strcmp(mapName,"mp_radar,") == 0)
		{
			printf("Map Outpost");
		}
		
		else if(strcmp(mapName,"mp_paris,") == 0)
		{
			printf("Map Ressistance");
		}
		
		else if(strcmp(mapName,"mp_seatown,") == 0)
		{
			printf("Map Seatown");
		}
		
		else if(strcmp(mapName,"mp_underground,") == 0)
		{
			printf("Map Underground");
		}
		
		else if(strcmp(mapName,"mp_village,") == 0)
		{
			printf("Map Village");
		}
		
		else if(strcmp(mapName,"mp_dome,") == 0)
		{
			printf("Map Dome");
		}
		
		
	
		if (strcmp(gameMode,"TDM_default,1") == 0)
		printf("\tMode Team Death Match");
		
		
		else if (strcmp(gameMode,"DOM_default,1") == 0)
		printf("\tMode Domination");
		
		
		else if (strcmp(gameMode,"CTF_default,1") == 0)
		printf("\tMode Capture The Flag");
		
		
		else if (strcmp(gameMode,"DZ_default,1") == 0)
		printf("\tMode Drop Zone");
		
		
		else if (strcmp(gameMode,"FFA_default,1") == 0)
		printf("\tMode Free For All");
		
		
		else if (strcmp(gameMode,"GG_default,1") == 0)
		printf("\tMode GunGame");
		
		
		else if (strcmp(gameMode,"HQ_default,1") == 0)
		printf("\tMode Headquaters");
		
		
		else if (strcmp(gameMode,"INF_default,1") == 0)
		printf("\tMode Infected");
		
		
		else if (strcmp(gameMode,"JUG_default,1") == 0)
		printf("\tMode Juggernaut");
		
		
		else if (strcmp(gameMode,"KC_default,1") == 0)
		printf("\tMode Kill Confirmed");
		
		
		else if (strcmp(gameMode,"OIC_default,1") == 0)
		printf("\tMode One in The Chamber");
		
		
		else if (strcmp(gameMode,"SAB_default,1") == 0)
		printf("\tMode Sabotage");
		
		
		else if (strcmp(gameMode,"SD_default,1") == 0)
		printf("\tMode Serch and Destroy");
		
		
		else if (strcmp(gameMode,"DEF_default,1") == 0)
		printf("\tMode Team Defender");
		
		
		else if (strcmp(gameMode,"TJ_default,1") == 0)
		printf("\tMode Team Juggernaut");
		printf("\n\n");
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
		}
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

	strcpy(temp_data,"");
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














