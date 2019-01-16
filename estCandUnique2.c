int estCandUnique(Cand C[9][9], int x, int y, Case CA, int nb){
    if((C[CA.x][CA.y].nbc!=1)||(C[CA.x][CA.y].tab[0]!=nb))
    return(0);
    else return(1);
}
