#ifndef GAMESFUNCTION_H
#define GAMESFUNCTION_H
#include "cinclear.h"
#include "word_array_hard.h"
#include "word_array_easy.h"
#include <string>
#include <iostream>
#include <chrono>
#include <thread>
#include <random>


//general pause function, 1 second.
void pause(){
    std::chrono::seconds dura(1);
    std::this_thread::sleep_for(dura);
}

void whichTestFunction (int menuChoiceIndex){
    int easyListSize = sizeof(easyList)/sizeof(easyList[0]);
    int hardListSize = sizeof(hardList)/sizeof(hardList[0]);
    char userAnswer;

    auto testCountdown = [&](){
        std::cout << "3\n";
        pause();
        std::cout << "2\n";
        pause();
        std::cout << "1\n";
        pause();
        std::cout << "Go!";
    };

    std::string emht[4] = {"easy", "medium", "hard", "analysis"};
    std::cout << "You have chosen the " << emht[menuChoiceIndex] << " test.\n Do you wish to continue? (Y/N)";
    std::cin >> userAnswer;


    while( std::cin.fail() || userAnswer!='y' || userAnswer!='n' ) {
        cinClear();
        std::cout << "Invalid response, please enter either Y or N";
        std::cin >> userAnswer;
    }

    if (userAnswer == 'y' || userAnswer == 'Y') {
        switch (menuChoiceIndex) {
        case 0:
          testCountdown();
            //continue coding here, incomplete test
            break;
        case 1:

            break;
        case 2:

            break;
        case 3:

            break;
        }
    }
}


int menuFunction(std::string userName) {
    int menuChoiceIndex;
    auto menuPrinter = [&](){
        std::cout << "\nBilly's word speed type tester!\n"
                  << userName
                  << ", please select an option!\n" << std::endl;
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

            return 1;
        case 2:

            return 1;
        case 3:

            return 1;
        case 4:

            return 1;
        case 5:

            return 1;
        case 6:
            return 0;
    }


    return 0;
}

#endif // GAMESFUNCTION_H
