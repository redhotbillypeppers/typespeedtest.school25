#include <iostream>
#include <chrono>
#include <thread>
#include <ctime>
#include "word_array_easy.h"
#include "word_array_hard.h"
#include "cinClear_nd_pause.h"
#include "user_class.h"
#include "sentence_array.h"

void testCountdown () {
    pause(1);
    std::cout << "3\n";
    pause(1);
    std::cout << "2\n";
    pause(1);
    std::cout << "1\n";
    pause(1);
    std::cout << "Go!" << std::endl;
}

void wpmResponses (float wpm) {
    if (wpm < 45) {
        std::cout << "\nThat was pretty slow... Practice hard and try again!";
    } else if (wpm < 75){
        std::cout << "\nPretty quick... Can you reach 75 next time?";
    } else if (wpm < 105){
        std::cout << "\nThat was fast... Maybe you can push harder to 105?";
    } else {
        std::cout << "\nThat was really quick! Whats it like being nifty with your fingies?";
    }
}

void analysisTestFunction () {
    int easyListSize = std::size(easyList);
    int hardListSize = std::size(hardList);
    std::string randomTestSentence;
    float wpmAverageNumerator;
    float wpmAverageDenominator = 0;
    float wpmAverage;
    char userAnswer;


    std::cout << "You have chosen the Analysis test." << std::endl;
    std::cout << "This test will have 3 parts, \n" << std::endl;
    std::cout << "1. A randomized list of 15 easy words\n2. A randomized list of 10 hard words \n3. A standard pre-generated sentence" << std::endl;
    std::cout << "\nYou will also get 2 attempts for each part, in case you accidentally mistype something.\n(The 2nd attempt will be re-generated)\n";
    std::cout << "\nDo you wish to continue? (Y/N)" << std::endl;

    std::cin >> userAnswer;
    while( !std::cin.fail() && userAnswer!='y' && userAnswer!='n' && userAnswer!='N' && userAnswer!='Y' ) {
        cinClear();
        std::cout << "Invalid response, please enter either Y or N: ";
        std::cin >> userAnswer;
    }
    cinClear();
    if (userAnswer=='N' || userAnswer=='n') {
        return;
    }

    std::cout << "Please type as precisely as you can, starting on GO!" << std::endl;
    testCountdown();


    for (int i = 0;  i< 15; i++) {
        randomTestSentence += easyList[rand() % (easyListSize)];
        if (i < 14) {
            randomTestSentence += " ";
        }
    }
    std::cout << randomTestSentence << std::endl;



    auto startTime = std::chrono::high_resolution_clock::now();
    std::getline(std::cin, randomTestSentence);
    cinClear();
    auto endTime = std::chrono::high_resolution_clock::now();
    auto time = std::chrono::duration<float>(endTime - startTime);

    float wpmAverageTest = (15.00/time.count()) * 60;
    wpmAverageDenominator += 15.00;
    wpmAverageNumerator += wpmAverageTest * 15.00;

    std::cout << wpmAverageTest << " words per minute. " << std::endl;


    pause(1);


    std::cout << "The next section is beginning on GO!" << std::endl;
    testCountdown();

    randomTestSentence = "";
    for (int i = 0;  i< 10; i++) {
        randomTestSentence += hardList[rand() % (hardListSize)];
        if (i < 9) {
            randomTestSentence += " ";
        }
    }
    std::cout << randomTestSentence << std::endl;


    {
        auto startTime = std::chrono::high_resolution_clock::now();
        std::getline(std::cin, randomTestSentence);
        cinClear();
        auto endTime = std::chrono::high_resolution_clock::now();
        auto time = std::chrono::duration<float>(endTime - startTime);

        float wpmAverageTest = (10.00/time.count()) * 60;
        wpmAverageDenominator += 10.00;
        wpmAverageNumerator += wpmAverageTest * 15.00;

        std::cout << wpmAverageTest << " words per minute. " << std::endl;
    }



    pause(1);

    std::cout << "The next section is beginning on GO!" << std::endl;
    testCountdown();

    std::cout << sentence[rand() % 21] << std::endl;
    {
        auto startTime = std::chrono::high_resolution_clock::now();
        std::getline(std::cin, randomTestSentence);
        cinClear();
        auto endTime = std::chrono::high_resolution_clock::now();
        auto time = std::chrono::duration<float>(endTime - startTime);
        float wpmAverageTest = (10.00/time.count()) * 60;
        wpmAverageDenominator += 10.00;
        wpmAverageNumerator += wpmAverageTest * 15.00;
    }




    wpmAverage = wpmAverageNumerator/wpmAverageDenominator;
    std::cout << "For this analysis you typed at a pace of " << wpmAverage <<" words per minute " << std::endl;
    pause(1);
    wpmResponses(wpmAverage);
    pause(2);
    std::cout << "\n\nGoing back to menu..." <<std::endl;
    pause(1);
}

