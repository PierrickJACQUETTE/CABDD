/**
* TP n°: 7
*
* Titre du TP : Disk Merge Join
*
* Date : 24/11/2017
*
* Nom : BESSA & ELBEZ & JACQUETTE
* Prenom : Alexandre & Samuel & Pierrick
*
* email :
   alexandrebessa26@gmail.com
   samuel.elbe@gmail.com
*  pierrick.jacquette@gmail.com
*
* Remarques : Effectue en trinome
*/

#ifndef DISKIO_H_
#define DISKIO_H_

#include "config.h"
#include "relation.h"

/**
* ecrire de min a size valeur dans le fichier
 * @param  path  chemin du fichier
 * @param  value tableau de ce qu'il faut ecrire
 * @param  size  tableau du tableau
 * @param  max   indice
 * @return       nombre de short ecrit
 */
int writeTabValue(char* path, short* value, int size, int max);

/**
* lire dans le fichier et stocker les valeurs dans value
 * @param  path  chemin du fichier
 * @param  value tableau de ce qu'il faut ecrire
 * @return        nombre de short lu
 */
int readTabValue(char* path, short* value);



#endif
