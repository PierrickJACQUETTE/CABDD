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

//create tree - name -> directory where files are inserted
Node* create(int opt, char *name){
	Node *rac = malloc(sizeof(Node)); // node vide qui me sert de base
	if(rac == NULL) { exit(-1); }
	rac->isLeaf = 1;
	rac->value1 = -1;
	rac->value2 = -1;
	rac->s1 = -1;
	rac->s2 = -1;
	rac->s3 = -1;
	rac->t1 = NULL;
	rac->t2 = NULL;
	rac->t3 = NULL;
	rac->father = NULL;
	rac->level = 0;
	rac->indic = 0;

	int i, n = countFileInDirectory(name);

	for(i = 0; i < n; i++){
		char *file = concateneNameFile(name,"",i);
		insertBulkData(opt, i, rac, file); // pour chaque fichier  je l'ajoute à ma racine
		printf("%s %d %d \n", file, rac->value1, rac->value2);
	}
	printf("\nrac %d %d\n", ((Node*)rac)->value1, ((Node*)rac)->value2);
	printf("rac left %d %d\n", ((Node*)((Node*)rac)->left)->value1, ((Node*)((Node*)rac)->left)->value2);
	printf("rac middle %d %d\n", ((Node*)((Node*)rac)->middle)->value1, ((Node*)((Node*)rac)->middle)->value2);
	printf("rac left left %d %d\n", ((Node*)((Node*)((Node*)rac)->left)->left)->value1, ((Node*)((Node*)((Node*)rac)->left)->left)->value2);
	printf("rac left middle %d %d\n", ((Node*)((Node*)((Node*)rac)->left)->middle)->value1, ((Node*)((Node*)((Node*)rac)->left)->middle)->value2);
	printf("rac middle left %d %d\n", ((Node*)((Node*)((Node*)rac)->middle)->left)->value1, ((Node*)((Node*)((Node*)rac)->middle)->left)->value2);
	printf("rac middle middle %d %d\n", ((Node*)((Node*)((Node*)rac)->middle)->middle)->value1, ((Node*)((Node*)((Node*)rac)->middle)->middle)->value2);

	printf("rac left left %d %d %d\n", ((Node*)((Node*)((Node*)rac)->left)->left)->s1, ((Node*)((Node*)((Node*)rac)->left)->left)->s2, ((Node*)((Node*)((Node*)rac)->left)->left)->s2);
	printf("rac left middle %d %d %d\n", ((Node*)((Node*)((Node*)rac)->left)->middle)->s1, ((Node*)((Node*)((Node*)rac)->left)->middle)->s2, ((Node*)((Node*)((Node*)rac)->left)->middle)->s2);
	printf("rac middle left %d %d %d\n", ((Node*)((Node*)((Node*)rac)->middle)->left)->s1, ((Node*)((Node*)((Node*)rac)->middle)->left)->s2, ((Node*)((Node*)((Node*)rac)->middle)->left)->s2);
	printf("rac middle middle %d %d %d\n", ((Node*)((Node*)((Node*)rac)->middle)->middle)->s1, ((Node*)((Node*)((Node*)rac)->middle)->middle)->s2, ((Node*)((Node*)((Node*)rac)->middle)->middle)->s3);

	return rac;
}

