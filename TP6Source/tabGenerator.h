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

#ifndef TABGENERATOR_H_
#define TABGENERATOR_H_

#include "config.h"

/*
* mettre les valeurs dans le tableau avec les valeurs identiques
*/
void fillInTab(short *tabI, short *tabR, short *tabS, int init);

/*
* randomizer le tableau
*/
void randomizer(short *tab, int count);

/*
* affichage du tableau
*/
void display(short *tabR, short *tabS);

#endif
