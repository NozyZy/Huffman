#include "Huffman/Coding.h"

int main(void) {

    printf("\n\nTEST FULL\n\n");

    Noeud* huffman = creerNoeud('\0', 0, "1");
    huffman->sad = creerNoeud('\0', 0, "2");
    huffman->sag = creerNoeud('\0', 0, "3");
    huffman->sag->sad = creerNoeud('A', 0, "4");
    huffman->sag->sag = creerNoeud('Z', 0, "5");
    huffman->sad->sag = creerNoeud('B', 0, "6");
    huffman->sad->sad = creerNoeud('\0', 0, "7");
    huffman->sad->sad->sag = creerNoeud('C', 0, "8");
    huffman->sad->sad->sad = creerNoeud('\0', 0, "9");
    huffman->sad->sad->sad->sag = creerNoeud('D', 0, "10");
    huffman->sad->sad->sad->sad = creerNoeud('\0', 0, "11");
    huffman->sad->sad->sad->sad->sag = creerNoeud('E', 0, "12");
    huffman->sad->sad->sad->sad->sad = creerNoeud('\0', 0, "13");
    huffman->sad->sad->sad->sad->sad->sad = creerNoeud('U', 0, "14");
    huffman->sad->sad->sad->sad->sad->sag = creerNoeud('F', 0, "15");

    afficherArbreBin(huffman);

    Noeud* dico = NULL;
    createAVLDico(&dico, huffman);
    printf("\nArbre dico :\n\n");
    afficherArbreBin(dico);

    freeArbre(dico);
    freeArbre(huffman);

    printf("\n\nTEST NULL\n\n");

    Noeud* huffman1 = NULL;

    afficherArbreBin(huffman1);

    Noeud* dico1 = NULL;
    createAVLDico(&dico1, huffman1);
    printf("\nArbre dico :\n\n");
    afficherArbreBin(dico1);

    freeArbre(dico1);
    freeArbre(huffman1);

    printf("\n\nTEST BAD HUFFMAN TREE\n\n");

    Noeud* huffman2 = creerNoeud('\0', 0, "1");
    huffman2->sad = creerNoeud('A', 0, "2");
    huffman2->sag = creerNoeud('B', 0, "3");
    huffman2->sag->sad = creerNoeud('C', 0, "4");
    huffman2->sag->sag = creerNoeud('D', 0, "5");


    afficherArbreBin(huffman2);

    Noeud* dico2 = NULL;
    createAVLDico(&dico2, huffman2);
    printf("\nArbre dico :\n\n");
    afficherArbreBin(dico2);

    freeArbre(dico2);
    freeArbre(huffman2);

    return EXIT_SUCCESS;
}