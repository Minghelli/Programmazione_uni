exe: main.o tipo.o liste.o funzioniApp.o
	g++ main.o tipo.o liste.o funzioniApp.o -o exe
main.o: main.cc tipo.h liste.h funzioniApp.h
	g++ -c -Wall main.cc
tipo.o: tipo.cc tipo.h
	g++ -c -Wall tipo.cc
liste.o: liste.cc liste.h
	g++ -c -Wall liste.cc
funzioniApp.o: funzioniApp.cc funzioniApp.h
	g++ -c -Wall funzioniApp.cc
clear:
	rm *.o exe