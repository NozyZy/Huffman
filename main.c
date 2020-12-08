#include "Huffman/Coding.h"

int main(void) {
    int choice = 0;
    printf("\n--------------Compresseur de fichier Huffman---------------\n");
    printf("\n\n   Que desirez-vous faire ?");
    printf("\n .1 -> Compresser mon fichier 'input.txt'");
    printf("\n .2 -> Decompresser mon fichier 'huffman.txt'");
    printf("\n .3 -> Fermer le programme");
    printf("\n\n ATTENTION : Tous vos fichiers seront ecrases par les nouveaux, assurez-vous de faire les sauvegardes necessaires si besoin.\n\n");
    while (choice < 1 || choice > 3) {
        printf(" Votre choix -> ");
        scanf("%d", &choice);
    }

    switch (choice){
        case (1):
            zipFile("../input.txt", "../huffman.txt");
            break;
        case (2):
            unzipFile("../dico.txt", "../huffman.txt");
            break;
        default:
            printf("\nFermeture du programme...\n");
            break;
    }

    system("PAUSE");

    return EXIT_SUCCESS;
}