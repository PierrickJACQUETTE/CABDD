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

#ifndef GENERATE_H_
#define GENERATE_H_

#include "relation.h"
#include "diskIO.h"

/**
* generer les fichiers pour le nested loop
 * @param directory chemin du repertoire
 * @param tableau   adresse du tableau a genere
 * @param sizeTab   taille du tableau en argument
 */
void generate(char* directory, short* tableau, int sizeTab);

#endif
