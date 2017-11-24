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
#include "graceHashJoin.h"
#include "tabGenerator.h"

int comp (const void * a, const void * b) {
	const short *ia = (const short *)a;
	const short *ib = (const short *)b;
	return *ia  - *ib;
}

int main(int argc, char const *argv[]) {

	int i, init = 96;
	short tabI[init], tabT[SIZ_M];
	srand(time(NULL));

	// int passe = (((init%10)+1)/2);

	randomizer(tabI, init);
	createDirectory("R");
	generateNested("R", tabI, init);

	createDirectory("R0");
	int f = countFileInDirectory("R");

	for(i = 0; i < f; i++){
		readTabValue(concateneNameFile("R", 'N', "R", i), tabT);
		qsort(tabT, SIZ_M, sizeof(short), comp);
		writeTabValue(concateneNameFile("R0", '0', "R", i), tabT, SIZ_M, 0);
	}

	// createDirectory("R/R0");
	// qsort(tabI, init, sizeof(short), comp);
	// generateNested("R", tabI, init);
    //
	// for(i = 0; i < init; i++){
	// 	printf("%d\n", tabI[i]);
	// }

	return EXIT_SUCCESS;
}
