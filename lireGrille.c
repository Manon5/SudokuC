#include <stdio.h>
#include <string.h>

int G[9] [9]

void lireGrille(){
// module
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
