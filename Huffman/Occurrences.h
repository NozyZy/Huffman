#include "InteractWithFile.h"
#include "DataStructures.h"

#ifndef HUFFMAN_OCCURRENCES_H
#define HUFFMAN_OCCURRENCES_H

Element* creerListeOccurrences(const char* content, size_t nombreCaractere);

Element* elementMinimum(List l);

Noeud* creeArbreOccurrences(List l);


#endif //HUFFMAN_OCCURRENCES_H
