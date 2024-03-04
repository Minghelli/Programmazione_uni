exe: tipo.o grafo.o compito.o
	g++ tipo.o grafo.o compito.o -o exe
tipo.o: tipo.cc tipo.h
	g++ -c -Wall tipo.cc
grafo.o: grafo.cc grafo.h
	g++ -c -Wall grafo.cc
compito.o: compito.cc tipo.h grafo.h
	g++ -c -Wall compito.cc
cl:
	rm *.o