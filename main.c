#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "liste.h"
#include "arithmetique2.h"
#include "rabinmiller.h"
#include <errno.h>

//typ base = 43341;
typ base =3037000500;

int main(){
	/*int * bit = (int *)malloc(sizeof(int));
	int b = 0;
	printf("Combien de bits ?\n");
	b = scanf("%d", bit);
	if (b != 1){
		perror("mauvaise saisie");
		exit(2);
	}
	printf("Calcul d'un nombre premier à %d bits\n", *bit);
	struct liste * p = aleat_impair(0,base,*bit);
	int compteur = 1;
	printf("                    essai n° : %d\n", compteur);
	clock_t c1 = clock();
	while(!est_premier(p,18)){ //On utilise tous les témoins de Miller
		compteur = compteur + 1;
		printf("                    essai n° : %d\n", compteur);
		p = impair_suivant(p);
	}
	clock_t c2 = clock();
	printf("Temps total : %f secondes\n", ((double) (c2-c1)) / ((double) (CLOCKS_PER_SEC)));
	p=miroir(p);
	printf("Premier trouvé en base 2 :\n");
	affiche_liste(p);
	p=miroir(p);
	p=two2ten(p);
	printf("Premier trouvé en base 10 :\n");
	affiche_liste(p);
	free(bit);*/

	/*int taille=1000;
	struct liste * l = aleat_impair(0,base,taille);
	affiche_liste_rapide(l);
	typ le_max=0;
	int i;
	for (i=0; i<taille; i++){
		if(l->tete>le_max){
			le_max=l->tete;
		}
		l=enleve(l);
	}
	printf("%lu\n%d\n", le_max, RAND_MAX);*/

	/*int bits=14;
	int n=digit(base,bits);
	typ a=most_significant_digit(base,bits);
	printf("%d\n%lu\n", n, a);*/

	int * bit = (int *)malloc(sizeof(int));
	int i;
	int b = 0;
	printf("How many bits do you want your prime to have ?\n");
	b = scanf("%d", bit);
	int taille=digit(base,*bit);
	typ msd=most_significant_digit(base,*bit);
	struct liste * l=aleat_liste(0,base,taille);
	struct liste * lmod2=NULL;
	int compteur = 1;
	l=miroir(l);
	if(taille>=3){
		l=enleve(enleve(l));
		l=ajout(base/2,l);
		l=ajout(msd,l);
		l=miroir(l);
	}
	else{
		l=enleve(l);
		l=ajout(msd,l);
		l=miroir(l);
	}
	lmod2=reste(l,ajout(2,NULL));
	if(!lmod2->tete){
		l=soustraction_free(l,ajout(1,NULL));
	}
	printf("try n° %d\n", compteur);
	while(!est_premier(l,18)){
		l=impair_suivant(l);
		compteur=compteur+1;
		printf("try n° %d\n", compteur);
	}
	printf("\n\n");
	printf("a prime was found !\n\nbase 10 :\n\n");
	l=changebase(l,base,10);
	affiche_liste(l);
	l=miroir(l);
	base=10;
	l=changebase(l,10,2);
	printf("\n\nbase 2 :\n\n");
	affiche_liste(l);
	printf("\n\nnumber of bits : %d\n", longueur(l));
	
	
	
	









	return 0;
}













	
