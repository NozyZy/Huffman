#include "DataStructures.h"

void createAVLcaractere(Noeud** AVL, char* content, size_t taille) {
	size_t i = 0;
	for (i = 0; i < taille; i++) {
		Noeud* tmp = creerNoeud(content[i], 1);
		if (tmp) {
			addNodeAVL(AVL, tmp);
		}
	}
}

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
	if (tmp) {
		addNodeBSTch(AVL, tmp);
		balance(AVL);
	}
}


void addNodeBSTch(Noeud** AVL, Noeud* tmp) {
	if (!(*AVL)) {
		(*AVL) = tmp;
	}
	else if	((*AVL)->ch == tmp->ch) {
		(*AVL)->occ = (*AVL)->occ + 1;
		freeArbre(tmp);
	}
	else if ((tmp->ch) < ((*AVL)->ch)) {
		addNodeBSTch(&((*AVL)->sag), tmp);
	}
	else if ((*AVL)->ch < (tmp->ch)) {
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
	else
	{
		exit(EXIT_FAILURE);
	}
}
