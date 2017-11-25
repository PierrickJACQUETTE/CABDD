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
