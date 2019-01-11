// fonction pas terminée : ne fonctionne pas, surement à cause des types

#include <studio.h>

void initJeu(int G[][9], Cand *C[][9], int *NBO, Case *O[])
{
 //module
 int i, j,a,b,c;
 
 a=0;
  for(i=0;i<9;i++)
  {
    for(j=0;j<9;j++)
    {
      if(G[i][j]=0)   //détermine si la case est ouverte ou fermee
      {
       // On remplit la table O (case ouverte/fermee)
       c=0;
       (*O)[c].x=i; // O est de type case, si la cas est ouverte, O enregistre les coordonnée de la case
       (*O)[c].y=j;
       a++;
       for(b=1;b<10;b++)
       {
        if(estCand(j,i,G[][],b)=1) //determine si b est un nombre candidat
        {
         // On remplit la table C (liste des candidats)
         (*C)[i][j].nbc++;
         (*C)[i][j].*tab[c]=b;
         c++;
        }
       }
      }
      else
      {
       (*C)[i][j].nbc=0;
       (*C)[i][j].tab=NULL;
      } 
    }
  }
 *NBO=a; // Compteur de cases ouvertes
}
