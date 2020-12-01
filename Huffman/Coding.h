#include "Dico.h"

#ifndef HUFFMAN_CODING_H
#define HUFFMAN_CODING_H

char* zipText(FILE* fText);                         /// return the compressed content of a file given in argument
void zipFile(char* toZipName, char* zippedName);    /// converts a toZipName file into a zippedName file, with the help of the dico

#endif //HUFFMAN_CODING_H
