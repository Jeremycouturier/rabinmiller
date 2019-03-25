#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "liste.h"
#include "arithmetique2.h"
#include <errno.h>

typ max(typ n1, typ n2){
	if(n1>=n2){
		return n1;
	}
	else{
		return n2;
	}
}

typ min(typ n1, typ n2){
	if(n1<=n2){
		return n1;
	}
	else{
		return n2;
	}
}

struct liste * addition(struct liste * l1, struct liste * l2){
	struct liste * l = NULL;
	struct liste * ll1 = l1;
	struct liste * ll2 = l2;
	int n1 = longueur(l1);
	int n2 = longueur(l2);
	int N = max(n1,n2);
	int n = min(n1,n2);
	int i;
	typ retenue = 0;
	typ bit = 0;

	for(i=0; i<N; i++){
		if(i<n){
			bit=(ll1->tete + ll2->tete + retenue)%base;
			retenue=(ll1->tete + ll2->tete + retenue)/base;
			l=ajout(bit,l);
			ll1 = ll1->queue;
			ll2 = ll2->queue;
		}
		else if(i>=n){
			if(n1<n2){
				bit= (ll2->tete + retenue)%base;
				retenue=(ll2->tete + retenue)/base;
				l=ajout(bit,l);
				ll2 = ll2->queue;
			}
			else{
				bit= (ll1->tete + retenue)%base;
				retenue=(ll1->tete + retenue)/base;
				l=ajout(bit,l);
				ll1 = ll1->queue;
			}
		}
	}
	while(retenue){
		bit=retenue;
		retenue=0;
		l=ajout(bit,l);
	}
	struct liste * ll = miroir(l);
	return ll;
}

struct liste * addition_free(struct liste * l1, struct liste * l2){
	struct liste * l = NULL;
	struct liste * ll2 = l2;
	int n1 = longueur(l1);
	int n2 = longueur(l2);
	int N = max(n1,n2);
	int n = min(n1,n2);
	int i;
	typ retenue = 0;
	typ bit = 0;

	for(i=0; i<N; i++){
		if(i<n){
			bit=(l1->tete + ll2->tete + retenue)%base;
			retenue=(l1->tete + ll2->tete + retenue)/base;
			l=ajout(bit,l);
			l1 = enleve(l1);
			ll2 = ll2->queue;
		}
		else if(i>=n){
			if(n1<n2){
				bit= (ll2->tete + retenue)%base;
				retenue=(ll2->tete + retenue)/base;
				l=ajout(bit,l);
				ll2 = ll2->queue;
			}
			else{
				bit= (l1->tete + retenue)%base;
				retenue=(l1->tete + retenue)/base;
				l=ajout(bit,l);
				l1 = enleve(l1);
			}
		}
	}
	while(retenue){
		bit=retenue;
		retenue=0;
		l=ajout(bit,l);
	}
	struct liste * ll = miroir(l);
	return ll;
}

struct liste * fois_base(struct liste * l, typ k){
	typ i = 0;
	for(i=0; i<k; i++){
		l=ajout(0,l);
	}
	return l;
}

struct liste * fois_bit(struct liste * l, typ nombre){
	struct liste * ll=l;
	struct liste * resultat=NULL;
	typ retenue=0;
	typ bit=0;
	while(ll!=NULL){
		bit=(nombre*ll->tete+retenue)%base;
		retenue=(nombre*ll->tete+retenue)/base;
		resultat=ajout(bit,resultat);
		ll=ll->queue;
	}
	if(retenue){
		bit=retenue;
		resultat=ajout(bit,resultat);
	}
	resultat=miroir(resultat);
	return resultat;
}

struct liste * fois(struct liste * l1, struct liste * l2){
	struct liste * ll1 = l1;
	int n1 = longueur(l1);
	int i = 0;
	struct liste * l = ajout(0,NULL);
	struct liste * intermediaire = NULL;

	for(i=0; i<n1; i++){
		if (ll1->tete){
			intermediaire=fois_bit(l2,ll1->tete);
			intermediaire=fois_base(intermediaire,i);
			l = addition_free(l, intermediaire);
			desallouer(intermediaire);
		}
		ll1 = ll1->queue;
	}
	return l;
}

