//fichier dans lequel on va tout regrouper
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//définition de la TAILLE_SUDOKU des grilles (9x9)
#define ARETE 3
#define TAILLE_SUDOKU ARETE * ARETE
#define TAILLE_LIGNE 6

//--------------------------------------------------
//définition des types structures
typedef struct { 
  int x;     
  int y;     
} Case;

typedef struct {
  int nbc;         // no de candidats
  int * tab;       // table candidats
} Cand;

Case O[TAILLE_SUDOKU * TAILLE_SUDOKU];
Cand C[TAILLE_SUDOKU][TAILLE_SUDOKU];

int NBO;
int G[TAILLE_SUDOKU][TAILLE_SUDOKU];

//--------------------------------------------------
void initialiseGrille() {   
    int x, y;
    for (x = 0; x < TAILLE_SUDOKU; x++){
        for (y = 0; y < TAILLE_SUDOKU; y++){
           G[x][y] = 0;
        }
    }    
}

//--------------------------------------------------
int lireGrille(char* nomFichier){
    FILE* fichier = NULL;
    fichier = fopen(nomFichier, "r");
    int continuer = 1;

    if (fichier != NULL) {
        int i, j, valeur;
        char ligne[TAILLE_LIGNE];
        while (fgets(ligne, TAILLE_LIGNE, fichier) != NULL){
          sscanf(ligne, "%d %d %d", &i, &j, &valeur);
          G[i][j] = valeur;
        }
    } else {
         printf("Impossible d ouvrir le fichier %s\n", nomFichier);
         continuer = 0;
    }
    close(fichier);
    return(continuer);
}

//--------------------------------------------------
void ecrireGrille(){

  printf("-------------------------\n");

  int i, j;
  for(i = 0; i < TAILLE_SUDOKU; i++){
    printf("| ");
    for(j = 0; j < TAILLE_SUDOKU; j++){
      printf("%d ", G[i][j]);
      if (j % ARETE == 2){
         printf("| ");
      }
    }
    printf("\n");
    
    if ((i % ARETE == 2) && (i < (TAILLE_SUDOKU - 1))) {
       printf("|-------|-------|-------|\n");
    }
  }

  printf("-------------------------\n");
}

//--------------------------------------------------
int estCand(int nb, int x, int y) {
    
//printf("Candidat  %d,%d pour valeur %d: ", x,y, nb);

  // test sur les X
  int i;
  for (i=0; i < TAILLE_SUDOKU; i++) {
    if (G[i][y] == nb ) {
//printf(" => found on X at %d,%d\n", i, y);
        
      return(0);
    }
  }
  // test sur les Y
  int j;
  for (j=0; j < TAILLE_SUDOKU; j++) {
    if (G[x][j] == nb) {
//printf(" => found on Y at %d,%d\n", x, j);
      return(0);
    }
  }
  
  // test la region
  int I=(x / ARETE) * ARETE;
  int J=(y / ARETE) * ARETE;
  for (i=0; i < ARETE; i++) {
    for (j=0; j < ARETE; j++) {
      if (G[I+i][J+j] == nb) {
//printf(" => found in area %d,%d\n", I, J);
        return(0);
      }
    }
  }
//printf(" => %d is CANDIDAT\n", nb);

  return(1);
}

//--------------------------------------------------
int initJeu() {

  int NbrCasesOuvertes=0;
  
  int i, j;
  for (i=0; i < TAILLE_SUDOKU; i++) {
    for (j=0; j < TAILLE_SUDOKU; j++) {
      C[i][j].nbc=0;
      if (G[i][j] > 0) { 
        C[i][j].tab=NULL;
      } else {
        C[i][j].tab=calloc(TAILLE_SUDOKU, sizeof(int));
        
        int nbr;
        for (nbr=1; nbr <= TAILLE_SUDOKU; nbr++) {
          if (estCand(nbr, i, j)) {
            C[i][j].tab[C[i][j].nbc++]=nbr;   
          }
        }
        
        O[NbrCasesOuvertes].x=i;
        O[NbrCasesOuvertes].y=j;
        NbrCasesOuvertes++;
      }
    }
  }
  
  return(NbrCasesOuvertes);
}

