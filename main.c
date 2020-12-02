#include "fonction.h"

int main()
{
    int *save = NULL;

    save = malloc(sizeof(int));

    char content[] = {'T', 'A', 'S', 'S', 'E', 'S', '\0'};

    Element* l = NULL;
    l = creerListe(content, 7);
    afficherListe("la liste", l);
    
    Noeud* a = NULL;
    a = creeArbre(l);

    
    chemin(a,'S');
    chemin(a,'E');
    chemin(a,'A');
    chemin(a,'T');
    
    

    freeList(l);
    freeArbre(a);

    

}

