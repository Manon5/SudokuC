// Fonction finie et vérifiée : tout fonctionne

#include <stdio.h>

void ecrireGrille(int G[9][9]){

  int i, j;

  printf("-------------------------\n");

  for(i = 0; i < 9; i++){
    printf("| ");
    for(j = 0; j < 9; j++){
      printf("%d ", G[i][j]);
      if(j == 2 || j == 5){
        printf("| ");
      }
    }
    printf("|\n");
    if(i == 2 || i == 5){
       printf("|-------|-------|-------|\n");
    }
  }

   printf("-------------------------\n");

}
