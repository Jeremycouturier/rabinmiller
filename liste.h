#ifndef _LISTE_H_
#define _LISTE_H_

//#define typ unsigned int
#define typ unsigned long

//base of numbering into which calculus are done
typ base;

struct liste {
	typ tete;
	struct liste * queue;
};

//add an element at the head of l
struct liste * ajout(typ t, struct liste * l);

//auxiliary recursive function for 'affiche_liste'
void affiche_liste_aux(struct liste * l, int compteur);

//print the list l by separating groups of three digits
void affiche_liste(struct liste *l);

//print the list l
void affiche_liste_rapide(struct liste * l);

//remove the head of list l and deallocate the corresponding address
struct liste * enleve(struct liste *l);

//duplicate the list l
struct liste * dupliquer(struct liste * l);

//deallocate entirely the list l
void desallouer(struct liste * l);

//return the length of list l
int longueur(struct liste *l);

//reverse and deallocate the list l -> no increase in RAM
struct liste * miroir(struct liste * l);

// reverse but doesn't deallocate l -> increase in RAM
struct liste * miroir_conservatif(struct liste * l);

// create a list from a vector
struct liste * vect_to_liste(typ * vect,int taille);

// create a random list of size size with digits between b-1 and a
struct liste * aleat_liste(typ a, typ b, int size);

// create a list whose integer it represents is odd
struct liste * aleat_impair(typ a, typ b, int size);

/* converts l from base base1 to base base2
base1 must be greater or equal to base2
Contrary to the usual, the head of the returned list corresponds
to the most significant digit
l is deallocated*/
struct liste * changebase(struct liste * l, typ base1, typ base2);

#endif
