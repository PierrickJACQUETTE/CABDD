/**
* TP n°: 6
*
* Titre du TP : Grace Hash Join
*
* Date : 17/11/2017
*
* Nom : ELBEZ & JACQUETTE
* Prenom : Samuel & Pierrick
*
* email : samuel.elbe@gmail.com
* 			jacquette@gmail.com
*
* Remarques : Effectue en binome
*/

#include "tabGenerator.h"

void fillInTab(short *tabI, short *tabR, short *tabS, int init){
    int i;
    for(i = 0; i < (SIZE-COMMON); i++){
        tabR[i] = tabI[i];
    }

    for(i = (SIZE-COMMON); i < SIZE; i++){
        tabR[i] = tabI[i];
        tabS[i] = tabI[i];
    }

    for(i = SIZE; i < init; i++){
        tabS[i-SIZE] = tabI[i];
    }
}

void randomizer(short *tab, int count){
    int x, i = 0;
    while(i < count){
        int r = rand()%MAX_SHT;
        for (x = 0; x < i; x++) {
            if(tab[x] == r) {
                break;
            }
        }
        if(x==i) {
            tab[i++] = r;
        }
    }
}

void display(short *tabR, short *tabS){
    int i;
    for(i = 0; i < SIZE; i++){
        int j;
        for (j = 0; j < SIZE; j++) {
            if(tabR[i] == tabS[j]){
                printf("%d\n", tabR[i]);
            }
        }
    }
}
