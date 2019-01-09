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
int * tab; // table candidats
} Cand;

//initialisation des fonctions, variables et tableaux
int tab[9]
int G[TAILLE][TAILLE];
Case O[81];
Cand C[9][9];
int NBO;
void lireGrille();
void ecrireGrille();
void initJeu(int*);
int quelleZone(int, int); //fonction utilisée dans estVoisine
int estVoisine(int, int, int, int, int); //fonction utilisée dans estCand 
int estCand(int, int, int, int);
int appartient(Cand, int, int, int);
int estCandUnique(Cand, int, int, int);
Case rechCaseUnique(Cand);
void suppr(); //module utilisé dans le module fermerCase
void fermerCase();
void fermerGrille();
int ecrireCand();

int main()
{
void lireGrille();
void ecrireGrille();
  //ajoputer de nouvelles fonctions dedans si il y en manque
  //ajouter les variables manquantes
}
