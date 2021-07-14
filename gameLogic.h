#include <iostream>
#include <sstream>
#include "unit.h"
Unit unitArray[3][3];
char symbol = 'X';
int count = 0;

int tryPlace(std::string cord, char symbol) {
    int xCord, yCord;
    // Converts the string to int.
    std::stringstream ss;
    ss << cord.front();
    ss >> xCord;
    ss.clear();
    ss << cord.back();
    ss >> yCord;
    // Return 2 means something is wrong with the coordinates.
    // Return 1 means that it couldn't place the symbol at the selected coord.
    // Return 0 means success.
    if (cord.length() != 2)
        return 2;
    if (xCord != 0 && xCord != 1 && xCord != 2)
        return 2;
    if (yCord != 0 && yCord != 1 && yCord != 2)
        return 2;
    if (unitArray[xCord][yCord].changeState(symbol))
        return 0;
    else
        return 1;
}

void render() {
    // Render the grid
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (j == 2)
                std::cout << "[" << unitArray[i][j].getState() << "]"
                          << std::endl;
            else
                std::cout << "[" << unitArray[i][j].getState() << "]";
        }
    }
}

void resetGame() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            unitArray[i][j].reset();
}

bool checkWin() {
    // Checks for a win horizontally.
    for (int x = 0; x < 3; x++) {
        for (int y = 1; y < 3; y++) {
            if (unitArray[x][y].getState() == unitArray[x][y-1].getState() && unitArray[x][y].getState() != ' ') {
                if (unitArray[x][y+1].getState() == unitArray[x][y].getState()) {
                    render();
                    std::cout << unitArray[x][y].getState() << " won!";
                    return true;
                }
            }
        }
    }
    // Checks for a win vertically.
    for (int x = 1; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            if (unitArray[x][y].getState() == unitArray[x-1][y].getState() && unitArray[x][y].getState() != ' ') {
                if (unitArray[x+1][y].getState() == unitArray[x][y].getState()) {
                    render();
                    std::cout << unitArray[x][y].getState() << " won!";
                    return true;
                }
            }
        }
    }
    // Checks for a win diagonally.
    if ((unitArray[0][0].getState() == unitArray[1][1].getState()) &&
        (unitArray[1][1].getState() == unitArray[2][2].getState()) &&
        (unitArray[0][0].getState() != ' ') || // This part checks for 1st diagonal
        (unitArray[0][2].getState() == unitArray[1][1].getState()) &&
        (unitArray[1][1].getState() == unitArray[2][0].getState()) &&
        (unitArray[2][0].getState() != ' ')) { // This part checks for 2nd diagonal
        render();
        std::cout << unitArray[1][1].getState() << " won!";
        return true;
    }
    // If there is no win, then every check will
    // fail and nothing will be returned.
    return false;
}

void logic() {
    std::string position;
    if (symbol == 'X') {
        std::cout << "It is X's turn: ";
        std::cin >> position;
        std::cout << std::endl;
        int result = tryPlace(position, symbol);
        if (result == 0){
            symbol = 'O';
            count++;
        }
        else if (result == 1)
            std::cout << "Place already taken, please choose another one. \n";
        else if (result == 2)
            std::cout << "Invalid coordinates.\n";
    } else {
        std::cout << "It is O's turn: ";
        std::cin >> position;
        std::cout << std::endl;
        int result = tryPlace(position, symbol);
        if (result == 0)
            symbol = 'X';
        else if (result == 1)
            std::cout << "Place already taken, please choose another one. \n";
        else if (result == 2)
            std::cout << "Invalid coordinates.\n";
    }
    if (checkWin()) {
        count = 0;
        bool playAgain = false;
        std::string input;
        std::cout << std::endl << "Would you like to play again? y/n: ";
        std::cin >> input;
        if (input == "y" || input == "Y")
            playAgain = true;
        if (playAgain)
            resetGame();
        else
            exit(0);
    }
    if (count == 9) {
        bool playAgain = false;
        std::string input;
        std::cout << std::endl << "It's a tie! Would you like to play again? y/n: ";
        std::cin >> input;
        if (input == "y" || input == "Y")
            playAgain = true;
        if (playAgain)
            resetGame();
        else
            exit(0);
    }
}
