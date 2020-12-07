/**
 * @file Dico.h
 * @author Gianlucca Annichiarico (agianlucca@gmail.com)
 * @brief Headers des fonctions du dictionnaire
 * @version 0.1
 * @date 2020-12-06
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include "HuffmanTree.h"

#ifndef HUFFMAN_DICO_H
#define HUFFMAN_DICO_H

void createAVLDico(Arbre* a, Arbre add);
void createBinCode(Arbre huffmanTree, char* binCode, int index);
void printDicoFile(Arbre dico, FILE* fDico);

#endif //HUFFMAN_DICO_H
