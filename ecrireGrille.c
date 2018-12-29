#include <stdio.h>

void ecrireGrille(int *G[][]){

  int i, j;
  
  printf("------------------------------\n");
  
  for(i = 0, i < 9, i++){
    printf("| ");
    for(j = 0, j < 9, j++){
      printf("%d ", G[i][j]);
    }
    printf("|");
  }
  
  printf("------------------------------\n");
  
}
