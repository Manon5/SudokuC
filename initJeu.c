#include <studio.h>

void initJeu(int G[][]*)
{
 //module
 int i, j,a,b,c;
 
 a=0;
  for(i=0;i<9;i++)
  {
    for(j=0;j<9;j++)
    {
      if(*G[i][j]=0)   //détermine si la case est ouverte ou fermee
      {
       // On remplit la table O (case ouverte/fermee)
       c=0;
       *O[c].x=i;
       *O[c].y=j;
       a++;
       for(b=1;b<10;b++)
       {
        if(estCand()=1) //paramètres a rejouter après que la fonction est faite et determine si b est un nombre candidat
        {
         // On remplit la table C (liste des candidats)
         *C[i][j].nbc++;
         *C[i][j].*tab[c]=b;
         c++;
        }
       }
      }
      else
      {
       *C[i][j].nbc=0;
       *C[i][j].tab=NULL;
      } 
    }
  }
 *NBO=a; // Compteur de cases ouvertes
}
