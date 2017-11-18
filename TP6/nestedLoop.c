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

#include "nestedLoop.h"

int nestedLoop(short R[], short S[], short RS[], int* iterRS, int sizeR, int sizeS, char* path) {
	int i, nbWrite = 0;
	for (i = 0; i < sizeR; i++) {
		int j;
		for (j = 0; j < sizeS; j++) {
			if ((int)(R[i]) == (int)(S[j])) {
				RS[*iterRS] = R[i];
				*iterRS+=1;
			}
			if(*iterRS == SIZ_M){
				writeTabValue(path, RS, *iterRS, 0);
				*iterRS = 0;
				nbWrite++;
			}
		}
	}
	return nbWrite;
}
