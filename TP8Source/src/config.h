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

#ifndef CONFIG_H_
#define CONFIG_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>

#define SIZ_M 10

#define ERROR_NULL(a,str) if (a == NULL) {fprintf(stderr, "%s\n", str); return EXIT_FAILURE;}
#define ERROR_SYS(a,str) if (a < 0) {fprintf(stderr, "%s\n", str); return EXIT_FAILURE;}
#define ERROR_NULLCHAR(a,str) if (a == NULL) {fprintf(stderr, "%s\n", str); return NULL;}
#define ERROR_SYSCHAR(a,str) if (a < 0) {fprintf(stderr, "%s\n", str); return NULL;}
#define ERROR_EOF(a,str) if (a == EOF) {fprintf(stderr, "%s\n", str); return EXIT_FAILURE;}


#endif
