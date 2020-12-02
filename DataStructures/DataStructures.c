#include "DataStructures.h"

void afficherListe(char* label, List  l) {
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

int verifElement(List l, char ch) {
    if (!l) return 0;									// le caractère n'est pas listé
    else {
        if (l->ch == ch) return 1;						// on a trouvé le caractère dans la liste
        else return verifElement((l->suivant), ch);		// rien a signaler, le caractère n'est pas encore listé, on regarde pour le suivant
    }
}

void supprimerElement(Element** l, char ch) {
    List prec = *l;
    List cour = *l;
    List rm = NULL;
    while (cour) {
        if (cour->ch == ch) {
            if (*l == cour) {
                rm = cour;
                *l = cour->suivant;
                cour = *l;
                free(rm);
            }
            else {
                prec->suivant = cour->suivant;
                cour = prec->suivant;
            }
        }
        else {
            prec = cour;
            cour = cour->suivant;
        }
    }
}

void ajoutListe(List* l, char ch) {
    if (*l) {
        if ((*l)->ch == ch) (*l)->occ = (*l)->occ + 1;   // on a trouvé le caractère dans la liste
        else ajoutListe(&((*l)->suivant), ch);    // rien a signaler, le caractère n'est pas encore listé, on regarde pour le suivant
    }
}

void freeList(List l) {
    if (l) {
        freeList(l->suivant);
        free(l);
    }
}

Noeud* creerNoeud(char ch, size_t occ) {
    Noeud* a = (Noeud*)malloc(sizeof(Noeud));
    a->ch = ch;
    a->occ = occ;
    a->sag = NULL;
    a->sad = NULL;
    return a;
}

void afficherArbre(Noeud* a) {
    if (a) {
        printf("[%c] : [%d]", a->ch, a->occ);
        if (a->sag) {
            printf("\nA gauche de (%c|%d) : \t", a->ch, a->occ);
            afficherArbre(a->sag);
        }
        else printf("\t");
        if (a->sad) {
            printf("\tA droite de (%c|%d) : \t", a->ch, a->occ);
            afficherArbre(a->sad);
        }
    }
}


void freeArbre(Noeud* a) {
    if (a) {
        if (a->sad) freeArbre(a->sad);
        if (a->sag) freeArbre(a->sag);
        free(a);
    }
}