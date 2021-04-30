#include <iostream>
#include <thread>
#include <mutex>

void thread_safe_print(std::string s) {
    static std::mutex m;
    std::lock_guard<std::mutex> guard(m);
    std::cout << s << std::endl;
}

int main() {
  // All threads use thread_safe_print
  std::thread t{[&] {
      for(int i=0; i<100; ++i) {
          thread_safe_print(std::to_string(i));
      }
  }};
  
  // Main thread ignores mutex
  for(char c=' '; c<='~'; ++c) {
      thread_safe_print(std::string(1, c));
  }
  
  t.join();
}
