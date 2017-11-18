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

#ifndef GRACEHASHJOIN_H_
#define GRACEHASHJOIN_H_

#include "inode.h"
#include "diskJoin.h"

/*
* effectue un grace hash join sur les deux premiers repertoires et met
* le resultat dans le troisieme
*/
void graceHashJoin(char* directoryOne, char* directoryTwo, char* directoryRes);

#endif
