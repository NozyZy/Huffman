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
void int2bin(int n, char* bin);
void textFileToBinFile(FILE* file, char* fBinName);
void zipFile(char* toZipName, char* zippedName);
void addNodeDico(Noeud** a, Noeud* tmp, int index);
int nbrCaractere(const char* ch);
void creatHuffmanFromDico(char* dicoName, Noeud** arb);
char chercheArbreCh(Noeud* arb, const char* bin);
void unzipFile(char* dicoName, char* dezippName);

#endif //HUFFMAN_CODING_H
