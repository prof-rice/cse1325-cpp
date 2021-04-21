#include <iostream>
#include <thread>
#include <chrono>

void countdown(std::string msg, int delay) {
    std::this_thread::sleep_for (std::chrono::seconds(delay));
    std::cout << msg << std::endl;
}

int main() {
    std::thread t(countdown, "Surprise!", 5);
    t.join();
}

