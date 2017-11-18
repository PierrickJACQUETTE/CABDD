/**
* TP n°: 6
*
* Titre du TP : Grace Hash Join
*
* Date : 17/11/2017
*
* Nom : ELBEZ & JACQUETTE
* Prenom : Samuel & Pierrick
*
* email : samuel.elbe@gmail.com
* 			jacquette@gmail.com
*
* Remarques : Effectue en binome
*/

#include "generate.h"

int hash(short key) {
	return key % SIZ_M;
}

void addInode(char* directory, char algo, int idDirectory, short value){
	char* pathDirectory = concateneNameDirectory(directory, algo, idDirectory);
	if(directoryIsExist(pathDirectory) == -1){
		createDirectory(pathDirectory);
	}
	usleep(1);
	int last = lastNumberNameFile(pathDirectory);
	if(last == -1){
		last++;
	}
	int res = writeValue(concateneNameFile(pathDirectory, algo, directory, last), &value, SIZ_M);
	if(res==0){
		writeValue(concateneNameFile(pathDirectory, algo, directory, last+1), &value, SIZ_M);
	}
}

void generateHash(char* directory, short* tableau, int sizeTab){
	int i;
	for(i=0; i<sizeTab; i++){
		addInode(directory, 'H', hash(tableau[i]), tableau[i]);
	}
}

void generateNested(char* directory, short* tableau, int sizeTab){
	int i, c = 0;
	for(i=0; i<sizeTab; i+=SIZ_M){
		int max = (i+SIZ_M >= sizeTab)? sizeTab-1 : i+SIZ_M;
		writeTabValue(concateneNameFile(directory, 'N', directory, c), tableau, max, i);
		c++;
	}
}
