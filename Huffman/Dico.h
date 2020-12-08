#include "HuffmanTree.h"

#ifndef HUFFMAN_DICO_H
#define HUFFMAN_DICO_H

void createAVLDico(Arbre* a, Arbre add);
void createBinCode(Arbre huffmanTree, char* binCode, int index);
void printDicoFile(Arbre dico, FILE* fDico);

#endif //HUFFMAN_DICO_H
