#include "Dico.h"

void createAVLDico(Arbre* dico, Arbre add){
    if (add) {
        if (add->ch != '\0') addNodeAVLch(dico, add);
        else {
            createAVLDico(dico, add->sad);
            createAVLDico(dico, add->sag);
        }
    }
}

void createBinCode(Arbre huffmanTree, char* binCode, int index) {
    if (huffmanTree) {
        if (huffmanTree->ch != '\0') {
            binCode[index] = '\0';
            huffmanTree->bin = (char*)malloc((index+1) * sizeof(char));
            strcpy(huffmanTree->bin, binCode);
        }
        binCode[index] = '0';
        createBinCode(huffmanTree->sag, binCode, index+1);
        binCode[index] = '1';
        createBinCode(huffmanTree->sad, binCode, index+1);
    }
}

void printDicoFile(Arbre dico, FILE* fDico) {
    if (!fDico) error1();
    if (dico) {
        printDicoFile(dico->sag, fDico);
        fprintf(fDico, "%c:%s\n", dico->ch, dico->bin);
        printDicoFile(dico->sad, fDico);
    }
}