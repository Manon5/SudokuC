#include <stdio.h>
#include <string.h>

int G[9] [9] //tableau à utiliser (je l'ai mis là pour ne pas oublier son initialisation)

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


}
