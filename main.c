#include "bin/Huffman/Coding.h"

#if defined POSIX
    #define CLEAR system ( "clear" )
#elif defined MSDOS || defined WIN32
    #define CLEAR system ( "cls" )
#endif

int main(void) {
    int choice = 0;

    while (choice != 3) {
        printf("\n--------------Compresseur de fichier Huffman---------------\n");
        printf("\n\n   Que desirez-vous faire ?");
        printf("\n .1 -> Compresser mon fichier 'input.txt'");
        printf("\n .2 -> Decompresser mon fichier 'huffman.txt'");
        printf("\n .3 -> Fermer le programme");
        printf("\n\n ATTENTION :\n - Tous vos fichiers seront ecrases par les nouveaux, assurez-vous de faire les sauvegardes necessaires si besoin.");
        printf("\n - Assurez-vous que vos fichiers soient places dans le dossier parent de l'executable !\n\n");
        while (choice < 1 || choice > 3) {
            printf(" Votre choix -> ");
            scanf("%d", &choice);
        }

        switch (choice) {
        case (1):
            zipFile("../input.txt", "../huffman.txt");
            printf("\nOuverture du fichier compresse 'huffman.txt', en attente de sa fermeture...\n");
            printf("Compression Ratio : %f%%\n", calculateRatio());
            system("..\\huffman.txt");
            choice = 0;
            break;
        case (2):
            unzipFile("../dico.txt", "../huffman.txt");
            printf("\nOuverture du fichier 'dico.txt', en attente de sa fermeture...\n");
            system("..\\dico.txt");
            choice = 0;
            break;
        default:
            printf("\nFermeture du programme...\n");
            printf("\nOuverture du fichier decompresse 'output.txt', en attente de sa fermeture...\n");
            system("..\\output.txt");
            break;
        }
        system("PAUSE");
        CLEAR;
    }
  
    return EXIT_SUCCESS;
}
