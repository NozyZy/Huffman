#include "DataStructures.h"

void triNodesOccurence(Noeud** AVL){
	if (*AVL) {
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
		}
	}
}
