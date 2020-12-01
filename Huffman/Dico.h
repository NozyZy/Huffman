#include "HuffmanTree.h"

#ifndef HUFFMAN_DICO_H
#define HUFFMAN_DICO_H

                                                                            // counts the number of char between all label given in argument (without \0 and \n)
void countNbBitLine(FILE* file, size_t line, size_t* count, char label);    // in a single line, given in argument, of a .txt file, given in argument
                                                                            // the counting is put in an array of int given in argument
void readFileDef(FILE* file, Def* def, size_t line);                        // fills a Def* given in argument, with the line of a file, all given in argument
void readFileDico(Dico* dico);                                              // fills a Dico* with a dico.txt file


#endif //HUFFMAN_DICO_H
