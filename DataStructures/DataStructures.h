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

void afficherListe(char* label, Element* l);

Element* creerElement(char ch);

void supprimerElement(Element** l, char ch);

int verifElement(Element* l, char ch);

Element* elementMinimum(Element* l);

void ajoutListe(Element** l, char ch);

void freeList(Element* l);


#endif //HUFFMAN_DATASTRUCTURES_H
