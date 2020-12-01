#include "DataStructures.h"

// prints a Def given in argument, with the choice of jumping a line
void printDef(Def* def, char doesJumpLine){
    if (doesJumpLine == 'y' || doesJumpLine == 'Y') printf("%c : %s (%d)\n", def->ch, def->bin, def->nbBit);
    else printf("%c : %s (%d)", def->ch, def->bin, def->nbBit);
}

// prints a Dico given in argument, with the choice of jumping a line
void printDico(Dico* dico, char doesJumpLine){
    size_t i = 0;
    for (i = 0; i < dico->sizeDico; i++)
        printDef(dico->arrayDico[i], doesJumpLine);
}

// free the memory of all the def, the array and the dico itself
void freeDico(Dico* dico){
    size_t i = 0;
    for(i = dico->sizeDico-1; i > 0 ; i--){
        free(dico->arrayDico[i]->bin);
        free(dico->arrayDico[i]);
    }
    free(dico->arrayDico);
    free(dico);
}