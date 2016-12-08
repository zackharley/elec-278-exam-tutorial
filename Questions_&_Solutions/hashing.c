#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 200
#define TABLE_SIZE 60

const char *FILENAME = "hashing.ini";

typedef struct Pair {
	char *key;
	char *value;
} Pair;

struct Pair *hashArray[TABLE_SIZE];
struct Pair *dummyPair; // will be pointed to by any empty indices

// Function Declarations
int hash(char *key);
int calculateLetterValue(char c);
Pair *search(char *key);
void populateHashTable();
void insert(char *key, char *value);
Pair *removeFromTable(Pair *pair);
void display();


int hash(char *key) {
	int hashIndex = calculateLetterValue(key[0]);

	for(int i = 1; i < 3; i++) {
		hashIndex *= calculateLetterValue(key[i]);
	}

	return hashIndex % TABLE_SIZE;
}

int calculateLetterValue(char c) {
	return c - 'a' + 1;
}

Pair *search(char *key) {
	int hashIndex = hash(key);

	while(hashArray[hashIndex] != NULL) {

		if(strcmp(hashArray[hashIndex]->key, key) == 0) {
			return hashArray[hashIndex];
		}

		++hashIndex;

		hashIndex %= TABLE_SIZE;

	}

	return NULL;
}

void populateHashTable() {
	FILE *fp;
	char str[BUFFER_SIZE];
	char *search = "=";
	char *key;
	char *value;

	fp = fopen(FILENAME, "r");

	if(fp == NULL) {
		perror("Error opening file");
	}
	
	while(fgets(str, BUFFER_SIZE, fp) != NULL) {
		key = strtok(str, search);
		value = strtok(NULL, "\n");
		insert(key, value);
	}

	fclose(fp);
}

void insert(char *key, char *value) {
	Pair *pair = (Pair *) malloc(sizeof(Pair));
	pair->key = malloc(sizeof(char) * (strlen(key) + 1));
	pair->value = malloc(sizeof(char) * (strlen(value) + 1));
	strcpy(pair->key, key);
	strcpy(pair->value, value);

	int hashIndex = hash(key);

	while(hashArray[hashIndex] != NULL && strcmp(hashArray[hashIndex]->key, "") != 0) {
		++hashIndex;
		hashIndex %= TABLE_SIZE;
	}

	hashArray[hashIndex] = pair;
}

Pair *removeFromTable(Pair *pair) {
	char *key = pair->key;

	int hashIndex = hash(key);

	while(hashArray[hashIndex] != NULL) {

		if(strcmp(hashArray[hashIndex]->key, key) == 0) {
			Pair *temp = hashArray[hashIndex];
			hashArray[hashIndex] = dummyPair;
			return temp; 
		}

		++hashIndex;
		hashIndex %= TABLE_SIZE;

	}

	return NULL;
}

void display() {
	for(int i = 0; i < TABLE_SIZE; i++) {
		if(hashArray[i] != NULL && strcmp(hashArray[i]->key, "") != 0) {
			printf("(%s, %s)\n", hashArray[i]->key, hashArray[i]->value);
		} else {
			printf(" ~~\n");
		}
	}

	printf("\n");
}

int main() {
	dummyPair = (Pair *) malloc(sizeof(Pair));
	dummyPair->key = "";
	dummyPair->value = "";

	Pair *pair = (Pair *) malloc(sizeof(Pair));

	populateHashTable();

	display();

	pair = search("jason");

	printf("Found '%s': %s\n\n", pair->key, pair->value);

	removeFromTable(pair);

	display();

	return 0;
}
