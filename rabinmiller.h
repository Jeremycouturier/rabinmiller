#ifndef _RABINMILLER_H_
#define _RABINMILLER_H_

/* if 'est_premier' returns 0 then p is a composite number
if 'est_premier' returns 1 then either p is very likely prime
or all the nbtemoin miller's witnesses used are 
strong liars (very unlikely to happen if nbtemoin is great)

Note that this function works only if (base) > (the greatest witness)
which happens to be 61 */
int est_premier(struct liste * p, int nbtemoin);

//returns a prime whose size in base base is taille
struct liste * premier(int taille);

#endif
