CXXFLAGS += --std=c++17

all: alls

debug: CXXFLAGS += -g
debug: alls

main: main.cpp
	-$(CXX) $(CXXFLAGS) main.cpp -o main

alls:  main

clean:
	rm -f *.o *.gch a.out  main

