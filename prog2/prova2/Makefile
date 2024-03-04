exe: compito.o carta.o bst.o
	g++ compito.o carta.o bst.o -o exe
compito.o: compito.cc carta.h bst.h
	g++ -c -Wall compito.cc
carta.o: carta.cc carta.h
	g++ -c -Wall carta.cc
bst.o: bst.cc carta.h bst.h
	g++ -c -Wall bst.cc
cl:
	rm *.o exe