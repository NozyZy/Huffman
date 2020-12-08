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
 * @brief Structure pour un element du noeud
 * 
 */
typedef struct ElementNode{
    Arbre data;
    struct ElementNode* suivant;
}ElementNode;

/**
 * @brief Structure pour la queue d'un arbre
 * 
 */
typedef struct Queue{
    struct ElementNode* last;
}Queue;

Noeud* creerNoeud(char ch, size_t occ, char* bin);
void afficherArbreOcc(Noeud* a);
void afficherArbreBin(Noeud* a);
void freeArbre(Noeud* a);

void addNodeAVLch(Noeud** AVL, Noeud* tmp);
void addNodeBSTch(Noeud** AVL, Noeud* tmp);
void addNodeBSTocc(Noeud** AVL, Noeud* tmp);

size_t depth(Noeud* a);
int getBF(Noeud* a);
void leftRotation(Noeud** a);
void rightRotation(Noeud** a);
void balance(Noeud** a);

Queue* createQueue();
int isEmptyQueue(Queue* q);
void pushQueue(Queue* q, Arbre val);
Arbre popQueue(Queue* q);
int sizeQueue(ElementNode* q);
Arbre getMinQueues(Queue* q1, Queue* q2);

#endif //HUFFMAN_DATASTRUCTURES_H
