/**
* TP n°: 7
*
* Titre du TP : Disk Merge Join
*
* Date : 24/11/2017
*
* Nom : ELBEZ & JACQUETTE
* Prenom : Samuel & Pierrick
*
* email : samuel.elbe@gmail.com
* 			jacquette@gmail.com
*
* Remarques : Effectue en binome
*/

#include "diskIO.h"

int countLine(FILE * file ){
	int ch;
	int count = 0;
	while ((ch = fgetc(file)) != EOF) {
		if (ch == '\n') {
			count++;
		}
	}
	return count;
}

int writeTabValue(char* path, short* value, int size, int max){
	FILE* file = NULL;
	int i, error;
	file = fopen(path, "a+");
	if (file != NULL) {
		for(i=max; i< size; i++){
			error = fprintf(file, "%d\n", (int)(value[i]));
			ERROR_SYS(error, "fprintf : writeValue : inOut.c");
		}
		ERROR_EOF(fclose(file), "fclose : writeValue : inOut.c");
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
		ERROR_EOF(fclose(file), "fclose : readShort : inOut.c");
	}
	return i;
}
