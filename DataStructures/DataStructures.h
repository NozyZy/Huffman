#include <stdlib.h>
#include <stdio.h>

#ifndef HUFFMAN_DATASTRUCTURES_H
#define HUFFMAN_DATASTRUCTURES_H



typedef struct Noeud {
	char ch;
	int occ;
	char* bin;
	struct Noeud* sad;
	struct Noeud* sag;
}Noeud;
typedef Noeud* Arbre;

typedef struct ElementNode{
    Arbre data;
    struct ElementNode* suivant;
}ElementNode;

typedef struct Queue{
    struct ElementNode* last;
}Queue;

void afficherArbreOcc(Noeud* a);
void afficherArbreBin(Noeud* a);
Noeud* creerNoeud(char ch, size_t occ, char* bin);
void freeArbre(Noeud* a);

void addNodeAVL(Noeud** AVL, Noeud* tmp);
void addNodeBSTch(Noeud** AVL, Noeud* tmp);
void addNodeBSTocc(Noeud** AVL, Noeud* tmp);

size_t depth(Noeud* a);
int getBF(Noeud* a);
void leftRotation(Noeud** a);
void rightRotation(Noeud** a);
void balance(Noeud** a);

Queue* createQueue();
int isEmptyQueue(Queue* q);
void pushQueue(Queue* q, Arbre val);
Arbre popQueue(Queue* q);
int sizeQueue(ElementNode* q);
Arbre getMinQueues(Queue* q1, Queue* q2);

#endif //HUFFMAN_DATASTRUCTURES_H
