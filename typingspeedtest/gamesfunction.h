#ifndef GAMESFUNCTION_H
#define GAMESFUNCTION_H
#include "cinclear.h"
#include "word_array_hard.h"
#include "word_array_easy.h"


void whichTestFunction = (std::string test){
    char userAnswer;

    std::cout << "You have chosen the " << test << " test.\n Do you want to continue? (Y/N)";
    std::cin >> userAnswer;

    while( std::cin.fail() || userAnswer!='y' || userAnswer!='n' ) {
        cinClear();
        std::cout << "Invalid response, please enter either Y or N";
        std::cin >> userAnswer;
    }

    if (userAnswer == 'y' || userAnswer == 'Y') {

    }else {
        menuChoiceIndex = 0;
    }
}

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
        menuPrinter();
        //while statement with updated cin registry ignore stuff
        while (std::cin.fail() || menuChoiceIndex < 1 || menuChoiceIndex > 6) {
            cinClear();
            menuPrinter();
        }

        //menu choice switch statement
        switch (menuChoiceIndex) {
            case 1:
                std::cout << "Welcome to the Easy Test!\n";
            std::cout << "Do you wish to start the test? (Y/N)"<< std::endl;
            std::cin >>
            menuPrinter()

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

#endif // GAMESFUNCTION_H
