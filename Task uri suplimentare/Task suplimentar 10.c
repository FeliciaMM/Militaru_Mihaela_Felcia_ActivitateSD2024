#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

typedef struct Roman {
	char* denumire;
	char* numeAutor;
	int cod;
}Roman;

typedef struct Node {
	struct Node* left;
	struct Node* right;
	Roman* info;
	int height;

}Node;

typedef struct ListNode {
	Roman* info;
	struct ListNode* next;
} ListNode;


typedef struct DoubleListNode {
	Roman* info;
	struct DoubleListNode* prev;
	struct DoubleListNode* next;
} DoubleListNode;


Node* creareNod(Roman* info) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->right = newNode->right = NULL;
	newNode->info = info;
	newNode->height = 1;

	return newNode;
}

Roman* creareRoman(const char* denumire, const char* numeAutor, int cod) {
	Roman* roman = (Roman*)malloc(sizeof(Roman));
	roman->denumire = (char*)malloc(sizeof(char) * (strlen(denumire) + 1));
	strcpy(roman->denumire, denumire);
	roman->numeAutor = (char*)malloc(sizeof(char) * (strlen(numeAutor) + 1));
	strcpy(roman->numeAutor, numeAutor);
	roman->cod = cod;

	return roman;
}

int maxNr(int a, int b) {
	return (a > b) ? a : b;
}

int getHeight(Node* node) {
	if (node == NULL) {
		return 0;
	}
	else {
		return node->height;
	}
}

int Echilibru(Node* node) {
	if (node == NULL)
		return 0;
	return getHeight(node->left) - getHeight(node->right);
}

Node* rotatieDreapta(Node* y) {
	Node* x = y->left;
	Node* T2 = x->right;
	x->right = y;
	y->left = T2;
	y->height = maxNr(getHeight(y->left), getHeight(y->right)) + 1;
	x->height = maxNr(getHeight(x->left), getHeight(x->right)) + 1;
	return x;
}


Node* rotatieStanga(Node* x) {
	Node* y = x->right;
	Node* T2 = y->left;	
	y->left = x;
	x->right = T2;
	x->height = maxNr(getHeight(x->left), getHeight(x->right)) + 1;
	y->height = maxNr(getHeight(y->left), getHeight(y->right)) + 1;

	return y;
}

Node* insert(Node* node, Roman* info) {
	if (node == NULL)
		return creareNod(info);

	if (info->cod < node->info->cod)
		node->left = insert(node->left, info);
	else if (info->cod > node->info->cod)
		node->right = insert(node->right, info);
	else 
		return node;

	
	node->height = 1 + maxNr(getHeight(node->left), getHeight(node->right));

	
	int echilibru = Echilibru(node);

	if (echilibru > 1 && info->cod < node->left->info->cod)
		return rotatieDreapta(node);

	
	if (echilibru < -1 && info->cod > node->right->info->cod)
		return rotatieStanga(node);


	if (echilibru > 1 && info->cod > node->left->info->cod) {
		node->left = rotatieStanga(node->left);
		return rotatieDreapta(node);
	}

	
	if (echilibru < -1 && info->cod < node->right->info->cod) {
		node->right = rotatieDreapta(node->right);
		return rotatieStanga(node);
	}

	
	return node;
}

void printRoman(Roman* roman) {
	printf("Denumire: %s, Autor: %s, Cod: %d\n", roman->denumire, roman->numeAutor, roman->cod);
}


Node* cautareNod(Node* node, int cod) {
	if (node == NULL || node->info->cod == cod)
		return node;

	if (cod < node->info->cod)
		return cautareNod(node->left, cod);

	return cautareNod(node->right, cod);
}

void salvareVector(Node* node, Roman* vector[], int* index) {
	if (node == NULL)
		return;

	vector[*index] = node->info;
	(*index)++;

	salvareVector(node->left, vector, index);
	salvareVector(node->right, vector, index);
}


ListNode* salvareListaSimpla(Node* node) {
	if (node == NULL)
		return NULL;

	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->info = node->info;
	newNode->next = NULL;

	newNode->next = salvareListaSimpla(node->left);
	ListNode* temp = newNode;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = salvareListaSimpla(node->right);

	return newNode;
}

DoubleListNode* salvareListaDubla(Node* node) {
	if (node == NULL)
		return NULL;

	DoubleListNode* newNode = (DoubleListNode*)malloc(sizeof(DoubleListNode));
	newNode->info = node->info;
	newNode->prev = NULL;
	newNode->next = NULL;

	DoubleListNode* left = salvareListaDubla(node->left);
	DoubleListNode* right = salvareListaDubla(node->right);

	if (left != NULL) {
		while (left->next != NULL)
			left = left->next;
		left->next = newNode;
		newNode->prev = left;
	}
	if (right != NULL) {
		right->prev = newNode;
		newNode->next = right;
	}

	return (left == NULL) ? newNode : node;
}

void inordine(Node* node) {
	if (node != NULL) {
		inordine(node->left);
		printRoman(node->info);
		inordine(node->right);
	}
}


void postordine(Node* node) {
	if (node != NULL) {
		postordine(node->left);
		postordine(node->right);
		printRoman(node->info);
	}
}


void eliberareArbore(Node* node) {
	if (node != NULL) {
		eliberareArbore(node->left);
		eliberareArbore(node->right);
		free(node->info->denumire);
		free(node->info->numeAutor);
		free(node->info);
		free(node);
	}
}

int main() {
	Node* node = NULL;

	node = insert(node, creareRoman("Marele Gatsby", "F. Scott Fitzgerald", 101));
	node = insert(node, creareRoman("Crima din Orient Express", "Agatha Christie", 102));
	node = insert(node, creareRoman("Domnisoara de la tara", "Jane Austen", 103));
	node = insert(node, creareRoman("Mandrie si prejudecata", "Jane Austen", 104));
	node = insert(node, creareRoman("Calatoriile lui Gulliver", "Jonathan Swift", 105));

	
	printf("Traversare preordine:\n");
	postordine(node); // Am corectat apelul funcției aici
	printf("\n\n");

	printf("Traversare inordine:\n");
	inordine(node);
	printf("\n\n");

	printf("Traversare postordine:\n");
	postordine(node); // Postordinea a fost afișată înainte, dar acum o afișăm din nou
	printf("\n\n");


	int codCautat = 103;
	Node* nodCautat = cautareNod(node, codCautat);
	if (nodCautat != NULL) {
		printf("Nodul cu codul %d a fost găsit: \n", codCautat);
		printRoman(nodCautat->info);
	}
	else {
		printf("Nodul cu codul %d nu a fost găsit.\n", codCautat);
	}

	eliberareArbore(node);

	return 0;
}