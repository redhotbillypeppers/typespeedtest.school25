#include <iostream>
#include <chrono>
#include <thread>
#include <ctime>
#include <fstream>
#include <sstream>

#include "word_array_easy.h"
#include "word_array_hard.h"
#include "cinClear_nd_pause.h"
#include "user_class.h"
#include "sentence_array.h"


//these are two global variables used to initialize the 3 users and which user is being used.
//supposedly using global variables are bad practice but because these are used almost everywhere,
//passing by reference in each function seemed like doing too much and this i thought was the easier path.
user globalUserList[3] = {user(""),user("unnamed_user"),user("unnamed_user")};
int globalWhichUser = 0;


//this is a simple function that allows for a 3, 2, 1 timer to happen before a test.
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

//this function allows for the program to be able to save to a .txt file
void save() {
    std::ofstream saveData; //create an output stream called saveData
    saveData.open("saveData.txt"); //assign saveData.txt to saveData
    saveData << "1" << std::endl; // this indicator is used to check if there is data in the initialization function
    if (saveData.is_open()) { //checks if file is open
        for (int i = 0; i < 3; i++) { //starts the loop so that we can grab and put data into saveData from our user class objects
            saveData << globalUserList[i].name << '\n'; //gets name and sets as the name for the object
            for (int j = 0; j < 4; j++) { //this loop iterates on each line
                for (int k = 0; k < globalUserList[i].WPMGames[j].size(); k++) { // this loop is used to place the data in ordered commas
                    if (k < globalUserList[i].WPMGames[j].size()-1) { // I wanted to use a range based for loop, but I don't know how to make it so the last one has no comment
                        saveData << globalUserList[i].WPMGames[j][k] << ",";
                    }else {
                        saveData << globalUserList[i].WPMGames[j][k];
                    }
                }
                saveData << '\n'; // new line once all data for that individual test for the individual user has been entered.
            }
        }
    } else { // error message in case savedata wasn't open
        std::cout << "Error saving to file: saveData file not open." << std::endl;
    }
    saveData.close(); // close the file
}

//this function gives responses based on how the user did on each test
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

