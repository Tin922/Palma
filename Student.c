#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#define MAX_NAME 1024
#define MAX_SIZE_ROW 1024

typedef struct Student {
	char Name[MAX_NAME];
	char Surname[MAX_NAME];
	int StudentNumber;
}Student;
/*
int CountF()
{
	int countStudent = 0;
	char buffer[MAX_SIZE_ROW] = { 0 };
	FILE* f = NULL;
	//printf("Insert file name\n");

	if ((fopen("Cranberry.txt", "r")) == NULL)
	{
		printf("File je prazan");
	}
	else printf("FIle nije prazan");

	while (!feof(f))
	{
		fgets(buffer, MAX_SIZE_ROW, f);
		if (strcmp(buffer, "\n") == 0)
			break;
		else countStudent++;
	}

	fclose(f);
	return countStudent;
}*/

void main()
{
	int countStudent = 0;
	char buffer[MAX_SIZE_ROW] = { 0 };
	FILE* f = NULL;
	//printf("Insert file name\n");

	if ((fopen("Cranberry.txt", "r")) == NULL)
	{
		printf("File je prazan");
	}
	else printf("FIle nije prazan");

	while (!feof(f))
	{
		//fgets(buffer, MAX_SIZE_ROW, f);
		if (strcmp(buffer, "\n") == 0)
			break;
		else countStudent++;
	}

	fclose(f);
	//int countStudent = CountF();
	printf("CountStudent ");
	printf("CountStudent = %d", countStudent);
}