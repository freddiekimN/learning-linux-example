foo.o : foo.h foo.cc 
	g++ -Wall -O2 -c foo.cc

bar.o : bar.h bar.cc
	g++ -Wall -O2 -c bar.cc

main.o : main.cc foo.h bar.h
	g++ -Wall -O2 -c main.cc

main : foo.o bar.o main.o
	g++ -Wall -O2 foo.o bar.o main.o -o main