/*
this function is the analysis test,
the analysis test is used to try and analyze the users real wpm by allowing 3 different use cases.
*/
void analysisTestFunction () {
    const int easyListSize = std::size(easyList); // variable used to help index for the random words

    //same as above. I probably could have just made it so that all instances of hardListSize were
    //std::size(hardlist) but it was easier to use hardListSize in my head when programming this
    const int hardListSize = std::size(hardList);

    std::string randomTestSentence; //this string is used so that I can display a random sentence
    float wpmAverageNumerator = 0.0; //used to put into the
    float wpmAverageDenominator = 0.0;
    float wpmAverage;
    char userAnswer; // used for y/n responses
    std::string userSentenceInput;

    // this lambda function times, calculates, and handles the user's test for a particular segment the analysis.
    auto lambdaTestFunction = [&](float wordCount) {
        int attempt = 0;
        while (true) {
            std::cout << randomTestSentence << std::endl;
            auto startTime = std::chrono::high_resolution_clock::now(); //starts the timer
            std::getline(std::cin, userSentenceInput); //prompt user for the given test string
            auto endTime = std::chrono::high_resolution_clock::now(); //ends the timer
            auto time = std::chrono::duration<float>(endTime - startTime); //calculate timer
            if (userSentenceInput != randomTestSentence) {// checks if sentence is correct or not
                attempt++; // if sentence is incorrect the user is given another try.
                if (attempt == 2) {
                    std::cout << "You have made too many attempts for this part." << std::endl;
                    pause(1);
                    std::cout << "Returning back to menu..." << std::endl;
                    return 0;
                }
                std::cout << "You mistyped somewhere in this code. \nRestarting test section...\n";
                testCountdown();
            }else { // the particular segment is calculated and assigned to
                float wpmAverageTest = (wordCount/time.count()) * 60;
                wpmAverageDenominator += wordCount;
                wpmAverageNumerator += wpmAverageTest * wordCount;
                std::cout << wpmAverageTest << " words per minute. " << std::endl;
                return 1;
            }
        }
    };

    //inform user of the analysis test
    std::cout << "You have chosen the Analysis test." << std::endl;
    std::cout << "This test will have 3 parts, \n" << std::endl;
    std::cout << "1. A randomized list of 15 easy words\n2. A randomized list of 10 hard words \n3. A standard pre-generated sentence" << std::endl;
    std::cout << "\nYou will also get 2 attempts for each part, in case you accidentally mistype something.\n";
    std::cout << "\nDo you wish to continue? (Y/N)" << std::endl;

    std::cin >> userAnswer;
    while( !std::cin.fail() && userAnswer!='y' && userAnswer!='n' && userAnswer!='N' && userAnswer!='Y' ) {// check if user response is valid
        cinClear();
        std::cout << "Invalid response, please enter either Y or N: ";
        std::cin >> userAnswer;
    }
    cinClear();
    if (userAnswer=='N' || userAnswer=='n') { // go back to menu function
        return;
    }

    std::cout << "Please type as precisely as you can, starting on GO!" << std::endl;
    testCountdown();
    //--------------------------------------

    //first section of the test
    for (int i = 0;  i< 15; i++) {// for loop creates a randomized string of 15 easy words
        randomTestSentence += easyList[rand() % (easyListSize)];
        if (i < 14) {
            randomTestSentence += " ";
        }
    }
    if (lambdaTestFunction(15.00) == 0) { //call to lambda function
        return;
    }

    //--------------------------------------
    pause(1);
    std::cout << "The next section is beginning on GO!" << std::endl;
    testCountdown();
    //--------------------------------------

    //second section of test
    randomTestSentence = "";
    for (int i = 0;  i< 10; i++) {
        randomTestSentence += hardList[rand() % (hardListSize)]; // generate a string of 10 words based on the hard words array.
        if (i < 9) {
            randomTestSentence += " ";
        }
    }
    if (lambdaTestFunction(10.00) == 0) { // check if user got it right
        return;
    }

    //--------------------------------------
    pause(1);
    std::cout << "The next section is beginning on GO!" << std::endl;
    testCountdown();
    //--------------------------------------

    // third section of the test
    randomTestSentence = sentence[rand() % 21]; // get a sentence from the sentence array at random
    if (lambdaTestFunction(14.00) == 0) { // check if user got it right
        return;
    }
    //--------------------------------------

    //calculate the wpm average for the analysis test based on the calculations done in the lambda function
    wpmAverage = wpmAverageNumerator/wpmAverageDenominator;
    globalUserList[globalWhichUser].WPMGames[3].push_back(wpmAverage); // pushback in the correct vector to add another game
    std::cout << "For this analysis you typed at a pace of " << wpmAverage <<" words per minute " << std::endl; //display total average
    pause(1);
    wpmResponses(wpmAverage); //display a response based on the wpm average
    pause(2); // pause an extra second to let the user really look at their average
    std::cout << "\n\nGoing back to menu..." <<std::endl;
    save(); //save current game data
}

