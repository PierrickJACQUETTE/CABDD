#ifndef LIBBT_H
#define LIBBT_H_

#include "config.h"

typedef struct {
	int isLeaf;
	short value1, value2; //cases
	short *t1, *t2, *t3; //only for leaf
	struct Node *left, * middle, *right; //only for node
	struct Node *father; //null à la racine
	short level, indic; //level_indice
} Node;

Node* create(int opt, char *name);
int insertBulkData(int opt, short i, Node *rac, char* file);
void loadInMemory(Node *rac, char* name);
void storeToDisk(Node *rac, char* name);

#endif
