#include "../bin/ville.h"

void afficherVille(Ville *v) {
	printf("%s %d %d\n", v->nom, v->x, v->y);
}

Ville creerVille(int x, int y, char* nom){
	Ville *new;
	assert( x >= 0 );
	assert( y >= 0 );
	new=malloc(sizeof(Ville));
	if( new == NULL ){
		perror("malloc");
		exit(1);
	}
	new->nom=malloc(sizeof(char)*strlen(nom));
	new->x=x;
	new->y=y;
	strcpy(new->nom, nom);
	return *new;
}

void saisirVille(Ville *v) {
	char *nom;
	printf("Entrez le nom de la ville");
	scanf("%s", nom);
	printf("Entrez les coordonnees de la ville");
	scanf("%d %d", &(v)->x, &(v)->y);
}

void saveVille(Ville *v, FILE* save) {
	fprintf(save, "%s %d %d\n", v->nom, v->x, v->y);
}

void lireVille(Ville *v, FILE* save) {
	fscanf(save, "%s %d %d", v->nom, &v->x, &v->y);
}
