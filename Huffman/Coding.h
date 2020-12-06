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

#ifndef HUFFMAN_CODING_H
#define HUFFMAN_CODING_H

void int2bin(int n, char* bin); // convert decimal into binary
void textFileToBinFile(FILE* file, char* fBinName); // convert a text file into a binary text file

#endif //HUFFMAN_CODING_H
