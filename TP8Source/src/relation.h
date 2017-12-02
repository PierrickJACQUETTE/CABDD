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
* concatener les arguments pour former le nom du repertoire
* @param  pathParent    chemin du dossier parent
* @param  path			chemin du dossier courant
* @return        		le resultat de la concatenation
*/
char* concateneNameDirectoryDirectory(char* pathParent, int path);

/**
* concatener les arguments pour former le nom du fichier
* @param  pathDirectory   chemin du dossier
* @param  nameFile      name de ce fichier
* @param  number        indice du fichier
* @return        le resultat de la concatenation
*/
char* concateneNameFile(char* pathDirectory, char* nameFile, int numberFile);

/**
* concatener les arguments pour former le nom du fichier
* @param  pathDirectory   chemin du dossier
* @param  nameFile      chemin du sous dossier
* @return        le resultat de la concatenation
*/
char* concateneChar(char* pathDirectory,  char* path);
/**
* connaitre le numero du dernier fichier dans ce repertoire
* @param  path chemin du dossier
* @return      nombre du dernier fichier
*/
int lastNumberNameFile(char* path);

/**
* compter le nombre de fichier dans le repertoire
* @param  path chemin du dossier
* @return      nombre de fichier
*/
int countFileInDirectory(char* path);

/**
* creer le repertoire
* @param  path chemin du dossier
* @return      erreur eventuelle
*/
int createDirectory(char* path);

#endif
