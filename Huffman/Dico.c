#include "Dico.h"

int verifElement(Element* l, char ch) {
    if (!l) return 0;									// le caractère n'est pas listé
    else {
        if (l->ch == ch) return 1;						// on a trouvé le caractère dans la liste
        else return verifElement(l->suivant, ch);		// rien a signaler, le caractère n'est pas encore listé, on regarde pour le suivant
    }
}

Element* creerListeOccurrences(const char* content, size_t nbCaractere) {
    if (nbCaractere == 0) return NULL;
    else {
        Element* lpremiere = creerElement(content[0]);
        Element* l;
        l = lpremiere;
        size_t i;										    // compter de 1 à nbCaractere - 1
        for (i = 1; i < nbCaractere; i++) {
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
        }
        return lpremiere;
    }
}

void triTabNodes(Noeud** tab, size_t size){
    if (tab && *tab && size > 0) {
        int i = 0, j = 0, curr;
        Noeud *tmp;
        for (i = 0; i < size - 1; i++) {
            curr = i;

            for (j = i + 1; j < size; j++) {
                if (tab[curr]->occ > tab[j]->occ) curr = j;
            }
            if (curr != i) {
                tmp = tab[i];
                tab[i] = tab[curr];
                tab[curr] = tmp;
            }
        }
    }
}


void addNodeBSTocc(Arbre* a, Arbre add){
    if (!(*a)) *a = creerNoeud(add->ch, add->occ, add->bin);
    else if (add->occ < (*a)->occ) addNodeBSTocc(&((*a)->sag), add);
    else if (add->occ > (*a)->occ) addNodeBSTocc(&((*a)->sad), add);
}

void addNodeBSTch(Arbre* a, Arbre add){
    if (!(*a)) *a = add;
    else if (add->ch < (*a)->ch) addNodeBSTch(&((*a)->sag), add);
    else if (add->ch > (*a)->ch) addNodeBSTch(&((*a)->sad), add);
}

int getMinNoEmptyBST(Arbre a){
    if(!(a->sag)) return a->occ;
    return getMinNoEmptyBST(a->sag);
}

size_t depth(Arbre a){
    if(!a) return 0;
    else {
        size_t dl = depth(a->sag);
        size_t dr = depth(a->sad);
        if (dl > dr) return 1 + dl;
        else return 1 + dr;
    }
}

int getBF(Arbre a){
    if (!a) return 0;
    return (int)(depth(a->sad) - depth(a->sag));
}

void leftRotation(Arbre* a){
    if (*a){
        Arbre temp = (*a)->sad;
        (*a)->sad = temp->sag;
        temp->sag = *a;
        *a = temp;
    }
}

void rightRotation(Arbre* a){
    if (*a){
        Arbre temp = (*a)->sag;
        (*a)->sag = temp->sad;
        temp->sad = *a;
        *a = temp;
    }
}

void balance(Arbre* a){
    if (*a){
        balance(&((*a)->sag));
        balance(&((*a)->sad));

        int BF = getBF(*a);
        if (BF <= -2) {
            if (getBF((*a)->sag) > 0) leftRotation(&((*a)->sag));
            rightRotation(a);
        }else if (BF >= 2) {
            if (getBF((*a)->sad) <= 0) rightRotation(&((*a)->sad));
            leftRotation(a);
        }
    }
}

void addNodeAVL(Arbre* a, Arbre add){
    addNodeBSTch(a, add);
    balance(a);
}

void createAVLDico(Arbre* dico, Arbre* addTab, size_t size){
    size_t i = 0;
    for(i = 0; i < size; i ++){
        addNodeAVL(dico, addTab[i]);
    }
}