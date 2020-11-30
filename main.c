#include "Huffman/Coding.h"

int main(void) {
    FILE* fInput;
    fInput = fopen("../input.txt", "r+");
    if (!fInput) error1();

    char* content = loadFile(fInput);
    Element* l = NULL;
    l = creerListeOccurrences(content, countCharFile(fInput));
    afficherListe("la liste", l);

    Noeud* a = NULL;
    a = creeArbreOccurrences(l);
    afficherArbre(a);

    freeList(l);
    freeArbre(a);

    return EXIT_SUCCESS;
}
