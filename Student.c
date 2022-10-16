#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#define MAX_NAME 1024
#define MAX_SIZE_ROW 1024
#define MAX_BR_BODOVA 50

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

void getDataAndPrintData(int countStudent)
{
	Student *s;
	FILE *f;
	float relativan_br_bodova=0; //postotak rijesenosti?
	int br_bodova=0;
	
	s=(Student*)malloc(sizeof(Student)*countStudent);
	
	f=fopen("studenti.txt","r");

	for(int i=0;i<countStudent;i++)	
	{
		fscanf(f,"%s %s %d", s[i].Name,s[i].Surname,&s[i].StudentNumber);
	}

	for(int i=0;i<countStudent;i++)
	{
		relativan_br_bodova=0;
		printf("%s %s %d\n",s[i].Name,s[i].Surname,s[i].StudentNumber);
		relativan_br_bodova=s[i].StudentNumber/(float)MAX_BR_BODOVA*100;
		printf("Realtivan broj bodova je:%f\n",relativan_br_bodova);
	}


}



void main()
{
	int countStudent = 0;
	char buffer[MAX_SIZE_ROW] = { 0 };
	FILE* f = NULL;
	
	
	countStudent=CountF();
	getDataAndPrintData(countStudent);
	
}
