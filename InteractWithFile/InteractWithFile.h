#include <stdlib.h>
#include <stdio.h>

#ifndef HUFFMAN_INTERACTWITHFILE_H
#define HUFFMAN_INTERACTWITHFILE_H

void error1();                                  // prints the main error, for no file found
char* loadFile(FILE* file);                     // loads the content of a .txt file, given in argument, in a char*
void printFile(FILE* file, char* content);      // prints the content of a .txt file
long unsigned int countCharFile(FILE* file);    // returns the number of chars in a .txt file
size_t countLineFile(FILE* file);               // returns the number of chars in a .txt file
void emptyFile(char* name);                     // create or empty a file


#endif //HUFFMAN_INTERACTWITHFILE_H
