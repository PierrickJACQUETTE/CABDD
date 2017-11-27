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
*  pierrick.jacquette@gmail.com
*
* Remarques : Effectue en binome
*/

#ifndef DISKSORTMERGE_H_
#define DISKSORTMERGE_H_

#include "sortMerge.h"

/**
 * Permet d'effectuer les différentes passes
 * @param path chemin du repertoire avec les fichiers
 * @param path chemin du repertoire pour les fichiers contenant les run
 */
void passe(char* path, char* pathVerif);

#endif
