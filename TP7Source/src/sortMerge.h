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

#ifndef SORTMERGE_H_
#define SORTMERGE_H_

#include "relation.h"
#include "diskIO.h"
#include "outil.h"

/**
 * Permet d effectuer un merge de R1 et R2 dans R3
 * @param R1                tableau R1 de short
 * @param R2                tableau R2 de short
 * @param R3                tableau R3 de short le resultat
 * @param iterR3            le nombre de case occcupe dans R3
 * @param passe             le numero de la passe courante
 * @param numFileR1         le numero du fichier courant pour R1
 * @param numFileR2         le numero du fichier courant pour R2
 * @param numFileR3         le numero du fichier courant pour R3
 * @param path              le nom du dossier
 * @param nameDirectory     le nom du dossier courant
 * @param nameDirectoryNext le nom du prochain dossier
 * @param readR2            le nombre de short dans R2
 */
void trie(short R1[], short R2[], short R3[], int* iterR3, int passe, int numFileR1, int numFileR2, int* numFileR3, char* path, char* nameDirectory, char* nameDirectoryNext, int readR2, char* nameCheck);

#endif
