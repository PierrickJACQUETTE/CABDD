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

#include "../../src/diskSortMerge.h"

int main(int argc, char const *argv[]) {
	SIZE = 20;
	char* pathCheck = "CheckTest";
	createDirectory(pathCheck);
	passe("Test", pathCheck);
	printf("Pour le comparer lancer le script\n ./test/LibDiskSortMerge/compare.sh demo/CheckTest/1/0.txt demo/Test/resultat.txt\n");
	return EXIT_SUCCESS;
}
