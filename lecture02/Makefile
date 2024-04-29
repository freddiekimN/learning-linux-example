CC = g++
CXXFLAGS = -Wall -O2
OBJS = foo.o bar.o main.o

foo.o : foo.h foo.cc
	$(CC) $(CXXFLAGS) -c foo.cc


bar.o : bar.h bar.cc
	$(CC) $(CXXFLAGS) -c bar.cc

main.o : main.cc foo.h bar.h
	$(CC) $(CXXFLAGS) -c main.cc

main : $(OBJS)
	$(CC) $(CXXFLAGS) $(OBJS) -o main

.PHONY : clean
clean :
	rm -f $(OBJS) main