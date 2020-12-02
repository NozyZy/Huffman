#include "fonction.h"
//ecrire et lire
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
    // first position to 0 / guessed size is 256 (2^8)
    size_t pos = 0, cap = 256;

    text = malloc((cap)*sizeof(char));
    // if allocation fails, return NULL
    if (!text) return NULL;
    // set the SEEK at the beginning of the file
    fseek(file, 0, SEEK_SET);
    // it checks all the chars, until it found the End of File (EOF = -1)
    while ((ch = fgetc(file)) != EOF) {
        text[pos] = (char)ch;
        pos++;

        // if bigger than 256, add 256
        if (pos >= cap) cap += 256;

        // adapt the size
        text = realloc(text, (cap+1)*sizeof(char));
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

// converts a decimal int given in argument in a char* binary given in argument
void int2bin(int n, char* bin){
    // only for positive decimal
    if (n > 0) {
        int i;
        char nb[2];
        for (i = 0; i < 8; i++) {
            // converts int n%2 (0 or 1) in a char
        	sprintf(nb, "%d", (n%2));
        	// fills the array upside down, to have a good binary
        	bin[7-i] = nb[0];
        	n = n/2;
        }
        bin[8] = '\0';
    }
}

// converts a text file in argument into an output.txt in binary
void textFileToBinFile(FILE* file){
    FILE* fBin;
    char *content = NULL, *bin = NULL;
    size_t size = 0, i = 0;
    // empty the output.txt file
    emptyFile("../output.txt");
    // open outputs.txt to add binary number, one by one (so not write "w+")
    fBin = fopen("../output.txt", "a+");
    // if no file found
    if(!fBin) error1();

    content = loadFile(file);
    size = countCharFile(file);
    bin = (char*)malloc(9*sizeof(char));

    for(i = 0; i < size; i++){
        // convert content of file in the bin char*
        int2bin((int)content[i], bin);
        // pints the binary char* into the fBin file
        printFile(fBin, bin);
    }
    free(bin);
    fclose(fBin);
}


/**********************************
*******     Occurrences     *******
***********************************/

void afficherListe(char* label, Element*  l) {
	if (label) printf("%s : ", label);
	while (l) {
		printf("->(%c|%d)", l->ch, l->occ);
		l = l->suivant;
	}
	printf("->x\n");
}

Element * creerElement(char ch) {
	Element* lNew = (Element*)malloc(sizeof(Element));
	lNew->ch = ch;
	lNew->occ = 1;
	lNew->suivant = NULL;
	return lNew;
}

int verifElement(Element* l, char ch) {
	if (!l) return 0;									// le caractère n'est pas listé
	else {
		if (l->ch == ch) return 1;						// on a trouvé le caractère dans la liste
		else return verifElement((l->suivant), ch);		// rien a signaler, le caractère n'est pas encore listé, on regarde pour le suivant
	}	
}

void ajoutListe(Element** l, char ch) {
	if (*l) {
        if ((*l)->ch == ch) (*l)->occ = (*l)->occ + 1;   // on a trouvé le caractère dans la liste
        else ajoutListe(&((*l)->suivant), ch);    // rien a signaler, le caractère n'est pas encore listé, on regarde pour le suivant
    }
}

void freeList(Element* l) {
	if (l) {
		freeList((l)->suivant);
		free(l);
	}
}

Element* creerListe(const char* content, size_t nbCaractere) {
	if (nbCaractere == 0) return NULL;
	else {
		Element* lpremiere = (Element*)malloc(sizeof(Element)) ;
		Element* l;
		lpremiere->ch = content[0];					        // initialisation du premier element
		lpremiere->occ = 1;
		lpremiere->suivant = NULL;
		l = lpremiere;
		int i = 1;										    // compter de 1 à nbCaractere - 1
		while (i != nbCaractere) {
			char ch = content[i];

            if (ch != '\0') {
                if (verifElement(lpremiere, ch) == 1) {		// on doit ajouter une occurrence
                    ajoutListe(&lpremiere, ch);
                }
                else {										// on doit l'ajouter à la liste
                    l->suivant = creerElement(ch);
                    l = l->suivant;
                }
            }
			i = i+1;
		}
		return lpremiere;
	}	
}

Element* elementMinimum(Element* l) {
	Element* charMinimum = (Element*)malloc(sizeof(Element));
	charMinimum->ch = l->ch;
	charMinimum->occ = l->occ;
	while (l) {
		if (l->occ < charMinimum->occ) {
			charMinimum->ch = l->ch;
			charMinimum->occ = l->occ;
		}
		l = l->suivant;
	}
	return charMinimum;
}

void supprimerElement(Element** l, char ch) {
	Element* prec = *l;
	Element* cour = *l;
	Element* rm = NULL;
	while (cour) {
		if (cour->ch == ch) {
			if (*l == cour) {
			    rm = cour;
				*l = cour->suivant;
				cour = *l;
				free(rm);
			}
			else {
				prec->suivant = cour->suivant;
				cour = prec->suivant;
			}
		}
		else {
			prec = cour;
			cour = cour->suivant;
		}
	}
}

/**********************************
*******        Arbre        *******
***********************************/

Noeud* creerNoeud(char ch, size_t occ) {
    Noeud* a = (Noeud*)malloc(sizeof(Noeud));
    a->ch = ch;
    a->occ = occ;
    a->sag = NULL;
    a->sad = NULL;
    return a;
}

void afficherArbre(Noeud* a) {
	if (a) {
		printf("[%c] : [%d]", a->ch, a->occ);
		if (a->sag) {
			printf("\nA gauche de (%c|%d) : \t", a->ch, a->occ);
			afficherArbre(a->sag);
		}
		else printf("\t");
		if (a->sad) {
            printf("\tA droite de (%c|%d) : \t", a->ch, a->occ);
            afficherArbre(a->sad);
        }
	}
}

Noeud* creeArbre(Element* l)
{
	Noeud* a = creerNoeud('\0', 0);

	Element* lEnCours;
	lEnCours = l;
	if (!l) return NULL;
	else {
		Noeud* aPremiere = creerNoeud('\0', 0);

		Element* tmp = elementMinimum(lEnCours);
		Noeud* aDroit = creerNoeud(tmp->ch, tmp->occ);
	    supprimerElement(&lEnCours, tmp->ch);

		tmp = elementMinimum(lEnCours);
        Noeud* aGauche = creerNoeud(tmp->ch, tmp->occ);
		supprimerElement(&lEnCours, tmp->ch);

		aPremiere->sad = aDroit;
		aPremiere->sag = aGauche;
		aPremiere->occ = (aPremiere->sad->occ) + (aPremiere->sag->occ);

		a->sad = aPremiere;
	}
	while (lEnCours->suivant) {
		Element* tmp = elementMinimum(lEnCours);
		Noeud* newA = creerNoeud(tmp->ch, tmp->occ);
		supprimerElement(&lEnCours, tmp->ch);

		Noeud* branchA = creerNoeud('\0', (newA->occ) + (a->sad->occ));
		branchA->sad = a->sad;
		branchA->sag = newA;
		a->sad = branchA;
	}
	Element* tmp = elementMinimum(lEnCours);
	Noeud* newA = creerNoeud(tmp->ch, tmp->occ);
	supprimerElement(&lEnCours, tmp->ch);

	a->occ = (newA->occ) + (a->sad->occ);
	a->sad = a->sad;
	a->sag = newA;
	return a;
}

//buscando lettre + bitsave
int *chemin(Noeud* a, char lettre){
	FILE *dico = NULL;

	dico = fopen("C:/Users/Juanito/Desktop/programmation/Huffman/dico.txt","r+");

	fprintf(dico,"Lettre = %c et son bit = ",lettre);

    Noeud* ojo = a;
    int buscando = 1;
	int i = 0;
	int *save = NULL;
	save = malloc(sizeof(int));

    while(buscando == 1){

        ojo = a->sag;

        if (lettre != ojo->ch)
        {
            printf("Vous n'etes pas sur la bonne lettre : %c & buscando %c bit : 1\n", ojo->ch, lettre);
			fputc('1',dico);
            a = a->sad;
			save[i] = 1;
			i++;

        }
        if (lettre == ojo->ch)
        {
            printf("Aqui esta : %c                                        bit : 0\n", ojo->ch);
			fputc('0',dico);
			fprintf(dico,"\n");
			save[i] = 0;
            buscando = 0;
        }
        if (lettre == a->ch)
        {
            printf("Aqui esta : %c\n", a->ch);
			fputc('1',dico);
			save[i] = 1;
            buscando = 0;
        }
    }
	return save;
	free(save);
	
}

void lecture_arbre(Noeud *a){
	Noeud *check = a;

	Noeud *copy = a;

	check = copy->sag;

	while (copy)
	{
		if (check->ch != NULL)
		{
			printf("Lettre = %c\n", check->ch);


		}

		copy = copy->sad;
		if (copy->ch != NULL)
		{
			printf("Lettre = %c\n", copy->ch);


		}
		check = copy->sag;
		
	}
}

void freeArbre(Noeud* a) {
	if (a) {
		if (a->sad) freeArbre(a->sad);
		if (a->sag) freeArbre(a->sag);
		free(a);
	}
}
