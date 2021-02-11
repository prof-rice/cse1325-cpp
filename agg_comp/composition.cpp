#include "ndouble.h"
#include <vector>

int main() {

    {
        // Let's composite 5 Ndoubles into vector v within a narrower scope on the HEAP.
        // ONLY vector v has the objects, so it will delete them when it is itself deleted.
        // Composition often does not use pointers (although we do sometimes for other reasons).
        std::vector<Ndouble> v = {
            Ndouble{" π", 3.14159265},
            Ndouble{" e", 2.71828},
            Ndouble{"√2", 1.4142135623},
            Ndouble{"√3", 1.7320508075},
            Ndouble{" λ", 1.30357},
        };
    
        // Think about this: The Ndouble objects are on the STACK.
        // v contains the ONLY copy of them. When v is deleted, so are the objects.
        // Now, let's print them out.
    
        for(Ndouble& n : v) std::cout << n << std::endl;
    
        // Now we EXIT the scope that contains v, deleting it (AND its composited objects)) 
        //   from the stack automatically.
    }
    
    // Challenge: Do the Ndouble objects still exist?
    //            Can we recreate and print out v?
    std::cout << "\nRe-creating objects" << std::endl;
    
    
    
    
    // Note that we don't have to explicitly delete our Ndouble objects.
    // They were composited - they were deleted when v was deleted.
}
