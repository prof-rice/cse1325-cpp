#include "puzzle.h"
#include "solver.h"

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>

#include "logger.h"

#include <thread>
#include <mutex>

int main(int argc, char* argv[]) {
    std::ostringstream oss_usage;
    oss_usage << "usage: " << argv[0] << " threads puzzle [puzzle]...\n";
    std::string usage = oss_usage.str();

    // Minimum executable + 2 parameters required
    if(argc < 3) {
        std::cerr << usage;
        exit(-1);
    }

    // Extract parameter 1        
    std::string p1 = std::string(argv[1]); 

    // Check for help request
    if(p1 == "-h" || p1 == "--help") {
        std::cerr << usage;
        exit(0);
    }

    // Read number of threads
    int NUM_THREADS;
    try {
        NUM_THREADS = std::stoi(p1);
    } catch(std::exception& e) {
        std::cerr << "Unable to read number of threads from " 
                  << p1 << ": " << e.what() << '\n' 
                  << usage;
        exit(-2);
    }

    // Load the puzzles
    std::vector<Puzzle> puzzles;
    for(int i=2; i<argc; ++i) {
        try {
            std::string filename = std::string{argv[i]};
            std::ifstream ifs{filename};
            puzzles.push_back(Puzzle{filename, ifs});
        } catch(std::exception& e) {
            std::cerr << "Unable to open " << argv[i] << ": " 
                      << e.what() << std::endl;
        }
    }

    // Exit if one or more puzzles failed to load
    if((argc-2) != puzzles.size()) exit(-3);     
    
    // ----- All data loaded -----
    
    // change type from size_type to int
    int puzzles_size = puzzles.size();
    
    // Capture the solutions in a vector 
    std::vector<Solution> solutions;

    // Keep track of threads for each word search
    std::vector<std::thread*> threads;
    std::mutex m;
    
    // Control allocation of puzzles to threads
    const int puzzles_per_thread = std::max(1, puzzles_size / NUM_THREADS); // At least 1
    int first = 0;
    int last = puzzles_per_thread - 1;
    
    for(int i=0; i<NUM_THREADS; ++i) {
        if(i == puzzles.size()) break; // out of puzzles
        if(i == (NUM_THREADS - 1)) last = puzzles_size - 1; // Ensure all puzzles are solved
        LOG("Thread " + std::to_string(i) + " solving " + std::to_string(first) + " to " + std::to_string(last));
        threads.push_back(new std::thread{
            [&, first, last] {
                for(int p=first; p<=last; ++p) {
                    if(p >= puzzles.size()) break;
                    Puzzle& puzzle = puzzles.at(p);
                    Solver solver{puzzle};
                    for(std::string word : puzzle) {
                        Solution s = solver.solve(word);
                        m.lock();
                        solutions.push_back(s);
                        m.unlock();
                    }
                }
            }
        });
        first = std::min(last + 1, puzzles_size - 1);
        last = std::min(first + puzzles_per_thread - 1, puzzles_size - 1);
    }    
        
    for(std::thread* t : threads) {
        t->join();
    }

    std::sort(solutions.begin(), solutions.end());
    for(Solution& s : solutions) std::cout << s << std::endl;
}
    
   
