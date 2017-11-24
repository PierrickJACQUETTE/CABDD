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

#ifndef INODE_H
#define INODE_H_

#include "inOut.h"

/*
* concatener les arguments pour former le nom du repertoire
*/
char* concateneNameDirectory(char* path, char algo, int number);

/*
* concatener les arguments pour former le nom du fichier
*/
char* concateneNameFile(char* pathDirectory, char algo, char* nameFile, int numberFile);

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
