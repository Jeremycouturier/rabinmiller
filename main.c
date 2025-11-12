#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "liste.h"
#include "arithmetique2.h"
#include "rabinmiller.h"
#include <errno.h>
#include <math.h>

typ base = 2327925600; // 2^5*3^2*5^2*7*11*13*17*19

int main(){
	int * bit = (int *)malloc(sizeof(int));
	int b = 0;
	double densite; // the density of prime
	double expectancy; // the expectancy of number of tries
	printf("How many bits do you want your prime to have (min=33) ?\n");
	b = scanf("%d", bit);
	if(*bit<33){
		perror("At least 33 bits, to ensure that the number has at least 2 digits");
		exit(1);
	}
	struct liste * l1=premier(bit);

	return 0;
}
