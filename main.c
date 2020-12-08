#include "Huffman/Coding.h"

int main(void) {
    clock_t begin, end;
    begin = clock();

    zipFile("../input.txt", "../huffman.txt");


    FILE *fInput, *fHuffman, *fBin; // files input.txt and binary.txt
    double cI, cH; // charIn, charOut, and ratio cB/cI (should be 8, or 0 if empty, so integer)
    float ratio = 0;

    fInput = fopen("../input.txt", "r+"); // <- Penser à changer le chemin d'acces !!
    if(!fInput) error1(); // if file is not found
    textFileToBinFile(fInput, "../binary.txt");

    fHuffman = fopen("../huffman.txt", "r+");
    if(!fHuffman) error1();

    fBin = fopen("../binary.txt", "r+");

    cI = countCharFile(fBin);
    cH = countCharFile(fHuffman);
    // calculate the ratio, only if cI != 0
    if (cI) ratio = (float)(cH/cI)*100;

    printf("\nCompression Ratio : %f %% ", ratio);
    fclose(fBin);
    fclose(fHuffman);
    fclose(fInput);

    unzipFile("../dico.txt", "../huffman.txt");

    end = clock();
    printf("\n\tall : %f sec\n\n\t", (float)(end-begin)/CLOCKS_PER_SEC);

    system("PAUSE");

    return EXIT_SUCCESS;
}