#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Functions.h"
void CopyFiles(char sourcename[],char targetname[])
{
	for (int i = 1; i <= 240; i++)
	{
		char sname[35];
		sprintf(sname, "%s\\result%d.txt",sourcename, i);
		FILE *source = fopen(sname, "r");
		if (!source) {
			perror("fopen failed");
			return;
		}
		char tname[35];
		sprintf(tname, "%s\\result%d.txt", targetname, i);
		FILE *target = fopen(tname, "w");
		if (!target) {
			perror("fopen failed");
			return;
		}

		char ch;
		while ((ch = fgetc(source)) != EOF)
			fputc(ch, target);
		fclose(source);
		fclose(target);
	}
}
void DeleteFolder(char name[20])
{
	char path[35];
	for (int i = 1; i <= 240; i++)
	{
		sprintf(path, "%s\\result%d.txt", name, i);
		remove(path);
	}
	sprintf(path, "%s\\game.txt" , name);
	remove(path);
	strcpy(path, "rmdir ");
	strcat(path, name);
	system(path);
}