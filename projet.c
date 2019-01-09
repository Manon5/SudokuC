//fichier dans lequel on va tout regrouper
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//définition de la taille des grilles (9x9)
#define TAILLE 9

//définition des types structures
typedef struct { //modifier les x et y si utilisation d'autres noms de variables
int x; // no de ligne
int y; // no de colonne
} Case;

typedef struct {
int nbc; // no de candidats
int * tab; // table candidats
} Cand;






void lireGrille(int *G[][]){
// module

    // On initialise à 0
    int i, j, l, c, v;
    for(i = 0, i < 9, i++){
        for(j = 0, j < 9, j++){
            G[i, j] = 0;
        }
    }

    // On lit dans le fichier texte pour remplir la grille
    FILE* fichier = NULL;
    fichier = fopen("grille_test.txt", "r");

    if (fichier != NULL){
        // Lecture du fichier
        while(getchar() != EOF){
          fscanf(fichier, "%d %d %d", &l, &c, &v);
          G[l][c] = v;
        }        
    }

    else{
        // Erreur dans le cas où le fichier n'existe pas

        printf("Impossible d'ouvrir le fichier");
    }


}


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


void initJeu(int *G[][])
{
 //module
 int i, j,a,b,c;
 
 a=0;
  for(i=0;i<9;i++)
  {
    for(j=0;j<9;j++)
    {
      if(*G[i][j]=0)   //détermine si la case est ouverte ou fermee
      {
       // On remplit la table O (case ouverte/fermee)
       c=0;
       *O[c].x=i;
       *O[c].y=j;
       a++;
       for(b=1;b<10;b++)
       {
        if(estCand(j,i,*G[][],b)=1) //determine si b est un nombre candidat
        {
         // On remplit la table C (liste des candidats)
         *C[i][j].nbc++;
         *C[i][j].*tab[c]=b;
         c++;
        }
       }
      }
      else
      {
       *C[i][j].nbc=0;
       *C[i][j].tab=NULL;
      } 
    }
  }
 *NBO=a; // Compteur de cases ouvertes
}


int quelleZone(int colonne, int ligne){
  // determine a quelle zone appartient une case (utilise dans estVoisine)
  int zone = 0;
  
  // en fonction de la colonne
  if(colonne < 3){
    zone =  1;
  }else if(colonne < 6){
    zone = 2;
  }else{
    zone = 3;
  }
  
  // En fonction de la ligne
  if(ligne > 5){
    zone = zone + 6;
  }else if(ligne > 3){
    zone  = zone + 3;
  }
  
  // on retourne le resultat
  return zone;
  
}


int estVoisine(int cA, int lA, int cB, int lB){  
  // determine si deux cases sont voisines (utilise dans estCand)
  // cA = colonne de la case A, lA = ligne de la case A

  int res = 0; //initialisation du resultat

  //on teste si A et B sont dans la meme ligne
  if(lA == lB){
    res = 1; // la case est voisine
  }
  // on teste si A et B sont dans la meme colonne
  else if(cA == cB){
    res = 1; // la case est voisine
  }
  // on teste si A et B sont dans la meme zone
  else if(quelleZone(cA,lA) == quelleZone(cB, lB){
    res = 1;
  }
          
          
  // on retourne le resultat
  return res;

}

          
int estCand(int col, int lig, int *G[][], int nb){ 
  // determine si un nombre nb est candidat pour une case donnee

  
  int i, j; // On parcourt toute la grille
  int res = 1; // on initialise à VRAI
  
  for(i = 0, i < 9, i++){
    for(j = 0, j < 9, j++){
      if(estVoisine(i, j, col, lig){
        // Les cases sont voisines : on teste si la case vaut nb
        if(G[i][j] == nb){
          // Meme valeur que nb : nb n'est pas candidat
          res = 0;
      }
    }
  }
  return res;       
  
}
         
         
int appartient(Cand C[][], int x, int y, int nb){
  int i;
  for(i=0;i<C[x][y].nbc;i++){
    if(nb=C[x][y].tab[i])
      return(1);
  }
  return(0);
}
       
         
int estCandUnique(Cand C[][9], int x, int y, int nb){
    if((C[x][y].nbc=!1)||(C[x][y].tab[0]=!nb))
    return(0);
    return(1);
}

         
Case rechCaseUnique(Cand C[][9]){
  Case coor;
  int i, j, n;
  coor.x=NULL;
  coor.y=NULL;
  for(i=0;i<9;i++){
    for(j=0;j<9;j++){
      if (C[i][j].nbc=!0){
        for(n=1;n<10;n++){
          if(estCandUnique(C[9][9],i,j,n)==1){
            coor.x=i;
            coor.y=j;
            return(coor);
          }
        }
      }
    }
  }

  return(coor);
}
         
         
//fonction permettant de supprimer 
         
         
 
