int fermerGrille(G[9][9], Cand C[9][9], Case O[81], *NBO)
{
    int fin, i, j, k, br; //dif permet de savoir si la grille est finie
    fin=0;
    while(fin==0)
    {
        br=0;  //permet de savoir si il faut revenir au while
        for(i=0;i<*NBO;i++)
        {
            for(j=1;j<10;j++)  //test pour chaque cas possible
            {
                if (estCandUnique(C[9][9], O[i].x, O[i].y, j)==1)
                {
                    fermerCase(G[9][9], C[9][9], O[i], j);
                    for(k=i;k<*NBO+1;i++)
                    {
                        O[k]=O[k+1]; //déplace les élément de O 
                    }
                    *NBO--;
                    br=1;
                    break;
                }
            }
            if(br==1) break;
        }
    if(br==0) fin=1; // si il n'y a pas eu de case remplit, la grille est finie
    }   
    if(NBO>0) return(1); //dit que la grille est difficile
    else return(0); //dit que la grille est facile
    
}

