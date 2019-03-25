#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "liste.h"
#include "arithmetique2.h"

struct liste * ajout(typ head, struct liste * l){
	struct liste * new_liste=NULL;
	new_liste=(struct liste *)malloc(sizeof(struct liste));
	new_liste->tete=head;
	new_liste->queue=l;
	return new_liste;
}

void affiche_liste_aux(struct liste * l, int compteur){
	if(l!=NULL && compteur%3 != 0){printf("%lu", l->tete);}
	if(l!=NULL && compteur%3 == 0){printf("%lu ", l->tete);}
	if(l->queue!=NULL){
		affiche_liste_aux(l->queue, compteur + 1);
	}
}

void affiche_liste(struct liste *l){
	if(longueur(l) % 3 == 0){affiche_liste_aux(l,1);}
	else if(longueur(l) % 3 == 1){printf("  "); affiche_liste_aux(l,3);}
	else{printf(" "); affiche_liste_aux(l,2);}
	printf("\n");
}

void affiche_liste_rapide(struct liste * l){
	struct liste * ll=l;
	while(ll!=NULL){
		printf("%lu ", ll->tete);
		ll=ll->queue;
	}
	printf("\n");
}

struct liste * enleve(struct liste *l){
	struct liste * q = NULL;
	if(l!=NULL){
		q=l->queue;
		free(l);
		l=NULL;
		return q;
	}
	else{
		return NULL;
	}
}

struct liste * dupliquer(struct liste * l){
	struct liste * ll = l;
	struct liste * q=NULL;
	while(ll != NULL){
		q=ajout(ll->tete,q);
		ll = ll->queue;
	}
	struct liste * qq = miroir(q);
	return qq;
}

void desallouer(struct liste * l){
	while(l != NULL){
		l = enleve(l);
	}
}

/*int longueur(struct liste *l){
	if(l==NULL){
		return 0;
	}
	else{
		return 1+longueur(l->queue);
	}
}*/

int longueur(struct liste * l){
	struct liste * ll = l;
	int i = 0;
	while(ll != NULL){
		i = i+1;
		ll = ll->queue;
	}
	return i;
}

struct liste * miroir(struct liste * l){
	typ t;
	struct liste * ll = NULL;

	while (l != NULL){
		t=l->tete;
		ll=ajout(t,ll);
		l=enleve(l);
	}
	return ll;
}

struct liste * miroir_conservatif(struct liste * l){
	struct liste * ll = l;
	struct liste * q = NULL;
	typ t;

	while (ll != NULL){
		t=ll->tete;
		q=ajout(t,q);
		ll = ll->queue;
	}
	return q;
}

struct liste * vect_to_liste(typ * vect,int taille){
	struct liste * l = NULL;
	int i;
	for(i=0; i<taille; i++){
		l=ajout(*(vect+i),l);
	}
	return l;
}

struct liste * aleat_liste(typ a, typ b, int size){ 
	typ c;
	int i = 0;
	struct liste * l = NULL;

	srand((int) (clock() + time(NULL)));
	c=rand()%(b-a-1)+a+1;
	l=ajout(c,l);
	for(i=0; i<size-1; i++){
		c=rand()%(b-a)+a;
		l=ajout(c, l);
	}
	return l;
}

struct liste * aleat_impair(typ a, typ b, int size){
	struct liste * l=aleat_liste(a,b,size);
	struct liste * lereste=NULL;
	if(base!=2){
		lereste=reste(l,ajout(2,NULL));
	}
	else{
		lereste=ajout(l->tete,NULL);
	}
	if(!lereste->tete){
		l=addition_free(l,ajout(1,NULL));	
	}
	return l;
}

struct liste * changebase(struct liste * l, typ base1, typ base2){
	struct liste * ll=NULL;
	struct liste * lereste=NULL;
	struct liste ** quotient_reste=NULL;
	struct liste * b2=ajout(base2,NULL);
	while(!est_egal(l,ajout(0,NULL))){
		quotient_reste=euclide(l,b2);
		desallouer(l);
		lereste=*(quotient_reste+1);
		l=*quotient_reste;
		ll=ajout(lereste->tete,ll);
		desallouer(lereste);
	}
	return ll;
}
























