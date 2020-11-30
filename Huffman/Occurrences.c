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