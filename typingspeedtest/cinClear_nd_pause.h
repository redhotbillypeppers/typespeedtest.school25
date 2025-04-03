//
// Created by benis on 4/1/2025.
//

#ifndef CINCLEAR_H
#define CINCLEAR_H
#include <iostream>
#include <chrono>
#include <thread>
void cinClear() {
    std::cin.clear();
    std::cin.ignore(500, '\n');
}

void pause(int time){
    std::chrono::seconds dura(time);
    std::this_thread::sleep_for(dura);
}
#endif //CINCLEAR_H
