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

#include "LibBT.h"
#include "relation.h"
#include "diskIO.h"


void display(Node* rac, int nb){
	if(rac != NULL){
		int i;
		for(i=0;i<nb; i++){
			printf("   ");
		}
		printf("%d %d\n", rac->value1, rac->value2);
		if(rac->isLeaf != 1){
			display((Node*)rac->left, nb+1);
			display((Node*)rac->middle, nb+1);
			display((Node*)rac->right, nb+1);
		}
	}
}

void init(Node** r){
	Node* rac = malloc(sizeof( Node)); // node vide qui me sert de base
	if(rac == NULL) { exit(-1); }
	rac->isLeaf = 1;
	rac->value1 = -1;
	rac->value2 = -1;
	rac->s1 = -1;
	rac->s2 = -1;
	rac->s3 = -1;
	rac->level = 0;
	rac->indic = 0;
	rac->left = NULL;
	rac->right = NULL;
	rac->middle = NULL;
	rac->father = NULL;
	*r = rac;
}

Node* create(Node* rac, char *name){
	init(&rac);
	int i;
	int n = countFileInDirectory(name);
	for(i = 0; i < n; i++){
		char *file = concateneNameFile(name, NULL, i);
		insertBulkData(i, rac, file); // pour chaque fichier  je l'ajoute à ma racine
	}
	return rac;
}

int insertBulkData(short i, Node *rac, char* file){
	if(rac == NULL){
		return -1;
	}
	if(rac->isLeaf){
		short tab[SIZ_M];
		tab[0] = 0;
		if(readFirst(file, tab) == 0){
			return -1;
		}
		if(rac->s1 == -1){
			rac->s1 = i;
		} else if (rac->s2 == -1) {
			rac->value1 = tab[0];
			rac->s2 = i;
		} else if (rac->s3 == -1){
			rac->value2 = tab[0];
			rac->s3 = i;
		} else {
			if(rac->father == NULL){
				Node *l = NULL;
				init(&l);
				Node *m =NULL;
				init(&m);

				l->value1 = rac->value1;
				l->s1 = rac->s1;
				l->s2 = rac->s2;
				l->father = (struct Node*)rac;
				l->level = rac->level;
				l->indic = rac->indic;

				m->value1 = tab[0];
				m->s1 = rac->s3;
				m->s2 = i;
				m->father = (struct Node*)rac;
				m->level = rac->level;
				m->indic = (rac->indic)+1;

				rac->isLeaf = 0;
				rac->value1 = rac->value2;
				rac->value2 = -1;
				rac->s1 = -1;
				rac->s2 = -1;
				rac->s3 = -1;
				rac->left = (struct Node*)l;
				rac->middle = (struct Node*)m;
				rac->level = (rac->level)+1;
				rac->indic = 0;

			} else {
				return 1;
			}
		}
	} else {
		if(rac->value2 == -1){
			int rc = insertBulkData( i, (Node *)rac->middle, file);
			if(rc){

				short tab[SIZ_M];
				tab[0] = 0;
				if(readFirst(file, tab) == 0){
					return -1;
				}

				Node * r = NULL;
				init(&r);
				r->value1 = tab[0];
				r->s1 = ((Node*)rac->middle)->s3;
				r->s2 = i;
				r->father = (struct Node*)rac;
				r->level = ((Node*)rac->middle)->level;
				r->indic = (((Node*)rac->middle)->indic)+1;
				rac->value2 = ((Node*)rac->middle)->value2;
				rac->right = (struct Node*)r;

				((Node*)rac->middle)->value2 = -1;
				((Node*)rac->middle)->s3 = -1;
			}
		} else {
			int rc = insertBulkData(i, (Node *)rac->right, file);
			if(rc){
				if(rac->father == NULL){
					Node *l = NULL;
					init(&l);
					Node *m = NULL;
					init(&m);
					Node *gc = NULL;
					init(&gc);

					short tab[SIZ_M];
					tab[0] = 0;
					if(readFirst(file, tab) == 0){
						return -1;
					}

					gc->value1 = tab[0];
					gc->s1 = ((Node*)rac->right)->s3;
					gc->s2 = i;
					gc->father = (struct Node*)m;
					gc->level = ((Node*)rac->right)->level;
					gc->indic = (((Node*)rac->right)->indic)+1;

					l->isLeaf = 0;
					l->value1 = rac->value1;
					l->left = rac->left;
					l->middle = rac->middle;
					l->father = (struct Node*)rac;
					l->level = rac->level;
					l->indic = rac->indic;
					((Node*)l->left)->father = (struct Node*)l;
					((Node*)l->middle)->father = (struct Node*)l;

					m->isLeaf = 0;
					m->value1 = ((Node*)rac->right)->value2;
					m->left = rac->right;
					m->middle = (struct Node*)gc;
					m->father = (struct Node*)rac;
					m->level = rac->level;
					m->indic = (rac->indic)+1;
					((Node*)m->left)->father = (struct Node*)m;
					((Node*)m->middle)->father = (struct Node*)m;

					((Node*)rac->right)->value2 = -1;
					((Node*)rac->right)->s3 = -1;

					rac->isLeaf = 0;
					rac->value1 = rac->value2;
					rac->value2 = -1;
					rac->left = (struct Node*)l;
					rac->middle = (struct Node*)m;
					rac->right = NULL;
					rac->level = (rac->level)+1;
					rac->indic = 0;
					rac->s3 = -1;

				} else {
					return 1;
				}
			}
		}
	}
	return 0;
}

Node* loadInMemory(Node *rac, char* name){
	name = getRac(name, "0_0");
	Node* n = NULL;
	init(&n);
	n = parse(n, name);
	return n;
}

void storeToDisk(Node *rac, char* name){
	if(rac->isLeaf == 1){
		ecrire_leaf(rac);
	}else{
		ecrire_node(rac);
		if(rac->left != NULL){
			storeToDisk((Node *)(rac->left), name);
		}
		if(rac->middle != NULL){
			storeToDisk((Node *)(rac->middle), name);
		}
		if(rac->right != NULL){
			storeToDisk((Node *)(rac->right), name);
		}
	}
}
