#include <studio.h>

void initJeu(int G[][]*){
 
 int i, j,c;
 c=0;
  for(i=0;i<9;i++)
  {
    for(j=0;j<9;j++)
    {
      if(*G[i][j]=0)
      {
       *O[c].x=i;
       *O[c].y=j;
       c++;
    }
  }
 *NBO=c;
}
