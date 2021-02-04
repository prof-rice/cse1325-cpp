CXXFLAGS = --std=c++17

all: scc

scc: main.o player.o die.o *.h
	$(CXX) $(CXXFLAGS) main.o player.o die.o -o scc

main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o
player.o: player.cpp *.h
	$(CXX) $(CXXFLAGS) -c player.cpp -o player.o
die.o: die.cpp *.h
	$(CXX) $(CXXFLAGS) -c die.cpp -o die.o

die.gch: die.h
	$(CXX) $(CXXFLAGS) -c die.h -o die.gch

clean:
	rm -f *.o *.gch ~* a.out scc 
