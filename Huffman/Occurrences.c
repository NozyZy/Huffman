#include "Occurrences.h"

void createAVLcaractere(Noeud** AVL, char* content, size_t taille) {
    size_t i = 0;
    for (i = 0; i < taille; i++) {
        Noeud* tmp = creerNoeud(content[i], 1);
        if (tmp) {
            addNodeAVL(AVL, tmp);
        }
    }
}