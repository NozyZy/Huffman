#include "Huffman/Coding.h"

int main(void) {
    printf("\n\nTEST FULL :\n\n");
    FILE * fInput = fopen("../input.txt", "r+");
    if (!fInput) error1();

    char* content = loadFile(fInput);
    size_t size = countCharFile(fInput);
    Noeud* AVLocc = NULL;

    createAVLcaractere(&AVLocc, content, size);
    afficherArbre(AVLocc);

    fclose(fInput);
    freeArbre(AVLocc);
    free(content);

    printf("\n\nTEST LITTLE :\n\n");

    char content2[] = {'A', 'A', 'B', 'C', 'C', 'C', 'C', 'Z', '\0'};
    int size2 = 8;
    Noeud* AVLocc2 = NULL;

    createAVLcaractere(&AVLocc2, content2, size2);
    afficherArbre(AVLocc2);

    freeArbre(AVLocc2);

    printf("\n\nTEST NULL :\n\n");

    char* content3 = NULL;
    int size3 = 0;
    Noeud* AVLocc3 = NULL;

    createAVLcaractere(&AVLocc3, content3, size3);
    afficherArbre(AVLocc3);

    freeArbre(AVLocc3);

    return EXIT_SUCCESS;
}