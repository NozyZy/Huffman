#include "Occurrences.h"

void createAVLcaractere(Noeud** AVL, char* content, size_t taille) {
    size_t i = 0;
    for (i = 0; i < taille; i++) {
        if (content[i] != '\0') {
            Noeud *tmp = creerNoeud(content[i], 1);
            if (tmp) {
                addNodeAVL(AVL, tmp);
            }
        }
    }
}

void creerOccQueue(Arbre AVL, Queue* q) {
    if (AVL) {
        creerOccQueue(AVL->sag, q);
        pushQueue(q, AVL);
        creerOccQueue(AVL->sad, q);
    }
}