//--------------------------------------------------
void ecrireCand() {
    
  printf("--------------------------------------------------------------------------------------------------------\n");

  int i, j;
  for(i = 0; i < TAILLE_SUDOKU; i++){
    printf("| ");
    for(j = 0; j < TAILLE_SUDOKU; j++){
        
      int l;
      for (l=0;  l < C[i][j].nbc; l++) {
        printf("%d",C[i][j].tab[l]);
      }
      for (l=C[i][j].nbc; l < TAILLE_SUDOKU; l++) {
         printf(" ");
      }

      if (j % ARETE == 2){
         printf("| ");
      } else {
         printf(" # ");
      }
    }
    printf("\n");
    
    if ((i % ARETE == 2) && (i < (TAILLE_SUDOKU - 1))) {
       printf("|----------------------------------|----------------------------------|----------------------------------|\n");
    }
  }

  printf("---------------------------------------------------------------------------------------------------------\n");
}

//--------------------------------------------------
int estCandUnique(int x, int y) {
      
  if (C[x][y].nbc == 1) {
printf("DBX: estCandUnique %d,%d :: %d\n", x, y, C[x][y].tab[0]);
    return(1);
  }
  return(0);
}

//--------------------------------------------------
int rechCaseUnique() {
   int c;
   for(c=0; c < NBO; c++) {
      if (estCandUnique(O[c].x,O[c].y)) {
         return(c);
      }
   }       
   return(-1);
}

//--------------------------------------------------
int appartient(int nb, int x, int y) {
  int i;
  for (i=0; i < C[x][y].nbc; i++) {
    if (nb == C[x][y].tab[i]) {
      return(1);
    }
  }
  return(0);
}

//--------------------------------------------------
void supprimer(int nb, int x, int y) {
  int i;
  for (i=0; i < C[x][y].nbc; i++) {
    if (nb == C[x][y].tab[i]) {
      C[x][y].tab[i]=C[x][y].tab[C[x][y].nbc-1];
      C[x][y].nbc--;
    }
  }   
}

//--------------------------------------------------
void nettoyerCases(int nb, int x, int y) {
    
  // purge sur les X
  int i;
  for (i=0; i < TAILLE_SUDOKU; i++) {
    if (appartient(nb, i, y)) {
 printf("DBX: cleaning X ::: %d, %d :: %d\n", i, y, nb);
       supprimer(nb, i, y);
    }
  }
  // purge sur les Y
  int j;
  for (j=0; j < TAILLE_SUDOKU; j++) {
    if (appartient(nb, x, j)) {
 printf("DBX: cleaning Y ::: %d, %d :: %d\n", x, j, nb);
       supprimer(nb, x, j);
    }
  }
  
  // purge la region
  int I=(x / ARETE) * ARETE;
  int J=(y / ARETE) * ARETE;
  for (i=0; i < ARETE; i++) {
    for (j=0; j < ARETE; j++) {
      if (appartient(nb,I+i, J+j)) { 
 printf("DBX: cleaning Zone ::: %d, %d :: %d\n", I+i, J+j, nb);
        supprimer(nb, I+i, J+j);
      }
    }
  }
}
//--------------------------------------------------
void fermerCase(int idx) {
   
   int val=C[O[idx].x][O[idx].y].tab[0];
   
   nettoyerCases(val, O[idx].x, O[idx].y);
   
   G[O[idx].x][O[idx].y]=val;
   
   free (C[O[idx].x][O[idx].y].tab);
   C[O[idx].x][O[idx].y].nbc=0;
   
   O[idx]=O[NBO-1];
   NBO--;
}

//--------------------------------------------------
void fermerGrille() {
    int idx;

    idx=rechCaseUnique();
    while (idx != -1) {
       fermerCase(idx);
       
       ecrireGrille();
       ecrireCand();
 
       idx=rechCaseUnique();
    }   
}

//--------------------------------------------------
//--------------------------------------------------
//--------------------------------------------------
int main() {
   initialiseGrille();

   if (lireGrille("grille_test.txt")) {
     ecrireGrille();
     
     NBO=initJeu();
     
     ecrireCand();
     
     fermerGrille();
      
     if (NBO > 0) {
       printf("La grille étant difficle, voici les condidats possibles pour les cases restantes\n");
        ecrireCand();
     } else {
       printf("Voici la grille finale\n");
       ecrireGrille();
     }
   }
}


