#include "Huffman/Coding.h"

int main(void) {
    int i = 0;
    FILE* fInput = fopen("../input.txt", "r+");
    char* content = loadFile(fInput);

    printf("%s\n", content);
    Element* l = NULL;
    size_t sizeContent = countCharFile(fInput), size;
    fclose(fInput);
    l = creerListeOccurrences(content, sizeContent);
    afficherListe("list", l);

    size = tailleListe(l);

    Element* temp = l;
    Noeud** tab = (Noeud**)malloc(size*sizeof(Noeud*));
    for (i = 0; i < size; i++){
        tab[i] = creerNoeud(temp->ch, temp->occ, "0");
        temp = temp->suivant;
    }

    triTabNodes(tab, size);
    afficherTabNoeuds(tab, size, "\nTableau de noeuds tries par occ croissante (ch|occ|bin): ");

    Noeud* dico = NULL;
    createAVLDico(&dico, tab, size);
    printf("\nArbre dico :\n\n");
    afficherArbreBin(dico);

    freeList(l);
    for(i = 0; i < size; i ++){
        free(tab[i]->bin);
        free(tab[i]);
    }
    free(tab);
    freeArbre(dico);

    return EXIT_SUCCESS;
}
