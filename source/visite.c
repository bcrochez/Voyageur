#include "../bin/visite.h"

float distance(Ville *v1, Ville *v2){
	/*assert( v1 != NULL );
	assert( v2 != NULL );*/
	return sqrt((v1->x - v2->x) * (v1->x - v2->x) + (v1->y - v2->y) * (v1->y - v2->y));
}

Visite alloueVisite(int taille){
	Visite *new;
	int i;
	new = (Visite*)malloc(sizeof(Visite));
	if( new == NULL ) {
		perror("malloc visite");
		exit(1);
	}
	new->taille = taille;
	new->indice = (int*)malloc(sizeof(int)*taille);
	if( new->indice == NULL ){
		perror("malloc visite ind");
		exit(1);
	}
	for( i=0; i<taille; i++)
		new->indice[i] = -1;
	return *new;
}

float longueurVisite(Carte *c, Visite *v){
	int i;
	float dist=0;
	for(i=0; i<v->taille-1; i++)
		dist += distance( &(c)->villes[v->indice[i]], &(c)->villes[v->indice[i+1]] );
	return dist;
}

void afficheVisite(Carte *c, Visite *v){
	int i;
	assert( c != NULL );
	assert( v != NULL );
	printf("\n == Visite == \n");
	for( i=0 ; i < v->taille ; i++){
		printf("%d) %s \t\t",i, c->villes[v->indice[i]].nom);
	}
	printf("\n");
	printf("== Longueur de la visite: %f ==\n",longueurVisite(c, v));
}

void genereVisite(Carte *c, Visite *v, int depart, int arrivee){
	int tab[c->taille];
	int i, j, r, tmp;
	int k=1;
	for(i=0; i<c->taille; i++)
		tab[i]=i;
	v->indice[0]=depart;
	v->indice[c->taille-1]=arrivee;
	tab[depart] = tab[arrivee] = -1;
	for(i=c->taille-2; i>0; i--){
		j=0;
		r=-1;
		tmp = rand()%i;	
		while( 1 ){
			if( tab[j] >= 0 )
				r++;
			if( r == tmp )
				break;
			j++;
		}
		v->indice[k] = tab[j];
		tab[j] = -1;
		k++;
	}
}
