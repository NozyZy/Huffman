#include "Coding.h"
#include <string.h>
#define TAILLE_MAX 1000 

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

    FILE* fZipped, *fToZip, *fDico = NULL;

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

    emptyFile("../dico.txt");
    fDico = fopen("../dico.txt", "a+");
    printDicoFile(dico, fDico);

    freeArbre(dico);
    freeArbre(huffman);
    freeArbre(AVL);
    freeArbre(AVLtrie);
    free(content);

    fclose(fZipped);
    fclose(fToZip);
    fclose(fDico);
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
int nbrCaractere(char* ch) {
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

void deZipFile(char* dicoName, char* dezippName) {
    Noeud* arb = creerNoeud('\0', 1, NULL);
    creatHuffmanFromDico(dicoName, &arb);
    emptyFile("../output.txt");
    FILE* dezip = fopen("../output.txt", "a+");
    FILE* huffman = fopen(dezippName, "r");
    char ch = '\0';
    int j; 
    char* content = loadFile(huffman);
    for (int i = 0; i < countCharFile(huffman); i++) {
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
        i = j-1 + i;
        ch = '\0';
    }
    fclose(dezip);
    fclose(huffman);
}

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
                info[i] = tmp;
                i++;
            }
            tmp = fgetc(file);
        }
        if (!info) return NULL;
        char* chtmp = malloc(nbrCaractere(info) * sizeof(char));
        strcpy(chtmp, info);
        addNodeDico(arb, creerNoeud(ch, 1, chtmp), 0);
    }
    fseek(file, 0, SEEK_SET);
    fclose(file);
}

char chercheArbreCh(Noeud* arb, char* bin) {
    if (!bin) exit(1);
    //int nbr = nbrCaractere(bin);
    if (!(arb)) {
        return NULL;
    }

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
    return arb->ch;   
}
