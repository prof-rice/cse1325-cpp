CXXFLAGS = --std=c++17

all: aggregation composition

aggregation: aggregation.o ndouble.o *.h
	$(CXX) $(CXXFLAGS) aggregation.o ndouble.o -o aggregation

aggregation.o: aggregation.cpp *.h
	$(CXX) $(CXXFLAGS) -c aggregation.cpp -o aggregation.o


composition: composition.o ndouble.o *.h
	$(CXX) $(CXXFLAGS) composition.o ndouble.o -o composition

composition.o: composition.cpp *.h
	$(CXX) $(CXXFLAGS) -c composition.cpp -o composition.o


ndouble.o: ndouble.cpp *.h
	-$(CXX) $(CXXFLAGS) -c ndouble.cpp -o ndouble.o

clean:
	rm -f *.o *.gch *~ a.out aggregation composition

