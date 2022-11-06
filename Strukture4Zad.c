#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Node {
	int X;
	int Y;
	struct Node* next;
}Node;

int ReadFromFile(Node** root);
int insertSorted(Node** root, int x, int y);
int insertAfter(Node* curr, int x, int y);
int PrintList(Node* root);
int mulitplyPolynoms(Node* root, Node** rootZ);
int AddPolynoms(Node* root);
int Deallocation(Node** root);

int main() {

	Node* root = malloc(sizeof(Node));
	if (root == NULL)
		return 5;
	root->next = NULL;

	Node* rootZ = malloc(sizeof(Node));
	if (rootZ == NULL)
		return 5;
	rootZ->next = NULL;
	
	ReadFromFile(&root);
	PrintList(root);
	AddPolynoms(root, &rootZ);

	printf("Zbrojeni polinomi\n");
	PrintList(rootZ);
	mulitplyPolynoms(root, &rootZ);

	Deallocation(&root);
	Deallocation(&rootZ);

	return 0;
}
int ReadFromFile(Node** root)
{
	Node Polinom = {
	   .X = 0,
	   .Y = 0,
	   .next = NULL
	};
	
	FILE* file = fopen("t.txt", "r");;
	if (file == NULL) {
		printf("File not opened\n");
		return 0;
	}
	while ((fscanf(file, "%d %d", &Polinom.X, &Polinom.Y)) >= 2){
		if (Polinom.X > 0 && Polinom.Y >= 0)
		{
			insertSorted(root, Polinom.X, Polinom.Y);
		}
	}
	return 0;
}
int insertAfter(Node* curr, int x, int y)
{
	Node* newNode = malloc(sizeof(Node));
	if (newNode == NULL) return 5;
	newNode->X = x;
	newNode->Y = y;

	newNode->next = curr->next;
	curr->next = newNode;

	return 0;
}
int insertSorted(Node** root, int x, int y)
{
	Node* newNode = malloc(sizeof(Node));
	if (newNode == NULL) return 5;
	newNode->X = x;
	newNode->Y = y;

	Node* curr = *root;
	while (curr->next != NULL)
	{
		if (y < curr->next->Y)
			break;

		curr = curr->next;
	}
	insertAfter(curr, x, y);

	return 0;
}
int PrintList(Node* root)
{
	Node* currentEl = root->next;
	while (currentEl != NULL)
	{
		printf("%dx^%d\n", currentEl->X, currentEl->Y);
		currentEl = currentEl->next;
	}
	return 0;
}
int AddPolynoms(Node* root, Node** rootZ) {
	int zbrojPolinomaX;
	int zbrojPolinomaY;
	Node* curr = root->next;;
	Node* curr2 = curr;

	while ((curr) != NULL) {
		zbrojPolinomaX = 0;
		zbrojPolinomaY = 0;
		while ( curr2 != NULL && curr->Y == curr2->Y )
		{
			zbrojPolinomaX = zbrojPolinomaX + curr2->X;
			zbrojPolinomaY = curr->Y;

			curr2 = curr2->next;
		}
		insertSorted(rootZ, zbrojPolinomaX, zbrojPolinomaY);
		curr = curr2;
	}
	return;
}
int mulitplyPolynoms(Node* root)
{
	Node* curr = root->next;
	int umnozakX = 1;
	int zbrojY = 0;
	
	while (curr != NULL) {
		umnozakX = umnozakX * curr->X;
		zbrojY = zbrojY + curr->Y;
		curr = curr->next;
	}
	printf("Umnozak polinoma = %dx^%d \n", umnozakX, zbrojY);
	return 0;
}
int Deallocation(Node** root)
{
	Node* toRemove = NULL;
	Node* curr = *root;
	
	while (curr != NULL){
		toRemove = curr;
		curr = curr->next;
		free(toRemove);
	}
	//free(*root);
	return 0;
}

