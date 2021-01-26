CXXFLAGS += -std=c++17
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

all: cpp java python zenity

cpp: hello.cpp 
	@printf "\nC++ with gtkmm (Gtk+)\n=====================\n"
	$(CXX) $(CXXFLAGS) hello.cpp  $(GTKFLAGS) -o hello
	./hello

java: Hello.java
	@printf "\nJava with Swing\n===============\n"
	javac Hello.java
	java Hello
	
python:
	@printf "\nPython with GObject (Gtk+)\n==========================\n"
	./hello.py

zenity:
	@printf "\nbash with Zenity\n================\n"
	-zenity --info --text="Hello, Professor Rice!"

clean:
	-rm -f *.o *~ *.class a.out hello
