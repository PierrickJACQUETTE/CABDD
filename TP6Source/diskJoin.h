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

#ifndef DISKJOIN_H_
#define DISKJOIN_H_

#include "inode.h"
#include "nestedLoop.h"

/**
* do the join between n files
*/
void diskJoin(char* pathR, char* pathS, char* pathRS, char algo, int* nbRead, int* nbWrite);

void diskJoinNested(char* pathDirectoryOne, char* pathDirectoryTwo, char* pathDirectoryRes);

#endif
