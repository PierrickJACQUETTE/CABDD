#include "generate.h"
#include "graceHashJoin.h"
#include "tabGenerator.h"

int main(int argc, char const *argv[]) {
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

    graceHashJoin("R", "S");
    diskJoinNested("R", "S");

    return 0;
}
