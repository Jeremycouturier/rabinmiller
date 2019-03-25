FF = gcc
OPTF = -g -O2

all: premier

liste.o: liste.c liste.h arithmetique2.h
	$(FF) $(OPTF) -c liste.c

arithmetique2.o: arithmetique2.c arithmetique2.h liste.o
	$(FF) $(OPTF) -c arithmetique2.c

rabinmiller.o: rabinmiller.c rabinmiller.h arithmetique2.o liste.o
	$(FF) $(OPTF) -c rabinmiller.c

premier: main.c rabinmiller.o arithmetique2.o liste.o
	$(FF) $(OPTF) main.c rabinmiller.o arithmetique2.o liste.o -o premier

clean: 
	\rm -f *.o
