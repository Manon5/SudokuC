//fichier dans lequel on va tout regrouper
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//définition de la taille des grilles (9x9)
#define TAILLE 9

//définition des types structures
typedef struct { //modifier les x et y si utilisation d'autres noms de variables
int x; // no de ligne
int y; // no de colonne
} Case;

typedef struct {
int nbc; // no de candidats
int tab[9]; // table candidats
} Cand;

//initialisation des fonctions, variables et tableaux
int tab[9];
int G[TAILLE][TAILLE];
Case O[81];
Cand C[9][9];
void lireGrille();
void ecrireGrille(int[9][9]);
void initJeu(int[9][9], Cand[9][9] , Case[81],int*);
int quelleZone(int, int); //fonction utilisée dans estVoisine
int estVoisine(int, int, int, int); //fonction utilisée dans estCand
int estCand(int, int, int[9][9], int);
int appartient(Cand[9][9], int, int, int);;
int estCandUnique(Cand[9][9], int, int, int);
Case rechCaseUnique(Cand[9][9],Case[81], int);
void suppr(Cand[9][9], int, int, int); //module utilisé dans le module fermerCase
void fermerCase(int[9][9], Cand[9][9], Case, int);
int fermerGrille(int[9][9], Cand[9][9], Case[81], int*);
int ecrireCand();//pas oublier le ecrire cand dans fermergrille

int main()
{
  int fac, NBO,i;
lireGrille(G);
ecrireGrille(G);//a completer et faire plus dans les autre fonctions
initJeu(G,C,O,&NBO);
fac=fermerGrille(G,C,O,&NBO);
printf("Voici la grille finale\n");
ecrireGrille(G);
if(fac==1){
printf("La grille étant difficle, voici les condidats possibles pour les cases restantes\n");
  //ecrireCand(); //ecrire cand a compléter
}


}

void lireGrille(int G[9][9]){
// module

    // On initialise à 0
    int i, j, l, c, v;
    char tab[20];
    for(i = 0; i < 9; i++){
        for(j = 0; j < 9; j++){
            G[i][j] = 0;
        }
    }

    // On lit dans le fichier texte pour remplir la grille
    FILE* fichier = NULL;
    fichier = fopen("grille_test.txt", "r");


    if (fichier != NULL){
        // Lecture du fichier
        while(fgets(tab, 20, fichier) != NULL){
          sscanf(tab, "%d %d %d", &l, &c, &v);
          G[l][c] = v;
        }
    }

    else{
        // Erreur dans le cas où le fichier n'existe pas

        printf("Impossible d ouvrir le fichier\n");
    }


}

void ecrireGrille(int G[9][9]){

  int i, j;

  printf("-------------------------\n");

  for(i = 0; i < 9; i++){
    printf("| ");
    for(j = 0; j < 9; j++){
      printf("%d ", G[i][j]);
      if(j == 2 || j == 5){
        printf("| ");
      }
    }
    printf("|\n");
    if(i == 2 || i == 5){
       printf("|-------|-------|-------|\n");
    }TAILLE;
  }

   printf("-------------------------\n");

}

void initJeu(int G[9][9], Cand C[9][9], Case O[81],int *NBO)
{
 //module
 int i, j,w,b,c,r;
 w=0;
  for(i=0;i<9;i++)
  {
    for(j=0;j<9;j++)
    {
      C[i][j].nbc=0;
      if(G[i][j]==0)   //détermine si la case est ouverte ou fermee
      {
       // On remplit la table O (case ouverte/fermee)
       c=0;
       O[w].x=i; // O est de type case, si la cas est ouverte, O enregistre les coordonnée de la case
       O[w].y=j;
      w++;
      for(b=1;b<10;b++)
       {
        if(estCand(j,i,G,b)==1) //determine si b est un nombre candidat
        {
         // On remplit la table C (liste des candidats)
         C[i][j].nbc++;
         C[i][j].tab[c]=b;
         c++;
       }
        }
          
      }
      else
      {
        for(r=0;r<9;r++)
       C[i][j].tab[r]=NULL ;
     }
    }
  }
 *NBO=w; // Compteur de cases ouvertes
}

int quelleZone(int colonne, int ligne){
  // determine a quelle zone appartient une case (utilise dans estVoisine)
  int zone = 0;

  // en fonction de la colonne
  if(colonne < 3){
    zone =  1;
  }else if(colonne < 6){
    zone = 2;
  }else{
    zone = 3;
  }

  // En fonction de la ligne
  if(ligne > 5){
    zone = zone + 6;
  }else if(ligne > 3){
    zone  = zone + 3;
  }

  // on retourne le resultat
  return zone;

}

