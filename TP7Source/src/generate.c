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

void generate(char* directory, short* tableau, int sizeTab){
	int i, c = 0;
	for(i=0; i<sizeTab; i+=SIZ_M){
		int max = (i+SIZ_M >= sizeTab)? sizeTab : i+SIZ_M;
		writeTabValue(concateneNameFile(directory, directory, c), tableau, max, i);
		c++;
	}
}
