#include <stdlib.h>
#include <stdio.h>
#include "InteractWithFile.h"

#ifndef HUFFMAN_CODING_H
#define HUFFMAN_CODING_H

void int2bin(int n, char* bin); // convert decimal into binary
void textFileToBinFile(FILE* file, char* fBinName); // convert a text file into a binary text file

#endif //HUFFMAN_CODING_H
