exe: grafo.o liste.o tipo.o compito.o
	g++ grafo.o liste.o tipo.o compito.o -o exe
grafo.o: grafo.cc grafo.h
	g++ -c -Wall grafo.cc
liste.o: liste.cc liste.h
	g++ -c -Wall liste.cc
tipo.o: tipo.cc tipo.h
	g++ -c -Wall tipo.cc
compito.o: compito.cc tipo.h grafo.h liste.h
	g++ -c -Wall compito.cc
cl:
	rm *.o exe