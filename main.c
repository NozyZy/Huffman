#include <stdlib.h>
#include <stdio.h>
#include "Huffman/Coding.h"

int main(void) {
    printf("oui");

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