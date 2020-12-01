#include "Dico.h"

// counts the number of char between all label given in argument (without \0 and \n)
// in a single line, given in argument, of a .txt file, given in argument
// the counting is put in an array of int given in argument
void countNbBitLine(FILE* file, size_t line, size_t* count, char label){
    if (count) {
        int ch;
        // i, nbLine, and nbC are only positive int, so size_t type is appropriate
        size_t i = 0, nbLine = 0, nbC = 0;

        // if file not found
        if (!file) error1();
        // sett the SEEK at the beginning of the file
        fseek(file, 0, SEEK_SET);
        // while not at the EOF, or the line asked for
        while ((ch = fgetc(file)) != EOF && nbLine < line - 1) {
            // counts all the char encountered, to set the SEEK later
            nbC++;
            if ((char) ch == '\n') nbLine++;
        }

        while (1) {
            // if the line has been totally read
            if (ch == EOF || (char) ch == '\n') break;
            // separates the counting array by the label
            if ((char) ch == label) {
                i++;
                // deletes the counting of the label itself
                count[i]--;
            }
            count[i]++;
            ch = fgetc(file);
        }
        // sett the SEEK at the beginning of the line asked (SEEK_SET need the number of char, here nbC + line - 1)
        fseek(file, (int) (nbC + line - 1), SEEK_SET);
    }
}

// fill a Def* given in argument, with the line of a file, all given in argument
void readFileDef(FILE* file, Def* def, size_t line){
    if (!file) error1();
    if (def) {
        size_t* nbChar = (size_t *) calloc(3, sizeof(size_t));
        // counts the number of char before and after the ':'
        countNbBitLine(file, line, nbChar, ':');
        if (nbChar) {
            if (nbChar[1] == 0) def->nbBit = nbChar[2];
            else def->nbBit = nbChar[1];
            def->bin = (char *) malloc(def->nbBit + 1 * sizeof(char));

            fscanf(file, "%c", &def->ch);
            // jump a line is /n in the dico, so we check the / first
            if (def->ch == '/') {
                char temp;
                fscanf(file, "%c", &temp);
                // if it's /n, change bin value, and do next the same way
                if (temp == 'n') {
                    def->ch = '\n';
                    fscanf(file, ":%s", def->bin);
                }
                    // if it's /:, read the bin without the :
                else fscanf(file, "%s", def->bin);
            } else fscanf(file, ":%s", def->bin);

            free(nbChar);
        }
    }
}

// fills a Dico* with a dico.txt file
void readFileDico(Dico* dico){
    FILE* fDico = fopen("../dico.txt", "r+");
    if (!fDico) error1();
    size_t nbLine = countLineFile(fDico), i = 0;
    // double dynamic allocation of the arrayDico
    dico->arrayDico = (Def**)malloc(nbLine*sizeof(Def*));
    dico->maxBitSize = 0;
    // dynamic allocation of each index of the array
    for (i = 0; i < nbLine; i++){
        dico->arrayDico[i] = (Def*)malloc(sizeof(Def));
        // fill the index, the Def, with the proper line of the dico.txt file
        readFileDef(fDico, dico->arrayDico[i], i+1);
        if (dico->arrayDico[i]->nbBit > dico->maxBitSize) dico->maxBitSize = dico->arrayDico[i]->nbBit;
    }
    dico->sizeDico = nbLine;

    fclose(fDico);
}