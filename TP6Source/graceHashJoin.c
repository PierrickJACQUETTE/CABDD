/**
* TP n°: 6
*
* Titre du TP : Grace Hash Join
*
* Date : 17/11/2017
*
* Nom : ELBEZ & JACQUETTE
* Prenom : Samuel & Pierrick
*
* email : samuel.elbe@gmail.com
* 			jacquette@gmail.com
*
* Remarques : Effectue en binome
*/

#include "graceHashJoin.h"

void graceHashJoin(char* directoryOne, char* directoryTwo, char* directoryRes){
	int i, nbRead = 0, nbWrite = 0;
	char* pathDirectoryOne;
	char* pathDirectoryTwo;
	for(i=0; i<SIZ_M;i++){
		pathDirectoryOne = concateneNameDirectory(directoryOne, 'H', i);
		pathDirectoryTwo = concateneNameDirectory(directoryTwo, 'H', i);
		if(directoryIsExist(pathDirectoryOne) > -1 && directoryIsExist(pathDirectoryTwo) > -1){
			diskJoin(pathDirectoryOne, pathDirectoryTwo, directoryRes, 'H', &nbRead, &nbWrite);
		}
	}
	nbWrite = (nbWrite<SIZ_M)? nbWrite : nbWrite%SIZ_M+1;
	printf("Grace Hash : Read : %d et Write : %d\n", nbRead, nbWrite);
}
