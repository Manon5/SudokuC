#include <studio.h>

void initJeu(int G[][]*){
 
 int i, j,a,b;
 
 a=0;
  for(i=0;i<9;i++)
  {
    for(j=0;j<9;j++)
    {
      *C[i][j].nbc=0;
      *C[i][j].tab=NULL;
      if(*G[i][j]=0)
      {
       c=0;
       *O[c].x=i;
       *O[c].y=j;
       a++;
       for(b=1;b<10;b++){
        if(estCand()=1)
        {
         *C[i][j].nbc++;
         *C[i][j].*tab[c]=b;
         c++;
        }
      }
    }
  }
 *NBO=a;
}
