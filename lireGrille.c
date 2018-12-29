#include <stdio.h>
#include <string.h>



void lireGrille(int *G[][]){
// module
    
    // On initialise à 0
    int i, j;
    for(i = 0, i < 9, i++){
        for(j = 0, j < 9, j++){
            G[i, j] = 0;
        }
    }
    
    // On lit dans le fichier texte pour remplir la grille
    FILE* fichier = NULL;

    fichier = fopen("grille_test.txt", "r");


    if (fichier != NULL)

    {

        // Lecture du fichier

    }

    else

    {

        // Erreur dans le cas où le fichier n'existe pas

        printf("Impossible d'ouvrir le fichier");

    }


}
