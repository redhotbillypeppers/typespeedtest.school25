//
// Created by benis on 4/1/2025.
//

#ifndef CINCLEAR_H
#define CINCLEAR_H
#include <iostream>
void cinClear() {
    std::cin.clear();
    std::cin.ignore(500, '\n');
}
#endif //CINCLEAR_H
