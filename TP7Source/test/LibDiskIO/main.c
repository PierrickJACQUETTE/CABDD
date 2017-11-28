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

#include "../../src/diskIO.h"

int main(int argc, char const *argv[]) {

	int rc;
	short tab[3] = {5,2,4}, res[3];
	char *path = "test/LibDiskIO/R.txt";

	writeTabValue(path, tab, 3, 0);

	rc = readTabValue(path, res);
	printf("Nb lecture %d\n", rc);

	int i;
	for(i = 0; i < 3; i++){
		printf("valeur dans tab : %d - valeur dans res : %d\n", tab[i], res[i]);
	}

	return EXIT_SUCCESS;
}