struct liste * fois_free(struct liste * l1, struct liste * l2){
	struct liste * ll1 = l1;
	int n1 = longueur(l1);
	int i = 0;
	struct liste * l = ajout(0,NULL);
	struct liste * intermediaire = NULL;

	for(i=0; i<n1; i++){
		if (ll1->tete){
			intermediaire=fois_bit(l2,ll1->tete);
			intermediaire=fois_base(intermediaire,i);
			l = addition_free(l, intermediaire);
			desallouer(intermediaire);
		}
		ll1 = ll1->queue;
	}
	desallouer(l2);
	return l;
}

struct liste * soustraction(struct liste * l1, struct liste * l2){
	struct liste * l = NULL;
	struct liste * ll1 = l1;
	struct liste * ll2 = l2;
	typ bit = 0;
	typ retenue = 0;
	int N = longueur(l1);
	int n = longueur(l2);
	int i=0;

	for(i=0; i<N; i++){
		if(i<n){
			bit = (base + ll1->tete - ll2->tete - retenue)%base ;
			if(ll1->tete<ll2->tete+retenue){
				retenue=1;
			}
			else{
				retenue=0;
			}
			l=ajout(bit,l);
			ll1 = ll1->queue;
			ll2 = ll2->queue;
		}
		else{
			bit = (base + ll1->tete - retenue)%base ;
			if(ll1->tete<retenue){
				retenue=1;
			}
			else{
				retenue=0;
			}
			l=ajout(bit,l);
			ll1 = ll1->queue;
		}
	}
	if(retenue){
		perror("probleme de retenue");
		exit(1);
	}
	i = 0;
	while(!l->tete && i<N-1){
		l=enleve(l);
		i = i+1;
	}
	struct liste * ll = miroir(l);
	return ll;
}

struct liste * soustraction_free(struct liste * l1, struct liste * l2){
	struct liste * l = NULL;
	struct liste * ll2 = l2;
	typ bit = 0;
	typ retenue = 0;
	int N = longueur(l1);
	int n = longueur(l2);
	int i=0;

	for(i=0; i<N; i++){
		if(i<n){
			bit = (base + l1->tete - ll2->tete - retenue)%base ;
			if(l1->tete<ll2->tete+retenue){
				retenue=1;
			}
			else{
				retenue=0;
			}
			l=ajout(bit,l);
			l1 = enleve(l1);
			ll2 = ll2->queue;
		}
		else{
			bit = (base + l1->tete - retenue)%base ;
			if(l1->tete<retenue){
				retenue=1;
			}
			else{
				retenue=0;
			}
			l=ajout(bit,l);
			l1 = enleve(l1);
		}
	}
	if(retenue){
		perror("probleme de retenue");
		exit(1);
	}
	i = 0;
	while(!l->tete && i<N-1){
		l=enleve(l);
		i = i+1;
	}
	struct liste * ll = miroir(l);
	return ll;
}

int est_inferieur (struct liste * l1, struct liste * l2){
	int n1 = longueur(l1);
	int n2 = longueur(l2);
	if(n1<n2){
		return 1;
	}
	else if(n1>n2){
		return 0;
	}
	int i = 0;
	struct liste * ll1 = miroir_conservatif(l1);
	struct liste * ll2 = miroir_conservatif(l2);
	
	for(i=0; i<n1-1; i++){
		if(ll1->tete > ll2->tete){
			desallouer(ll1);
			desallouer(ll2);
			return 0;
		}
		else if(ll1->tete < ll2->tete){
			desallouer(ll1);
			desallouer(ll2);
			return 1;
		}
		ll1 = enleve(ll1);
		ll2 = enleve(ll2);
	}
	typ t1 = ll1->tete;
	typ t2 = ll2->tete;
	desallouer(ll1);
	desallouer(ll2);
	return t1<=t2;
}

