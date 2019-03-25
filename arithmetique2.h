#ifndef _ARITHMETIQUE_H_
#define _ARITHMETIQUE_H_

//returns max(n1,n2)
typ max(typ n1, typ n2);

//returns min(n1,n2)
typ min(typ n1, typ n2);

//return l1+l2
struct liste * addition(struct liste * l1, struct liste * l2);

//return l1+l2 and deallocate l1 -> no increase in RAM
struct liste * addition_free(struct liste * l1, struct liste * l2);

//return l*base^k
struct liste * fois_base(struct liste * l, typ k);

//return l*nombre, where 0 <= nombre < base
struct liste * fois_bit(struct liste * l, typ nombre);

//return l1*l2
//For efficiency purposes, the shortest list should be the first argument
struct liste * fois(struct liste * l1, struct liste * l2);

//same as 'fois' but l2 is deallocated -> no increase in RAM
struct liste * fois_free(struct liste * l1, struct liste * l2);

//returns l1-l2
//l1 must be greater than l2
struct liste * soustraction(struct liste * l1, struct liste * l2);

//same as 'soustraction' but l1 is deallocated
struct liste * soustraction_free(struct liste * l1, struct liste * l2);

//returns 1 if l1<=l2, 0 else
int est_inferieur (struct liste * l1, struct liste * l2);

//returns 1 if l1<l2, 0 else
int est_strictement_inferieur (struct liste * l1, struct liste * l2);

//returns 1 if l1==l2, 0 else
int est_egal(struct liste * l1, struct liste * l2);

//get the most significant digit of l
typ bit_poids_fort(struct liste * l);

/*returns a list whose two elements are the quotient and the remainder
of l1/l2, respectively*/
struct liste ** euclide(struct liste * l1, struct liste * l2);

//same as euclide but l1 is deallocated
struct liste ** euclide_free(struct liste * l1, struct liste * l2);

//return the remainder of l1/l2
struct liste * reste(struct liste * l1, struct liste * l2);

//same as reste but l1 is deallocated
struct liste * reste_free(struct liste * l1, struct liste * l2);

//modular exponentiation : returns b^e mod m, without computing l^e
struct liste * exp_mod(struct liste * b, struct liste * e, struct liste * m);

/*returns l+2
is used in main to travel along the odd integer until a prime is found
l is deallocated*/
struct liste * impair_suivant(struct liste * l);

#endif
