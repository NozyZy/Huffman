#include "Coding.h"

char* codeFromChar(char ch, Arbre dico) {
    if (dico) {
        if ((int)ch < (int)dico->ch) return codeFromChar(ch, dico->sag);
        if ((int)ch > (int)dico->ch) return codeFromChar(ch, dico->sad);
        if ((int)ch == (int)dico->ch) return dico->bin;
    }
    return NULL;
}


/// compress a file named toZipName into a file named zippedName
void zipFile(char* toZipName, char* zippedName){
    clock_t begin2, end2;
    begin2 = clock();

    FILE* fZipped, *fToZip;

    emptyFile(zippedName);
    fZipped = fopen(zippedName, "a+");
    if (!fZipped) error1();

    fToZip = fopen(toZipName, "r+");
    if (!fToZip) error1();

    char* content = loadFile(fToZip);
    Arbre AVL = NULL, AVLtrie = NULL, huffman = NULL, dico = NULL;
    size_t sizeContent = countCharFile(fToZip), i = 0;

    createAVLcaractere(&AVL, content, sizeContent);

    createAVLoccurrence(&AVLtrie, AVL);

    huffman = creerArbreHuffman(AVLtrie);

    char* bin = (char*)malloc(huffman->occ*sizeof(char));
    createBinCode(huffman, bin, 0);
    free(bin);

    createAVLDico(&dico, huffman);

    end2 = clock();
    printf("\nall trees : %f sec\n", (float)(end2-begin2)/CLOCKS_PER_SEC);

    clock_t begin, end;
    begin = clock();
    for (i = 0; i < sizeContent; i++) {
        printFile(fZipped, codeFromChar(content[i], dico));
    }
    end = clock();
    printf("The file has been succesfully compressed !\n\nzip : %f sec\n", (float)(end-begin)/CLOCKS_PER_SEC);

    freeArbre(dico);
    freeArbre(huffman);
    freeArbre(AVL);
    freeArbre(AVLtrie);
    free(content);

    fclose(fZipped);
    fclose(fToZip);
}


/**
 * @brief Convertie un nombre donné en argument en son écriture en binaire
 * 
 * @param n 
 * @param bin 
 */
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

/**
 * @brief Convertie un fichier.txt texte donné en argument en fichier.txt binaire
 * 
 * @param file 
 * @param fBinName 
 */
// converts a text file in argument into an output.txt in binary
void textFileToBinFile(FILE* file, char* fBinName){
    FILE* fBin;
    char *content = NULL, *bin = NULL;
    size_t size = 0, i = 0;
    // empty the output.txt file
    emptyFile(fBinName);
    // open outputs.txt to add binary number, one by one (so not write "w+")
    fBin = fopen(fBinName, "a+");
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
void deZipFile(char* dicoName, char* zippName) {
    
    Noeud* arb = creerNoeud('\0', 1, NULL);
    creatHuffmanFromDico(dicoName, &arb);
    printf("\nArbre dico :\n");
    afficherArbreBin(arb);

    emptyFile("../output.txt");
    FILE* dezip = fopen(".. /output.txt", "a+");
    FILE* huffman = fopen(zippName, "r");

    char bin[TAILLE_MAX] = "";
    char ch = NULL;
    int i;

    while ((bin[0] = (char)fgetc(huffman)) != EOF) {
        i = 1;
        while (ch == '\0') {
            ch = chercheArbreCh(arb, bin);
            bin[i] = fgetc(huffman);
            i++;
        }
        printf("-%c-", ch);
        fprintf(zippName, "%c", ch);
        ch = NULL;
        //bin = "";
    }

    fclose(dezip);
    fclose(huffman);
}
