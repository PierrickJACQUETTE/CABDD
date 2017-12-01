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
*  pierrick.jacquette@gmail.com
*
* Remarques : Effectue en binome
*/

#include "generate.h"

void generate(char* directory, short* tableau, int sizeTab){
	int i, c = 0;
	for(i=0; i<sizeTab; i+=SIZ_M){
		int max = (i+SIZ_M >= sizeTab)? sizeTab : i+SIZ_M;
		writeTabValue(concateneNameFile(directory, directory, c), tableau, max, i);
		c++;
	}
}
