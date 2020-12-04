#include "Dico.h"

#ifndef HUFFMAN_CODING_H
#define HUFFMAN_CODING_H

void int2bin(int n, char* bin);
void textFileToBinFile(FILE* file, char* fBinName);
char* codeFromChar(char ch, Arbre dico);
void zipFile(char* toZipName, char* zippedName);

#endif //HUFFMAN_CODING_H
