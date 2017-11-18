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

#ifndef INOUT_H_
#define INOUT_H_

#include "config.h"

int writeValue(char* path, short* value, int sizeMax);
int writeTabValue(char* path, short* value, int size, int min);
int readTabValue(char* path, short* value);



#endif
