#include <stdlib.h>
#include <stdio.h>

#ifndef HUFFMAN_INTERACTWITHFILE_H
#define HUFFMAN_INTERACTWITHFILE_H

void error1(); // prints the main error, for no file found
char* loadFile(FILE* file); // loads the content of a .txt file, given in argument, in a char*
long unsigned int countCharFile(FILE* file); // returns the number of chars in a .txt file
void printFile(FILE* file, char* content);
void emptyFile(char* name);

#endif //HUFFMAN_INTERACTWITHFILE_H
