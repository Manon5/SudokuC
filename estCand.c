#include <stdio.h>


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
         
  
}
