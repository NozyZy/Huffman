#include "InteractWithFile.h"

/**
 * @brief Affiche l'erreur principal, pour un document non trouvé
 * 
 */
void error1(){
    printf("No such file or directory - error 1\n");
    exit(1);
}

/**
 * @brief Retourne le contenu d'un fichier.txt
 * 
 * @param file 
 * @return char* 
 */
char* loadFile(FILE* file){
    int ch;
    char *text;
    if (!file) error1();
    // first position to 0 / guessed size is 8 (2^3)
    size_t pos = 0, size = 8;

    text = malloc(size*sizeof(char));
    if (!text) return NULL;
    fseek(file, 0, SEEK_SET);
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

/**
 * @brief Affiche le contenu donné en argument dans un fichier donné en argument
 * 
 * @param file 
 * @param content 
 */
void printFile(FILE* file, char* content){
    if (!file) error1();
    fprintf(file, "%s", content);
}

/**
 * @brief Retourne le nombre de charactères dans un fichier .txt
 * 
 * @param file 
 * @return long unsigned int 
 */
size_t countCharFile(FILE* file){
    long unsigned int count = 0;
    int ch;

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

/**
 * @brief Crée un fichier vide ou vide un fichier, avec le nom donné en argument
 * 
 * @param name 
 */
void emptyFile(char* name){
    FILE* file = fopen(name, "w+");

    if (!file) error1();
    char ch[1] = {"\0"};
    // writes down the empty char \0
    printFile(file, ch);
    fclose(file);
}