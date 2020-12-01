#include "DataStructures.h"

void afficherListe(char* label, Element*  l) {
    if (label) printf("%s : ", label);
    while (l) {
        printf("->(%c|%d)", l->ch, l->occ);
        l = l->suivant;
    }
    printf("->x\n");
}

Element * creerElement(char ch) {
    Element* lNew = (Element*)malloc(sizeof(Element));
    lNew->ch = ch;
    lNew->occ = 1;
    lNew->suivant = NULL;
    return lNew;
}

void ajoutListe(Element** l, char ch) {
    if (*l) {
        if ((*l)->ch == ch) (*l)->occ = (*l)->occ + 1;   // on a trouvé le caractère dans la liste
        else ajoutListe(&((*l)->suivant), ch);    // rien a signaler, le caractère n'est pas encore listé, on regarde pour le suivant
    }
}

size_t tailleListe(Liste l){
    if (!l) return 0;
    return 1 + tailleListe(l->suivant);
}

void freeList(Element* l) {
    if (l) {
        freeList(l->suivant);
        free(l);
    }
}


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
            printf("A gauche de (%c|%d) : \t", a->ch, a->occ);
            afficherArbreOcc(a->sag);
        }
        else printf("\t");
        if (a->sad) {
            printf("\tA droite de (%c|%d) : \t", a->ch, a->occ);
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

void afficherTabNoeuds(Arbre* tab, size_t size, char* label){
    printf("%s", label);
    if (*tab && size > 0) {
        size_t i = 0;
        for (i = 0; i < size; i++) {
            printf("(%c|%d|%s)->", tab[i]->ch, tab[i]->occ, tab[i]->bin);
        }
    }
}