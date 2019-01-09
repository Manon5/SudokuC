int appartient(Cand *C[][], int x, int y, int nb){
  int i;
  for(i=0;i<*C[x][y].nbc;i++){
    if(nb=*C[x][y].tab[i])
      return(1);
  }
  return(0);
}
