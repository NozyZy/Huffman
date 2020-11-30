#include "Occurrences.h"

Element* creerListeOccurrences(const char* content, size_t nbCaractere) {
    if (nbCaractere == 0) return NULL;
    else {
        Element* lpremiere = (Element*)malloc(sizeof(Element)) ;
        Element* l;
        lpremiere->ch = content[0];					        // initialisation du premier element
        lpremiere->occ = 1;
        lpremiere->suivant = NULL;
        l = lpremiere;
        int i = 1;										    // compter de 1 à nbCaractere - 1
        while (i != nbCaractere) {
            char ch = content[i];

            if (ch != '\0') {
                if (verifElement(lpremiere, ch) == 1) {		// on doit ajouter une occurrence
                    ajoutListe(&lpremiere, ch);
                }
                else {										// on doit l'ajouter à la liste
                    l->suivant = creerElement(ch);
                    l = l->suivant;
                }
            }
            i = i+1;
        }
        return lpremiere;
    }
}

Element* elementMinimum(List l) {
    Element* charMinimum = (Element*)malloc(sizeof(Element));
    charMinimum->ch = l->ch;
    charMinimum->occ = l->occ;
    while (l) {
        if (l->occ < charMinimum->occ) {
            charMinimum->ch = l->ch;
            charMinimum->occ = l->occ;
        }
        l = l->suivant;
    }
    return charMinimum;
}

Arbre creeArbreOccurrences(List l) {
    Arbre a = creerNoeud('\0', 0);

    Element* lEnCours;
    lEnCours = l;
    if (!l) return NULL;
    else {
        Arbre aPremiere = creerNoeud('\0', 0);

        List tmp = elementMinimum(lEnCours);
        Arbre aDroit = creerNoeud(tmp->ch, tmp->occ);
        supprimerElement(&lEnCours, tmp->ch);

        tmp = elementMinimum(lEnCours);
        Arbre aGauche = creerNoeud(tmp->ch, tmp->occ);
        supprimerElement(&lEnCours, tmp->ch);

        aPremiere->sad = aDroit;
        aPremiere->sag = aGauche;
        aPremiere->occ = (aPremiere->sad->occ) + (aPremiere->sag->occ);

        a->sad = aPremiere;
    }
    while (lEnCours->suivant) {
        List tmp = elementMinimum(lEnCours);
        Arbre newA = creerNoeud(tmp->ch, tmp->occ);
        supprimerElement(&lEnCours, tmp->ch);

        Arbre branchA = creerNoeud('\0', (newA->occ) + (a->sad->occ));
        branchA->sad = a->sad;
        branchA->sag = newA;
        a->sad = branchA;
    }
    List tmp = elementMinimum(lEnCours);
    Arbre newA = creerNoeud(tmp->ch, tmp->occ);
    supprimerElement(&lEnCours, tmp->ch);

    a->occ = (newA->occ) + (a->sad->occ);
    a->sad = a->sad;
    a->sag = newA;
    return a;
}