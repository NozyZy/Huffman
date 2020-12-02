#include "HuffmanTree.h"

#ifndef HUFFMAN_DICO_H
#define HUFFMAN_DICO_H

int verifElement(Element* l, char ch);
Element* creerListeOccurrences(const char* content, size_t nombreCaractere);
void triTabNodes(Noeud** tab, size_t size);

void addNodeBSTocc(Arbre* a, Arbre add);
void addNodeBSTch(Arbre* a, Arbre add);
int getMinNoEmptyBST(Arbre a);
size_t depth(Arbre a);
int getBF(Arbre a);
void leftRotation(Arbre* a);
void rightRotation(Arbre* a);
void balance(Arbre* a);
void addNodeAVL(Arbre* a, Arbre add);
void createAVLDico(Arbre* a, Arbre add);


#endif //HUFFMAN_DICO_H
