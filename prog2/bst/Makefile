out: tipo.o main.o bst.o
	g++ tipo.o main.o bst.o -o out
tipo.o: tipo.cc tipo.h
	g++ -c -Wall tipo.cc
main.o: main.cc tipo.h bst.h
	g++ -c -Wall main.cc
bst.o: bst.cc bst.h
	g++ -c -Wall bst.cc
clear:
	rm *.o out;