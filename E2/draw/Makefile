CXXFLAGS += --std=c++17
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

all: letter

debug: CXXFLAGS += -g
debug: fib

letter: main.o canvas.o *.h
	$(CXX) $(CXXFLAGS) main.o canvas.o $(GTKFLAGS) -o letter

main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp $(GTKFLAGS) -o main.o

canvas.o: canvas.cpp *.h
	$(CXX) $(CXXFLAGS) -c canvas.cpp $(GTKFLAGS) -o canvas.o

clean:
	rm -f *.o *.gch *~ a.out letter

