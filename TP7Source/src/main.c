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

#include "generate.h"
#include "tabGenerator.h"
#include "diskSortMerge.h"

int main(int argc, char const *argv[]) {
	char* path = "R";
	short tabI[SIZE];
	randomizer(tabI, SIZE);
	createDirectory(path);
	generate(path, tabI, SIZE);

	passe(path);

	return EXIT_SUCCESS;
}
