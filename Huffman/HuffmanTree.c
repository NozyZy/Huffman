#include "HuffmanTree.h"

Arbre creerArbreHuffman(Queue* occQueue) {

    if (sizeQueue(occQueue->last) <= 1) { // Si la file initiale n'a qu'un HuffmanNode => rien à construire.
        return popQueue(occQueue);    // returns NULL if empty, the only node if not
    }

    Queue *nodeQueue = createQueue();

    while ((sizeQueue(occQueue->last) != 0) || (sizeQueue(nodeQueue->last) >= 1)) {

        int occQSize = sizeQueue(occQueue->last);
        int nodeQSize = sizeQueue(nodeQueue->last);
        if ((occQSize + nodeQSize) < 2)  { // occQSize forcément nul et nodeQSize forcément égal à 1
            return popQueue(nodeQueue);  // On retourne donc directement le parent final
        } else {
            Noeud* min1 = getMinQueues(occQueue, nodeQueue);
            Noeud* min2 = getMinQueues(occQueue, nodeQueue);
            if (min1->ch != '\0') {
                min1->sad = min1->sag = NULL;
            }
            if (min2->ch != '\0') {
                min2->sad = min2->sag = NULL;
            }
            Arbre huffman = creerNoeud('\0', min1->occ + min2->occ);
            huffman->sad = min1;
            huffman->sag = min2;

            pushQueue(nodeQueue, huffman);
        }
    }
    return NULL;
}