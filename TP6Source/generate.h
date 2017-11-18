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

/*
* generer les fichiers pour le hash
*/
void generateHash(char* directory, short* tableau, int sizeTab);

/*
* generer les fichiers pour le nested loop
*/
void generateNested(char* directory, short* tableau, int sizeTab);

#endif
