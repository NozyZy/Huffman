/**
 * @file Coding.h
 * @author Gianlucca Annichiarico (agianlucca@gmail.com)
 * @brief Headers des fonctions de conversion
 * @version 0.1
 * @date 2020-12-06
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include "Dico.h"
#include <time.h>

#ifndef HUFFMAN_CODING_H
#define HUFFMAN_CODING_H

char* codeFromChar(char ch, Arbre dico);
void zipFile(char* toZipName, char* zippedName);
void textFileToBinFile(FILE* file, char* fBinName);
void int2bin(int n, char* bin);

#endif //HUFFMAN_CODING_H
