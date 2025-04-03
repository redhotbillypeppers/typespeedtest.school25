#include <iostream>
#include <chrono>
#include <thread>

#include "menufunction.h"


int main() {
    std::string userName;
    std::cout
    << "\nWelcome to Billy's word speed type tester!\n"
    << "\nPlease enter your name: ";

    srand(time(NULL));

    std::cin >> userName;

    std::cout << "Thank you " << userName << std::endl;

    int i = 1;
    while (i == 1) {
        i = menuFunction(userName);
    }

    return 0;
}