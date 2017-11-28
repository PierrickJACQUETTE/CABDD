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

#include "generate.h"
#include "tabGenerator.h"
#include "diskSortMerge.h"

int main(int argc, char const *argv[]) {
	SIZE = 96;
	char* path = "R";
	char* pathVerif = "Check";
	short tabI[SIZE];
	randomizer(tabI, SIZE);
	createDirectory(path);
	createDirectory(pathVerif);
	generate(path, tabI, SIZE);

	passe(path, pathVerif);

	return EXIT_SUCCESS;
}
