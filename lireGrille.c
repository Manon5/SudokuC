#include <stdio.h>
#include <string.h>

lireGrille(){

    FILE* fichier = NULL;

    fichier = fopen("grille_test.txt", "r");


    if (fichier != NULL)

    {

        // Lecture du fichier

    }

    else

    {

        // Erreur

        printf("Impossible d'ouvrir le fichier");

    }


    return 0;

}
