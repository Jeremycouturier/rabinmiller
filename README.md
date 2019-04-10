This project aims to generate big prime number using the Rabin-Miller primality test.

Integers are represented by the linked list of their digits, the head of the list being the least significant digit.

All the arithmetic functions needed to run the rabin-miller primality test are hand-coded by myself.

Each .c file is associated with a .h file which contains comments about what are the purposes of the functions defined in the .c file. The .c contain only fews comments.

liste.c contains functions who manipule linked list
arithmetique2.c contains functions who perform arithmetic operations on the linked lists.
rabinmiller.c contains the rabinmiller test in itself

By default, calculus are done in base 3037000500, which is the highest possible usable base if sizeof(unsigned long)==8. If sizeof(unsigned long)==4 on your architecture, then you should change this value to 43341 by editing the beginning of the main file.

Due to the way miller witnesses are represented in the est_premier function (see rabinmiller.c), you mustn't use a base lower than 62 if you use this function.

Note that the expectancy of runtime indicated at the beginning of the search for prime number assumes that the base you use is 3037000500 and is just an expectancy, the real runtime could be much larger of much smaller.

                **************************

To install, just download the whole project in any directory, go to that directory and use the make command.
The subsequent executable is called premier

                **************************

jrmy@Deimos ~/C/rabinmiller_github $ ./premier
How many bits do you want your prime to have ?

107

Density of prime in this region : 0.013483

Expectancy of runtime : 0.491230 seconds

try n° 1
found to be composite in 0.013371 seconds

try n° 2
found to be composite in 0.013437 seconds

try n° 3
found to be composite in 0.013025 seconds

try n° 4
found to be composite in 0.013367 seconds

try n° 5
found to be composite in 0.013509 seconds

try n° 6

Found to be prime !

base 10 :

162 255 950 439 571 628 593 066 072 666 033 


base 2 :

 11 111 111 111 111 101 010 100 000 001 111 001 100 110 000 011 000 111 100 100 011 110 111 101 001 001 011 001 111 101 001 110 111 110 110 001 


number of bits : 107