int insertBulkData(int opt, short i, Node *rac, char* file){
	if(rac == NULL){
		return -1;
	}

	if(rac->isLeaf){

		short tab[SIZ_M];
		if(opt){
			tab[0] = 0;
			if(readFirst(file, tab) == 0){
				return -1;
			}
		} else {
			if(readTabValue(file, tab) == 0){
				return -1;
			}
		}

		if(rac->t1 == NULL){
			if(opt){
				rac->s1 = i;
				rac->t1 = &i;
				// short k = *i;
				// rac->t1 = &k;
			} else {
				rac->t1 = tab;
			}
		} else if (rac->t2 == NULL) {
			rac->value1 = tab[0];
			if(opt){
				// short k = *i;
				// rac->t2 = &k;
				// printf("rac : %d et i : %d\n\n", (int)*(rac->t2), *i);
				rac->s2 = i;
				rac->t2 = &i;
			} else {
				rac->t2 = tab;
			}
		} else if (rac->t3 == NULL){
			rac->value2 = tab[0];
			if(opt){
				rac->s3 = i;
				rac->t3 = &i;
				// short k = *i;
				// rac->t3 = &k;
				// printf("rac : %d et i : %d\n\n", (int)(*rac->t2), *i);
			} else {
				rac->t3 = tab;
			}
		} else {
			if(rac->father == NULL){
				Node *l = malloc(sizeof(Node));
				if(l == NULL) { exit(-1); }
				Node *m = malloc(sizeof(Node));
				if(m == NULL) { exit(-1); }

				// printf("rac : %d et i : %d\n\n", (int)*(rac->t1), *i);
				// printf("rac : %d et i : %d\n\n", (int)*(rac->t2), *i);
				l->isLeaf = 1;
				l->value1 = rac->value1;
				l->value2 = -1;
				// short t1 = *(rac->t1);
				// l->t1 = &t1;
				// short t2 = *(rac->t2);
				// l->t2 = &t2;

				if(opt){
					l->s1 = rac->s1;
					l->s2 = rac->s2;
				} else {

				}
				l->father = (struct Node*)rac;
				l->level = rac->level;
				l->indic = rac->indic;

				// printf("%d", (int)(*(l->t2)));

				m->isLeaf = 1;
				m->value1 = tab[0];
				m->value2 = -1;
				// short t = *(rac->t3);
				// m->t1 = &t;
				// short t3 = *(rac->t3);
				// m->t1 = &t3;
				if(opt){
					// short k = *i;
					// m->t2 = &k;
					m->s1 = rac->s3;
					m->s2 = i;
				} else {
					m->t2 = tab;
				}
				m->father = (struct Node*)rac;
				m->level = rac->level;
				m->indic = (rac->indic)+1;

				rac->isLeaf = 0;
				rac->value1 = rac->value2;
				rac->value2 = -1;
				rac->s1 = -1;
				rac->s2 = -1;
				rac->s3 = -1;
				rac->t1 = NULL;
				rac->t2 = NULL;
				rac->t3 = NULL;
				rac->left = (struct Node*)l;
				rac->middle = (struct Node*)m;
				rac->level = (rac->level)+1;
				rac->indic = 0;

				// printf("%d", (int)(*((Node*)(rac->left))->t2));

			} else {
				return 1;
			}
		}
	} else {
		if(rac->value2 == -1){
			int rc = insertBulkData(opt, i, (Node *)rac->middle, file);
			if(rc){

				short tab[SIZ_M];
				if(opt){
					tab[0] = 0;
					if(readFirst(file, tab) == 0){
						return -1;
					}
				} else {
					if(readTabValue(file, tab) == 0){
						return -1;
					}
				}

				Node * r = malloc(sizeof(Node));
				if(r == NULL) { exit(-1); }

				r->isLeaf = 1;
				r->value1 = tab[0];
				// short t1 = *(((Node*)rac->middle)->t3);
				// r->t1 = &t1;

				if(opt){
					// short k = *i;
					// r->t2 = &k;
					r->s1 = ((Node*)rac->middle)->s3;
					r->s2 = i;
					r->t1 = &i;
					r->t2 = &i;
				} else {
					r->t2 = tab;
				}
				r->father = (struct Node*)rac;
				r->level = ((Node*)rac->middle)->level;
				r->indic = (((Node*)rac->middle)->indic)+1;

				rac->value2 = ((Node*)rac->middle)->value2;
				rac->right = (struct Node*)r;

				((Node*)rac->middle)->value2 = -1;
				// ((Node*)rac->middle)->t3 = NULL;
			}
		} else {
			int rc = insertBulkData(opt, i, (Node *)rac->right, file);
			if(rc){
				if(rac->father == NULL){
					Node *l = malloc(sizeof(Node));
					if(l == NULL) { exit(-1); }
					Node *m = malloc(sizeof(Node));
					if(m == NULL) { exit(-1); }
					Node *gc = malloc(sizeof(Node));
					if(gc == NULL) { exit(-1); }

					short tab[SIZ_M];
					if(opt){
						tab[0] = 0;
						if(readFirst(file, tab) == 0){
							return -1;
						}
					} else {
						if(readTabValue(file, tab) == 0){
							return -1;
						}
					}

					gc->isLeaf = 1;
					gc->value1 = tab[0];
					gc->value2 = -1;
					// short t1 = *(((Node*)rac->right)->t3);
					// gc->t1 = &t1;
					if(opt){
						// short k = *i;
						// gc->t2 = &k;
						gc->s1 = ((Node*)rac->right)->s3;
						gc->s2 = i;
						gc->t1 = &i;
						gc->t2 = &i;
					} else {
						gc->t2 = tab;
					}
					gc->father = (struct Node*)m;
					gc->level = ((Node*)rac->right)->level;
					gc->indic = (((Node*)rac->right)->indic)+1;

					l->isLeaf = 0;
					l->value1 = rac->value1;
					l->value2 = -1;
					l->left = rac->left;
					l->middle = rac->middle;
					l->father = (struct Node*)rac;
					l->level = rac->level;
					l->indic = rac->indic;

					m->isLeaf = 0;
					m->value1 = ((Node*)rac->right)->value2;
					m->value2 = -1;
					m->left = rac->right;
					m->middle = (struct Node*)gc;
					m->father = (struct Node*)rac;
					m->level = rac->level;
					m->indic = (rac->indic)+1;

					((Node*)rac->right)->value2 = -1;

					rac->isLeaf = 0;
					rac->value1 = rac->value2;
					rac->value2 = -1;
					rac->left = (struct Node*)l;
					rac->middle = (struct Node*)m;
					rac->right = NULL;
					rac->level = (rac->level)+1;
					rac->indic = 0;

				} else {
					return 1;
				}
			}
		}
	}
	return 0;
}

void loadInMemory(Node *rac, char* name){}

void storeToDisk(Node *rac, char* name){}
