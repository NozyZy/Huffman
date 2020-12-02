#include "Dico.h"

void addNodeBSTocc(Arbre* a, Arbre add){
    if (!(*a)) *a = creerNoeud(add->ch, add->occ, add->bin);
    else if (add->occ < (*a)->occ) addNodeBSTocc(&((*a)->sag), add);
    else if (add->occ > (*a)->occ) addNodeBSTocc(&((*a)->sad), add);
}

void addNodeBSTch(Arbre* a, Arbre add){
    if (!(*a)) *a = creerNoeud(add->ch, add->occ, add->bin);
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

void createAVLDico(Arbre* dico, Arbre add){
    if (add) {
        if (add->ch != '\0') addNodeAVL(dico, add);
        else {
            createAVLDico(dico, add->sag);
            createAVLDico(dico, add->sad);
        }
    }
}