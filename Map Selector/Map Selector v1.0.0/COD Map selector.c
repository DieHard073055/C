/*
Maps

	mp_plaza2,
	mp_mogadishu,
	mp_bootleg,
	mp_carbon,
	mp_dome,
	mp_exchange,
	mp_lambeth,
	mp_hardhat,
	mp_interchange,
	mp_alpha,
	mp_bravo,
	mp_radar,
	mp_paris,
	mp_seatown,
	mp_underground,
	mp_village,
	
Game Modes	  

	TDM_default,1
 	DOM_default,1
 	CTF_default,1
 	DZ_default,1
 	FFA_default,1
 	GG_default,1
 	HQ_default,1
 	INF_default,1
 	JUG_default,1
 	KC_default,1
 	OIC_default,1
 	SAB_default,1
 	SD_default,1
	DEF_default,1
 	TJ_default,1

*/
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>


int GetRandomNum(int max, int min);
char MenuPrint();
int DetailAnalyser(int map, int mode,char Name[100]);
int  GetDetails();
char printMap(char mapName[40],char gameMode[40],char Name[100]);
char RandomGameModeGen(char Name[100]);

int main()
{
	
	  GetDetails();


	return 0;

}
int GetRandomNum(int max, int min)
{
	static int initial = 0;
	int randNum;
	
	if (initial == 0)
	{
		srand(time(NULL));
		initial = 1;
	
	}
	
	randNum = rand() % (max - min + 1) + min;
	return randNum;

}
char MenuPrint()
{
	
	printf("\n\n\tctrl + f to generate Random maps\n\n");
	printf("\t\tSelect A Map and A Game Mode");
	
	printf("\n\n\n\ta) Arkaden\ta)Team Death Match");
	printf("\n\tb) Bakaraa\tb)Domination");
	printf("\n\tc) Bootleg\tc)Capture The Flag");
	printf("\n\td) Carbon\td)Drop Zone");
	printf("\n\te) Dome\t\te)Free For All");
	printf("\n\tf) DownTown\tf)Gun Game");
	printf("\n\tg) Fallen\tg)Headquaters");
	printf("\n\th) Hardhat\th)Infected");
	printf("\n\ti) Interchange\ti)Juggernaut");
	printf("\n\tj) Lockdown\tj)Kill Confirmed");
	printf("\n\tk) Mission\tk)One in The Chamber");
	printf("\n\tl) Outpost\tl)Sabotage");
	printf("\n\tm) Resistance\tm)Search and Destroy");
	printf("\n\tn) Seatown\tn)Team Defender");
	printf("\n\to) Underground\to)Team Juggernaut");
	printf("\n\tp) Village\n\n\n\n");


}

int DetailAnalyser(int map, int mode,char Name[100])
{
/*
Maps

	mp_plaza2,
	mp_mogadishu,
	mp_bootleg,
	mp_carbon,
	mp_dome,
	mp_exchange,
	mp_lambeth,
	mp_hardhat,
	mp_interchange,
	mp_alpha,
	mp_bravo,
	mp_radar,
	mp_paris,
	mp_seatown,
	mp_underground,
	mp_village,

*/
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
	printMap(mapName,gameMode,Name);
}
char printMap(char mapName[40],char gameMode[40],char Name[100])
{
	FILE *WTM;	  
	char mapFile[105];
	sprintf(mapFile,"%s.dspl",Name);
	
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
int GetDetails()
{
	int mapCounter =0,map,mode;
	char Name[100];
	printf("Eshan's MW3 Map Selector v.1.0.0 alpha");
	printf("\n\n\n\n\tPlease Enter a Name for The File\n\tFile Name: ");
	scanf("%[^\n]",Name);
	system("cls");
	MenuPrint();
	do
	{
		
		map = getch();
		if(map == 13)
		{
			break;
		}
		else if(map == 6)
		{
			RandomGameModeGen(Name);
			printf("\n\nFILES SUCCESSFULLY WRITTEN!");
			break;	  
		}
		mode = getch();
		++mapCounter;
		printf("\nGame# %i\t",mapCounter);
		DetailAnalyser(map,mode,Name);
	}while(map!=13);
}
char RandomGameModeGen(char Name[100])
{
	
	int NoGames,UserSelection,x,map,mode;

	system("cls");

	printf("\n\n\n\n\tPlease Select one of the Random Map Generators\n\n");
	printf("\tctrl + F\tRandom Free For All\n");
	printf("\tctrl + T\tRandom Team Death Match\n");
	printf("\tctrl + A\tRandom All Team Games\n");
	printf("\tctrl + D\tRandom Maps + Random Game Modes\n");


	UserSelection = getch();
	printf("\n\nPlease Enter the number of Games you want\n\t");
	scanf("%i",&NoGames);
	/*/6,20,1,4*/
	switch(UserSelection)
	{
		case(6):/*FreeForAll*/
			for(x=0;x<NoGames;x++)
			{
				map =	GetRandomNum(112,97);
				printf("Game# %i\t",x+1);
				DetailAnalyser(map,101,Name);
				printf("\n");
			}
		break;
		case(20):/*TeamDeathMatch*/
			for(x=0;x<NoGames;x++)
			{
				map =	GetRandomNum(112,97);
				printf("Game# %i\t",x+1);
				DetailAnalyser(map,97,Name);
				printf("\n");
			}
		break;
		case(1):/*AllTeamGames*/
			for(x=0;x<NoGames;x++)
			{
				mode =	 GetRandomNum(112,97);
				map =	GetRandomNum(112,97);
				/*101,102,104,105,107*/
				if(mode == 101||mode == 102||mode == 104||mode == 105||mode == 107)
				{
					--x;
				}
				else
				{
					printf("Game# %i\t",x+1);
					DetailAnalyser(map,mode,Name);
					printf("\n");
				}
			}
		break;
		case(4):/*AllRandom*/
			for(x=0;x<NoGames;x++)
			{
				map =	GetRandomNum(112,97);
				mode = GetRandomNum(111,97),
				printf("Game# %i\t",x+1);
				DetailAnalyser(map,mode,Name);
				printf("\n");
			}
		break;
	}

}

