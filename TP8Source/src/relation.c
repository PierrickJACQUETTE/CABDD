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

#include "relation.h"

char* concateneNameDirectory(char* path, int number){
	char *str = malloc(sizeof(char)*20);
	ERROR_NULLCHAR(str, "malloc : concateneNameDirectory : relation.c");
	int error = sprintf(str, "%s%d", path, number);
	ERROR_SYSCHAR(error , "sprintf : concateneNameDirectory : relation.c");
	return str;
}

char* concateneNameDirectoryDirectory(char* pathParent, int path){
	char *str = malloc(sizeof(char)*20);
	ERROR_NULLCHAR(str, "malloc : concateneNameDirectoryDirectory : relation.c");
	int error = sprintf(str, "%s/%d", pathParent, path);
	ERROR_SYSCHAR(error , "sprintf : concateneNameDirectoryDirectory : relation.c");
	return str;
}

char* concateneNameFile(char* pathDirectory,  char* nameFile, int numberFile){
	char *str = malloc(sizeof(char)*20);
	ERROR_NULLCHAR(str, "malloc : concateneNameFile : relation.c");
	int error;
	if(nameFile == NULL){
		error = sprintf(str, "%s/%d.txt", pathDirectory, numberFile);
	}
	else{
		error = sprintf(str, "%s/%s", pathDirectory, nameFile);
	}
	ERROR_SYSCHAR(error , "sprintf : concateneNameFile : relation.c");
	return str;
}

char* concateneChar(char* pathDirectory,  char* path){
	char *str = malloc(sizeof(char)*20);
	ERROR_NULLCHAR(str, "malloc : concateneChar : relation.c");
	int error = sprintf(str, "%s/%s", pathDirectory, path);
	ERROR_SYSCHAR(error , "sprintf : concateneChar : relation.c");
	return str;
}

int lastNumberNameFile(char* path){
	int file_count = 0;
	DIR * dirp;
	struct dirent * entry;
	dirp = opendir(path);
	//si le dossier nest pas encore cree par le system
	while(dirp == NULL){
		dirp = opendir(path);
	}
	ERROR_NULL(dirp, "opendir : lastNumberNameFile : relation.c");
	while ((entry = readdir(dirp)) != NULL) {
		if (entry->d_type == DT_REG) { /* If the entry is a regular file */
			file_count++;
		}
	}
	int error = closedir(dirp);
	ERROR_SYS(error, "closedir : lastNumberNameFile : relation.c");
	return file_count-1;
}

int countFileInDirectory(char* path){
	return lastNumberNameFile(path)+1;
}

int createDirectory(char* path){
	return mkdir(path, 0777);
}
