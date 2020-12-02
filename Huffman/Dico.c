#include "Dico.h"


void createDicoFile(Noeud *a, char* dicoName){//permet de lire l'abre en fonction des char et de les afficher dans l'odre de poids
    if (a) {
        emptyFile(dicoName);
        FILE *fDico = NULL;

        fDico = fopen(dicoName, "a+");
        if (!fDico) error1();

        char* code = (char*)malloc(a->occ*sizeof(char)), *copy;
        Noeud *eye = NULL; //oeil pour checker la lettre
        int i = -1;
        while (a) {
            i++;
            eye = a->sag;  //l'oeil check toujours a gauche
            if (eye) {
                code[i] = '0';
                if (eye->ch != '\0') {
                    copy = code;
                    copy[i + 1] = '\0';
                    if (eye->ch == '\n') fprintf(fDico, "%s:%s\n", "/n", copy);
                    else fprintf(fDico, "%c:%s\n", eye->ch, copy);
                }
            }
            code[i] = '1';
            if (a->ch != '\0') {
                code[i] = '\0';
                fprintf(fDico, "%c:%s\n", a->ch, code);
            }
            a = a->sad;
        }
        fclose(fDico);
        free(code);
    }
}