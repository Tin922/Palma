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

int CountF()
{
	int countStudent = 0;
	char buffer[MAX_SIZE_ROW] = { 0 };
	FILE* f = NULL;
	
	f=fopen("studenti.txt","r");

	if(f==NULL)
	{
		printf("file je prazan");
	}
	

	while (!feof(f))
	{
		fgets(buffer, MAX_SIZE_ROW, f);
		if (strcmp("\n",buffer) != 0)
			countStudent++;
	}

	fclose(f);
	return countStudent;
}

void main()
{
	int countStudent = 0;
	char buffer[MAX_SIZE_ROW] = { 0 };
	FILE* f = NULL;
	
	countStudent=CountF();


	
	
	printf("CountStudent ");
	printf("CountStudent = %d", countStudent);
}