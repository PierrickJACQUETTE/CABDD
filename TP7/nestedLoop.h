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

#ifndef NESTEDLOOP_H_
#define NESTEDLOOP_H_

#include "inOut.h"

/*
* effectue un nestedLoop entre R et S et stocke le resultat dans RS
* maintient les compteurs à jour
* si le tableau RS est plein ecrit le tableau dans le fichier path
*/
int nestedLoop(short R[], short S[], short RS[], int* iterRS, int sizeR, int sizeS, char* path, int* nbWrite);

#endif
