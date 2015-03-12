#ifndef __CARTE__
#define __CARTE__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <assert.h>

#include "ville.h"

typedef struct{
	int taille;
	Ville* villes;
}Carte;

Carte alloueCarte(int taille);
void afficherCarte(Carte *c);
void creerCarte(Carte *c, int largeur, int longueur);
void saveCarte(Carte *c, char* nom);
void lireCarte(Carte *c, char* nom);

#endif
