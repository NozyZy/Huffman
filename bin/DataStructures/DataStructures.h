/**
 * \mainpage Annichiarico Gianlucca, Gomez Valère, Sanglar Lisa et Quentin Vincent
 * \section  Présentation
 * Le projet correspond à un logiciel de compression de texte sans perte de données, se basant sur le principe de l’arbre de Huffman. Il s’agit de compresser le contenu d’un fichier texte converti en bit, afin de réécrire un code binaire encodé, qui prend moins de place que l’original. L’application devra, sur une interface console, demander à l’utilisateur de lui donner le chemin d’accès à un fichier d’origine, pour lui en créer un nouveau compressé, ainsi qu’un fichier dictionnaire permettant la décompression. Il faudra aussi présenter à l’utilisateur le taux de réussite de la compression (si des caractères n’ont pas réussi à être compressés), ainsi que le taux de compréhension (rapport du nombre de bits d’origine sur nombre de bits d’arrivé). Ce logiciel a donc besoin de pouvoir interagir avec des fichiers extérieurs, tout en utilisant des structures de données adaptées à son bon fonctionnement. La première étape était donc de comprendre le sujet dans sa globalité, mais surtout ces quelques étapes cruciales nécessitant les structures de données, et par là nous entendons surtout la création de l’arbre de Huffman.
 * \n
 * \section Github
 * https://github.com/NozyZy/Huffman
 *
 *
 */

/**
 * @file DataStructures.h
 * @author Gianlucca Annichiarico (agianlucca@gmail.com)
 * @brief Headers des fonction des structures de données
 * @version 0.1
 * @date 2020-12-06
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include <stdlib.h>
#include <stdio.h>

#ifndef HUFFMAN_DATASTRUCTURES_H
#define HUFFMAN_DATASTRUCTURES_H

/**
 * @brief Structure pour un Noeud 
 * 
 */
typedef struct Noeud {
	char ch;
	int occ;
	char* bin;
	struct Noeud* sad;
	struct Noeud* sag;
}Noeud;
typedef Noeud* Arbre;

/**
 * @brief Structure pour un element Noeud d'une file
 * 
 */
typedef struct ElementNode{
    Arbre data;
    struct ElementNode* suivant;
}ElementNode;

/**
 * @brief Structure pour une file de Noeuds
 * 
 */
typedef struct Queue{
    struct ElementNode* last;
}Queue;

extern  Arbre   creerNoeud      (char ch, size_t occ, char* bin);
extern  void    afficherArbreOcc(Arbre a);
extern  void    afficherArbreBin(Arbre a);
extern  void    freeArbre       (Arbre a);

extern  void    addNodeAVLch    (Arbre* AVL, Arbre tmp);
extern  void    addNodeBSTch    (Arbre* AVL, Arbre tmp);
extern  void    addNodeBSTocc   (Arbre* AVL, Arbre tmp);

extern  size_t  depth           (Arbre a);
extern  int     getBF           (Arbre a);
extern  void    leftRotation    (Arbre* a);
extern  void    rightRotation   (Arbre* a);
extern  void    balance         (Arbre* a);

extern  Queue*  createQueue     (void);
extern  int     isEmptyQueue    (Queue* q);
extern  void    pushQueue       (Queue* q, Arbre val);
extern  Arbre   popQueue        (Queue* q);
extern  int     sizeQueue       (ElementNode* q);
extern  Arbre   getMinQueues    (Queue* q1, Queue* q2);

#endif //HUFFMAN_DATASTRUCTURES_H
