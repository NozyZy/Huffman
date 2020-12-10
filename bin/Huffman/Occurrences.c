#include "Occurrences.h"

/**
 * @brief Crée un AVL trié par caractères
 * 
 * @param AVL 
 * @param content 
 * @param taille 
 */
void createAVLcaractere(Arbre* AVL, char* content, size_t taille) {
    size_t i = 0;
    for (i = 0; i < taille; i++) {
        if (content[i] != '\0') {
            Noeud *tmp = creerNoeud(content[i], 1, NULL);
            if (tmp) addNodeAVLch(AVL, tmp);
        }
    }
}

/**
 * @brief Ajoute un noeud à un AVL trié en occurrences
 * 
 * @param AVL 
 * @param tmp 
 */
void addNodeAVLocc(Arbre* AVL, Noeud * tmp) {
    if (tmp) {
        addNodeBSTocc(AVL, tmp);
        balance(AVL);
    }
}
/**
 * @brief Crée un AVL trié en occurrences
 * 
 * @param AVL 
 * @param a 
 */
void createAVLoccurrence(Arbre* AVL, Arbre a) {
    if (a) {
        createAVLoccurrence(AVL, a->sag);
        Arbre tmp = creerNoeud(a->ch, a->occ, NULL);
        if (tmp) addNodeAVLocc(AVL, tmp);
        createAVLoccurrence(AVL, a->sad);
    }
}

/**
 * @brief Crée une file de noeuds triés par occurrences, grâce à l'AVL
 * 
 * @param AVL 
 * @param q 
 */
void creerOccQueue(Arbre AVL, Queue* q) {
    if (AVL) {
        creerOccQueue(AVL->sag, q);
        pushQueue(q, AVL);
        creerOccQueue(AVL->sad, q);
    }
}