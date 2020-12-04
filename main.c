#include "Huffman/Coding.h"

int main(void) {
    FILE* fToZip = fopen("../input.txt", "r+");
    char* content = loadFile(fToZip);
    Arbre AVL = NULL, AVLtrie = NULL, huffman = NULL, dico = NULL;
    size_t sizeContent = countCharFile(fToZip);

    printf("\n_____________AVL trie par caracteres :\n");
    createAVLcaractere(&AVL, content, sizeContent);
    afficherArbreOcc(AVL);

    printf("\n_____________AVL trie par occurrences :\n");
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

    printf("\n_____________Dico trie par caracteres :\n\n");
    createAVLDico(&dico, huffman);
    afficherArbreBin(dico);

    free(AVL);
    free(AVLtrie);
    free(huffman);
    free(dico);
    fclose(fToZip);
    return EXIT_SUCCESS;
}