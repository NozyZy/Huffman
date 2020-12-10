/**
 * @file Coding.h
 * @author Gianlucca Annichiarico (agianlucca@gmail.com)
 * @brief Headers des fonctions de conversion (encodage decodage)
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

extern  char*   codeFromChar            (char ch, Arbre dico);
extern  void    int2bin                 (int n, char* bin);
extern  void    textFileToBinFile       (FILE* file, char* fBinName);
extern  void    zipFile                 (char* toZipName, char* zippedName);
extern  void    addNodeDico             (Arbre* a, Arbre tmp, int index);
extern  int     nbrCaractere            (const char* ch);
extern  void    createHuffmanFromDico   (char* dicoName, Arbre* arb);
extern  char    chercheArbreCh          (Arbre arb, const char* bin);
extern  void    unzipFile               (char* dicoName, char* unzipName);
extern  float   calculateRatio          (void);

#endif //HUFFMAN_CODING_H