int estVoisine(int cA, int lA, int cB, int lB){
  // determine si deux cases sont voisines (utilise dans estCand)
  // cA = colonne de la case A, lA = ligne de la case A

  int res = 0; //initialisation du resultat

  //on teste si A et B sont dans la meme ligne
  if(lA == lB){
    res = 1; // la case est voisine
  }
  // on teste si A et B sont dans la meme colonne
  else if(cA == cB){
    res = 1; // la case est voisine
  }
  // on teste si A et B sont dans la meme zone
  else if(quelleZone(cA,lA) == quelleZone(cB, lB)){
    res = 1;
  }


  // on retourne le resultat
  return res;

}

int estCand(int col, int lig, int G[9][9], int nb){
  // determine si un nombre nb est candidat pour une case donnee


  int i, j; // On parcourt toute la grille
  int res = 1; // on initialise à VRAI

  for(i = 0; i < 9; i++){
    for(j = 0; j < 9; j++){
      if(estVoisine(j, i, col, lig)){
        // Les cases sont voisines : on teste si la case vaut nb
        if(G[i][j] == nb){
          // Meme valeur que nb : nb n'est pas candidat
          res = 0;
        }
      }
    }
  }
  return res;
}

int appartient(Cand C[9][9], int x, int y, int nb){
  int i;
  for(i=0;i<C[x][y].nbc;i++){
    if(nb=C[x][y].tab[i])
      return(1);
  }
  return(0);
}

int estCandUnique(Cand C[9][9], int x, int y, int nb){
    if((C[x][y].nbc=!1)||(C[x][y].tab[0]=!nb))
    return(0);
    else return(1);
}

Case rechCaseUnique(Cand C[9][9],Case O[81],int NBO){
  Case coor;
  int i, n;
  coor.x=NULL;
  coor.y=NULL;
  for(i=0;i<NBO;i++)
    {
    if(C[O[i].x][O[i].y].nbc+1==1)
        {
        for(n=1;n<10;n++){
          if(estCandUnique(C,O[i].x,O[i].y,n)==1){
            coor.x=O[i].x;
            coor.y=O[i].y;
            return(coor);
          }
        }
      
    } 
  }

  return(coor);
}

void suppr(Cand C[9][9], int x, int y, int nb ){
  int i,t;
  for(i=0;i<C[x][y].nbc;i++){
    if(C[x][y].tab[i]==nb){
      C[x][y].tab[i]=NULL;
      t=i;
      break;
    }
  }
  for(i=t;i<C[x][y].nbc-1;i++){
    C[x][y].tab[i]=C[x][y].tab[i+1];
  }
  C[x][y].nbc--;
}

void fermerCase(int G[9][9], Cand C[9][9], Case coor,int nb){ // coor c'est une case du tableau de O
  int i, part, j,r;
  G[coor.x][coor.y]=nb;
  C[coor.x][coor.y].nbc=0;
  for(r=0;r<9;r++)
  C[coor.x][coor.y].tab[r]=NULL;
  for(i=0;i<9;i++){
    if(appartient(C, i, coor.y, nb)==1){
      suppr(C, i, coor.y, nb);  //fonction a faire : supprime la case du nombre dans le tableau et décale vers la droite c'elle après et fait nbc-1
    }
  }
  for(i=0;i<9;i++) {
    if(appartient(C, coor.x, i, nb)==1){
      suppr(C, coor.x, i, nb);
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
      if(appartient(C, coor.x + i, coor.y + j, nb)==1){
        suppr(C, coor.x + i, coor.y + j, nb);
      }
    }
  }
}

int fermerGrille(int G[9][9], Cand C[9][9], Case O[81], int *NBO)
{
    int fin, i, k, f, nb,ga; //dif permet de savoir si la grille est finie
    Case coor;
    fin=0;
    while(fin==0)
    {
        f=0;
        coor=rechCaseUnique(C,G,*NBO);
        if(coor.x=!NULL){  
           nb=C[coor.x][coor.y].tab[0];
            fermerCase(G, C, coor, nb);
            for(i=0;i<=*NBO;i++)
            {
                if((coor.x==O[i].x)&&(coor.y==O[i].y))
                {
                    break;
                }
            }
            for(k=i;k<*NBO-1;k++)
            {
                O[k]=O[k+1]; //déplace les élément de O
            }
            *NBO--;
            printf("Elimination des candidats uniques...\n la case (%d,%d)est fermee avec le chiffre %d\n",O[i].x,O[i].y,nb);
            ecrireGrille(G);
            printf("Voici les candidats des %d cases ouvertes de la grille :",*NBO);
            //ecrire cand
            f=1;
        }
    if(f=!1)    
        fin=1; // si il n'y a pas eu de case remplit, la grille est finie
    }
    if(*NBO>0) return(1); //dit que la grille est difficile
    else return(0); //dit que la grille est facile
}
