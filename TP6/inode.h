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

char* concateneNameDirectory(char* path, char algo, int number);

char* concateneNameFile(char* pathDirectory, char algo, char* nameFile, int numberFile);

int lastNumberNameFile(char* path);

int countFileInDirectory(char* path);

int directoryIsExist(char* path);

int createDirectory(char* path);

#endif
