#include <iostream>
#include "word_array_easy.h"
#include "word_array_hard.h"
#include "cinClear_nd_pause.h"
#include "whichTestFunction.h"

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
        std::string inputSentence;
        std::cout << "\nPlease type the given word sequence EXACTLY on GO!." << std::endl;
        testCountdown();

        switch (menuChoiceIndex) {
            case 1:
                for (int i;  i< 15; i++) {
                    randomTestSentence += easyList[rand() % (easyListSize)];
                }
            break;
            case 2:{
                if (rand() % 2 == 0) {
                    randomTestSentence += easyList[rand() % (easyListSize)];
                } else {
                    randomTestSentence += hardList[rand() % (hardListSize)];
                }
            }
            break;
            case 3:
                randomTestSentence += hardList[rand() % (hardListSize)];
            break;
        }



        std::cout << randomTestSentence << std::endl;
        auto startTime = std::chrono::high_resolution_clock::now();
        std::getline(std::cin, inputSentence);
        auto endTime = std::chrono::high_resolution_clock::now();

        if (inputSentence + " " != randomTestSentence) {
            pause(1);
            std::cout << "You didnt type the sequence exactly :(\n ";
            pause(1);
            std::cout << "\nGoing back to menu...\n";
            pause(1);

            std::cout<< randomTestSentence <<"\n" << inputSentence << std::endl;
        } else {
            pause(1);
            auto time = std::chrono::duration<double>(endTime - startTime);
            std::cout << "Your WPM for this test was " << ((15.00/time.count())*60) << " words per minute.";

            pause(1);
            std::cout << "\nGoing back to menu...\n";
            pause(1);
        }
    }
}