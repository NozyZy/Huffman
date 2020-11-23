#include <stdlib.h>
#include <stdio.h>
#include "Huffman/Coding.h"

int main(void) {
    FILE *fInput, *fOutput; // files Input.txt and Output.txt
    size_t cI, cO, ratio = 0; // charIn, charOut, and ratio cO/cI (should be 8, or 0 if empty, so integer)
    char *contentIn = NULL, *contentOut = NULL; // content of Input.txt and Output.txt

    fInput = fopen("../input.txt", "r+"); // <- Penser à changer le chemin d'acces !!
    if(!fInput) error1(); // if file is not found
    textFileToBinFile(fInput);

    fOutput = fopen("../output.txt", "r+");
    if(!fOutput) error1(); // if file is not found

    cI = countCharFile(fInput);
    cO = countCharFile(fOutput);
    // calculate the ratio, only if cI != 0
    if (cI) ratio = cO/cI;

    contentIn = loadFile(fInput);
    contentOut = loadFile(fOutput);

    printf("\nInput : %s\nOutput : %s\n\nInput #char : %d\nOutput #char : %d\nRatio : %d\n", contentIn, contentOut, cI, cO, ratio);

    fclose(fInput);
    fclose(fOutput);
    return EXIT_SUCCESS;
}