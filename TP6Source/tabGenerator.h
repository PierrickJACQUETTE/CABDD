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

void fillInTab(short *tabI, short *tabR, short *tabS, int init);
void randomizer(short *tab, int count);
void display(short *tabR, short *tabS);

#endif
