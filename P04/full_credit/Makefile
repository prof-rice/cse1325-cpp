CXXFLAGS += --std=c++17

all: flashcards

debug: CXXFLAGS += -g
debug: flashcards

flashcards: main.o deck.o card.o *.h
	$(CXX) $(CXXFLAGS) main.o deck.o card.o -o flashcards

main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

deck.o: deck.cpp *.h
	$(CXX) $(CXXFLAGS) -c deck.cpp -o deck.o

card.o: card.cpp *.h
	$(CXX) $(CXXFLAGS) -c card.cpp -o card.o

test.o: test.cpp *.h
	$(CXX) $(CXXFLAGS) -c test.cpp -o test.o

clean:
	rm -f *.o *.gch *~ a.out flashcards

