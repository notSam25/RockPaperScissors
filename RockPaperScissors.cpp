/* RockPaperScissors.cpp
 * Made to teach a friend how to use Switch statments.
*/

#include <iostream>
#include <String>
#include <stdio.h>

enum PlayerInput {
    ROCK = 1,
    PAPER,
    SCISSORS
};

int main() {
    srand(time(0));
    std::string input;

    std::cout << "Would you like to play? y/n ";
    std::cin >> input;

    while (input == "y" || input == "Y") {
        int RandomNumber = rand() % 3 + 1, PlayerSelection = 0;
        bool WonRound = false;

        std::cout << std::endl
                  << "(r)ock (p)aper or s(cissors)?" << std::endl;
        std::cin >> input;
        
        if (input == "r")
            PlayerSelection = 1;
        else if (input == "p")
            PlayerSelection = 2;
        else if (input == "s")
            PlayerSelection = 3;

        switch (RandomNumber)
        {
        case PlayerInput::ROCK:
            std::cout << "Computer chose: ROCK" << std::endl;
            if (PlayerSelection == (int)PlayerInput::PAPER)
                WonRound = true;
            break;
        case PlayerInput::PAPER:
            std::cout << "Computer chose: PAPER" << std::endl;
            if (PlayerSelection == (int)PlayerInput::SCISSORS)
                WonRound = true;
            break;
        case PlayerInput::SCISSORS:
            std::cout << "Computer chose: SCISSORS" << std::endl;
            if (PlayerSelection == (int)PlayerInput::ROCK)
                WonRound = true;
            break;
        default:
            break;
        }

        if (RandomNumber == PlayerSelection)
            std::cout << "It's a tie!" << std::endl;
        else if (WonRound)
            std::cout << "You won the round!" << std::endl;
        else
            std::cout << "You lost the round :(" << std::endl;

        std::cout << "Would you like to play? y/n ";
        std::cin >> input;
    }

    std::cout << std::endl
              << "Cya!" << std::endl;
    return 0;
}