
void fermerCase(int *G[][9], Cand *C[][9], Case coor,int nb){
  int i, part, j;
  Case coor2;
  coor2.x=0;
  coor2.y=0;
  *G[coor.x][coor.y]=nb;
  (*C)[coor.x][coor.y].nbc=0;
  (*C)[coor.x][coor.y].tab=NULL;
  for(i=0;i<9;i++){
    if(appartient(C[9][9], i, coor.y, nb)==1){
      suppr(*C[9][9], i, coor.y, nb);  //fonction a faire : supprime la case du nombre dans le tableau et décale vers la droite c'elle après et fait nbc-1
    }
  }
  for(i=0;i<9;i++){
    if(appartient(C[9][9], coor.x, i, nb)==1){
      suppr(*C[9][9], coor.x, i, nb);
    }
  }
  part=quelleZone(coor.y, coor.x);
  switch(part){
    case 2:coor.y+=3; break;
    case 3:coor.y+=6; break;
    case 4:coor.x+=3; break;
    case 5:coor.y+=3;coor.x+=3; break;
    case 6:coor.y+=6;coor.x+=3; break;
    case 7:coor.x+=6; break;
    case 8:coor.y+=3;coor.x+=6; break;
    case 9:coor.y+=6;coor.x+=6; break;
  }
  for (i=0;i<3;i++){
    for(j=0;j<3;j++){
      if(appartient(C[9][9], coor.x + i, coor.y + j, nb)==1){
        suppr(*C[9][9], coor.x + i, coor.y + j, nb);
      }
    }
  }
