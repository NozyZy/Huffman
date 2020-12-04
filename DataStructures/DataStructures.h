#include <stdlib.h>
#include <stdio.h>

#ifndef HUFFMAN_DATASTRUCTURES_H
#define HUFFMAN_DATASTRUCTURES_H

typedef struct Element {
    char ch;
    int occ;
    struct Element* suivant;
}Element;
typedef Element* Liste;

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

Noeud* creerNoeud(char ch, size_t occ, char* bin);
void afficherArbreOcc(Noeud* a);
void afficherArbreBin(Noeud* a);
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

void afficherListe(char* label, Element* l);
Element* creerElement(char ch);
void ajoutListe(Element** l, char ch);
size_t tailleListe(Liste l);
void freeList(Element* l);

void afficherTabNoeuds(Arbre* tab, size_t size, char* label);

#endif //HUFFMAN_DATASTRUCTURES_H
