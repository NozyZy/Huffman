#include "DataStructures.h"

/**
 * @brief Affiche l'arbre avec ses occurrences
 *
 * @param a
 */
void afficherArbreOcc(Arbre a) {

}

/**
 * @brief Affiche l'arbre avec ses codes binaires
 *
 * @param a
 */
void afficherArbreBin(Arbre a) {

}

/**
 * @brief Crée un noeud alloué dynamiquement
 *
 * @param ch
 * @param occ
 * @param bin
 * @return Arbre
 */
Arbre creerNoeud(char ch, size_t occ, char* bin) {
    return NULL;
}

/**
 * @brief Libère l'arbre
 *
 * @param a
 */
void freeArbre(Arbre a) {

}

/**
 * @brief Ajoute un noeud dans l'AVL
 *
 * @param AVL
 * @param tmp
 */
void addNodeAVLch(Arbre* AVL, Arbre tmp) {

}

/**
 * @brief Ajoute un noeud dans l'abre de tri (alphabétique)
 *
 * @param AVL
 * @param tmp
 */
void addNodeBSTch(Arbre* AVL, Arbre tmp) {

}

/**
 * @brief Ajoute un noeud dans l'arbre de tri (Occurrence)
 *
 * @param AVL
 * @param tmp
 */
void addNodeBSTocc(Arbre* AVL, Arbre tmp) {

}

/**
 * @brief Renvoie la prodonfeur de l'arbre (0 si l'arbre n'existe pas)
 *
 * @param a
 * @return size_t
 */
size_t depth(Arbre a) {
    return 0;
}

/**
 * @brief Renvoie le balance factor de l'AVL
 *
 * @param a
 * @return int
 */
int getBF(Arbre a) {
    return 0;
}

/**
 * @brief Rotation gauche de noeuds
 *
 * @param a
 */
void leftRotation(Arbre* a) {

}

/**
 * @brief Rotation droite de noeuds
 *
 * @param a
 */
void rightRotation(Arbre* a) {

}

/**
 * @brief Tant que le Balance Factor > 2 Réequillibre l'arbre : avoir un AVL
 *
 * @param a
 */
void balance(Arbre* a) {

}

/**
 * @brief Crée une file allouée dynamiquement
 *
 * @return Queue*
 */
Queue* createQueue(){
    return NULL;
}

/**
 * @brief Renvoie l'état de la file, vidée ou non
 *
 * @param q
 * @return int
 */
int isEmptyQueue(Queue* q){
    return 0;
}

/**
 * @brief Enfile un noeud
 *
 * @param q
 * @param val
 */
void pushQueue(Queue* q, Arbre val) {

}

/**
 * @brief Défile un noeud
 *
 * @param q
 * @return Arbre
 */
Arbre popQueue(Queue* q){
    return NULL;
}

/**
 * @brief Renvoie la taille de la file
 *
 * @param q
 * @return int
 */
int sizeQueue(ElementNode* q) {
    return 0;
}

/**
 * @brief Compare et choisi le noeud avec l'occurrence la plus petite
 *
 * @param q1
 * @param q2
 * @return Arbre
 */
Arbre getMinQueues(Queue* q1, Queue* q2) {
    return NULL;

}