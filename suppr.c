
void suppr(Cand C[9][9], int x, int y, int nb ){
  int i,t;
  for(i=0;i<C[x][y].nbc;i++){
    if(C[x][y].tab[i]==nb){
      C[x][y].tab[i]=NULL;
      t=i;
      break;
    }
  }
  for(i=t;i<C[x][y].nbc-1;i++){
    C[x][y].tab[i]=C[x][y].tab[i+1];
  }
  C[x][y].nbc--;
}
