// permet de définir les types utilisés dans notre programme : fonctionne comme une bibliothèque

//définition des types structures

typedef struct { //modifier les x et y si utilisation d'autres noms de variables
int x; // no de ligne
int y; // no de colonne
} Case;

typedef struct {
int nbc; // no de candidats
int *tab; // table candidats
} Cand;
