#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void intro(void);
int choice(char f[600]);
void choice_2(char f[600], int type);
void Decission(char f[600], int type);
void selection (int k, char f[600], int type);
void Get_name(char f[600]);
void mesg(char msg[300]);
void Ok(char msg[300], char f[600]);
void Warning(char msg[300], char f[600]);
void Ok_Cancel (char msg[300], char f[600]);
void A_R_I (char msg[300], char f[600]);
void Function(int k, char f[600]);
void end(char f[600]);
void See_you(void);
void herp(void);
void derp(int i);
char S;
int main()
{
	int type;
	char f[600];
	S = 'F';
	type = choice(f);
	S = 'T';
	choice_2(f, type);
	See_you();
	return 0;
}
void intro(void)
{
	system("color 70");
	printf("Welcome to Eshan Basic v.1.0.0\n");
}
int choice(char f[600])
{
	char ans[10];
	char msg[300];
	intro();
	system("cls");
	Get_name(f);
	system("cls");
	printf("Choose an option\n\n");
	printf("\t%c OK - OK button Message box\n", 26);
	printf("\t%c WAR - Warning Message box\n", 26);
	printf("\t%c OC - OK and Cancel Message box\n", 26);
	printf("\t%c AIR - Abort Retry and Cancel Message box\n\t", 26);
	printf("\nChoice: ");
	fflush(stdin);
	scanf("%s", ans);
	if (strcmp(ans, "q") == 0 || strcmp(ans, "Q") == 0)
	{
		exit(-1);
	}
	mesg(msg);
	if (strcmp(ans, "OK") == 0 || strcmp(ans, "ok") == 0)
	{
		Ok(msg, f);
		return 0;
	}
	else if (strcmp(ans, "War") == 0 || strcmp(ans, "WAR") == 0 || strcmp(ans, "war") == 0)
	{
		Warning(msg, f);
		return 48;
	}
	else if (strcmp(ans, "OC") == 0 || strcmp(ans, "Oc") == 0 || strcmp(ans, "oc") == 0)
	{
		Ok_Cancel(msg, f);
		return 1;
	}
	else if (strcmp(ans, "Air") == 0 || strcmp(ans, "AIR") == 0 || strcmp(ans, "air") == 0)
	{
		A_R_I(msg, f);
		return 2;
	}
}
void choice_2(char f[600], int type)
{
	char ans[10];
	int y = 0;
	do
	{
		printf("\n\nMessage added.");
		printf("\nDo you want to add another message box? (yes/no)\nAns: ");
		fflush(stdin);
		scanf("%s", ans);
		if (strcmp(ans, "NO") == 0 || strcmp(ans, "No") == 0 || strcmp(ans, "no") == 0)
		{
			break;
		}
		else if (strcmp(ans, "YES") == 0 || strcmp(ans, "Yes") == 0 || strcmp(ans, "yes") == 0)
		{
			Decission(f, type);
		}
	}
	while (y = 1);
}
void Get_name(char f[600])
{
	int length;
	system("cls");
	printf("\tWELCOME TO MSGBOX PROGRAM MAKER\n");
	printf("\t===============================\n\n");
	printf("\nGive a name for your program.\nName:\t");
	fflush(stdin);
	scanf("%[^\n]", f);
	strcat(f, ".vbs");
	herp();
}
void mesg(char msg[300])
{
	system("cls");
	printf("\nEnter a message you want to display.\nMsg:\t");
	fflush(stdin);
	scanf("%[^\n]", msg);
}
void Ok(char msg[300], char f[600])
{
	FILE *MyF;
	if (S == 'F')
	{
		MyF = fopen(f, "w");
	}
	else if (S == 'T')
	{
		MyF = fopen(f, "a+");
	}
	if ( MyF == 0)
	{
		printf("\tFailed to open file");
	}
	else
	{
		if (S == 'F')
		{
			fprintf(MyF, "x=msgbox(\" %s \",0,\" Eshan Basic v.1.0.0 \") \n", msg);
			fclose(MyF);
		}
		else if (S == 'T')
		{
			fprintf(MyF, "x=msgbox(\" %s \",0,\" Eshan Basic v.1.0.0 \") \n", msg);
			fclose(MyF);
		}
	}
}
void Warning( char msg[300], char f[600])
{
	FILE *MyF;
	if (S == 'F')
	{
		MyF = fopen(f, "w");
	}
	else if (S == 'T')
	{
		MyF = fopen(f, "a+");
	}
	if ( MyF == 0)
	{
		printf("\tFailed to open file");
	}
	else
	{
		if (S == 'F')
		{
			fprintf(MyF, "x=msgbox(\" %s \",48,\" Eshan Basic v.1.0.0 \") \n", msg);
			fclose(MyF);
		}
		else if (S == 'T')
		{
			fprintf(MyF, "x=msgbox(\" %s \",48,\" Eshan Basic v.1.0.0 \") \n", msg);
			fclose(MyF);
		}
	}
}
void Ok_Cancel (char msg[300], char f[600])
{
	FILE *MyF;
	if (S == 'F')
	{
		MyF = fopen(f, "w");
	}
	else if (S == 'T')
	{
		MyF = fopen(f, "a+");
	}
	if ( MyF == 0)
	{
		printf("\tFailed to open file");
	}
	else
	{
		if (S == 'F')
		{
			fprintf(MyF, "x=msgbox(\" %s \",1,\" Eshan Basic v.1.0.0 \") \n", msg);
			fclose(MyF);
		}
		else if (S == 'T')
		{
			fprintf(MyF, "x=msgbox(\" %s \",1,\" Eshan Basic v.1.0.0 \") \n", msg);
			fclose(MyF);
		}
	}
}
void A_R_I (char msg[300], char f[600])
{
	FILE *MyF;
	if (S == 'F')
	{
		MyF = fopen(f, "w");
	}
	else if (S == 'T')
	{
		MyF = fopen(f, "a+");
	}
	if ( MyF == 0)
	{
		printf("\tFailed to open the file");
	}
	else
	{
		if (S == 'F')
		{
			fprintf(MyF, "x=msgbox(\" %s \",2,\" Eshan Basic v.1.0.0 \") \n", msg);
			fclose(MyF);
		}
		else if (S == 'T')
		{
			fprintf(MyF, "x=msgbox(\" %s \",2,\" Eshan Basic v.1.0.0 \") \n", msg);
			fclose(MyF);
		}
	}
}
void Decission(char f[600], int type)
{
	char ans[10], msg[300
	                 ], NB[5], T[30];
	int nB = 0, j, k;
	system("cls");
	printf("\nBefore you making another message box:\n");
	if (type == 0 || type == 48)
	{
		printf("\nWould you like to display a message after user presses OK?\n(Yes/ No)\nAns:\t");
		fflush(stdin);
		scanf("%s", ans);
		if (strcmp(ans, "YES") == 0 || strcmp(ans, "Yes") == 0 || strcmp(ans, "yes") == 0)
		{
			nB++;
			NB[0] = 'T';
		}
	}
	else if (type == 1)
	{
		printf("\nWould you like to display a message after user presses OK?\n(Yes/No)\nAns:\t");
		fflush(stdin);
		scanf("%s", ans);
		if (strcmp(ans, "YES") == 0 || strcmp(ans, "Yes") == 0 || strcmp(ans, "yes") == 0)
		{
			nB++;
			NB[0] = 'T';
		}
		printf("\nWould you like to display a message after the user presses CANCEL?\n(Yes/No)\nAns:\t");
		fflush(stdin);
		scanf("%s", ans);
		if (strcmp(ans, "YES") == 0 || strcmp(ans, "Yes") == 0 || strcmp(ans, "yes") == 0)
		{
			nB++;
			NB[1] = 'T';
		}
	}
	else if (type == 2)
	{
		printf("\nWould you like to display a message after the user presses ABORT?\n(Yes/No)\nAns:\t");
		fflush(stdin);
		scanf("%s", ans);
		if (strcmp(ans, "YES") == 0 || strcmp(ans, "Yes") == 0 || strcmp(ans, "yes") == 0)
		{
			nB++;
			NB[2] = 'T';
		}
		printf("\nWould you like to display a message after the user presses RETRY?\n(Yes/No)\nAns:\t");
		fflush(stdin);
		scanf("%s", ans);
		if (strcmp(ans, "YES") == 0 || strcmp(ans, "Yes") == 0 || strcmp(ans, "yes") == 0)
		{
			nB++;
			NB[3] = 'T';
		}
		printf("\nDo you want to display a message after the user press IGNORE?\n\t(Yes/No)\n\nAns:\t");
		fflush(stdin);
		scanf("%s", ans);
		if (strcmp(ans, "YES") == 0 || strcmp(ans, "Yes") == 0 || strcmp(ans, "yes") == 0)
		{
			nB++;
			NB[4] = 'T';
		}
	}
	for (j = 0;j < nB;j++)
	{
		for (k = 0; k < 5; k++)
		{
			if (NB[k] == 'T')
			{
				NB[k] = 'F';
				if (k == 0)
				{
					strcpy(T, "Okay");
				}
				else if (k == 1)
				{
					strcpy(T, "Cancel");
				}
				else if (k == 2)
				{
					strcpy(T, "Abort");
				}
				else if (k == 3)
				{
					strcpy(T, "Retry");
				}
				else if (k == 4)
				{
					strcpy(T, "Ignore");
				}
				break;
			}
		}
		printf("What type of message box do you want to show when the user press %s button\n", T);
		selection(k, f, type);
	} /* 0 = ok 48 = Warning 1 = ok and cancel 2 = abort retry and ignore Ok(msg,f) Warning(msg,f); Ok_Cancel(msg,f); A_R_I(msg,f); */
}
void selection (int k, char f[600], int type)
{
	char ans[10], msg[300];
	system("cls");
	printf("\nChoose an option\n\n");
	printf("\t%c OK - OK button Message box\n", 26);
	printf("\t%c WAR - Warning Message box\n", 26);
	printf("\t%c OC - OK and Cancel Message box\n", 26);
	printf("\t%c AIR - Abort Retry and Cancel Message box\n", 26);
	printf("Choice: ");
	fflush(stdin);
	scanf("%s", ans);
	if (strcmp(ans, "q") == 0 || strcmp(ans, "Q") == 0)
	{
		exit(-1);
	}
	Function(k, f);
	mesg(msg);
	if (strcmp(ans, "OK") == 0 || strcmp(ans, "ok") == 0)
	{
		Ok(msg, f);
		type = 0;
	}
	else if (strcmp(ans, "War") == 0 || strcmp(ans, "WAR") == 0 || strcmp(ans, "war") == 0)
	{
		Warning(msg, f);
		type = 48;
	}
	else if (strcmp(ans, "OC") == 0 || strcmp(ans, "Oc") == 0 || strcmp(ans, "oc") == 0)
	{
		Ok_Cancel(msg, f);
		type = 1;
	}
	else if (strcmp(ans, "Air") == 0 || strcmp(ans, "AIR") == 0 || strcmp(ans, "air") == 0)
	{
		A_R_I(msg, f);
		type = 2;
	}
	end(f);
}
void See_you(void)
{
	system("cls");
	system("color F2");
	printf("\n\n%c%c To see results,\n%c%c check the folder that this program was saved in.\n\n", 176, 177, 176, 177);
	system("pause");
}
void Function(int k, char f[600])
{
	FILE *MyF;
	if ( k == 0)
	{
		MyF = fopen(f, "a+");
		if ( MyF == 0)
		{
			printf("error");
		}
		else
		{
			fprintf(MyF, "If x=vbOk then\n");
			fclose(MyF);
		}
	}
	else if ( k == 1)
	{
		MyF = fopen(f, "a+");
		if ( MyF == 0)
		{
			printf("error");
		}
		else
		{
			fprintf(MyF, "If x=vbCancel then\n");
			fclose(MyF);
		}
	}
	else if ( k == 2)
	{
		MyF = fopen(f, "a+");
		if ( MyF == 0)
		{
			printf("error");
		}
		else
		{
			fprintf(MyF, "If x=vbAbort then\n");
			fclose(MyF);
		}
	}
	else if ( k == 3)
	{
		MyF = fopen(f, "a+");
		if ( MyF == 0)
		{
			printf("error");
		}
		else
		{
			fprintf(MyF, "If x=vbRetry then\n");
			fclose(MyF);
		}
	}
	else if ( k == 4)
	{
		MyF = fopen(f, "a+");
		if ( MyF == 0)
		{
			printf("error");
		}
		else
		{
			fprintf(MyF, "If x=vbIgnore then\n");
			fclose(MyF);
		}
	}
}
void end(char f[600])
{
	FILE *MyF;
	MyF = fopen(f, "a+");
	if ( MyF == 0)
	{
		printf("error end");
	}
	else
	{
		fprintf(MyF, "End if\n");
		fclose(MyF);
	}
}
void herp(void)
{
	int i, j, k, l;
	for (i = 0; i < 10 ;i++)
	{
		l = i;
		for ( j = 0;j < 15;j++)
		{
			printf("Loading.\n");
			derp(l);
			printf(".....");
			system("cls");
		}
		for ( k = 0;k < 15;k++)
		{
			printf("Loading..\n");
			derp(l);
			printf("..");
			system("cls");
		}
		for ( k = 0;k <15;k++)
		{
			printf("Loading...\n");
			derp(l);
			printf("...");
			system("cls");
		}
		for ( k = 0;k < 15;k++)
		{
			printf("Loading.....\n");
			derp(l);
			printf("...");
			system("cls");
		}
	}
}
void derp(int i)
{
	if (i <= 5)
	{
		printf("Data files.");
	}
	else if (i > 5 && i <= 10)
	{
		printf("Searching.");
	}
	else if (i > 10 && i <= 15)
	{
		printf("Reading.");
	}
	else if (i > 15 && i <= 20)
	{
		printf("Summarizing");
	}
	else printf("Done.");
}

