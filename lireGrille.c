// Fonction terminée et vérifiée

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void lireGrille(int G[9][9]){
// module

    // On initialise à 0
    int i, j, l, c, v;
    char tab[20];
    for(i = 0; i < 9; i++){
        for(j = 0; j < 9; j++){
            G[i][j] = 0;
        }
    }

    // On lit dans le fichier texte pour remplir la grille
    FILE* fichier = NULL;
    fichier = fopen("grille_tes.txt", "r");


    if (fichier != NULL){
        // Lecture du fichier
        while(fgets(tab, 20, fichier) != NULL){
          sscanf(tab, "%d %d %d", &l, &c, &v);
          G[l][c] = v;
        }
    }

    else{
        // Erreur dans le cas où le fichier n'existe pas

        printf("Impossible d'ouvrir le fichier\n");
    }


}
