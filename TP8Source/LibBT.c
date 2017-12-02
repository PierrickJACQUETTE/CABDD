#include "LibBT.h"

//create tree - name -> directory where files are inserted
Node* create(char *name){
	Node *rac = malloc(sizeof(Node)); // node vide qui me sert de base
	//tab pour fichier 10 -> use size de config
	//countfile name- for on it
	char *file_i = "couille";
	insertBulkData(0, rac, file_i); // pour chaque fichier  je l'ajoute à ma racine
	return rac;
}

//shitstorm - opt -> mem or phy
void insertBulkData(int opt, Node *rac, char* namefile){
	//check if rac != null
	//namedir = "S"
	//j'insère à la racine  après :
		// - lire first pour chaque value
		// - [memoire] avoir lu tout le fichier, le stocker en mémoire et recup pour t1, t2, t3
		// - [disk] ti -> nom du file -> remove .txt
	return ;
}

void loadInMemory(Node *rac, char* name){

}

void storeToDisk(Node *rac, char* name){

}

int main(int argc, char const *argv[]) {
	printf("fuck you\n");
	return 0;
}
