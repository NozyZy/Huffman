#include "InteractWithFile.h"

/// prints the main error, for file not found
void error1(){
    printf("No such file or directory - error 1\n");
    exit(1);
}

/// returns the content of a .txt file, given in argument, in a char*
char* loadFile(FILE* file){
    int ch;
    char *text;
    // if no file, exit
    if (!file) error1();
    // first position to 0 / guessed size is 8 (2^3)
    size_t pos = 0, size = 8;

    text = malloc(size*sizeof(char));
    // if allocation fails, return NULL
    if (!text) return NULL;
    // set the SEEK at the beginning of the file
    fseek(file, 0, SEEK_SET);
    // it checks all the chars, until it found the End of File (EOF = -1)
    while ((ch = fgetc(file)) != EOF) {
        text[pos] = (char)ch;
        pos++;

        if (pos >= size) {
            size += 8;
            // adapt the size
            text = realloc(text, size * sizeof(char));
        }
        if (!text) return NULL;
    }
    // remove empty allocation
    text = realloc(text, pos * sizeof(char));
    if (!text) return NULL;

    text[pos] = '\0';
    fseek(file, 0, SEEK_SET);
    return text;
}

/// prints the content given in argument in a .txt file given in argument
void printFile(FILE* file, char* content){
    if (!file) error1();
    fprintf(file, "%s", content);
}

/// returns the number of chars in a .txt file
int countCharFile(FILE* file){
    int count = 0, ch;

    if (!file) error1();
    fseek(file, 0, SEEK_SET);

    while (1) {
        ch = fgetc(file);
        if (ch == EOF) break;
        count++;
    }
    fseek(file, 0, SEEK_SET);
    return count;
}

/// returns the number of chars in a .txt file
size_t countLineFile(FILE* file){
    size_t line = 0;
    int ch = 0;
    while (ch != EOF) {
        ch = fgetc(file);
        if (ch == '\n' || ch == EOF) line++;
    }
    fseek(file, 0, SEEK_SET);
    return line;
}


/// creates an empty file, or empty the file, with the name given in argument
void emptyFile(char* name){
    FILE* file = fopen(name, "w+");

    if (!file) error1();
    char ch[1] = {"\0"};
    // writes down the empty char \0
    printFile(file, ch);
    fclose(file);
}
