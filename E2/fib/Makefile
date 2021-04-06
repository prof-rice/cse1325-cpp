CXXFLAGS += --std=c++17
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

all: fib

debug: CXXFLAGS += -g
debug: fib

cli: cli.o fib.o *.h
	$(CXX) $(CXXFLAGS) cli.o fib.o -o fib

fib: main.o mainwin.o fib.o *.h
	$(CXX) $(CXXFLAGS) main.o mainwin.o fib.o $(GTKFLAGS) -o fib

main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp $(GTKFLAGS) -o main.o

mainwin.o: mainwin.cpp *.h
	$(CXX) $(CXXFLAGS) -c mainwin.cpp $(GTKFLAGS) -o mainwin.o

#entrydialog.o: entrydialog.cpp *.h
#	$(CXX) $(CXXFLAGS) -c entrydialog.cpp $(GTKFLAGS) -o entrydialog.o


fib.o: fib.cpp *.h
	-$(CXX) $(CXXFLAGS) -c fib.cpp -o fib.o

clean:
	rm -f *.o *.gch *~ a.out fib cli

