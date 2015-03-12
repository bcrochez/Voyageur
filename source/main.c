#include "../bin/main.h"

int main(int argc, char** argv){
	Carte c;
	Visite v;
	assert( argc == 4 );
	assert( atoi(argv[1]) > 0 );
	assert( atoi(argv[2]) > 0 );
	assert( atoi(argv[3]) > 0 );
	/*char *nom;
	strcpy(nom, "carte.txt");*/
	c = alloueCarte(atoi(argv[3]));
	creerCarte(&c, atoi(argv[1]), atoi(argv[2]));
	/*lireCarte(&c, nom);*/
	afficherCarte(&c);
	/*saveCarte(&c, nom);*/
	v = alloueVisite(atoi(argv[3]));
	genereVisite(&c, &v, 0, 1);
	afficheVisite(&c, &v);
	return 1;
}
