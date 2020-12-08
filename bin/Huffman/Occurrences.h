/**
 * @file Occurrences.h
 * @author Gianlucca Annichiarico (agianlucca@gmail.com)
 * @brief Headers des fonctions des Occurrences
 * @version 0.1
 * @date 2020-12-06
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include "InteractWithFile.h"
#include "DataStructures.h"

#ifndef HUFFMAN_OCCURRENCES_H
#define HUFFMAN_OCCURRENCES_H

void createAVLcaractere(Noeud** AVL, char* content, size_t taille);
void triNodesOccurence(Noeud** AVL);
void addNodeAVLocc(Noeud **AVL, Noeud * tmp);
void createAVLoccurrence(Noeud** AVL, Noeud* a);
void creerOccQueue(Arbre AVL, Queue* q);

#endif //HUFFMAN_OCCURRENCES_H
