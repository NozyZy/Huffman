#include "Coding.h"
#define TAILLE_MAX 1000 

/**
 * @brief Renvoie le code binaire à partir de di char stocker dans l'arbre dico
 * 
 * @param ch 
 * @param dico 
 * @return char* 
 */
char* codeFromChar(char ch, Arbre dico) {
    if (dico) {
        if ((int)ch < (int)dico->ch) return codeFromChar(ch, dico->sag);
        if ((int)ch > (int)dico->ch) return codeFromChar(ch, dico->sad);
        if ((int)ch == (int)dico->ch) return dico->bin;
    }
    return NULL;
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
    //free(bin);
    fclose(fBin);
}

/// compress a file named toZipName into a file named zippedName
void zipFile(char* toZipName, char* zippedName){
    //clock_t begin2, end2;
    //begin2 = clock();

    FILE* fZipped, *fToZip, *fDico = NULL;

    emptyFile(zippedName);
    fZipped = fopen(zippedName, "a+");
    if (!fZipped) error1();

    fToZip = fopen(toZipName, "r+");
    if (!fToZip) error1();

    char* content = loadFile(fToZip);
    Arbre AVL = NULL, AVLtrie = NULL, huffman = NULL, dico = NULL;
    size_t sizeContent = countCharFile(fToZip), i = 0;
    if (sizeContent > 0) {
        createAVLcaractere(&AVL, content, sizeContent);

        createAVLoccurrence(&AVLtrie, AVL);

        huffman = creerArbreHuffman(AVLtrie);

        char *bin = (char *) malloc(huffman->occ * sizeof(char));
        createBinCode(huffman, bin, 0);
        //free(bin);

        createAVLDico(&dico, huffman);

        //end2 = clock();
        //printf("\nall trees : %f sec\n", (float)(end2-begin2)/CLOCKS_PER_SEC);

        clock_t begin, end;
        begin = clock();
        for (i = 0; i < sizeContent; i++) {
            printFile(fZipped, codeFromChar(content[i], dico));
        }
        end = clock();
        printf("\nThe file has been succesfully compressed !\nzip : %f sec\n", (float) (end - begin) / CLOCKS_PER_SEC);

        emptyFile("../dico.txt");
        fDico = fopen("../dico.txt", "a+");
        printDicoFile(dico, fDico);

        freeArbre(dico); // ok
        freeArbre(huffman); // ok
        freeArbre(AVL); // ok
        //freeArbre(AVLtrie); // probleme
        //free(content); // probleme
        fclose(fDico);
    }
    else {
        printf("\nVotre fichier input est vide !");
    }

    fclose(fZipped);
    fclose(fToZip);

}
/**
 * @brief Ajoute un noeud dans l'arbre dico
 * 
 * @param a 
 * @param tmp 
 * @param index 
 */
void addNodeDico(Noeud** a, Noeud* tmp, int index) {
    if (tmp) {
        if (!(*a)) {
            if (tmp->bin[index] != '\0') *a = creerNoeud('\0', 1, NULL);
            else *a = creerNoeud(tmp->ch, 1, tmp->bin);
        }
        if (tmp->bin[index] == '0') addNodeDico(&((*a)->sag), tmp, index + 1);
        else if (tmp->bin[index] == '1') addNodeDico(&((*a)->sad), tmp, index + 1);
    }
}
/**
 * @brief Renvoie le nombre de caractère
 * 
 * @param ch 
 * @return int 
 */
int nbrCaractere(const char* ch) {
    int nbr = 0;
    for (int i = 0; ch[i] != '\0'; i++)
    {
        if (ch[i] == '0' || ch[i] == '1')
        {
            nbr++;
        }
    }
    return nbr;
}
/**
 * @brief Créer un arbre d'Huffman à partir du dico
 * 
 * @param dicoName 
 * @param arb 
 */
void creatHuffmanFromDico(char* dicoName, Noeud** arb) {
    FILE* file = fopen(dicoName, "r");
    if (!file) exit(1);

    int i, tmp;
    while (((tmp = fgetc(file))) != EOF) {
        i = 0;
        char ch = (char)tmp;
        char info[TAILLE_MAX] = "";

        tmp = fgetc(file);
        while (tmp != '\n' && tmp != EOF) {
            if (tmp == '0' || tmp == '1') {
                info[i] = (char)tmp;
                i++;
            }
            tmp = fgetc(file);
        }

        if (info[0] != '\0') {
            char* chtmp = malloc(nbrCaractere(info) * sizeof(char));
            strcpy(chtmp, info);
            addNodeDico(arb, creerNoeud(ch, 1, chtmp), 0);
        }
    }
    fseek(file, 0, SEEK_SET);
    fclose(file);
}
/**
 * @brief Cherche dans l'abre un char
 * 
 * @param arb 
 * @param bin 
 * @return char 
 */
char chercheArbreCh(Noeud* arb, const char* bin) {
    if (!bin) exit(1);
    if (!(arb)) return '\0';

    int i = 0;
    while (bin[i] != '\0') {
        if (arb) {
            if (bin[i] == '0') {
                arb = arb->sag;
            }
            else if (bin[i] == '1') {
                arb = arb->sad;
            }
            i++;
        }
    }
    if (arb) return arb->ch;
    return '\0';
}
/**
 * @brief Decompresse le zip
 * 
 * @param dicoName 
 * @param dezippName 
 */
void unzipFile(char* dicoName, char* dezippName) {
    clock_t begin, end;
    begin = clock();

    emptyFile("../output.txt");
    FILE* dezip = fopen("../output.txt", "a+");
    FILE* huffman = fopen(dezippName, "r");

    char* content = loadFile(huffman);
    size_t sizeContent = countCharFile(huffman);

    if (sizeContent > 0) {
        Noeud* arb = creerNoeud('\0', 1, NULL);
        creatHuffmanFromDico(dicoName, &arb);

        char ch = '\0';
        int j;

        for (int i = 0; i < sizeContent; i++) {
            char bin[TAILLE_MAX] = "";
            bin[0] = content[i];
            bin[1] = '\0';

            j = 1;
            while (ch == '\0') {

                ch = chercheArbreCh(arb, bin);
                if (ch == '\0') {
                    bin[j] = content[j + i];
                    j++;
                    bin[j] = '\0';
                }
            }
            fprintf(dezip,"%c", ch);
            i = j-1 + i;
            ch = '\0';

        }

        end = clock();
        printf("\nThe file has been succesfully decompressed !\nunzip : %f sec\n", (float)(end-begin)/CLOCKS_PER_SEC);
    }
    else {
        printf("Le fichier huffman.txt est vide !");
    }


    fclose(dezip);
    fclose(huffman);

    //free(content);
    //freeArbre(arb);
}
/**
 * @brief calcule et renvoie le ration
 * 
 * @return float 
 */
float calculateRatio() {
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

    return ratio;
}