#include "DataStructures.h"

Noeud* creerNoeud(char ch, size_t occ, char* bin) {
    int i = 0;
    while (bin[i] == '1' || bin[i] == '0'){
        i++;
    }

    Noeud* a = (Noeud*)malloc(sizeof(Noeud));
    a->ch = ch;
    a->occ = occ;
    a->bin = (char*)malloc(i*sizeof(char));
    a->bin = bin;
    a->sag = NULL;
    a->sad = NULL;
    return a;
}

void afficherArbreOcc(Noeud* a) {
    if (a) {
        printf("[%c] : [%d]\n", a->ch, a->occ);
        if (a->sag) {
            printf("A gauche de (%c|%d) : ", a->ch, a->occ);
            afficherArbreOcc(a->sag);
        }
        if (a->sad) {
            printf("A droite de (%c|%d) : ", a->ch, a->occ);
            afficherArbreOcc(a->sad);
        }
    }
}

void afficherArbreBin(Noeud* a) {
    if (a) {
        printf("[%c] : [%s]\n", a->ch, a->bin);
        if (a->sag) {
            printf("A gauche de (%c|%s) : ", a->ch, a->bin);
            afficherArbreBin(a->sag);
        }
        if (a->sad) {
            printf("A droite de (%c|%s) : ", a->ch, a->bin);
            afficherArbreBin(a->sad);
        }
    }
}

void freeArbre(Noeud* a) {
    if (a) {
        freeArbre(a->sad);
        freeArbre(a->sag);
        free(a);
    }
}
