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

#ifndef OUTIL_H_
#define OUTIL_H_

#include "config.h"

/**
 * Permet d'effectuer le cacul d'une puissance d'un nombre
 * @param  number    nombre a mettre a la puissance
 * @param  puissance puissance a laquelle mettre le nombre
 * @return           resultat du calcul
 */
int myPow(int number, int puissance);

/**
 * Permet d'effectuer une comparaison
 * @param  a un short
 * @param  b le deuxieme
  * @return  la difference entre les deux
 */
int comp (const void * a, const void * b);

#endif
