#include "ndouble.h"
#include <vector>

int main() {
    // Let's create 5 Ndoubles on the HEAP with which to work.
    // I'll store them in an array.
    const int SIZE = 5;
    Ndouble* my_ndoubles[] = {
        new Ndouble{" π", 3.14159265},
        new Ndouble{" e", 2.71828},
        new Ndouble{"√2", 1.4142135623},
        new Ndouble{"√3", 1.7320508075},
        new Ndouble{" λ", 1.30357},
    };
    
    // Now let's aggregate these objects into a vector on the stack
    //   within a narrower scope.
    // Aggregation usually means storing either a pointer or a reference.
    // The object exists OUTSIDE of the aggregating container object.
    
    {
        std::vector<Ndouble*> v;
        for(int i=0; i<SIZE; ++i) v.push_back(my_ndoubles[i]);
    
        // Think about this: The Ndouble objects are on the heap.
        // v contains ONLY a pointer to each of them.
        // Now, let's print them out.
    
        for(Ndouble* n : v) std::cout << *n << std::endl;
    
        // Now we EXIT the scope that contains v, deleting it from the stack.
    }
    
    // Challenge: Do the Ndouble objects still exist?
    //            Can we recreate and print out v?
    std::cout << "\nRe-creating objects" << std::endl;
    

 
  
    // While exiting the program deletes all objects automatically,
    //   I elect to explicitly delete them here for clarity.
    for(int i=0; i<SIZE; ++i) delete my_ndoubles[i];
}
