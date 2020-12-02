#include "Dico.h"


//buscando lettre + bitsave
int *chemin(Noeud* a, char lettre){
    FILE *dico = NULL;

    dico = fopen("C:/Users/Juanito/Desktop/programmation/Huffman/dico.txt","a+");//open file

    fprintf(dico,"%c : ",lettre);

    Noeud* ojo = a; //oeil pour checker la lettre
    int buscando = 1;//demarage d'une boucle infini

    while(buscando == 1){

        ojo = a->sag;//l'oeil check toujours a gauche

        if (lettre != ojo->ch)//si la lettre ne correspond pas
        {
            printf("Vous n'etes pas sur la bonne lettre : %c & buscando %c bit : 1\n", ojo->ch, lettre);

            fputc('1',dico);//on écrit 1 dans le dico

            a = a->sad;//on va au noeud suivant



        }
        if (lettre == ojo->ch)
        {
            printf("Aqui esta : %c                                        bit : 0\n", ojo->ch);

            fputc('0',dico);
            fprintf(dico,"\n");

            buscando = 0;//fin de la boucle infini
        }
        if (lettre == a->ch)
        {
            printf("Aqui esta : %c\n", a->ch);

            buscando = 0;
        }
    }
}

void lecture_arbre(Noeud *a){//permet de lire l'abre en fonction des char et de les afficher dans l'odre de poids
    Noeud *check = a;//idem a ojo

    Noeud *copy = a;//copie de l'abre en local

    check = copy->sag;//idem que ojo

    while (copy) {
        if (check->ch != NULL)
        {
            printf("Lettre = %c\n", check->ch);
            //Normalement ici on appelle la fonction chemin mais l'adresse de l'abre ne fonctionne pas
        }

        copy = copy->sad;
        if (copy->ch != NULL)
        {
            printf("Lettre = %c\n", copy->ch);
            //Normalement ici on appelle la fonction chemin mais l'adresse de l'abre ne fonctionne pas
        }
        check = copy->sag;

    }
}