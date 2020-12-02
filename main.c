#include <stdlib.h>
#include <stdio.h>
#include "Huffman/Coding.h"

int main(void) {
    FILE *fInput, *fBin; // files input.txt and binary.txt
    long unsigned int cI, cB; // charIn, charOut, and ratio cB/cI (should be 8, or 0 if empty, so integer)
    size_t ratio = 0;
    char *contentIn = NULL, *contentBin = NULL; // content of Input.txt and Output.txt

    fInput = fopen("../input.txt", "r+"); // <- Penser à changer le chemin d'acces !!
    if(!fInput) error1(); // if file is not found
    textFileToBinFile(fInput, "../binary.txt");

    fBin = fopen("../binary.txt", "r+");
    if(!fBin) error1(); // if file is not found

    cI = countCharFile(fInput);
    cB = countCharFile(fBin);
    // calculate the ratio, only if cI != 0
    if (cI) ratio = cB/cI;

    contentIn = loadFile(fInput);
    contentBin = loadFile(fBin);

    printf("\nInput : %s\nOutput : %s\n\nInput #char : %ld\nOutput #char : %ld\nRatio : %d\n", contentIn, contentBin, cI, cB, ratio);

    fclose(fInput);
    fclose(fBin);
    return EXIT_SUCCESS;
}
