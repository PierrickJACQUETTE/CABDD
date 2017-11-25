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

/*
* concatener les arguments pour former le nom du repertoire
*/
char* concateneNameDirectory(char* path, int number);

/*
* concatener les arguments pour former le nom du fichier
*/
char* concateneNameFile(char* pathDirectory, char* nameFile, int numberFile);

/*
* connaitre le numero du dernier fichier dans ce repertoire
*/
int lastNumberNameFile(char* path);

/*
* compter le nombre de fichier dans le repertoire
*/
int countFileInDirectory(char* path);

/*
* savoir si le repertoire existe
*/
int directoryIsExist(char* path);

/*
* creer le repertoire
*/
int createDirectory(char* path);

#endif
