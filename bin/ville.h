#ifndef __VILLE__
#define __VILLE__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <assert.h>

typedef struct{
	int x, y;
	char* nom;
}Ville;

void afficherVille(Ville *v);
Ville creerVille(int x, int y, char* nom);
void saisirVille(Ville *v);
void saveVille(Ville *v, FILE* save);
void lireVille(Ville *v, FILE* save);

#endif
