out: main.o bfs.o grafo.o
	g++ main.o bfs.o grafo.o -o out
main.o: main.cc
	g++ -c -Wall main.cc
bfs.o: bfs.cc bfs.h
	g++ -c -Wall bfs.cc
grafo.o: grafo.cc grafo.h
	g++ -c -Wall grafo.cc
clear:
	rm *.o out