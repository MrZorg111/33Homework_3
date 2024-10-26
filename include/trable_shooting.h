#pragma once
#include <iostream>
#include <exception>

int check_input(int user_input) {
    if (user_input > 5 || user_input < 1 || user_input == 5) {
        throw std::invalid_argument(user_input == 5 ? "Exit " : "Error! Incorrect input!");
    }
    return user_input;
}
