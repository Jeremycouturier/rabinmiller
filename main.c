#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "liste.h"
#include "arithmetique2.h"
#include "rabinmiller.h"
#include <errno.h>
#include <math.h>

//typ base = 43341;
typ base =2327925600; // 2^5*3^2*5^2*7*11*13*17*19

int main(){
	int * taille = (int *)malloc(sizeof(int));
	int b = 0;
	double densite; // the density of prime
	double expectancy; // the expectancy of number of tries
	printf("How many digits (in base 2327925600) do you want your prime to have ?\n");
	b = scanf("%d", taille);
	if(*taille<2){
		perror("At least 2 digits");
		exit(1);
	}
	struct liste * l1=premier(taille);

	return 0;
}

/*int main(){
	printf("%lu\n", most_significant_digit(base,33));

	return 0;
}*/











	
