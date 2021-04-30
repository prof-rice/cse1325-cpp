#include <iostream>
#include <sstream>
#include <thread>
#include <mutex>

// ts_cout acts just like std::cout, and prints all when destructed
// BUT you must ONLY use ts_cout - uses of std::cout can still interfere!
class ts_cout: public std::ostringstream {
  public:
    ts_cout() = default;
    ~ts_cout() {
        std::lock_guard<std::mutex> guard(_m);
        std::cout << this->str();
    }
  private:
    static std::mutex _m;
};
std::mutex ts_cout::_m{};  // static attributes must be defined


int main() {
  // All threads use ts_cout
  std::thread t{[&] {
      for(int i=0; i<100; ++i) {
          ts_cout{} << i << std::endl;
      }
  }};
  
  for(char c=' '; c<='~'; ++c) {
      ts_cout{} << c << std::endl;
  }
  
  t.join();
}
