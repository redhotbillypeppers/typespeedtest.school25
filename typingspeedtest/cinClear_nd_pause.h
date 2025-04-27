#include <iostream>
#include <chrono>
#include <thread>

//this cinClear function wraps these 2 commands into one so it's a little cleaner everywhere we use it.
//there could have been a function which handles EVERY input exception into one but since each one had different cases
//I thought
void cinClear() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

//this pause function gives a simple function I can use to tell the console to pause any message for x seconds
void pause(int time){
    std::chrono::seconds dura(time);
    std::this_thread::sleep_for(dura);
}
