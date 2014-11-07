CXX=g++ 
CXXFLAGS=-Wall -g

all:	main

main:   lib/Queue.h lib/queueImp.h lib/Set.h lib/set1.h lib/Map.h lib/map1.h  lib/main1.cpp Movie.h Movie.cpp User.h User.cpp lib/Netflix.h lib/Netflix.cpp
		g++ $(CXXFLAGS) lib/main1.cpp Movie.cpp  User.cpp lib/Netflix.cpp -o bin/main

clean:
		rm -f *.o *~
