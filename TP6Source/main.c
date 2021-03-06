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

#include "test.h"
#include "generate.h"
#include "graceHashJoin.h"
#include "tabGenerator.h"

int main(int argc, char const *argv[]) {

	test();

    int init = (SIZE*2)-COMMON;
    short tabI[init];
    short tabR[SIZE];
    short tabS[SIZE];
    srand(time(NULL));

    randomizer(tabI, init);
    fillInTab(tabI, tabR, tabS, init);

    generateHash("S", tabS, SIZE);
    generateHash("R", tabR, SIZE);
    generateNested("R", tabR, SIZE);
    generateNested("S", tabS, SIZE);

    graceHashJoin("R", "S", "RSH");
    diskJoinNested("R", "S", "RS");

    return EXIT_SUCCESS;
}