void whichTestFunction (int menuChoiceIndex){
    int easyListSize = std::size(easyList);
    int hardListSize = std::size(hardList);
    char userAnswer;

    std::string emht[4] = {"easy", "medium", "hard", "analysis"};
    std::cout << "You have chosen the " << emht[menuChoiceIndex - 1] << " test.\nDo you wish to continue? (Y/N)\n";
    std::cin >> userAnswer;

    while( !std::cin.fail() && userAnswer!='y' && userAnswer!='n' && userAnswer!='N' && userAnswer!='Y' ) {
        cinClear();
        std::cout << "Invalid response, please enter either Y or N: ";
        std::cin >> userAnswer;
    }
    cinClear();

    if (userAnswer == 'y' || userAnswer == 'Y') {
        std::string randomTestSentence;
        std::string randomTestSentence2;
        std::string inputSentence;
        std::string inputSentence2;
        float testWPM;

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
                	    randomTestSentence += hardList[rand() % (hardListSize)];
                	} else {
                	    randomTestSentence += easyList[rand() % (easyListSize)];
                	}
              	    if (i < 9) {
              	        randomTestSentence += " ";
              	    }
                }
                for (int i = 0; i<10; i++) {
                    if  (rand() % 3 == 0) {
                        randomTestSentence2 += hardList[rand() % (hardListSize)];
                    } else {
                        randomTestSentence2 += easyList[rand() % (easyListSize)];
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

        if (inputSentence != randomTestSentence || inputSentence2 != randomTestSentence2) {
            pause(1);
            std::cout << "You didnt type the sequence exactly :(";
            pause(1);
            std::cout << "\nGoing back to menu...\n";
            pause(1);
            std::cout<< randomTestSentence <<"\n" << inputSentence << std::endl;
        } else if (menuChoiceIndex == 2 || menuChoiceIndex == 3) {
            pause(1);
            auto time = std::chrono::duration<double>(endTime - startTime);
            testWPM = (20.00/time.count())*60;
            std::cout << "Your WPM for this test was " << testWPM << " words per minute. ";
            pause(1);
            wpmResponses(testWPM);
            pause(2);
            std::cout << "\nGoing back to menu...\n";
            pause(1);

        }else {
            pause(1);
            auto time = std::chrono::duration<double>(endTime - startTime);
            testWPM = (15.00/time.count())*60;
            std::cout << "Your WPM for this test was " << testWPM << " words per minute. ";
            wpmResponses(testWPM);
            pause(2);
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
        cinClear();
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
            analysisTestFunction();
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
    srand(time(nullptr));
    std::cout
    << "\nWelcome to Billy's word speed type tester!\n"
    << "\nPlease enter your name: ";

    std::cin >> userName;

    std::cout << "Thank you " << userName << std::endl;

    int i = 1;
    while (i == 1) {
        i = menuFunction(userName);
    }

    return 0;
}