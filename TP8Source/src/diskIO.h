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

#ifndef DISKIO_H_
#define DISKIO_H_

#include "config.h"
#include "relation.h"


/**
* lire dans le fichier et stocker les valeurs dans value
* @param  path  chemin du fichier
* @param  value tableau de ce qu'il faut ecrire
* @return        nombre de short lu
*/
int readTabValue(char* path, short* value);

/**
* lire dans le fichier et stocker la premiere valeure
* @param  path  chemin du fichier
* @param  value la ou il faut ecrire la valeur
* @return        nombre de short lu
*/
int readFirst(char *path, short* value);

Node* parse(Node* rac, char* name);
void ecrire_node(Node* node);
void ecrire_leaf(Node* node);
char* getRac(char* name, char* nameFile);
#endif
