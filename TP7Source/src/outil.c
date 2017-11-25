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

#include "outil.h"

int myPow(int number, int puissance){
	int i, res = 1;
	for(i=1; i<puissance+1; i++){
		res*= number;
	}
	return res;
}

int comp (const void * a, const void * b) {
	const short *ia = (const short *)a;
	const short *ib = (const short *)b;
	return *ia  - *ib;
}
