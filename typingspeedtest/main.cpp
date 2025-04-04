#include <iostream>
#include <chrono>
#include <thread>
#include <ctime>
#include "word_array_easy.h"
#include "word_array_hard.h"
#include "cinClear_nd_pause.h"
#include "user_class.h"

void whichTestFunction (int menuChoiceIndex){
    int easyListSize = sizeof(easyList)/sizeof(easyList[0]);
    int hardListSize = sizeof(hardList)/sizeof(hardList[0]);
    char userAnswer;

    auto testCountdown = [&](){
        pause(1);
        std::cout << "3\n";
        pause(1);
        std::cout << "2\n";
        pause(1);
        std::cout << "1\n";
        pause(1);
        std::cout << "Go!" << std::endl;
        cinClear();
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
        std::string randomTestSentence;
        std::string randomTestSentence2;
        std::string inputSentence;
        std::string inputSentence2;
        std::cout << "\nPlease type the given word sequence EXACTLY on GO!." << std::endl;
        testCountdown();

        switch (menuChoiceIndex) {
            case 1:
                for (int i = 0;  i< 15; i++) {
                    randomTestSentence += easyList[rand() % (easyListSize)];
                    if (i < 14) {
                        randomTestSentence += " ";
                    }
                }
            break;
            case 2:{
              	for (int i = 0; i<10; i++){
                	if  (rand() % 3 == 0) {
                	    randomTestSentence += hardList[rand() % (easyListSize)];
                	} else {
                	    randomTestSentence += easyList[rand() % (hardListSize)];
                	}
              	    if (i < 9) {
              	        randomTestSentence += " ";
              	    }
                }
                for (int i = 0; i<10; i++) {
                    if  (rand() % 3 == 0) {
                        randomTestSentence2 += hardList[rand() % (easyListSize)];
                    } else {
                        randomTestSentence2 += easyList[rand() % (hardListSize)];
                    }
                    if (i < 9) {
                        randomTestSentence2 += " ";
                    }
                }
            }
            break;
            case 3:{
                for(int i = 0; i < 10; i++){
              	    randomTestSentence += hardList[rand() % (hardListSize)];
                    randomTestSentence2 += hardList[rand() % (hardListSize)];
                    if (i < 9) {
                        randomTestSentence += " ";
                        randomTestSentence2 += " ";
                    }
                }
            }
            break;
        }

        std::cout << randomTestSentence << std::endl;
        std::cout << randomTestSentence2 << std::endl;
        auto startTime = std::chrono::high_resolution_clock::now();
        std::getline(std::cin, inputSentence);
        if (menuChoiceIndex == 2 || menuChoiceIndex == 3) {
            std::getline(std::cin, inputSentence2);
        }
        auto endTime = std::chrono::high_resolution_clock::now();

        if (inputSentence + " " != randomTestSentence || inputSentence2 + " " != randomTestSentence2) {
            pause(1);
            std::cout << "You didnt type the sequence exactly :(\n ";
            pause(1);
            std::cout << "\nGoing back to menu...\n";
            pause(1);
            std::cout<< randomTestSentence <<"\n" << inputSentence << std::endl;
        } else if (menuChoiceIndex == 2 || menuChoiceIndex == 3) {
            pause(1);
            auto time = std::chrono::duration<double>(endTime - startTime);
            std::cout << "Your WPM for this test was " << ((20.00/time.count())*60) << " words per minute.";
            pause(1);
            std::cout << "\nGoing back to menu...\n";
            pause(1);
        }else {
            pause(1);
            auto time = std::chrono::duration<double>(endTime - startTime);
            std::cout << "Your WPM for this test was " << ((15.00/time.count())*60) << " words per minute.";
            pause(1);
            std::cout << "\nGoing back to menu...\n";
            pause(1);
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

            return 1;
        case 5:
            //statistics add here
                return 1;
        case 6:
            return 0;
    }
    return 0;
}

int main() {
    std::string userName;
    std::cout
    << "\nWelcome to Billy's word speed type tester!\n"
    << "\nPlease enter your name: ";

    srand(time(nullptr));

    std::cin >> userName;

    std::cout << "Thank you " << userName << std::endl;

    int i = 1;
    while (i == 1) {
        i = menuFunction(userName);
    }

    return 0;
}