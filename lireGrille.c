#include <stdio.h>
#include <string.h>

lireGrille(){

    FILE* fichier = NULL;

    fichier = fopen("grille_test.txt", "r");


    if (fichier != NULL)

    {

        // On peut lire et écrire dans le fichier

    }

    else

    {

        // On affiche un message d'erreur si on veut

        printf("Impossible d'ouvrir le fichier");

    }


    return 0;

}
