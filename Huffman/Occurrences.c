#include "Occurrences.h"

void createAVLcaractere(Noeud** AVL, char* content, size_t taille) {
    size_t i = 0;
    for (i = 0; i < taille; i++) {
        if (content[i] != '\0') {
            Noeud *tmp = creerNoeud(content[i], 1, NULL);
            if (tmp) {
                addNodeAVLch(AVL, tmp);
            }
        }
    }
}

void triNodesOccurence(Noeud** AVL) {
    if (*AVL) {
        if (!(*AVL)->sad) {
            rightRotation(&((*AVL))->sad);
        }
        if (!(*AVL)->sag) {
            leftRotation(&((*AVL))->sag);
        }
        if ((*AVL)->sag) {
            triNodesOccurence(&((*AVL)->sag));

            if ((*AVL)->occ < (*AVL)->sag->occ) {
                rightRotation(AVL);
            }
        }
        if ((*AVL)->sad) {
            triNodesOccurence(&((*AVL)->sad));

            if ((*AVL)->occ < (*AVL)->sad->occ) {
                leftRotation(AVL);
            }
        }
    }
}

void addNodeAVLocc(Noeud **AVL, Noeud * tmp) {
    if (tmp) {
        addNodeBSTocc(AVL, tmp);
        balance(AVL);
    }
}

void createAVLoccurrence(Noeud** AVL, Noeud* a) {
    if (a) {
        createAVLoccurrence(AVL, a->sag);
        Noeud* tmp = creerNoeud(a->ch, a->occ, NULL);
        if (tmp) {
            addNodeAVLocc(AVL, tmp);
        }
        createAVLoccurrence(AVL, a->sad);
    }
}

void creerOccQueue(Arbre AVL, Queue* q) {
    if (AVL) {
        creerOccQueue(AVL->sag, q);
        pushQueue(q, AVL);
        creerOccQueue(AVL->sad, q);
    }
}