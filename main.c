#include <stdlib.h>
#include <stdio.h>
#include "Huffman/Coding.h"

int main(void) {
    char content[] = {'T', 'A', 'S', 'S', 'E', 'S', '\0'};

    Element* l = NULL;
    l = creerListe(content, 7);
    afficherListe("la liste", l);

    freeList(l);

    return EXIT_SUCCESS;
}