#include "Huffman/Coding.h"

int main(void) {
    FILE* fToZip = fopen("../input.txt", "r+");
    char* content = loadFile(fToZip);
    Arbre AVL = NULL, AVLtrie = NULL, huffman = NULL;
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

    free(AVL);
    free(AVLtrie);
    free(huffman);

    fclose(fToZip);

    return EXIT_SUCCESS;
}