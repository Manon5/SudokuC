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
int initJeu(int[9][9], Cand[9][9] , Case[81]);
int quelleZone(int, int); //fonction utilisée dans estVoisine
int estVoisine(int, int, int, int); //fonction utilisée dans estCand
int estCand(int, int, int[9][9], int);
int appartient(Cand[9][9], int, int, int);
int estCandUnique(Cand[9][9], Case, int);
Case rechCaseUnique(Cand[9][9],Case[81], int);
void suppr(Cand[9][9], int, int, int); //module utilisé dans le module fermerCase
void fermerCase(int[9][9], Cand[9][9], Case);
int fermerGrille(int[9][9], Cand[9][9], Case[81], int);
void ecrireCand(Cand[9][9]);//pas oublier le ecrire cand dans fermergrille

int main()
{
  int fac, NBO, i;
lireGrille(G);
ecrireGrille(G);//a completer et faire plus dans les autre fonctions
NBO=initJeu(G,C,O);
fac=fermerGrille(G,C,O,NBO);
ecrireGrille(G);
if(fac==1){
printf("La grille étant difficle, voici les condidats possibles pour les cases restantes\n");
  ecrireCand(C);
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

int initJeu(int G[9][9], Cand C[9][9], Case O[81])
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
 return(w); // Compteur de cases ouvertes
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
int estCandUnique(Cand C[9][9], Case CA, int nb){
    if((C[CA.x][CA.y].nbc!=1)||(C[CA.x][CA.y].tab[0]!=nb))
    return(0);
    else return(1);
}


Case rechCaseUnique(Cand C[9][9],Case O[81],int NBO){
  Case res;
  int i, k;
  res.x= NULL;
  res.y= NULL;
  printf("NBO = %d\n", NBO); 
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

void fermerCase(int G[9][9], Cand C[9][9], Case ca){ 
  // On ferme la case
  G[ca.x][ca.y] = C[ca.x][ca.y].tab[0];

  // On retire le candidat des cases voisines
  int i, j;
  for (i = 0; i < 9; i++) { // on parcourt le tableau
    for (j = 0; j < 9; j++) {
      if(G[i][j] == 0 && estVoisine(ca.x, ca.y, i, j)){ // si la case est voisine et ouverte
        suppr(C, ca.x, ca.y, C[ca.x][ca.y].tab[0]); // on supprime le candidat de la liste
      }
    }
  }
}
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

void ecrireCand(Cand C[9][9])
{
    int a,i,j,k,l,comptb;
    for(a=0;a<9;a++)
    {
        if(a%3==0)
        { 
            for(i=0;i<82;i++)
            {
                printf("*");
            }
            printf("\n");
        }
        else
        {
            printf("*");
            for(i=0;i<3;i++)
            {
                for(j=0;j<26;j++)
                {
                    printf("-");
                }
                printf("*");
            }   
        }
        printf("*");
        for(k=0;k<9;k++)
        {
            printf(" ");
            comptb=6-C[a][k].nbc;
            for(l=0;l<comptb;l++)
            {
                printf(" ");
            }
            for(l=0;l<C[a][k].nbc;l++)
            {
                printf("%d",C[a][k].tab[l]);
            }
            printf(" ");
            if(k%3==2)
            {
                printf("*");
            }
            else
            {
                printf("|");
            }
        
        }    
        
    }
    for(i=0;i<82;i++)
            {
                printf("*");
            }
            printf("\n");    
}
