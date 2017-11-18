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
#include "diskJoin.h"

void diskJoin(char* pathR, char* pathS, char* pathRS, char algo, int* nbRead, int* nbWrite){
	int iterRS = 0, readS = 1, i, j = 0, nbReadR = 0, nbReadS = 0;
	short strR[SIZ_M];
	short strS[SIZ_M];
	short strRS[SIZ_M];
	int nbFileR = countFileInDirectory(pathR);
	int nbFileS = countFileInDirectory(pathS);
	char * path = concateneNameFile(pathRS, algo,"RS", 0);
	for(i = 0; i<nbFileR; i++){
		nbReadR = readTabValue(concateneNameFile(pathR, algo, "R", i), strR);
		*nbRead+=1;
		while(j>= 0 && j < nbFileS){
			if(readS == 1){
				nbReadS = readTabValue(concateneNameFile(pathS, algo, "S", j), strS);
				*nbRead+=1;
			}else{
				readS = 1;
			}
			nestedLoop(strR, strS, strRS, &iterRS, nbReadR, nbReadS, path, nbWrite);
			j = (i%2 ==0)? j+1 : j-1;
		}
		readS = 0;
		j = (i%2 ==0)? j-1 : j+1;
	}
	writeTabValue(path, strRS, iterRS, 0);
	if(iterRS>0){
		*nbWrite+=1;
	}
}

void diskJoinNested(char* pathDirectoryOne, char* pathDirectoryTwo, char* pathDirectoryRes){
	int nbRead = 0, nbWrite = 0;
	diskJoin(pathDirectoryOne, pathDirectoryTwo, pathDirectoryRes, 'N', &nbRead, &nbWrite);
	printf("Nested Loop : Read : %d et Write : %d\n", nbRead, nbWrite);
}
