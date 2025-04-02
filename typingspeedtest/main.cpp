#include <iostream>
#include <chrono>
#include <thread>
#include "word_array_easy.h"
#include "word_array_hard.h"


bool menuFunction(bool mainMenu) {
    int menuChoiceIndex;
    auto menuPrinter = [&](){
        std::cout
            << "    1. Easy Test\n"
            << "    2. Medium Test\n"
            << "    3. Hard Test\n"
            << "    4. Analysis Test\n"
            << "    5. User Stats\n"
            << "    6. Back to Games\n";
        std::cin >> menuChoiceIndex;
    };
    while (menuChoiceIndex==0) {
        //while statement with updated cin registry ignore stuff
        while (std::cin.fail() || menuChoiceIndex < 1 || menuChoiceIndex > 6) {
            std::cin.clear();
            std::cin.ignore(500, '\n');
            menuPrinter();
        }

        //menu choice switch statement
        switch (menuChoiceIndex) {
            case 1:
                std::cout << "Welcome to the Easy Test!\n";
            std::cout << "Do you wish to start the test? (Y/N)"<< std::endl;
            std::cin >>
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                return false;
                break;
        }
    }
}

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