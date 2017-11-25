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

#include "sortMerge.h"

void trie(short R1[], short R2[], short R3[], int* iterR3, int passe, int numFileR1, int numFileR2, int* numFileR3, char* path, char* nameDirectory, char* nameDirectoryNext, int readR2){
	int iterR1 = 0, iterR2 = 0, i, numFileR1Start = numFileR1, numFileR2Start = numFileR2;
	for(i = 0; i<(SIZ_M*2*myPow(2, passe-1))-(SIZ_M-readR2); i++){
		if(iterR1==SIZ_M && iterR2==readR2){
			break;
		}else if(((iterR2 < readR2 && R2[iterR2] < R1[iterR1]) || iterR1 >= SIZ_M)){
			R3[(*iterR3)] = R2[iterR2];
			iterR2 = iterR2 + 1;
			*iterR3 = *iterR3 +1;
		}else{
			R3[(*iterR3)] = R1[iterR1];
			iterR1 = iterR1 + 1;
			*iterR3 = *iterR3 +1;
		}
		if(iterR1 == SIZ_M && numFileR1 < numFileR1Start + myPow(2, passe-1)-1){
			readTabValue(concateneNameFile(nameDirectory, path, numFileR1), R1);
			iterR1 = 0;
			numFileR1++;
		}
		if(iterR2 == SIZ_M && numFileR2 < numFileR2Start + myPow(2, passe-1)-1){
			readR2 = readTabValue(concateneNameFile(nameDirectory, path, numFileR2), R2);
			iterR2 = 0;
			numFileR2++;
		}
		if(*iterR3 == SIZ_M){
			writeTabValue(concateneNameFile(nameDirectoryNext, path, *numFileR3), R3, *iterR3, 0);
			*iterR3 = 0;
			*numFileR3 = *numFileR3 +1;
		}
	}
}
