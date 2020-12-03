#include "Huffman/Coding.h"
#include <time.h>

int main(void) {
    clock_t begin, end;
    float spent;
    begin = clock();
    FILE* input = fopen("../input.txt", "r+");
    char* content = loadFile(input);
    Arbre AVL = NULL, AVLtrie = NULL, huffman = NULL, dico = NULL;

    printf("\n_____________AVL trié par caractères :\n");
    createAVLcaractere(&AVL, content, countCharFile(input));
    fclose(input);
    afficherArbreOcc(AVL);

    printf("\n_____________AVL trié par occurrences :\n");
    createAVLoccurrence(&AVLtrie, AVL);
    afficherArbreOcc(AVLtrie);

    printf("\n_____________Arbre de Huffman :\n");
    huffman = creerArbreHuffman(AVLtrie);
    afficherArbreOcc(huffman);

    printf("\n_____________Abre de Huffman avec les codes binaires :\n");
    char* bin = (char*)malloc(huffman->occ*sizeof(char));
    createBinCode(huffman, bin, 0);
    free(bin);
    afficherArbreBin(huffman);

    printf("\n_____________Dico trié par caractères :\n\n");
    createAVLDico(&dico, huffman);
    afficherArbreBin(dico);

    end = clock();
    spent = ((float)(end - begin)/CLOCKS_PER_SEC);
    printf("\ntime spent : %f", spent);

    freeArbre(dico);
    freeArbre(huffman);
    freeArbre(AVL);
    freeArbre(AVLtrie);

    return EXIT_SUCCESS;
}