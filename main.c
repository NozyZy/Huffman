#include "Huffman/Coding.h"

int main(void) {

    //char content[] = {'T', 'A', 'S', 'S', 'E', 'S', 'E', 'E', 'E', '\0'};

    Noeud* AVL = NULL;
    Noeud* huffman = NULL;

    //createAVLcaractere(&AVL, content, 10);
    AVL = creerNoeud('A', 2);
    AVL->sag = creerNoeud('B', 1);
    AVL->sad = creerNoeud('C', 3);
    afficherArbre(AVL);

    printf("\n_____________\n");
    //triNodesOccurence(&AVL);
    afficherArbre(AVL);
    Queue* occQueue = createQueue();
    creerOccQueue(AVL, occQueue);
    pushQueue(occQueue, creerNoeud('D', 4));
    pushQueue(occQueue, creerNoeud('E', 5));
    pushQueue(occQueue, creerNoeud('F', 6));
    pushQueue(occQueue, creerNoeud('G', 7));
    pushQueue(occQueue, creerNoeud('H', 8));
    pushQueue(occQueue, creerNoeud('I', 9));
    while (!isEmptyQueue(occQueue)) {
        printf("%c|%d ", occQueue->last->data->ch, occQueue->last->data->occ);
        popQueue(occQueue);
    }
    creerOccQueue(AVL, occQueue);
    pushQueue(occQueue, creerNoeud('D', 4));
    printf("\n !: ");
    huffman = creerArbreHuffman(occQueue);
    printf("\n_________\n");
    afficherArbre(huffman);

    freeArbre(AVL);
    freeArbre(huffman);

    return EXIT_SUCCESS;
}