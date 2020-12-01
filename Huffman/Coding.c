#include "Coding.h"

/// converts a text fil given in argument, in a binary file with the help of dico file
char* zipText(FILE* fText){

    char *content = loadFile(fText), *zip = NULL, *error = NULL;
    size_t  j = 0, k = 0, sizeZip = 0, sizeError = 0;
    long unsigned int i = 0, sizeMax, sizeContent = countCharFile(fText);
    Dico* dico = (Dico*)malloc(sizeof(Dico));
    if (!dico) return NULL;

    readFileDico(dico);

    sizeMax = sizeContent * dico->maxBitSize;

    zip = (char*)malloc(sizeMax * sizeof(char));
    if (!zip) return NULL;

    error = (char*)malloc(sizeContent * sizeof(char));
    if (!error) return NULL;
    // will read all char of the file, compare it to every char of the dico, until it founds the same and add it
    for (i = 0; i < sizeContent; i++){
        for (j = 0; j < dico->sizeDico; j++){

            if (content[i] == dico->arrayDico[j]->ch){
                for (k = 0; k < dico->arrayDico[j]->nbBit; k ++){
                    zip[sizeZip++] = dico->arrayDico[j]->bin[k];
                } break;

            } else if (j == dico->sizeDico - 1) {
                j = 0;
                while (error[j] != content[i] && j < sizeError) {
                    j++;
                }
                if (j == sizeError) error[sizeError++] = content[i];
                j = dico->sizeDico - 1;
            }
        }
    }

    zip[sizeZip] = '\0';

    if (sizeError){
        error[sizeError] = '\0';
        printf("\nLa compression de input.txt vers hauffman.txt a ete effectuee !\nLes caracteres suivants n'ont pas pu etre convertis : ");
        for (i = 0; i < sizeError; i++){
            printf("%c", error[i]);
            if (i < sizeError - 1) printf("-");
        }

    } else printf("\nLa compression de input.txt vers hauffman.txt a ete effectuee avec succes ! ");

    free(error);
    free(content);
    freeDico(dico);
    return zip;
}

/// compress a file named toZipName into a file named zippedName
void zipFile(char* toZipName, char* zippedName){
    FILE* fZipped, *fToZip;
    char *zip = NULL;

    fZipped = fopen(zippedName, "w+");
    if (!fZipped) error1();

    fToZip = fopen(toZipName, "r+");
    if (!fToZip) error1();

    printFile(fZipped, zip = zipText(fToZip));

    fclose(fZipped);
    fclose(fToZip);
    free(zip);
}
