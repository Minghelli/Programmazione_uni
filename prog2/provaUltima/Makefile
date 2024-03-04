exe: compito.o liste.o tipo.o
	g++ compito.o liste.o tipo.o -o exe
tipo.o: tipo.cc tipo.h
	g++ -c -Wall tipo.cc
liste.o: liste.cc liste.h
	g++ -c -Wall liste.cc
compito.o: compito.cc liste.h tipo.h
	g++ -c -Wall compito.cc
cl:
	rm *.o exe