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
			printf("found to be composite in %f seconds\n\n", ((double) (c2-c1)) / ((double) (CLOCKS_PER_SEC)));
		}
	}
	printf("\n");
	printf("Found to be prime !\n\nbase 10 :\n\n");
	l=changebase(l,base,10);
	affiche_liste(l);
	l=miroir(l);
	base=10;
	l=changebase(l,10,2);
	printf("\n\nbase 2 :\n\n");
	affiche_liste(l);
	printf("\n\nnumber of bits : %d\n", longueur(l));

	/*typ vect[150]={1007124945,2137390151,818169221,1373222706,104441109,591686834,1091770796,1760761846,1896113762,1715378,864151730,214200203,2016395396,1239126459,1298569532,720957033,813782258,539624476,2011184663,708882266,55701571,1567788487,213153166,2003747089,730328053,72658977,1735199794,984482937,1374681575,1712514555,717870301,234322871,1702421058,1536039522,1607545577,1806862168,2127726356,551832726,1420140366,1876356471,553548104,136808448,2090556674,422459852,1375934908,1241642558,1143416885,42233518,1781267035,1007117900,751115784,1836968606,427422739,964268950,1693232048,1157750793,1036927928,1280948194,2142233730,264125855,845979102,712620383,498448727,400916512,101176258,2105994304,60295032,81418966,510343382,1480435398,1957775437,1063891486,1617243847,1900848464,1486351338,845695107,995007374,482284576,887928625,628790761,1489402476,1639044409,318275720,1916825216,455829712,2011507768,927092361,1492757640,1144972314,921842443,1756883495,1990951416,1634462827,107848574,244384281,1735639085,66359231,304679313,1817058051,576702613,1785114712,1627349841,1640594100,1254874911,1380714657,979461790,2100570018,228238383,1461746366,841014995,857029145,803665195,332575756,1175304865,573006763,788405468,1039328985,1500099124,133679460,36817651,274457919,1890562956,2027769068,1908920746,1998411530,124669701,1497076183,2064770761,429349014,1166650587,493989727,66980078,646516780,2134583827,1321854989,2027231437,966561969,1274941359,107986172,280824688,2115956354,965015317,1084489883,301048463,2140320182,1657496646,1089453931,1032165519,1010112122,1223133403};

	//typ vect[48]={1007124945,2137390151,818169221,1373222706,104441109,591686834,1091770796,1760761847,1007124945,2137390151,818169221,1373222706,104441109,591686834,1091770796,1760761847,1007124945,2137390151,818169221,1373222706,104441109,591686834,1091770796,1760761847,1007124945,2137390151,818169221,1373222706,104441109,591686834,1091770796,1760761847,1007124945,2137390151,818169221,1373222706,104441109,591686834,1091770796,1760761847,1007124945,2137390151,818169221,1373222706,104441109,591686834,1091770796,1760761847};

	struct liste * l = vect_to_liste(vect,150);
	int a=est_premier(l,18);*/




	return 0;
}













	
