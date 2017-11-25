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

#include "relation.h"

char* concateneNameDirectory(char* path, int number){
	char *str = malloc(sizeof(char)*20);
	ERROR_NULLCHAR(str, "malloc : concateneNameDirectory : inode.c");
	int error = sprintf(str, "%s%d", path, number);
	ERROR_SYSCHAR(error , "sprintf : concateneNameDirectory : inode.c");
	return str;
}

char* concateneNameFile(char* pathDirectory,  char* nameFile, int numberFile){
	char *str = malloc(sizeof(char)*20);
	ERROR_NULLCHAR(str, "malloc : concateneNameFile : inode.c");
	int error = sprintf(str, "%s/%s%d.txt", pathDirectory, nameFile, numberFile);
	ERROR_SYSCHAR(error , "sprintf : concateneNameFile : inode.c");
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
	ERROR_NULL(dirp, "opendir : lastNumberNameFile : inode.c");
	while ((entry = readdir(dirp)) != NULL) {
		if (entry->d_type == DT_REG) { /* If the entry is a regular file */
			file_count++;
		}
	}
	int error = closedir(dirp);
	ERROR_SYS(error, "closedir : lastNumberNameFile : inode.c");
	return file_count-1;
}

int countFileInDirectory(char* path){
	return lastNumberNameFile(path)+1;
}

int createDirectory(char* path){
	return mkdir(path, 0777);
}
