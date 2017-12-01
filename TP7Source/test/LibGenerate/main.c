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

#include "../../src/generate.h"
#include "../../src/relation.h"

int main(int argc, char const *argv[]) {

	short tab[12] = {0,1,2,3,4,5,6,7,8,9,10,11};
	createDirectory("test");
	generate("test", tab, 12);
	printf("On attend 2 : on a %d\n", countFileInDirectory("test"));
	return EXIT_SUCCESS;
}
