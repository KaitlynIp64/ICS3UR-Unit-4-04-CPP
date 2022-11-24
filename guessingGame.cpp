// Copyright (c) 2022 Kaitlyn Ip All rights reserved.
//
// Created by: Kaitlyn Ip
// Date: Nov 2022
// This program asks the user to guess a number between 0 to 9
// and tells the user if the guess is right or wrong

#include <iostream>
#include <random>

int main() {
    int correctNum;
    int userNumInt;
    std::string userNumString;
    while (true) {
        // get the user's guess
        std::cout << "Enter a whole number between 0 to 9: ";
        std::cin >> userNumString;
        std::cout << "" << std::endl;
        // generate a number between 0 to 9
        std::random_device rseed;
        std::mt19937 rgen(rseed());
        std::uniform_int_distribution<int> idist(0, 9);
        correctNum = idist(rgen);
        try {
            userNumInt = std::stoi(userNumString);
            // calculates the square of each number from 0 to the user number
            if (userNumInt == correctNum) {
                std::cout << "You guessed the correct number!"
                "Thank you for playing!" << std::endl;
                break;
            } else {
                std::cout << "You guess incorrectly."
                "Please try again!" << std::endl;
            }
            // make sure to catch errors such as anything but an integer
        } catch (std::invalid_argument) {
            // The user did not enter an integer.
            std::cout << "That is not a valid input.";
        }
    }
    std::cout << std::endl;
    std::cout << "\nDone." << std::endl;
}
