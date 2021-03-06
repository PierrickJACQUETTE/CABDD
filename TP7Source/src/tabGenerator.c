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

#include "tabGenerator.h"

void randomizer(short *tab, int count){
	srand(time(NULL));
	int x, i = 0;
	while(i < count){
		int r = rand()%MAX_SHT;
		for (x = 0; x < i; x++) {
			if(tab[x] == r) {
				break;
			}
		}
		if(x==i) {
			tab[i++] = r;
		}
	}
}
