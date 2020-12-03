#include <stdlib.h>
#include <stdio.h>

#ifndef HUFFMAN_DATASTRUCTURES_H
#define HUFFMAN_DATASTRUCTURES_H


typedef struct Element {
	char ch;
	int occ;
	struct Element* suivant;
}Element;

typedef struct Noeud {
	char ch;
	int occ;
	char* bin;
	struct Noeud* sad;
	struct Noeud* sag;
}Noeud;

void afficherArbre(Noeud* a);
void addNodeBSTch(Noeud** AVL, Noeud* tmp);
size_t depth(Noeud* a);
int getBF(Noeud* a);
void leftRotation(Noeud** a);
void rightRotation(Noeud** a);
void balance(Noeud** a);
void addNodeAVL(Noeud** AVL, Noeud* tmp);
Noeud* creerNoeud(char ch, size_t occ);
void freeArbre(Noeud* a);

#endif //HUFFMAN_DATASTRUCTURES_H
