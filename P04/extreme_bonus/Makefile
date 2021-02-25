CXXFLAGS += --std=c++17

all: help flashcards
help:
	@printf 'Use target eog for Eye of Gnome, feh for Feh,\n  or et for Enlightenment Terminology - default is ristretto\n'

eog: CXXFLAGS += -DEOG
eog: clean flashcards

feh: CXXFLAGS += -DFEH
feh: clean flashcards

et: CXXFLAGS += -DET
et: clean flashcards

flashcards: main.o deck.o card.o hintcard.o imagecard.o *.h
	$(CXX) $(CXXFLAGS) main.o deck.o card.o hintcard.o imagecard.o -o flashcards

main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

deck.o: deck.cpp *.h
	$(CXX) $(CXXFLAGS) -c deck.cpp -o deck.o

card.o: card.cpp *.h
	$(CXX) $(CXXFLAGS) -c card.cpp -o card.o

hintcard.o: hintcard.cpp *.h
	$(CXX) $(CXXFLAGS) -c hintcard.cpp -o hintcard.o

imagecard.o: imagecard.cpp *.h
	$(CXX) $(CXXFLAGS) -c imagecard.cpp -o imagecard.o

test.o: test.cpp *.h
	$(CXX) $(CXXFLAGS) -c test.cpp -o test.o

clean:
	rm -f *.o *.gch *~ a.out flashcards

