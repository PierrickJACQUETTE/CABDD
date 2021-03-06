/**
* TP n°: 7
*
* Titre du TP : Disk Merge Join
*
* Date : 24/11/2017
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

#include "diskSortMerge.h"

void passe0(char* path, char* pathVerif){
	int i;
	short tabT[SIZ_M];
	char* nameDirectoryNext = concateneNameDirectory(path, 0);
	createDirectory(nameDirectoryNext);
	char* nameCheck = concateneNameDirectoryDirectory(pathVerif, 0);
	createDirectory (nameCheck);
	int f = countFileInDirectory(path);
	for(i = 0; i < f; i++){
		int lu = readTabValue(concateneNameFile(path, path, i), tabT);
		qsort(tabT, SIZ_M, sizeof(short), comp);
		writeTabValue(concateneNameFile(nameDirectoryNext, path, i), tabT, lu, 0);
		writeTabValue(concateneNameFile(nameCheck, "", i), tabT, lu, 0);
	}
}

void passeN(char* path, int passe, char* pathVerif){
	int i, copiei, iterR3, numFileR3, numFileR2, readR2;
	char* nameDirectoryNext;
	char* nameDirectory;
	short tabR1[SIZ_M];
	short tabR2[SIZ_M];
	short tabR3[SIZ_M];
	nameDirectoryNext = concateneNameDirectory(path, passe);
	createDirectory(nameDirectoryNext);
	nameDirectory = concateneNameDirectory(path, passe-1);
	char* nameCheck = concateneNameDirectoryDirectory(pathVerif, passe);
	createDirectory (nameCheck);
	int f = countFileInDirectory(nameDirectory);
	i=0;
	for(i=0; i<f-(myPow(2, passe)/2); i+=myPow(2, passe)){
		iterR3 = 0;
		numFileR3 = i;
		numFileR2 = myPow(2, passe-1) + i;
		readTabValue(concateneNameFile(nameDirectory, path, i), tabR1);
		readR2 = readTabValue(concateneNameFile(nameDirectory, path, numFileR2), tabR2);
		trie(tabR1, tabR2, tabR3, &iterR3, passe, i+1, numFileR2+1, &numFileR3, path, nameDirectory, nameDirectoryNext, readR2, nameCheck);
		if(iterR3 != 0){
			writeTabValue(concateneNameFile(nameDirectoryNext, path, numFileR3), tabR3, iterR3, 0);
			writeTabValue(concateneNameFile(nameCheck, "", i), tabR3, iterR3, 0);
			copiei = i;
			numFileR3++;
			iterR3 = 0;
		}
	}
	for(i=i; i<f; i++){
		readR2 = readTabValue(concateneNameFile(nameDirectory, path, i), tabR2);
		writeTabValue(concateneNameFile(nameDirectoryNext, path, numFileR3), tabR2, readR2, 0);
		writeTabValue(concateneNameFile(nameCheck, "", copiei), tabR3, readR2, 0);
		numFileR3++;
	}
}

void nPasse(char* path, char* pathVerif){
	int i;
	int nbPasse = (SIZE/SIZ_M)/2;
	for(i=1; i < nbPasse+1; i++){
		passeN(path, i, pathVerif);
	}
}

void passe(char* path, char* pathVerif){
	passe0(path, pathVerif);
	nPasse(path, pathVerif);
}
