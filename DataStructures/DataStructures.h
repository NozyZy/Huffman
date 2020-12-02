#include <stdlib.h>
#include <stdio.h>

#ifndef HUFFMAN_DATASTRUCTURES_H
#define HUFFMAN_DATASTRUCTURES_H

typedef struct Element {
    char ch;
    int occ;
    struct Element* suivant;
}Element;
typedef Element* List;

typedef struct Noeud {
    char ch;
    int occ;
    struct Noeud* sad;
    struct Noeud* sag;
}Noeud;
typedef Noeud* Arbre;

void afficherListe(char* label, List l);

Element* creerElement(char ch);

int verifElement(List l, char ch);

void supprimerElement(Element** l, char ch);

void ajoutListe(List* l, char ch);

void freeList(List l);


void afficherArbre(Arbre a);

Noeud* creerNoeud(char ch, size_t occ);

void freeArbre(Arbre a);


#endif //HUFFMAN_DATASTRUCTURES_H
