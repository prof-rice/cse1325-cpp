#include <map>
#include <iostream>
#include <fstream>

int main() {
    std::map<std::string, int> cities;
    std::ifstream ist{"citypop.dat"};
    std::string city;
    int pop;
    while (ist >> city) {
        ist >> pop;
        cities[city] = pop;
    }
    while (std::cin) {
        std::cout << "Enter a city: ";
        std::cin >> city;
        if (cities.find(city) != cities.end())
        std::cout << city << " population is "
                  << cities[city] << std::endl;
        else
            std::cerr << city << " not found" << std::endl;
    }
}
