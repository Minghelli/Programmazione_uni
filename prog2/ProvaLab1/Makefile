exe: compito.o coda.o grafi.o
	g++ compito.o coda.o grafi.o -o exe

compito.o: compito.cc
	g++ -Wall -c compito.cc

coda.o: coda.cc coda.h
	g++ -Wall -c coda.cc

grafi.o: grafi.cc grafi.h
	g++ -Wall -c grafi.cc

cl: 
	rm *.o exe