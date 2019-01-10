#include <stdio.h>

void ecrireGrille(int G[9][9]){

  int i, j;

  printf("------------------------------\n");

  for(i = 0; i < 9; i++){
    printf("| ");
    for(j = 0; j < 9; j++){
      printf("%d ", G[i][j]);
    }
    printf("|\n");
  }

  printf("------------------------------\n");

}
