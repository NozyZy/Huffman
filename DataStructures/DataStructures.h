#include <stdlib.h>
#include <stdio.h>

#ifndef HUFFMAN_DATASTRUCTURES_H
#define HUFFMAN_DATASTRUCTURES_H

typedef struct Noeud {
    char ch;
    size_t occ;
    char* bin;
    struct Noeud* sad;
    struct Noeud* sag;
}Noeud;

typedef Noeud* Arbre;


void afficherArbreOcc(Noeud* a);
void afficherArbreBin(Noeud* a);
Noeud* creerNoeud(char ch, size_t occ, char* bin);
void freeArbre(Noeud* a);



#endif //HUFFMAN_DATASTRUCTURES_H
