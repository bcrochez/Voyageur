#ifndef __VISITE__
#define __VISITE__

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>
#include<assert.h>

#include "carte.h"
#include "ville.h"

typedef struct{
	int taille;
	int* indice;
}Visite;

Visite alloueVisite(int taille);
float distance(Ville *v1, Ville *v2);
float longueurVisite(Carte *c, Visite *v);
void afficheVisite(Carte *c, Visite *v);
void genereVisite(Carte *c, Visite *v, int depart, int arrivee);

#endif
