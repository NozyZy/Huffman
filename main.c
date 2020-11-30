#include "Huffman/Coding.h"

int main(void) {
    FILE* fInput;
    fInput = fopen("../input.txt", "r+");
    if (!fInput) error1();

    char* content = loadFile(fInput);
    Element* l = NULL;
    l = creerListeOccurrences(content, countCharFile(fInput));
    afficherListe("la liste", l);

    freeList(l);

    return EXIT_SUCCESS;
}