#include <iostream>
#include <thread>
#include <mutex>

int main() {
  std::mutex m;
  
  // Thread 1 uses mutex
  std::thread t{[&] {
      for(int i=0; i<100; ++i) {
          std::lock_guard<std::mutex> guard(m);
          std::cout << i << std::endl;
      }
  }};
  
  // Main thread ignores mutex
  for(char c=' '; c<='~'; ++c) {
      std::cout << c << std::endl;
  }
  
  t.join();
}
