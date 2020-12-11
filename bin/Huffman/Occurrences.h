/**
 * @file Occurrences.h
 * @author Gianlucca Annichiarico (agianlucca@gmail.com)
 * @brief Headers des fonctions des occurrences
 * @version 0.1
 * @date 2020-12-06
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include "../InteractWithFile/InteractWithFile.h"
#include "../DataStructures/DataStructures.h"

#ifndef HUFFMAN_OCCURRENCES_H
#define HUFFMAN_OCCURRENCES_H

extern  void    createAVLcaractere  (Arbre* AVL, char* content, size_t taille);
extern  void    addNodeAVLocc       (Arbre* AVL, Noeud * tmp);
extern  void    createAVLoccurrence (Arbre* AVL, Arbre a);
extern  void    creerOccQueue       (Arbre AVL, Queue* q);

#endif //HUFFMAN_OCCURRENCES_H
