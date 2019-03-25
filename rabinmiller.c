#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "liste.h"
#include "arithmetique2.h"
#include <errno.h>

int est_premier(struct liste * p, int nbtemoin){
	typ p1[1] = {2};          //2    Les 18 témoins de Miller utilisés
	typ p2[1] = {3};          //3
	typ p3[1] = {5};          //5
	typ p4[1] = {7};          //7
	typ p5[1] = {11};        //11
	typ p6[1] = {13};        //13
	typ p7[1] = {17};        //17
	typ p8[1] = {19};    //19
	typ p9[1] = {23};    //23
	typ p10[1] = {29};   //29
	typ p11[1] = {31};   //31
	typ p12[1] = {37}; //37
	typ p13[1] = {41}; //41
	typ p14[1] = {43}; //43
	typ p15[1] = {47}; //47
	typ p16[1] = {53}; //53
	typ p17[1] = {59}; //59
	typ p18[1] = {61}; //61

	struct liste * deux = vect_to_liste(p1, 1);
	struct liste * trois = vect_to_liste(p2, 1);
	struct liste * cinq = vect_to_liste(p3, 1);
	struct liste * sept = vect_to_liste(p4, 1);
	struct liste * onze = vect_to_liste(p5, 1);
	struct liste * treize = vect_to_liste(p6, 1);
	struct liste * dixsept = vect_to_liste(p7, 1);
	struct liste * dixneuf = vect_to_liste(p8, 1);
	struct liste * vingttrois = vect_to_liste(p9, 1);
	struct liste * vingtneuf = vect_to_liste(p10, 1);
	struct liste * trenteetun = vect_to_liste(p11, 1);
	struct liste * trentesept = vect_to_liste(p12, 1);
	struct liste * quaranteetun = vect_to_liste(p13, 1);
	struct liste * quarantetrois = vect_to_liste(p14, 1);
	struct liste * quarantesept = vect_to_liste(p15, 1);
	struct liste * cinquantetrois = vect_to_liste(p16, 1);
	struct liste * cinquanteneuf = vect_to_liste(p17, 1);
	struct liste * soixanteetun = vect_to_liste(p18, 1);

	struct liste * temoin[18] ={deux,trois,cinq,sept,onze,treize,dixsept,dixneuf,vingttrois,vingtneuf,trenteetun,trentesept,
				    quaranteetun,quarantetrois,quarantesept,cinquantetrois,cinquanteneuf,soixanteetun};
	struct liste * d = dupliquer(p);
	struct liste * pour_comparaison = dupliquer(p); //on génère p-1 sans désallouer p
	pour_comparaison=soustraction_free(pour_comparaison,ajout(1,NULL));
	struct liste * un = ajout(1,NULL);
	int i = 1;
	d=soustraction_free(d,un);
	int s = 0;
	int rang = 0;
	int autre_temoin = 1;
	int stop = 0;
	struct liste * mod;
	struct liste * letemoin = temoin[rang];
	struct liste * lereste=ajout(0,NULL);
	struct liste * lequotient=NULL;
	struct liste ** quotient_reste=NULL;
	while(est_egal(lereste,ajout(0,NULL))){       // On écrit p-1 = d*2^s
		desallouer(lereste);
		quotient_reste=euclide_free(d,deux);
		d = *quotient_reste;
		lereste = *(quotient_reste+1);
		s = s+1;
	}
	s=s-1;
	d=addition_free(fois_bit(d,2),un);
	while(autre_temoin){
		autre_temoin = 0;
		stop = 0;
		i = 1;
		mod = exp_mod(letemoin, d, p);
		if (est_egal(mod,pour_comparaison) || est_egal(mod,un)){
			stop = 1;
			autre_temoin = 1;
		}
		while(!stop && i<=s-1){
			mod = fois_free(mod,mod);
			mod = reste_free(mod,p);
			if(est_egal(mod,pour_comparaison)){
				stop = 1;
				autre_temoin = 1;
			}
			i = i+1;
		}
		if(rang == nbtemoin-1 && autre_temoin){
			desallouer(mod);
			desallouer(pour_comparaison);
			desallouer(d);
			desallouer(un);
			return 1;
		}
		rang = rang + 1;
		letemoin = temoin[rang];
	}
	desallouer(mod);
	desallouer(pour_comparaison);
	desallouer(d);
	desallouer(un);
	return 0;
}

























	
