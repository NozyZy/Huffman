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