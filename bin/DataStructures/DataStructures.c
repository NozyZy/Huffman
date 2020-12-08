#include "DataStructures.h"
#define TAILLE_MAX 1000 
/**
 * @brief Affiche l'arbre avec ses occurrences
 * 
 * @param a 
 */
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
/**
 * @brief Affiche l'arbre avec ses codes binaires
 * 
 * @param a 
 */
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
/**
 * @brief Crée un noeud alloué dynamiquement
 * 
 * @param ch 
 * @param occ 
 * @param bin 
 * @return Noeud* 
 */
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

/**
 * @brief Libère l'arbre
 * 
 * @param a 
 */
void freeArbre(Noeud* a) {
    if (a != NULL) {
        if (a->sad) freeArbre(a->sad);
        if (a->sag) freeArbre(a->sag);
        free(a);
    }

}

/**
 * @brief Ajoute un noeud dans l'AVL
 * 
 * @param AVL 
 * @param tmp 
 */
void addNodeAVLch(Noeud** AVL, Noeud* tmp) {
    addNodeBSTch(AVL, tmp);
    balance(AVL);
}

/**
 * @brief Ajoute un noeud dans l'abre de tri (alphabétique)
 * 
 * @param AVL 
 * @param tmp 
 */
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
/**
 * @brief Ajoute un noeud dans l'arbre de tri (Occurrence)
 * 
 * @param AVL 
 * @param tmp 
 */
void addNodeBSTocc(Noeud** AVL, Noeud* tmp) {
    if (tmp) {
        if (!(*AVL)) {
            (*AVL) = creerNoeud(tmp->ch, tmp->occ, NULL);
        } else if (tmp->occ <= (*AVL)->occ) {
            addNodeBSTocc(&((*AVL)->sag), tmp);
        } else if ((*AVL)->occ < tmp->occ) {
            addNodeBSTocc(&((*AVL)->sad), tmp);
        }
    }
}

/**
 * @brief Renvoie la prodonfeur de l'arbre (0 si l'arbre n'existe pas)
 * 
 * @param a 
 * @return size_t 
 */
size_t depth(Noeud* a) {
	if (!a) return 0;
	else {
		size_t dl = depth(a->sag);
		size_t dr = depth(a->sad);
		if (dl > dr) return 1 + dl;
		else return 1 + dr;
	}
}
/**
 * @brief Renvoie le balance factor de l'AVL
 * 
 * @param a 
 * @return int 
 */
int getBF(Noeud* a) {
	if (!a) return 0;
	return (int)(depth(a->sad) - depth(a->sag));
}
/**
 * @brief Rotation gauche de noeuds
 * 
 * @param a 
 */
void leftRotation(Noeud** a) {
	if (*a) {
		Noeud* temp = (*a)->sad;
		(*a)->sad = temp->sag;
		temp->sag = *a;
		*a = temp;
	}
}
/**
 * @brief Rotation droite de noeuds
 * 
 * @param a 
 */
void rightRotation(Noeud** a) {
	if (*a) {
		Noeud* temp = (*a)->sag;
		(*a)->sag = temp->sad;
		temp->sad = *a;
		*a = temp;
	}
}
/**
 * @brief Tant que le Balance Factor > 2 Réequillibre l'arbre : avoir un AVL
 * 
 * @param a 
 */
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

/**
 * @brief Crée une file allouée dynamiquement
 * 
 * @return Queue* 
 */
Queue* createQueue(){
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->last = NULL;
    return q;
}
/**
 * @brief Renvoie l'état de la file, vidée ou non
 * 
 * @param q 
 * @return int 
 */
int isEmptyQueue(Queue* q){
    if (!(q->last)) return 1;
    return 0;
}
/**
 * @brief Enfile un noeud
 * 
 * @param q 
 * @param val 
 */
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
/**
 * @brief Défile un noeud
 * 
 * @param q 
 * @return Arbre 
 */
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
/**
 * @brief Renvoie la taille de la file
 * 
 * @param q 
 * @return int 
 */
int sizeQueue(ElementNode* q) {
    if (!q) return 0;
    return 1 + sizeQueue(q->suivant);
}
/**
 * @brief Compare et choisi le noeud avec l'occurrence la plus petite
 * 
 * @param q1 
 * @param q2 
 * @return Arbre 
 */
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



