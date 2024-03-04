out: main.o tipo.o codaDFS.o albero.o
	g++ main.o tipo.o codaDFS.o albero.o -o out

main.o: main.cc
	g++ -c main.cc

tipo.o: tipo.cc tipo.h
	g++ -c tipo.cc 

codaDFS.o: codaDFS.cc codaDFS.h
	g++ -c codaDFS.cc

albero.o: albero.cc albero.h
	g++ -c albero.cc

clean:
	rm *.o out
