#include "diskSortMerge.h"

int comp (const void * a, const void * b) {
	const short *ia = (const short *)a;
	const short *ib = (const short *)b;
	return *ia  - *ib;
}

// int passe = (((init%10)+1)/2);

void passe0(char* path){
    int i;
    short tabT[SIZ_M];
    char* nameDirectoryNext = concateneNameDirectory(path, 0);
    createDirectory(nameDirectoryNext);
    int f = countFileInDirectory(path);
    for(i = 0; i < f; i++){
        readTabValue(concateneNameFile(path, path, i), tabT);
        qsort(tabT, SIZ_M, sizeof(short), comp);
        writeTabValue(concateneNameFile(nameDirectoryNext, path, i), tabT, SIZ_M, 0);
    }
}

void passe(char* path){
    passe0(path);
}
