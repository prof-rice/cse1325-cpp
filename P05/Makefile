CXXFLAGS += --std=c++17

all: cli smart

debug: CXXFLAGS += -g
debug: smart

cli: cli.o person.o student.o parent.o *.h
	$(CXX) $(CXXFLAGS) cli.o person.o student.o parent.o -o cli

smart: main.o person.o student.o parent.o *.h
	$(CXX) $(CXXFLAGS) main.o person.o student.o parent.o -o smart

cli.o: cli.cpp *.h
	$(CXX) $(CXXFLAGS) -c cli.cpp -o cli.o

main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

person.o: person.cpp *.h
	-$(CXX) $(CXXFLAGS) -c person.cpp -o person.o

student.o: student.cpp *.h
	-$(CXX) $(CXXFLAGS) -c student.cpp -o student.o

parent.o: parent.cpp *.h
	$(CXX) $(CXXFLAGS) -c parent.cpp -o parent.o

clean:
	rm -f *.o *.gch *~ a.out smart cli

