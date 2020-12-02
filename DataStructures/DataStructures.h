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
    size_t occ;
    char* bin;
    struct Noeud* sad;
    struct Noeud* sag;
}Noeud;

typedef Noeud* Arbre;


void afficherListe(char* label, Element* l);
Element* creerElement(char ch);
void ajoutListe(Element** l, char ch);
size_t tailleListe(Liste l);
void freeList(Element* l);

void afficherArbreOcc(Noeud* a);
void afficherArbreBin(Noeud* a);
Noeud* creerNoeud(char ch, size_t occ, char* bin);
void freeArbre(Noeud* a);

void afficherTabNoeuds(Arbre* tab, size_t size, char* label);

#endif //HUFFMAN_DATASTRUCTURES_H
