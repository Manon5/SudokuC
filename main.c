#include <stdio.h>
#include <string.h>

typedef struct { //modifier les x et y si utilisation d'autres noms de variables
int x; // no de ligne
int y; // no de colonne
} Case;

typedef struct {
int nbc; // no de candidats
int * tab; // table candidats
} Cand;

void lireGrille(); //module de lecture du tableau G
void ecrireGrille(); //module qui permet d'afficher le tableau G à l'écran
void initJeu(); //module d'initialisation des tables C, O et de la variable NBO
estCand(); //permet de savoir si un nombre est candidat ou non
appartient(); //le nombre appartient-il aux nombres candidats?
estCandUnique(); //le candidat est-il unique ou non?
rechCaseUnique(); //cette case contient-elle un candidat unique?
fermerCase(); //rempli une case ouverte de la grille et 
fermerGrille(); //rempli grille par méthode des candidatis uniques
ecrireCand(); //affiche les candidats des cases ouvertes

int main()
{
void lireGrille();
void ecrireGrille();
  //ajoputer de nouvelles fonctions dedans si il y en manque
  //ajouter les variables manquantes
}
