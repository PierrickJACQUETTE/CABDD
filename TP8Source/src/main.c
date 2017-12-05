/*
* TP n°: 8
*
* Titre du TP : Bulk B Tree
*
* Date : 01/12/2017
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

#include "LibBT.h"

int main(int argc, char const *argv[]) {
	Node* n = NULL;
	n = create(n, 1, "../data/S");
	mkdir("../data/tree", S_IRWXU | S_IXGRP | S_IRGRP | S_IXOTH | S_IROTH);
	storeToDisk(n, "../data/tree");
	Node* n2 = NULL;
	n2 = loadInMemory(n2, "../data/tree");
	display(n2, 0);
	return EXIT_SUCCESS;

}
