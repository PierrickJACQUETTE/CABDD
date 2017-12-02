#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int isLeaf;
	short value1, value2; //cases
	short *t1, *t2, *t3; //only for leaf
	struct Node *left, *right; //only for node
	struct Node *father; //null à la racine
	short level, indic; //level_indice
} Node;

Node* create(char *name);
void insertBulkData(int opt, Node *rac, char* namefile);
void loadInMemory(Node *rac, char* name);
void storeToDisk(Node *rac, char* name);
