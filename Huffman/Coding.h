#include "Dico.h"
#include <time.h>

#ifndef HUFFMAN_CODING_H
#define HUFFMAN_CODING_H

char* codeFromChar(char ch, Arbre dico);
void zipFile(char* toZipName, char* zippedName);
void textFileToBinFile(FILE* file, char* fBinName);
void int2bin(int n, char* bin);

#endif //HUFFMAN_CODING_H
