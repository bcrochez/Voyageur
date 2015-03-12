#include "../bin/carte.h"

void afficherCarte(Carte *c) {
	int i;
	for(i=0; i<c->taille; i++)
		afficherVille(&(c)->villes[i]);
}

char voyelleRandom(int i) {
	char voyelles[] = "AEIOUYAEIOU";
	return voyelles[i%11];
}

char consonneRandom(int i) {
	char consonnes[] = "BCDFGHJKMNRSTWZ";
	return consonnes[i%15];
}

void nomRandom(char *nom) {
	int i, j;
	if(rand()%2)
		for(j=0; j<5; j++) {
			i=rand()%26;
			if(j == 0 || j == 2)
				nom[j] = consonneRandom(i);
			else
				nom[j] = voyelleRandom(i);
		}
	else
		for(j=0; j<5; j++) {
			i=rand()%26;
			if(!(j%2))
				nom[j] = voyelleRandom(i);
			else
				nom[j] = consonneRandom(i);
		}
	nom[5]='\0';
}

Carte alloueCarte(int taille){
	Carte *new;
	new = (Carte*)malloc(sizeof(Carte));
	if( new == NULL ) {
		perror("malloc carte");
		exit(1);
	}
	new->taille = taille;
	new->villes = (Ville*)malloc(sizeof(Ville)*taille);
	if( new->villes == NULL ){
		perror("malloc carte ind");
		exit(1);
	}
	return *new;
}

void creerCarte(Carte *c, int largeur, int longueur){
	int i;
	char nom[6];
	srandom(time(NULL));
	for(i=0; i < c->taille; i++) {
		nomRandom(nom);
		c->villes[i] = creerVille(random()%largeur, random()%longueur, nom);
	}
}

void saveCarte(Carte *c, char *nom) {
	FILE* save;
	int i;
	save = fopen(nom, "w");
	for(i=0; i<c->taille; i++)
		saveVille(&(c)->villes[i], save);
	fclose(save);
}

void lireCarte(Carte *c, char *nom) {
	int i;
	FILE* load;
	load = fopen(nom, "r");
	for(i=0; i<c->taille; i++)
		lireVille(&(c)->villes[i], load);
	fclose(load);
}
