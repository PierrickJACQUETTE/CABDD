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

int writeTabValue(char* path, short* value, int size, int max){
	FILE* file = NULL;
	int i, error;
	file = fopen(path, "a+");
	if (file != NULL) {
		for(i=max; i< size; i++){
			error = fprintf(file, "%d\n", (int)(value[i]));
			ERROR_SYS(error, "fprintf : writeValue : diskIO.c");
		}
		ERROR_EOF(fclose(file), "fclose : writeValue : diskIO.c");
	}
	return EXIT_SUCCESS;
}

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

int readFirst(char* path, short* value){
	int i =0;
	FILE* file = NULL;
	file = fopen(path, "r");
	if (file != NULL) {
		char * line = NULL;
		size_t len = 0;
		getline(&line, &len, file);
		*value = atoi(line);
		i++;
		ERROR_EOF(fclose(file), "fclose : readFirst : diskIO.c");
	}
	return i;
}
