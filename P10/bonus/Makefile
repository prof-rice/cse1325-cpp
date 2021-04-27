CXXFLAGS += --std=c++17 -pthread

all: wssolver

debug: CXXFLAGS += -g
debug: wssolver

logger: CXXFLAGS += -DLOGGER
logger: wssolver

wssolver: main.o puzzle.o solution.o solver.o  *.h
	$(CXX) $(CXXFLAGS) main.o puzzle.o solution.o solver.o  -o wssolver

main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp $(GTKFLAGS) -o main.o

puzzle.o: puzzle.cpp *.h
	$(CXX) $(CXXFLAGS) -c puzzle.cpp $(GTKFLAGS) -o puzzle.o

solution.o: solution.cpp *.h
	$(CXX) $(CXXFLAGS) -c solution.cpp $(GTKFLAGS) -o solution.o

solver.o: solver.cpp *.h
	$(CXX) $(CXXFLAGS) -c solver.cpp -o solver.o

clean:
	rm -f *.o *.gch *~ a.out wssolver temp.txt

