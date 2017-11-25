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

#include <stdio.h>
#include "relation.h"

int main(int argc, char const *argv[]) {
	char* path = "R";
	char* pathVerif = "R0";

	char* nameDirectoryNext = concateneNameDirectory(path, 0);
	createDirectory(nameDirectoryNext);

	char* nameCheck = concateneNameFile(pathVerif, "", 0);
	createDirectory(nameCheck);

	int f = countFileInDirectory(".");
	printf("Nombre de fichiers dans le fichier courant : %d\n", f);

	return EXIT_SUCCESS;
}
