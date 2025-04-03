#ifndef GAMESFUNCTION_H
#define GAMESFUNCTION_H

#include "cinClear_nd_pause.h"
#include <string>
#include <iostream>
#include <random>

int menuFunction(std::string userName) {
    int menuChoiceIndex;
    auto menuPrinter = [&](){
        std::cout << "\nBilly's word speed type tester!\n"
                  << userName
                  << ", please select an option!" << std::endl;
        std::cout
            << "    1. Easy Test\n"
            << "    2. Medium Test\n"
            << "    3. Hard Test\n"
            << "    4. Analysis Test\n"
            << "    5. User Stats\n"
            << "    6. Back to Games\n";
        std::cin >> menuChoiceIndex;
    };

    menuPrinter();

    while (std::cin.fail() || menuChoiceIndex < 1 || menuChoiceIndex > 6) {
      std::cout << "Invalid response, please enter a menu number(1-6)!\n";
      cinClear();
      std::cin >> menuChoiceIndex;
    }

    switch (menuChoiceIndex) {
        case 1:
            whichTestFunction(1);
            return 1;
        case 2:
            whichTestFunction(2);
            return 1;
        case 3:
            whichTestFunction(3);
            return 1;
        case 4:

            return 1;
        case 5:
            //statistics add here
            return 1;
        case 6:
            return 0;
    }


    return 0;
}

#endif // GAMESFUNCTION_H
