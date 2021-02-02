CXXFLAGS = --std=c++17

pets: main.o pet.o *.h
	$(CXX) $(CXXFLAGS) main.o pet.o -o pets

main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

pet.o: pet.cpp *.h
	-$(CXX) $(CXXFLAGS) -c pet.cpp -o pet.o

clean:
	rm -f *.o *.gch *~ a.out pets

