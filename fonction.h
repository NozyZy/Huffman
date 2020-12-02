#include <stdio.h>
#include <stdlib.h>

/**********************************
*******      Structures     *******
***********************************/

typedef struct Element {
	char ch;
	int occ;
	struct Element* suivant;
}Element;


typedef struct Noeud {
	char ch;
	int occ;
	struct Noeud* sad;
	struct Noeud* sag;
}Noeud;

/**********************************
*******      Fonctions      *******
***********************************/

Element* creerListe(const char* content, size_t nombreCaractere);
void afficherListe(char* label, Element* l);
Element* creerElement(char ch);
int verifElement(Element* l, char ch);
void ajoutListe(Element** l, char ch);
void freeList(Element* l);

Element* elementMinimum(Element* l);
void afficherArbre(Noeud *a);
void supprimerElement(Element **l, char ch);
void lecture_arbre(Noeud*);
Noeud* creerNoeud(char ch, size_t occ);
Noeud* creeArbre(Element* l);
int *chemin(Noeud* , char);
void freeArbre(Noeud* a);


//ecrire dans les fichier
void error1();							   // prints the main error, for no file found
char *loadFile(FILE *file);				   // loads the content of a .txt file, given in argument, in a char*
void printFile(FILE *file, char *content); // prints the content of a .txt file
int countCharFile(FILE *file);			   // returns the number of chars in a .txt file
void emptyFile(char *name);				   // create or empty a file
void int2bin(int n, char *bin);			   // convert decimal into binary
void textFileToBinFile(FILE *file);		   // convert a text file into a binary text file