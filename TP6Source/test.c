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

void test(){
	graceHashJoin("Test/R", "Test/S", "Test/RSH");
    diskJoinNested("Test/R", "Test/S", "Test/RS");

	short tabRS[SIZ_M];
	printf("Nested Loop : ");
	int r = readTabValue("Test/RS/RSN0.txt", tabRS);
	if(tabRS[0] == 4 && r == 1){
		printf("ok\n");
	}else{
		printf("failed\n");
	}

	printf("Grace Hash Join : ");
	r = readTabValue("Test/RSH/RSH0.txt", tabRS);
	if(tabRS[0] == 4 && r == 1){
		printf("ok\n");
	}else{
		printf("failed\n");
	}
	printf("\n\n");

}
