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

/**
 * lire le contenu dun fichier pour le stocker dans un node
 * @param  rac  node où stocket les infprmations
 * @param  name nom du fichier ou lire
 * @return      node rempli
 */
Node* parse(Node* rac, char* name);

/**
 * ecrire le contenu dun node dans un fichier
 * @param node le node a ecrire
 */
void ecrire_node(Node* node);

/**
 * ecrire le contenu dun node dans un fichier
 * @param node le node a ecrire sachant que c'est une feuille
 */
void ecrire_leaf(Node* node);

/**
 * permet a partir d'un fichier de trouver le fichier ou la racine est stocker
 * @param  name     nom du repertoire
 * @param  nameFile nom du fichier ou lire
 * @return          nom du fichier ou est la racine
 */
char* getRac(char* name, char* nameFile);
#endif
