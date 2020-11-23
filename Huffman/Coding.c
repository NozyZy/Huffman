#include "Coding.h"

// converts a decimal int given in argument in a char* binary given in argument
void int2bin(int n, char* bin){
    // only for positive decimal
    if (n > 0) {
        int i;
        char nb[2];
        for (i = 0; i < 8; i++) {
            // converts int n%2 (0 or 1) in a char
            sprintf(nb, "%d", (n%2));
            // fills the array upside down, to have a good binary
            bin[7-i] = nb[0];
            n = n/2;
        }
        bin[8] = '\0';
    }
}

// converts a text file in argument into an output.txt in binary
void textFileToBinFile(FILE* file){
    FILE* fBin;
    char *content = NULL, *bin = NULL;
    size_t size = 0, i = 0;
    // empty the output.txt file
    emptyFile("../output.txt");
    // open outputs.txt to add binary number, one by one (so not write "w+")
    fBin = fopen("../output.txt", "a+");
    // if no file found
    if(!fBin) error1();

    content = loadFile(file);
    size = countCharFile(file);
    bin = (char*)malloc(9*sizeof(char));

    for(i = 0; i < size; i++){
        // convert content of file in the bin char*
        int2bin((int)content[i], bin);
        // pints the binary char* into the fBin file
        printFile(fBin, bin);
    }
    printf("\nThe file has been succesfully converted to binary !\n");
    free(bin);
    fclose(fBin);

}