int est_strictement_inferieur (struct liste * l1, struct liste * l2){
	int n1 = longueur(l1);
	int n2 = longueur(l2);
	if(n1<n2){
		return 1;
	}
	else if(n1>n2){
		return 0;
	}
	int i = 0;
	struct liste * ll1 = miroir_conservatif(l1);
	struct liste * ll2 = miroir_conservatif(l2);
	
	for(i=0; i<n1-1; i++){
		if(ll1->tete > ll2->tete){
			desallouer(ll1);
			desallouer(ll2);
			return 0;
		}
		else if(ll1->tete < ll2->tete){
			desallouer(ll1);
			desallouer(ll2);
			return 1;
		}
		ll1 = enleve(ll1);
		ll2 = enleve(ll2);
	}
	typ t1 = ll1->tete;
	typ t2 = ll2->tete;
	desallouer(ll1);
	desallouer(ll2);
	return t1<t2;
}

int est_egal(struct liste * l1, struct liste * l2){
	if(longueur(l1) != longueur(l2)){
		return 0;
	}
	int i = 0;
	struct liste * ll1 = l1;
	struct liste * ll2 = l2;
	for(i=0; i<longueur(l1); i++){
		if (ll1->tete != ll2->tete){
			return 0;
		}
		ll1 = ll1->queue;
		ll2 = ll2->queue;
	}
	return 1;
}

typ bit_poids_fort(struct liste * l){
	struct liste * ll=l;
	typ bit=0;
	while(ll->queue!=NULL){
		ll=ll->queue;
	}
	bit=ll->tete;
	return bit;
}

struct liste ** euclide(struct liste * l1, struct liste * l2){
	int n;
	if(longueur(l1)>=longueur(l2)){n = longueur(l1)-longueur(l2);}
	else{n = 0;}
	struct liste * l = ajout(0,NULL);
	struct liste * ll2 = dupliquer(l2);
	struct liste * ll1 = dupliquer(l1);
	struct liste ** quotient_reste = (struct liste **)malloc(2*sizeof(struct liste *));
	struct liste * a_ajouter=NULL;
	struct liste * intermediaire=NULL;
	ll2 = fois_base(ll2, n);
	typ K,k,atester;
	while(est_inferieur(l2,ll1)){
		K=base;
		k=0;
		while(K-k>1){
			atester=(K-k)/2+k;
			intermediaire=fois_bit(ll2,atester);
			if(est_inferieur(intermediaire,ll1)){
				k=atester;
			}
			else{
				K=atester;
			}
			desallouer(intermediaire);
		}
		if(k!=0){
			a_ajouter=fois_base(ajout(k,NULL),n);
			l=addition_free(l,a_ajouter);
			intermediaire=fois_bit(ll2,k);
			ll1=soustraction_free(ll1,intermediaire);
			desallouer(intermediaire);
			desallouer(a_ajouter);
		}
		ll2 = enleve(ll2);
		n = n-1;
	}
	*(quotient_reste+1) = ll1;
	*(quotient_reste+0) = l;
	desallouer(ll2);
	return quotient_reste;
}

struct liste ** euclide_free(struct liste * l1, struct liste * l2){
	int n;
	if(longueur(l1)>=longueur(l2)){n = longueur(l1)-longueur(l2);}
	else{n = 0;}
	struct liste * l = ajout(0,NULL);
	struct liste * ll2 = dupliquer(l2);
	struct liste ** quotient_reste = (struct liste **)malloc(2*sizeof(struct liste *));
	struct liste * a_ajouter=NULL;
	struct liste * intermediaire=NULL;
	ll2 = fois_base(ll2, n);
	typ K,k,atester;
	while(est_inferieur(l2,l1)){
		K=base;
		k=0;
		while(K-k>1){
			atester=(K-k)/2+k;
			intermediaire=fois_bit(ll2,atester);
			if(est_inferieur(intermediaire,l1)){
				k=atester;
			}
			else{
				K=atester;
			}
			desallouer(intermediaire);
		}
		if(k!=0){
			a_ajouter=fois_base(ajout(k,NULL),n);
			l=addition_free(l,a_ajouter);
			intermediaire=fois_bit(ll2,k);
			l1=soustraction_free(l1,intermediaire);
			desallouer(intermediaire);
			desallouer(a_ajouter);
		}
		ll2 = enleve(ll2);
		n = n-1;
	}
	*(quotient_reste+1) = l1;
	*(quotient_reste+0) = l;
	desallouer(ll2);
	return quotient_reste;
}
	
