CXXFLAGS = --std=c++17 -pthread

info:
	@echo
	@printf 'Type e.g., "make auto"  to create program "auto" from auto.cpp\n'
	@printf 'Type       "make all"   to create every program\n'
	@printf 'Type       "make clean" to delete every program\n\n'

contention: contention.cpp
	-$(CXX) $(CXXFLAGS) -o contention contention.cpp
	@printf "Now type ./contention to execute the result\n\n"

function: function.cpp
	-$(CXX) $(CXXFLAGS) -o function function.cpp
	@printf "Now type ./function to execute the result\n\n"

stringstream: stringstream.cpp
	-$(CXX) $(CXXFLAGS) -o stringstream stringstream.cpp
	@printf "Now type ./stringstream to execute the result\n\n"

all:  contention function stringstream

clean:
	rm -f *.o *.gch a.out  contention function stringstream

