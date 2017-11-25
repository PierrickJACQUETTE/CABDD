#include "diskSortMerge.h"

int comp (const void * a, const void * b) {
	const short *ia = (const short *)a;
	const short *ib = (const short *)b;
	return *ia  - *ib;
}

int myPow(int number, int puissance){
	int i, res = 1;
	for(i=1; i<puissance+1; i++){
		res*= number;
	}
	return res;
}

void trie(short R1[], short R2[], short R3[], int* iterR3, int passe, int numFileR1, int numFileR2, int* numFileR3, char* path, char* nameDirectory, char* nameDirectoryNext, int readR2){
	int iterR1 = 0, iterR2 = 0, i;
	for(i = 0; i<SIZ_M*2*myPow(2, passe-1) && (iterR2 < readR2 || iterR1 < SIZ_M); i++){
		if((iterR2 < readR2 && R2[iterR2] < R1[iterR1]) || iterR1 >= SIZ_M){
			R3[(*iterR3)] = R2[iterR2];
			iterR2 = iterR2 + 1;
		}else{
			R3[(*iterR3)] = R1[iterR1];
			iterR1 = iterR1 + 1;
		}
		*iterR3 = *iterR3 +1;
		if(iterR1 == SIZ_M && numFileR1 < myPow(2, passe-1)){
			readTabValue(concateneNameFile(nameDirectory, path, numFileR1), R1);
			iterR1 = 0;
			numFileR1++;
		}
		if(iterR2 == SIZ_M && numFileR2 < myPow(2, passe-1)){
			readR2 = readTabValue(concateneNameFile(nameDirectory, path, numFileR2), R2);
			iterR2 = 0;
			numFileR2++;
		}
		if(*iterR3 == SIZ_M){
			writeTabValue(concateneNameFile(nameDirectoryNext, path, *numFileR3), R3, *iterR3, 0);
			*iterR3 = 0;
			*numFileR3 = *numFileR3 +1;
		}
	}
}

// int passe = (((init%10)+1)/2);

void passe0(char* path){
	int i;
	short tabT[SIZ_M];
	char* nameDirectoryNext = concateneNameDirectory(path, 0);
	createDirectory(nameDirectoryNext);
	int f = countFileInDirectory(path);
	for(i = 0; i < f; i++){
		int lu = readTabValue(concateneNameFile(path, path, i), tabT);
		qsort(tabT, SIZ_M, sizeof(short), comp);
		writeTabValue(concateneNameFile(nameDirectoryNext, path, i), tabT, lu, 0);
	}
}

void passe1(char* path){
	int passe = 1;
	int i, iterR3, numFileR3, numFileR2;
	char* nameDirectoryNext;
	char* nameDirectory;
	short tabR1[SIZ_M];
	short tabR2[SIZ_M];
	short tabR3[SIZ_M];
	nameDirectoryNext = concateneNameDirectory(path, passe);
	createDirectory(nameDirectoryNext);
	nameDirectory = concateneNameDirectory(path, passe-1);
	int f = countFileInDirectory(nameDirectory);
	i=0;
		for(i=0; i<f+1-(myPow(2, passe)/2); i+=myPow(2, passe)){
			iterR3 = 0;
			numFileR3 = i;
			numFileR2 = myPow(2, passe-1);
			readTabValue(concateneNameFile(nameDirectory, path, i), tabR1);
			int readR2 = readTabValue(concateneNameFile(nameDirectory, path, i+numFileR2), tabR2);
			trie(tabR1, tabR2, tabR3, &iterR3, passe, i+1, numFileR2+1, &numFileR3, path, nameDirectory, nameDirectoryNext, readR2);
			if(iterR3 != 0){
				writeTabValue(concateneNameFile(nameDirectoryNext, path, numFileR3), tabR3, iterR3, 0);
				numFileR3++;
				iterR3 = 0;
			}
		}
		//add rejeton
}

void passe(char* path){
	passe0(path);
	passe1(path);
}
