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

void afficherListe(char* label, List l);

List creerElement(char ch);

int verifElement(List l, char ch);

void ajoutListe(List* l, char ch);

void freeList(List l);


#endif //HUFFMAN_DATASTRUCTURES_H
