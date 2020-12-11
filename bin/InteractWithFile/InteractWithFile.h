/**
 * @file InteractWithFile.h
 * @author Gianlucca Annichiarico (agianlucca@gmail.com)
 * @brief Headers des fonctions de gestion de fichiers textes
 * @version 0.1
 * @date 2020-12-06
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include <stdlib.h>
#include <stdio.h>

#ifndef HUFFMAN_INTERACTWITHFILE_H
#define HUFFMAN_INTERACTWITHFILE_H

extern  void    error1          (void);
extern  char*   loadFile        (FILE* file);
extern  size_t  countCharFile   (FILE* file);
extern  void    printFile       (FILE* file, char* content);
extern  void    emptyFile       (char* name);

#endif //HUFFMAN_INTERACTWITHFILE_H
