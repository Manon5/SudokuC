Case rechCaseUnique(Cand C[9][9],Case O[81],int NBO){
  Case res;
  int i, k;
  res.x= NULL;
  res.y= NULL;
  for(i=0;i<NBO;i++){
    if(C[O[i].x][O[i].y].nbc==1){  
        for(k=1;k<10;k++){
          if(estCandUnique(C,O[i],k)==1){
            return O[i];
          }
        }
    } 
  }

  return res;
}
