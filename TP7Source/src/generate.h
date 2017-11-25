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
* 			jacquette@gmail.com
*
* Remarques : Effectue en binome
*/

#ifndef GENERATE_H_
#define GENERATE_H_

#include "relation.h"
#include "diskIO.h"

/*
* generer les fichiers pour le nested loop
*/
void generate(char* directory, short* tableau, int sizeTab);

#endif
