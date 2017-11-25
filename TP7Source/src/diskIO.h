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

#ifndef DISKIO_H_
#define DISKIO_H_

#include "config.h"

/*
* ecrire une valeur dans le fichier
*/
int writeValue(char* path, short* value, int sizeMax);

/*
* ecrire de min a size valeur dans le fichier
*/
int writeTabValue(char* path, short* value, int size, int min);

/*
* lire dans le fichier et stocker les valeurs dans value
*/
int readTabValue(char* path, short* value);



#endif
