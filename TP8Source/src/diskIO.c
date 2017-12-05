/*
* TP n°: 8
*
* Titre du TP : Bulk B Tree
*
* Date : 01/12/2017
*
* Nom : BESSA & ELBEZ & JACQUETTE
* Prenom : Alexandre & Samuel & Pierrick
*
* email :
alexandrebessa26@gmail.com
samuel.elbe@gmail.com
*  pierrick.jacquette@gmail.com
*
* Remarques : Effectue en trinome
*/

#include "diskIO.h"

int readTabValue(char* path, short value[]){
	int i =0;
	FILE* file = NULL;
	file = fopen(path, "r");
	if (file != NULL) {
		char * line = NULL;
		size_t len = 0;
		while (getline(&line, &len, file) != -1) {
			short t = atoi(line);
			value[i] = t;
			i++;
		}
		ERROR_EOF(fclose(file), "fclose : readShort : diskIO.c");
	}
	return i;
}

int readFirst(char* path, short value[]){
	int i =0;
	FILE* file = NULL;
	file = fopen(path, "r");
	if (file != NULL) {
		char * line = NULL;
		size_t len = 0;
		getline(&line, &len, file);
		short t = atoi(line);
		value[i] = t;
		i++;
		ERROR_EOF(fclose(file), "fclose : readFirst : diskIO.c");
	}
	return i;
}

Node* nodeLine(char* line, Node* n){
	line = removeLineJump(line);
	if(strcmp(line, "Null") == 0){
		return NULL;
	}else{
		char * name = malloc(sizeof(char)*50);
		name = concateneNameFile("../data/tree", line, -1);
		n = parse(n,name);
		free(name);
		return n;
	}
}

Node* parse(Node* rac, char* name){
	Node* n = malloc(sizeof(Node));
	FILE* file = fopen(name, "r");
	if (file != NULL) {
		char * line = NULL;
		size_t len = 0;
		getline(&line, &len, file);
		if(rac != NULL){
			n->father = ((struct Node*)rac);
		}else{
			n->father = NULL;
		}
		getline(&line, &len, file);
		n->value1 = atoi(line);
		getline(&line, &len, file);
		n->value2 = atoi(line);
		getline(&line, &len, file);
		n->isLeaf = atoi(line);
		if(n->isLeaf == 1){
			getline(&line, &len, file);
			n->s1 = atoi(line);
			getline(&line, &len, file);
			n->s2 = atoi(line);
			getline(&line, &len, file);
			n->s3 = atoi(line);
		}else{
			getline(&line, &len, file);
			n->left = (struct Node*)nodeLine(line, n);
			getline(&line, &len, file);
			n->middle = (struct Node*)nodeLine(line, n);
			getline(&line, &len, file);
			n->right = (struct Node*)nodeLine(line, n);
		}
		fclose(file);
	}
	return n;
}

void ecrire_node(Node* node){
	FILE* file = NULL;
	char* file_name = malloc(sizeof(char)*20);
	sprintf(file_name,"../data/tree/%d_%d", node->level, node->indic);
	file = fopen(file_name, "w+");
	if(file != NULL){
		if(node->father != NULL){
			fprintf(file, "%d_%d\n", ((Node*)node->father)->level, ((Node*)node->father)->indic);
		}else{
			fprintf(file, "Null\n");
		}
		fprintf(file, "%d\n", node->value1);
		fprintf(file, "%d\n", node->value2);
		fprintf(file, "%d\n", node->isLeaf);
		if(node->left != NULL){
			fprintf(file, "%d_%d\n", ((Node*)node->left)->level, ((Node*)node->left)->indic);
		}else{
			fprintf(file, "Null\n");
		}
		if(node->middle != NULL){
			fprintf(file, "%d_%d\n", ((Node*)node->middle)->level, ((Node*)node->middle)->indic);
		}else{
			fprintf(file, "Null\n");
		}
		if(node->right != NULL){
			fprintf(file, "%d_%d\n", ((Node*)node->right)->level, ((Node*)node->right)->indic);
		}else{
			fprintf(file, "Null\n");
		}
		fclose(file);
	}
}

void ecrire_leaf(Node* node){
	FILE* file = NULL;
	char* file_name = malloc(sizeof(char)*20);
	sprintf(file_name,"../data/tree/%d_%d", node->level, node->indic);
	file = fopen(file_name, "w+");
	if(file != NULL){
		if(node->father != NULL){
			fprintf(file, "%d_%d\n", ((Node*)node->father)->level, ((Node*)node->father)->indic);
		}else{
			fprintf(file, "Null\n");
		}
		fprintf(file, "%d\n", node->value1);
		fprintf(file, "%d\n", node->value2);
		fprintf(file, "%d\n", node->isLeaf);
		if(node->s1 != -1){
			fprintf(file, "%d.txt\n", node->s1);
		}else{
			fprintf(file, "-1\n");
		}
		if(node->s2 != -1){
			fprintf(file, "%d.txt\n", node->s2);
		}else{
			fprintf(file, "-1\n");
		}
		if(node->s3 != -1){
			fprintf(file, "%d.txt\n", node->s3);
		}else{
			fprintf(file, "-1\n");
		}
	}
	fclose(file);
}

char* getRac(char* name, char* nameFile){
	nameFile = concateneNameFile(name, nameFile, -1);
	if(nameFile[strlen(nameFile)-1] == '\n'){
		nameFile[(strlen(nameFile) - 1)] = '\0';
	}
	FILE* file = fopen(nameFile, "r");

	if (file != NULL) {
		char * line = NULL;
		size_t len = 0;
		getline(&line, &len, file);
		if(strcmp(line,"Null\n")==0){
			return nameFile;
		}else{
			nameFile = getRac(name,line);
		}
		fclose(file);
	}
	return nameFile;
}
