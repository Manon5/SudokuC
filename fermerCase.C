void fermerCase(int G[9][9], Cand C[9][9], Case ca){ 
  // On ferme la case
  G[ca.x, ca.y] = C[ca.x, ca.y].tab[0];

  // On retire le candidat des cases voisines
  int i, j;
  for (i = 0; i < 9; i++) { // on parcourt le tableau
    for (j = 0; j < 9; j++) {
      if(C[i, j] == 0 && estVoisine(ca.x, ca.y, i, j)){ // si la case est voisine et ouverte
        suppr(C, ca.x, ca.y, C[ca.x, ca.y].tab[0]); // on supprime le candidat de la liste
      }
    }
  }
}