struct liste * reste(struct liste * l1, struct liste * l2){
	int n;
	if(longueur(l1)>=longueur(l2)){n = longueur(l1)-longueur(l2);}
	else{n = 0;}
	struct liste * ll2 = dupliquer(l2);
	struct liste * ll1 = dupliquer(l1);
	struct liste * intermediaire=NULL;
	typ K;
	typ k;
	typ atester;
	ll2 = fois_base(ll2, n);
	while(est_inferieur(l2,ll1)){
		K=base;
		k=0;
		while(K-k>1){
			atester=(K-k)/2+k;
			intermediaire=fois_bit(ll2,atester);
			if(est_inferieur(intermediaire,ll1)){
				k=atester;
			}
			else{
				K=atester;
			}
			desallouer(intermediaire);
		}
		if(k!=0){
			intermediaire=fois_bit(ll2,k);
			ll1=soustraction_free(ll1,intermediaire);
			desallouer(intermediaire);
		}
		ll2=enleve(ll2);
	}
	desallouer(ll2);
	return ll1;
}


struct liste * reste_free(struct liste * l1, struct liste * l2){
	int n;
	if(longueur(l1)>=longueur(l2)){n = longueur(l1)-longueur(l2);}
	else{n = 0;}
	struct liste * ll2 = dupliquer(l2);
	struct liste * intermediaire=NULL;
	typ K;
	typ k;
	typ atester;
	ll2 = fois_base(ll2, n);
	while(est_inferieur(l2,l1)){
		K=base;
		k=0;
		while(K-k>1){
			atester=(K-k)/2+k;
			intermediaire=fois_bit(ll2,atester);
			if(est_inferieur(intermediaire,l1)){
				k=atester;
			}
			else{
				K=atester;
			}
			desallouer(intermediaire);
		}
		if(k!=0){
			intermediaire=fois_bit(ll2,k);
			l1=soustraction_free(l1,intermediaire);
			desallouer(intermediaire);
		}
		ll2=enleve(ll2);
	}
	desallouer(ll2);
	return l1;
}

struct liste * exp_mod(struct liste * b, struct liste * e, struct liste * m){ //renvoie (b^e) mod m
	if(base==2){
		struct liste * ee = e;
		struct liste * resultat = ajout(1,NULL);
		struct liste * bb = dupliquer(b);
		while(ee != NULL){
			if(ee->tete){
				resultat = fois_free(bb, resultat);
				resultat = reste_free(resultat, m);
			}
			ee = ee->queue;
			bb = fois_free(bb,bb);
			bb = reste_free(bb,m);
		}	
		desallouer(bb);
		return resultat;
	}
	else{
		struct liste * deux=ajout(2,NULL);
		struct liste ** quotient_reste=NULL;
		struct liste * power=NULL;
		struct liste * ee = dupliquer(e);
		struct liste * resultat = dupliquer(b);
		while(est_strictement_inferieur(ajout(1,NULL),ee)){
			quotient_reste=euclide_free(ee,deux);
			ee=*(quotient_reste);
			power=ajout((*(quotient_reste+1))->tete,power);
			desallouer(*(quotient_reste+1));
		}
		while(power!=NULL){
			if(power->tete){
				resultat=fois_free(resultat,resultat);
				resultat=reste_free(resultat,m);
				resultat=fois_free(b,resultat);
				resultat=reste_free(resultat,m);
				power=enleve(power);
			}
			else{
				resultat=fois_free(resultat,resultat);
				resultat=reste_free(resultat,m);
				power=enleve(power);
			}
		}
		desallouer(deux);
		desallouer(ee);
		return resultat;
	}
}
	
struct liste * impair_suivant(struct liste * l){
	struct liste * deux=NULL;
	if(base==2){
		deux = ajout(0,ajout(1,NULL));
	}
	else{
		deux = ajout(2,NULL);
	}
	struct liste * ll = addition(l,deux);
	desallouer(deux);
	desallouer(l);
	return ll;
}



















