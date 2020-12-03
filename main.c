#include "Huffman/Coding.h"

int main(void) {
    clock_t begin, end;
    begin = clock();
    zipFile("../input.txt", "../huffman.txt");
    end = clock();
    printf("all : %f", (float)(end-begin)/CLOCKS_PER_SEC);

    FILE *fInput, *fHuffman, *fBin; // files input.txt and binary.txt
    double cI, cH; // charIn, charOut, and ratio cB/cI (should be 8, or 0 if empty, so integer)
    float ratio = 0;

    fInput = fopen("../input.txt", "r+"); // <- Penser à changer le chemin d'acces !!
    if(!fInput) error1(); // if file is not found
    textFileToBinFile(fInput, "../binary.txt");

    fHuffman = fopen("../huffman.txt", "r+");
    if(!fHuffman) error1(); // if file is not found

    fBin = fopen("../binary.txt", "r+");

    cI = countCharFile(fBin);
    cH = countCharFile(fHuffman);
    // calculate the ratio, only if cI != 0
    if (cI) ratio = (float)(cH/cI)*100;

    printf("\n\n Ratio : %f %%", ratio);
    fclose(fBin);
    fclose(fHuffman);
    fclose(fInput);

    return EXIT_SUCCESS;
}