#include "HuffmanTree.h"

/**
 * @brief Crée l'arbre Huffman à partir d'un AVl trié en occurrences
 * 
 * @param AVLocc 
 * @return Arbre 
 */
Arbre createHuffmanTree(Arbre AVLocc) {
    Queue* occQueue = createQueue();
    creerOccQueue(AVLocc, occQueue);

    if (sizeQueue(occQueue->last) <= 1) return popQueue(occQueue);

    Queue *nodeQueue = createQueue();
    Arbre minD = NULL, minG = NULL, huffmanTree = NULL;
    while ((sizeQueue(occQueue->last) + sizeQueue(nodeQueue->last)) > 1) {
        minD = getMinQueues(occQueue, nodeQueue);
        minG = getMinQueues(occQueue, nodeQueue);

        if (minD->ch != '\0') minD->sad = minD->sag = NULL;
        if (minG->ch != '\0') minG->sad = minG->sag = NULL;

        huffmanTree = creerNoeud('\0', minD->occ + minG->occ, NULL);
        huffmanTree->sad = minD;
        huffmanTree->sag = minG;

        pushQueue(nodeQueue, huffmanTree);
    }

    return popQueue(nodeQueue);
}