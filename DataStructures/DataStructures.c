#include "DataStructures.h"
#define TAILLE_MAX 1000 

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

Noeud* creerNoeud(char ch, size_t occ, char* bin) {
	Noeud* a = (Noeud*)malloc(sizeof(Noeud));
	if (a) {
		a->ch = ch;
		a->occ = occ;
		a->bin = bin;
		a->sag = NULL;
		a->sad = NULL;
		return a;
	}
	return NULL;
}

void freeArbre(Noeud* a) {
    if (a) {
        if (a->sad) freeArbre(a->sad);
        if (a->sag) freeArbre(a->sag);
        free(a);
    }
}


void addNodeAVL(Noeud** AVL, Noeud* tmp) {
    addNodeBSTch(AVL, tmp);
    balance(AVL);
}

void addNodeBSTch(Noeud** AVL, Noeud* tmp) {
	if (!(*AVL)) {
		(*AVL) = creerNoeud(tmp->ch, tmp->occ, tmp->bin);
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

void addNodeBSTocc(Noeud** AVL, Noeud* tmp) {
    if (!(*AVL)) {
        (*AVL) = creerNoeud(tmp->ch, tmp->occ, NULL);
    }
    else if (tmp->occ <= (*AVL)->occ) {
        addNodeBSTocc(&((*AVL)->sag), tmp);
    }
    else if ((*AVL)->occ < tmp->occ) {
        addNodeBSTocc(&((*AVL)->sad), tmp);
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


Queue* createQueue(){
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->last = NULL;
    return q;
}

int isEmptyQueue(Queue* q){
    if (!(q->last)) return 1;
    return 0;
}

void pushQueue(Queue* q, Arbre val) {
    if (val) {
        ElementNode *n = (ElementNode *) malloc(sizeof(ElementNode));
        n->data = val;
        n->suivant = NULL;
        if (isEmptyQueue(q)) q->last = n;
        else {
            ElementNode *temp = q->last;
            while (temp->suivant) {
                temp = temp->suivant;
            }
            temp->suivant = n;
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

void creatHuffmanFromDico(char* dicoName, Noeud** arb) {
    FILE* file = fopen(dicoName, "r");
    if (!file) exit(1);

    int i, tmp;
    while (((tmp = fgetc(file))) != EOF) {
        i = 0;
        char ch = (char)tmp;
        char info[TAILLE_MAX] = "";

        tmp = fgetc(file);
        while (tmp != '\n' && tmp != EOF) {
            if (tmp == '0' || tmp == '1') {
                info[i] = tmp;
                i++;
            }
            tmp = fgetc(file);
        }

        if (!info) return NULL;
        addNoeudDico(arb, ch, info);
    }
    fseek(file, 0, SEEK_SET);
    fclose(file);
}

void addNoeudDico(Noeud** a, char ch, char* info) {
    int index = nbrCaractere(info);
    Noeud* tmp = *a;
    Noeud* tmpv2 = tmp;

    for (int i = 0; i < index; i++) {
        if (!(tmp)) {
            tmp = creerNoeud('\0', 1, NULL);
        }
        if (info[i] == '0') {
            if (!(tmp->sad)) {
                tmp->sad = creerNoeud('\0', 1, NULL);
            }
            tmp = tmp->sad;
        }
        else if (info[i] == '1') {
            if (!(tmp->sag)) {
                tmp->sag = creerNoeud('\0', 1, NULL);
            }
            tmp = tmp->sag;
        }
        printf("\n%d", i);
        afficherArbreBin(tmp);
    }
    tmp = creerNoeud(ch, 1, info);
    *a = tmpv2;
}

int nbrCaractere(char* ch) {
    int nbr = 0;
    for (int i = 0; ch[i] != '\0'; i++)
    {
        if (ch[i] == '0' || ch[i] == '1')
        {
            nbr++;
        }
    }
    return nbr;
}

char chercheArbreCh(Noeud* arb, char* bin) {
    int nbr = nbrCaractere(bin);

    for (int i = 0; i < nbr; i++) {
        if (!(arb)) {
            return NULL;
        }

        if (bin[i] == '0') {
            arb = arb->sad;
        }
        else if (bin[i] == '1') {
            arb = arb->sag;
        }
    }
    return (arb->ch);
}


