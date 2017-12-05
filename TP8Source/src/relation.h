/*
* TP n°: 8
*
* Titre du TP : Bulk B Tree
*
* Date : 01/12/2017
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

#ifndef RELATION_H
#define RELATION_H_

#include "config.h"

/**
* concatener les arguments pour former le nom du repertoire
* @param  path   chemin du dossier
* @param  number indice du dossier
* @return        le resultat de la concatenation
*/
char* concateneNameDirectory(char* path, int number);

/**
* concatener les arguments pour former le nom du fichier
* @param  pathDirectory   chemin du dossier
* @param  nameFile      name de ce fichier
* @param  number        indice du fichier
* @return        le resultat de la concatenation
*/
char* concateneNameFile(char* pathDirectory, char* nameFile, int numberFile);

/**
* compter le nombre de fichier dans le repertoire
* @param  path chemin du dossier
* @return      nombre de fichier
*/
int countFileInDirectory(char* path);

/**
 * Supprime le \n a la fin de line
 * @param  line ou il faut retirer le \n
 * @return new line sans \n
 */
char* removeLineJump(char* line);


#endif
