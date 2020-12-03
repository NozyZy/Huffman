#include "DataStructures.h"


Noeud* creerNoeud(char ch, size_t occ) {
	Noeud* a = (Noeud*)malloc(sizeof(Noeud));
	if (a) {
		a->ch = ch;
		a->occ = occ;
		a->sag = NULL;
		a->sad = NULL;
		return a;
	}
	else {
		exit(EXIT_FAILURE);
	}	
}

void addNodeAVL(Noeud** AVL, Noeud* tmp) {
    addNodeBSTch(AVL, tmp);
    balance(AVL);
}

void addNodeBSTch(Noeud** AVL, Noeud* tmp) {
	if (!(*AVL)) {
		(*AVL) = creerNoeud(tmp->ch, tmp->occ);
	}
	else if	((*AVL)->ch == tmp->ch) {
		(*AVL)->occ = (*AVL)->occ + 1;
		freeArbre(tmp);
	}
	else if (tmp->ch < (*AVL)->ch) {
		addNodeBSTch(&((*AVL)->sag), tmp);
	}
	else if ((*AVL)->ch < tmp->ch) {
		addNodeBSTch(&((*AVL)->sad), tmp);
	}
}

void freeArbre(Noeud* a) {
	if (a) {
		if (a->sad) freeArbre(a->sad);
		if (a->sag) freeArbre(a->sag);
		free(a);
	}
}

size_t depth(Noeud* a) {
	if (!a) return 0;
	else {
		size_t dl = depth(a->sag);
		size_t dr = depth(a->sad);
		if (dl > dr) return 1 + dl;
		else return 1 + dr;
	}
}

int getBF(Noeud* a) {
	if (!a) return 0;
	return (int)(depth(a->sad) - depth(a->sag));
}

void leftRotation(Noeud** a) {
	if (*a) {
		Noeud* temp = (*a)->sad;
		(*a)->sad = temp->sag;
		temp->sag = *a;
		*a = temp;
	}
}

void rightRotation(Noeud** a) {
	if (*a) {
		Noeud* temp = (*a)->sag;
		(*a)->sag = temp->sad;
		temp->sad = *a;
		*a = temp;
	}
}

void balance(Noeud** a) {
	if (*a) {
		balance(&((*a)->sag));
		balance(&((*a)->sad));

		int BF = getBF(*a);
		if (BF <= -2) {
			if (getBF((*a)->sag) > 0) leftRotation(&((*a)->sag));
			rightRotation(a);
		}
		else if (BF >= 2) {
			if (getBF((*a)->sad) <= 0) rightRotation(&((*a)->sad));
			leftRotation(a);
		}
	}
}

void afficherArbre(Noeud* a) {
    if (a) {
        printf("[%c] : [%d]\n", a->ch, a->occ);
        if (a->sag) {
            printf("A gauche de (%c|%d) : ", a->ch, a->occ);
            afficherArbre(a->sag);
        }
        if (a->sad) {
            printf("A droite de (%c|%d) : ", a->ch, a->occ);
            afficherArbre(a->sad);
        }/*
        afficherArbre(a->sag);
        printf("(%c|%d) ", a->ch, a->occ);
        afficherArbre(a->sad);*/
    }
}

void triNodesOccurence(Noeud** AVL){
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

Noeud* creerNoeudBin(char ch, size_t occ, char* bin) {
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

Queue* createQueue(){
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->last = NULL;
    return q;
}

int isEmptyQueue(Queue* q){
    if (!(q->last)) return 1;
    return 0;
}

void pushQueue(Queue* q, Arbre val){
    if (val) {
        ElementNode* n = (ElementNode*)malloc(sizeof(ElementNode));
        n->data = val;
        n->suivant = NULL;
        if (isEmptyQueue(q)) q->last = n;
        else {
            ElementNode* temp = q->last;
            while(temp->suivant) {
                temp = temp->suivant;
            }
            temp->suivant = n;

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

Arbre popQueue(Queue* q){
    if (isEmptyQueue(q)) return NULL;
    else {
        ElementNode* bottom = q->last;
        q->last = q->last->suivant;
        Arbre temp = bottom->data;
        free(bottom);
        return temp;
    }
}

int sizeQueue(ElementNode* q) {
    if (!q) return 0;
    return 1 + sizeQueue(q->suivant);
}

Arbre getMinQueues(Queue* q1, Queue* q2) {
    if (!q1 && !q2) return NULL;
    if (!q1) return popQueue(q2);
    if (!q2) return popQueue(q1);
    if (!(q1->last) && !(q2->last)) return NULL;
    if (!(q1->last)) return popQueue(q2);
    if (!(q2->last)) return popQueue(q1);
    if (q1->last->data->occ < q2->last->data->occ) return popQueue(q1);
    return popQueue(q2);
}

void freeArbre(Noeud* a) {
    if (a) {
        freeArbre(a->sad);
        freeArbre(a->sag);
        free(a);
    }
}

