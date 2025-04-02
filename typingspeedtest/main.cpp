#include <iostream>
#include <chrono>
#include <thread>

#include "gamesfunction.h"





int main() {
    std::string userName;
    bool mainMenu = true;
    std::cout
    << "\nWelcome to Billy's word speed type tester!\n"
    << "\nPlease enter your name: ";

    std::cin >> userName;

    std::cout << "Thank you " << userName << std::endl;
    std::cout << "\nBilly's word speed type tester!\n"
                << userName
                << ", please select an option!\n" << std::endl;
    while (bool i = true) {
        i = menuFunction(mainMenu);
    }
    return 0;
}