// this function is used for the easy medium and hard tests,
// there are a lot of similarities between this one and the analysis test function
// I chose not to include them as one function for three reasons
// 1. its easier this way 2. less complexity in one function 3. the games were different enough to solicit this
void whichTestFunction (int menuChoiceIndex){
    int easyListSize = std::size(easyList);// variable used to help index for the random words

    //same as above. I probably could have just made it so that all instances of hardListSize were
    //std::size(hardlist) but it was easier to use hardListSize in my head when programming this
    int hardListSize = std::size(hardList);

    char userAnswer;

    std::string emht[4] = {"easy", "medium", "hard", "analysis"};
    std::cout << "You have chosen the " << emht[menuChoiceIndex - 1] << " test.\nDo you wish to continue? (Y/N)\n";
    std::cin >> userAnswer;

    //error case if user does not input y or n
    while( !std::cin.fail() && userAnswer!='y' && userAnswer!='n' && userAnswer!='N' && userAnswer!='Y' ) {
        cinClear();
        std::cout << "Invalid response, please enter either Y or N: ";
        std::cin >> userAnswer;
    }
    cinClear(); // clear the cin register so that getline doesnt get y or n

    //if user wants to continue then let them
    if (userAnswer == 'y' || userAnswer == 'Y') {
        std::string randomTestSentence; //test sentence for all three tests
        std::string randomTestSentence2; //test sentence for medium and hard tests
        std::string inputSentence; //input sentence to be compared with randomTestSentence
        std::string inputSentence2;//input sentence to be compared with randomTestSentence2
        float testWPM; // test wpm to be pushed back into the correct vector that holds this data

        std::cout << "\nPlease type the given word sequence EXACTLY on GO!." << std::endl;
        testCountdown();

        //switch statement that creates random arrays of easy, hard or easy and hard words.
        switch (menuChoiceIndex) {
            case 1: //easy test sentence creation
                for (int i = 0;  i< 15; i++) {
                    randomTestSentence += easyList[rand() % (easyListSize)];
                    if (i < 14) { //conditional so that the sentence does not have a space at the end
                        randomTestSentence += " ";
                    }
                }
            break;
            case 2:{ // medium test sentences creation
              	for (int i = 0; i<10; i++){
                	if  (rand() % 3 == 0) {// 1 in 3 chance for a word in one of these sentences to be hard
                	    randomTestSentence += hardList[rand() % (hardListSize)];
                	} else {
                	    randomTestSentence += easyList[rand() % (easyListSize)];
                	}
              	    if (i < 9) { //conditional so that the sentence does not have a space at the end
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
            case 3:{//hard test sentences creation, all words in both sentences are from the hard words array
                for(int i = 0; i < 10; i++){
              	    randomTestSentence += hardList[rand() % (hardListSize)];
                    randomTestSentence2 += hardList[rand() % (hardListSize)];
                    if (i < 9) {
                        randomTestSentence += " ";
                        randomTestSentence2 += " ";
                    }
                }
                break;
            }
            default:
                std::cout << "Internal pass by value error! ";
                exit(0);
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
            std::cout<< randomTestSentence <<"\n" << inputSentence << std::endl;
        } else if (menuChoiceIndex == 2 || menuChoiceIndex == 3) {
            pause(1);
            auto time = std::chrono::duration<double>(endTime - startTime);
            testWPM = (20.00/time.count())*60;
            globalUserList[globalWhichUser].WPMGames[menuChoiceIndex-1].push_back(testWPM);
            std::cout << "Your WPM for this test was " << testWPM << " words per minute. ";
            pause(1);
            wpmResponses(testWPM);
            pause(2);
            std::cout << "\nGoing back to menu...\n";

        }else {
            pause(1);
            auto time = std::chrono::duration<double>(endTime - startTime);
            testWPM = (15.00/time.count())*60;
            globalUserList[globalWhichUser].WPMGames[0].push_back(testWPM);
            std::cout << "Your WPM for this test was " << testWPM << " words per minute. ";
            wpmResponses(testWPM);
            pause(2);
            std::cout << "\nGoing back to menu...\n";
        }
    }
    save();
}

//this menu shows stats for the user by accessing the data from the user object
void statsMenu() {
    int testTotalCount; //test count
    int userAnswer; //user input

    //lambda function used so that it can be reused as part of the menu
    auto menuPrinter = [&]() {
        globalUserList[globalWhichUser].wpmAverageCalc0123();//call the method to analyze data
        std::cout << "Billy's word speed type tester!\n"
        << globalUserList[globalWhichUser].name << "'s stats:\n";
        std::cout << "-----------------------------" << std::endl;
        std::cout << "Average easy WPM: " << globalUserList[globalWhichUser].averageWPM[0] << std::endl;
        std::cout << "Average medium WPM: " << globalUserList[globalWhichUser].averageWPM[1] << std::endl;
        std::cout << "Average hard WPM: " << globalUserList[globalWhichUser].averageWPM[2] << std::endl;
        std::cout << "Average analysis WPM: " << globalUserList[globalWhichUser].averageWPM[3] << std::endl;
        std::cout << "Total average WPM: " << globalUserList[globalWhichUser].averageWPM[4] << std::endl;
        std::cout << "\nEasy tests taken: " << globalUserList[globalWhichUser].WPMGames[0].size() << std::endl;
        std::cout << "Medium tests taken: " << globalUserList[globalWhichUser].WPMGames[1].size() << std::endl;
        std::cout << "Hard tests taken: " << globalUserList[globalWhichUser].WPMGames[2].size() << std::endl;
        std::cout << "Analysis tests taken: " << globalUserList[globalWhichUser].WPMGames[3].size() << std::endl;
        for (int i = 0; i < 4; i++) {
            testTotalCount += globalUserList[globalWhichUser].WPMGames[i].size();
        }
        std::cout << "total tests taken: " << testTotalCount << std::endl;
        std::cout << "-----------------------------" << std::endl;


        std::cout // mini menu
        << "1. Change user name\n"
        << "2. Change user\n"
        << "3. Exit back to menu" << std::endl;
    };


    //this while true statement is used so that the menu reappears after a user enters a choice and is finished with that choice
    while (true) {
        testTotalCount = 0; // variable for the test
        menuPrinter(); // print the menu(lambda functions are cool to me)
        std::cin >> userAnswer;
        while ( !std::cin.fail() && userAnswer != 1 && userAnswer != 2 && userAnswer != 3) { // check if user input is valid, if not, spew error message
            cinClear(); // clear cin register
            std::cout << "Invalid response: Please enter a number between 1-3" << std::endl;
            std::cin >> userAnswer;
        }

        //switch statement for the menu
        switch (userAnswer) {
            case 1:
                std::cout << "Change username to: " << std::endl;

                // cin ignore used to get rid of any potential left over characters in cin register
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin, globalUserList[globalWhichUser].name, '\n'); //assign new name
                std::cout << "Username changed to: " << globalUserList[globalWhichUser].name << std::endl;
                pause(1);
                break;
            case 2: // menu option 2 that changes the user to a different one based on user input
                std::cout << "Change to which user?" << std::endl;
                std::cout << "1. " << globalUserList[0].name << std::endl;
                std::cout << "2. " << globalUserList[1].name << std::endl;
                std::cout << "3. " << globalUserList[2].name << std::endl;
                std::cin >> globalWhichUser; //assign user defined input to this global var
                globalWhichUser -= 1;
                while (std::cin.fail() || (globalWhichUser != 0 && globalWhichUser != 1 && globalWhichUser != 2)) { // check for correct input
                    cinClear();
                    std::cout << "Invalid input, Please enter a number between 1 and 3: ";
                    std::cin >> globalWhichUser;
                    std::cout << globalWhichUser;
                    globalWhichUser -= 1;
                }
                break;
            case 3: // exit case
                std::cout << "Exiting back to menu..." << std::endl;
                return;
            default:
                std::cout << "Invalid input, Please enter a number between 1 and 3: ";
                break;
        }
    }
}


//all the other functions lead back into this menu function which acts as a liaison to every function.
int menuFunction() {
    int menuChoiceIndex; // initialize the var that a user can input

    //prints the menu according to what user is being used
    std::cout << "\nBilly's word speed type tester!\n"
              << globalUserList[globalWhichUser].name
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

    //checks if user input is correct, if not, prompt the user to reenter.
    while (std::cin.fail() || menuChoiceIndex < 1 || menuChoiceIndex > 6) {
        std::cout << "Invalid response, please enter a menu number(1-6)!\n";
        std::cin >> menuChoiceIndex;
        cinClear();
    }

    //switch function to go to different parts of the menu
    //if you notice all of them are return 1 except the last one which is return 0
    //this is because I want the above menu to reappear once the user is done with their test or done looking at their stats
    //and so since it is returning 1 the while loop will stay true until I exit using return zero
    //in which case the game will exit and save
    switch (menuChoiceIndex) {
        case 1: //easy test
            whichTestFunction(1);
        return 1;
        case 2: // medium test
            whichTestFunction(2);
        return 1;
        case 3: // hard test
            whichTestFunction(3);
        return 1;
        case 4: // analysis test
            analysisTestFunction();
            return 1;
        case 5: // go to stats menu
            statsMenu();
            return 1;
        case 6: // back to games menu/exit this game
            return 0;
        default: // probably will never happen since this is internal
            std::cout << "Internal Pass by value error! (function menuFunction)" << std::endl;
            exit(0);
    }
}

//this initializer function sets the seed for the rng and checks if there is already data
//and if not it will grab the data and set it for our defined global user objects
void initializer() {
    srand(time(nullptr)); //sets seed for random number generator

    std::ifstream saveData("saveData.txt");
    std::string bucket;
    getline(saveData, bucket,'\n');

    try {
        //first it checks to see if there is data in the file using 1, if not then the data is to be implicitly deleted
        //and written into using the save() function
        if (std::stoi(bucket) == 1) {
            //this for loop iterates within the saveData.txt file
            for (int i = 0; i < 3; i++) {
                std::getline(saveData,bucket, '\n');  //first we assign the name to the already initialized player object
                globalUserList[i].name = bucket;
                for (int j = 0; j < 4; j++) { // then we iterate from the 4 lines to get data in this order: easy, medium, hard, analysis tests
                    std::getline(saveData,bucket); // here we get the whole line and end at \n (since std::getline automatically sets the delimiter to \n)
                    std::stringstream ss(bucket); // here we set the string as a stringstream so that we can perform io operations on the string
                    while (getline(ss,bucket,',')) { // then here we get the data from the bucket until our string ends
                        globalUserList[i].WPMGames[j].push_back(std::stof(bucket)); // before every comma we add the game data to the vector
                    }
                }
            }

            //prompt to ask the user which user they want to use since they have already made a save in the past
            std::cout << "Welcome back to Billy's Word Speed Type tester! " << std::endl;
            std::cout << "Who is playing today?" << std::endl;
            std::cout << "1. " << globalUserList[0].name << std::endl;
            std::cout << "2. " << globalUserList[1].name << std::endl;
            std::cout << "3. " << globalUserList[2].name << std::endl;
            std::cin >> globalWhichUser;
            globalWhichUser -= 1;

            //if the input is incorrect it will give an error message shown in the std::cout below
            while (std::cin.fail() || (globalWhichUser != 0 && globalWhichUser != 1 && globalWhichUser != 2)) {
                cinClear();
                std::cout << "Invalid input, Please enter a number between 1 and 3: ";
                std::cin >> globalWhichUser;
                globalWhichUser -= 1;
            }
            std::cout << "Welcome back " << globalUserList[globalWhichUser].name << "!";
        }
    //this will catch the invalid argument from std::stoi in case if there is nothing(aka first time program use)
    } catch (std::invalid_argument){
        std::cout << "\nWelcome to Billy's word speed type tester!\n"
            << "\nPlease enter your name: ";
        std::getline(std::cin, globalUserList[0].name, '\n');
        std::cout << "Thank you " << globalUserList[0].name << std::endl;
    }
    saveData.close(); //close the file
}

//this is my main function that initializes the menu loop for the game
//int main function has a simple loop, and initializes using the initializer function
int main(){
    //initializer function initializes save states and checks if user has data
    initializer();

    //menu loop
    int i = 1;
    while (i == 1) {
        i = menuFunction();
    }


    save();   //saves player stats using the save function
    std::cout << "Game Saved!" << std::endl;
    std::cout << "Goodbye!" << std::endl;
    return 0;
}