This project aims to generate big prime number using the Rabin-Miller primality test.

Integers are represented by the linked list of their digits, the head of the list being the least significant digit.

All the arithmetic functions needed to run the rabin-miller primality test are hand-coded by myself.

Each .c file is associated with a .h file which contains comments about what are the purposes of the functions defined in the .c file. The .c contain only fews comments.

liste.c contains functions who manipule linked list
arithmetique2.c contains functions who perform arithmetic operations on the linked lists.
rabinmiller.c contains the rabinmiller test in itself

By default, calculus are done in base 2327925600=2^5*3^2*5^2*7*11*13*17*19. In this base, a number terminating by 0 is divisible by all integer in [2,36]\{23,27,29,31}. This
allows to be more efficient than just checking every odd number. The expectancy of number of tries takes into account the fact that not all odd integers are tested, and is calculated from
the repartition of prime number.

The Rabin-Miller primality test is probabilistic. When it finds a number to be composite, then it is composite. And if every Miller witnesses tested are not witness for the compositeness of p,
then p is declared to be very probably prime. In this code, we use all primes from 2 to 61 as Miller witnesses (18 primes in total). The user can easily add more witnesses by slightly modifying
the function "est_premier" (is_prime) in the file rabinmiller.c. The probability of mistake quickly tends to 0 as the number of witnesses grows up.

                **************************

To install, just download the whole project in any directory, go to that directory and use the make command (gcc must be installed).
The subsequent executable is called premier

                **************************

jrmy@Deimos ~/C/rabinmiller $ ./premier
How many bits do you want your prime to have (min=33) ?
249
expectancy of number of tries: 29.33

try n° 1
found to be composite in 0.137486 seconds

try n° 2
found to be composite in 0.129286 seconds

try n° 3
found to be composite in 0.129995 seconds

try n° 4

Found to be prime !

base 10 :

862 487 421 085 197 879 217 602 072 446 386 312 130 326 397 616 929 259 336 940 550 477 284 953 631 


base 2 :

111 101 000 001 001 101 000 110 001 111 000 110 001 111 011 100 000 111 000 100 110 101 101 000 001 011 100 000 000 010 011 001 101 111 010 110 011 001 111 011 010 110 010 010 110 000 101 101 000 101 010 000 011 000 001 110 111 100 011 111 100 001 010 000 010 011 101 111 101 101 010 110 110 110 100 000 001 001 100 111 000 011 111 
