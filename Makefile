CXX=g++ 
CXXFLAGS=-Wall -g

all:	main

main:  lib/Set.h lib/set1.h lib/Map.h lib/map1.h  lib/main1.cpp
		g++  lib/main1.cpp -o bin/main

clean:
		rm -f *.o *~
