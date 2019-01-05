#include <stdio.h>

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


// on retourne le resultat
return res;

}

int estCand(){ 
// determine si un nombre est candidat pour une case donnee

}
