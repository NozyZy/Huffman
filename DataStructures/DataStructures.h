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
void triNodesOccurence(Noeud** AVL);

Queue* createQueue();

int isEmptyQueue(Queue* q);

void pushQueue(Queue* q, Arbre val);

Arbre popQueue(Queue* q);
int sizeQueue(ElementNode* q);
Arbre getMinQueues(Queue* q1, Queue* q2);


typedef struct NoeudDico {
    char ch;
    size_t occ;
    char* bin;
    struct Noeud* sad;
    struct Noeud* sag;
}NoeudDico;


void afficherArbreOcc(Noeud* a);
void afficherArbreBin(NoeudDico* a);
NoeudDico* creerNoeudDico(char ch, size_t occ, char* bin);
void freeArbreDico(NoeudDico* a);



#endif //HUFFMAN_DATASTRUCTURES_H
