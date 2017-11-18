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

#ifndef GENERATE_H_
#define GENERATE_H_

#include "inode.h"

void generateHash(char* directory, short* tableau, int sizeTab);

void generateNested(char* directory, short* tableau, int sizeTab);

#endif
