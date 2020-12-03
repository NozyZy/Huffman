#include "InteractWithFile.h"
#include "DataStructures.h"

#ifndef HUFFMAN_OCCURRENCES_H
#define HUFFMAN_OCCURRENCES_H

void createAVLcaractere(Noeud** AVL, char* content, size_t taille);
void creerOccQueue(Arbre AVL, Queue* q);

#endif //HUFFMAN_OCCURRENCES_H
