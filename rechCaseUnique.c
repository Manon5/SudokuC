// a changer en utilisant O
Case rechCaseUnique(Cand C[][9]){
  Case coor;
  int i, j, n;
  coor.x=NULL;
  coor.y=NULL;
  for(i=0;i<9;i++){
    for(j=0;j<9;j++){
      if (C[i][j].nbc==1){
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
