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

#ifndef LIBBT_H
#define LIBBT_H_

#include "config.h"



/**
* creer un arbre
* @param  opt 	 savoir si l'on veux que l'arbre soit en memoire ou en disque(1)
* @param  name	 nom du repertoire ou est stocke les fichiers S triee
* @return        l'arbre cree avec tout les fichiers de S
*/
Node* create(Node* rac, int opt, char *name);

/**
* permet d'inserrer dans l'arbre le noeud contenu dans le file
* @param  opt	 savoir si l'on veux que l'arbre soit en memoire ou en disque(1)
* @param  i 	 nom du fichier que l'on veux inserer
* @param rac	 Node represantant la racine de l'arbre dans lequel inserer le nouveau noeud
* @return        -1 si erreur sinon 0
*/
int insertBulkData(int opt, short i, Node *rac, char* file);

/**
* permet de charger en memoire un arbre stocker dans le repertoire name
* @param  rac	 arbre dans lequel stockee les noeuds
* @param  name 	 nom du dossier
*/
Node* loadInMemory(Node *rac, char* name);

/**
* permet de stocker en disque un arbre
* @param  rac	 arbre a stocker
* @param  name   dossier dans lequel stockee l'arbre
*/
void storeToDisk(Node *rac, char* name);

void display(Node* rac, int nb);

#endif
