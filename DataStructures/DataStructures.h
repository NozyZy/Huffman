#include <stdlib.h>
#include <stdio.h>

#ifndef HUFFMAN_DATASTRUCTURES_H
#define HUFFMAN_DATASTRUCTURES_H

typedef struct Def{
    char ch; // the char
    char* bin; // his binary code
    size_t nbBit; // the number of bit in the binary code
}Def;

typedef struct Dico{
    struct Def** arrayDico; // array of def
    size_t sizeDico; // size of array, number of def
    size_t maxBitSize; // size of the biggest binary code
}Dico;


void printDef(Def* def, char doesJumpLine);     // prints a Def given in argument, with the choice of jumping a line
void printDico(Dico* dico, char doesJumpLine);  // prints a Dico given in argument, with the choice of jumping a line
void freeDico(Dico* dico);                      // free the memory of all the def, the array and the dico itself

#endif //HUFFMAN_DATASTRUCTURES_H
