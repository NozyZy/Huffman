#include "InteractWithFile.h"

// prints the main error, for file not found
void error1(){
    printf("No such file or directory - error 1\n");
    exit(1);
}

// returns the content of a .txt file, given in argument, in a char*
char* loadFile(FILE* file){
    int ch;
    char *text;
    // if no file, exit
    if (!file) error1();
    // first position to 0 / guessed size is 8 (2^3)
    size_t pos = 0, cap = 8;

    text = malloc(cap*sizeof(char));
    // if allocation fails, return NULL
    if (!text) return NULL;
    // set the SEEK at the beginning of the file
    fseek(file, 0, SEEK_SET);
    // it checks all the chars, until it found the End of File (EOF = -1)
    while ((ch = fgetc(file)) != EOF) {
        text[pos] = (char)ch;
        pos++;

        // if bigger than 8, add 8
        if (pos >= cap) {
            cap += 8;
            // adapt the size
            text = realloc(text, cap * sizeof(char));
        }
        if (!text) return NULL;
    }
    // remove empty allocation
    text = realloc(text, pos * sizeof(char));
    if (!text) return NULL;

    text[pos] = '\0';
    // set the SEEK to the beginning of the file
    fseek(file, 0, SEEK_SET);
    return text;
}

// prints the content given in argument in a .txt file given in argument
void printFile(FILE* file, char* content){
    // if no file, exit
    if (!file) error1();
    // prints all the content in the file
    fprintf(file, "%s", content);
}

// returns the number of chars in a .txt file
int countCharFile(FILE* file){
    int count = 0, ch;
    // if no file, exit
    if (!file) error1();
    // set the SEEK to the beginning of the file
    fseek(file, 0, SEEK_SET);
    while (1) {
        ch = fgetc(file);
        // if End Of File, stop the loop
        if (ch == EOF) break;
        count++;
    }
    fseek(file, 0, SEEK_SET);
    return count;
}

// creates an empty file, or empty the file, with the name given in argument
void emptyFile(char* name){
    FILE* file = fopen(name, "w+");
    // if no file, exit
    if (!file) error1();
    char ch[1] = {"\0"};
    // writes in the empty char \0
    printFile(file, ch);
    fclose(file);
}
