#include "Coding.h"

int main()
{
    FILE* fInput = fopen("../input.txt", "r+");
    char* content = loadFile(fInput);
    Element* l = NULL;
    l = creerListeOccurrences(content, countCharFile(fInput));
    fclose(fInput);
    afficherListe("la liste", l);
    
    Noeud* a = NULL;
    a = creeArbreOccurrences(l);
    afficherArbre(a);

    createDicoFile(a, "../dico.txt");

    freeList(l);
    freeArbre(a);
    fclose(fInput);
}
