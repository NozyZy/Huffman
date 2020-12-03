#include "Huffman/Coding.h"

int main(void) {

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

    huffman = creerArbreHuffman(AVL);
    printf("\n_________\n");
    afficherArbre(huffman);

    freeArbre(AVL);
    freeArbre(huffman);

    return EXIT_SUCCESS;
}