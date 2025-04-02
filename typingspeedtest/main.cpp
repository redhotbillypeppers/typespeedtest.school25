#include <iostream>
#include "word_array_easy.h"
#include "word_array_hard.h"

int main() {
    std::string userName;
    int menuChoiceIndex = 0;
    std::cout
    << "\nWelcome to Billy's word speed type tester!\n"
    << "\nPlease enter your name: ";

    std::cin >> userName;

    std::cout << "Thank you " << userName << std::endl;
    std::cout << "\nBilly's word speed type tester!\n"
                << userName
                << ", please select an option!\n" << std::endl;

    auto menuPrinter = [&](){
        std::cout
            << "    1. Easy Test\n"
            << "    2. Medium Test\n"
            << "    3. Hard Test\n"
            << "    4. Analysis Mode\n"
            << "    5. Stats\n"
            << "    6. Back to Games\n";
        std::cin >> menuChoiceIndex;
    };


    while (std::cin.fail() || menuChoiceIndex < 1 || menuChoiceIndex > 6) {
        std::cin.clear();
        std::cin.ignore(500, '\n');
        menuPrinter();
    }

    switch (menuChoiceIndex) {
        case 1:
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
            break;
    }
}