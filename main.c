#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "liste.h"
#include "arithmetique2.h"
#include "rabinmiller.h"
#include <errno.h>
#include <math.h>

//typ base = 43341;
typ base =3037000500;

int main(){
	int * bit = (int *)malloc(sizeof(int));
	int i;
	int b = 0;
	int boolean;
    clock_t c1;
    clock_t c2;
	double densite; // the density of prime
	double expectancy; // the expectancy of runtime
	double time_per_composite; // the time needed fo a composite number to be tested
	printf("How many bits do you want your prime to have ?\n");
	b = scanf("%d", bit);
	time_per_composite=2.504e-8*pow((*bit),2.8203);
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
	densite=density_of_prime(l,msd);
	printf("\nDensity of prime in this region : %lf\n", densite);
	expectancy=0.5*(1.0/densite)*time_per_composite;
	printf("\nExpectancy of runtime : %lf seconds\n", expectancy);
	printf("\ntry n° %d\n", compteur);
    c1=clock();
	boolean = est_premier(l,18);
    c2=clock();
    if(!boolean){
		printf("found to be composite in %f secondes\n\n", ((double) (c2-c1)) / ((double) (CLOCKS_PER_SEC)));
	}

	while(!boolean){
		l=impair_suivant(l);
		compteur=compteur+1;
		printf("try n° %d\n", compteur);
		c1 = clock();
		boolean = est_premier(l,18);
		c2 = clock();
		if(!boolean){
			printf("found to be composite in %f secondes\n\n", ((double) (c2-c1)) / ((double) (CLOCKS_PER_SEC)));
		}
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













	
