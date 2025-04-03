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
        pause();
        std::cout << "3\n";
        pause();
        std::cout << "2\n";
        pause();
        std::cout << "1\n";
        pause();
        std::cout << "Go!" << std::endl;
        cinClear();
    };

    auto officialTypeTest = [&](int testType) {
        std::string randomTestSentence;
        std::string inputSentence;
        std::cout << "\nPlease type the given word sequence EXACTLY on GO!." << std::endl;
        testCountdown();

        for(int i = 0; i < 15; i++) {
            switch (testType) {
                case 1:
                    randomTestSentence += easyList[rand() % (easyListSize + 1)];
                break;
                case 2:{
                    int coinFlip = rand() % 2;
                    if (coinFlip == 0) {
                        randomTestSentence += easyList[rand() % (easyListSize + 1)];
                    } else {
                        randomTestSentence += hardList[rand() % (hardListSize + 1)];
                    }
                }
                break;
                case 3:
                    randomTestSentence += hardList[rand() % (hardListSize + 1)];
                break;
            }
        }

        std::cout << randomTestSentence << std::endl;
        auto startTime = std::chrono::high_resolution_clock::now();
        std::getline(std::cin, inputSentence);
        auto endTime = std::chrono::high_resolution_clock::now();

        if (inputSentence + " " != randomTestSentence) {
            pause();
            std::cout << "You didnt type the sequence exactly :(\n ";
            pause();
            std::cout << "\nGoing back to menu...\n";
            pause();

            std::cout<< randomTestSentence <<"\n" << inputSentence << std::endl;
        } else {
            pause();
            auto time = std::chrono::duration_cast<std::chrono::seconds>(endTime - startTime);
            std::cout << "Your WPM for this  test was " << ((15/time.count())*60) << " words per minute.";

            pause();
            std::cout << "\nGoing back to menu...\n";
            pause();
        }
    };

    std::string emht[4] = {"easy", "medium", "hard", "analysis"};
    std::cout << "You have chosen the " << emht[menuChoiceIndex - 1] << " test.\nDo you wish to continue? (Y/N)\n";
    std::cin >> userAnswer;

    while( !std::cin.fail() && userAnswer!='y' && userAnswer!='n' && userAnswer!='N' && userAnswer!='Y' ) {
        cinClear();
        std::cout << "Invalid response, please enter either Y or N: ";
        std::cin >> userAnswer;
    }





    if (userAnswer == 'y' || userAnswer == 'Y') {
        switch (menuChoiceIndex) {
            case 1:
            officialTypeTest(menuChoiceIndex);
            break;
        case 2:
            officialTypeTest(menuChoiceIndex);
            break;
        case 3:
            officialTypeTest(menuChoiceIndex);
            break;
        case 4:
            officialTypeTest(menuChoiceIndex);
            break;
        }
    }
}


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
            whichTestFunction(4);
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
