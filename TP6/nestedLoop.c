#include "nestedLoop.h"

int nestedLoop(short R[], short S[], short RS[], int* iterRS, int sizeR, int sizeS, char* path) {
	int i, nbWrite = 0;
	for (i = 0; i < sizeR; i++) {
		int j;
		for (j = 0; j < sizeS; j++) {
			if ((int)(R[i]) == (int)(S[j])) {
				RS[*iterRS] = R[i];
				*iterRS+=1;
			}
			if(*iterRS == SIZ_M){
				writeTabValue(path, RS, *iterRS, 0);
				*iterRS = 0;
				nbWrite++;
			}
		}
	}
	return nbWrite;
}
