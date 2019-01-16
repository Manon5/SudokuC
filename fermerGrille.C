int fermerGrille(int G[9][9],Cand C[9][9], Case O[81], int NBO)
{
    Case coor;
    int fin, tampon,nb,i;
    fin=0;
    while((fin=!1)||(NBO!=0))
    {
        coor=rechCaseUnique(C,O,NBO);
        if(coor.x==NULL)    //teste si il y a une case unique dans coor
        {
        fin=1;
        }
        else
        {
            nb=C[coor.x][coor.y].tab[0];  //utile pour le printf plus bas
            fermerCase(G,C,coor);
            for(i=0;i<NBO;i++)
            {
                if((coor.x==O[i].x)&&(coor.y==O[i].y))  //prend la position de l'élément a retirer de O
                {
                    tampon=i;
                    break;
                }    
            }
            O[tampon]=O[NBO-1];  //ecrase l'élément ciblé par le dernier élément du tableau
            NBO--;
            printf("Elimination des candidats uniques...\n la case (%d,%d)est fermee avec le chiffre %d\n",coor.x,coor.y,nb);
            ecrireGrille(G);
            printf("Voici les candidats des %d cases ouvertes de la grille :",NBO);
            ecrireCand(C);
        }
        
    }
    if(NBO>0)
    {
        return(1);
    }
    return(0);
}
