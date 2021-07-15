#include <iostream>
#include <sstream>
#include "unit.h"
Unit unitArray[3][3];
char symbol = 'X';

int tryPlace(std::string cord, char symbol)
{
    int xCord, yCord;
    // Converts the string to int.
    std::stringstream ss;
    ss << cord.front();
    ss >> xCord;
    ss.clear();
    ss << cord.back();
    ss >> yCord;
    // Return 1 means that it couldn't place the symbol at the selected coord.
    // Return 0 means success.
    if (unitArray[xCord][yCord].changeState(symbol))
        return 0;
    else
        return 1;
}

void resetGame()
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            unitArray[i][j].reset();
}

bool checkWin() {
    // Checks for a win horizontally.
    for (int x = 0; x < 3; x++)
    {
        for (int y = 1; y < 3; y++)
        {
            if (unitArray[x][y].getState() == unitArray[x][y-1].getState()
                && unitArray[x][y].getState() != ' ')
            {
                if (unitArray[x][y+1].getState() == unitArray[x][y].getState())
                {
                    return true;
                }
            }
        }
    }
    // Checks for a win vertically.
    for (int x = 1; x < 3; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            if (unitArray[x][y].getState() == unitArray[x-1][y].getState()
                && unitArray[x][y].getState() != ' ')
            {
                if (unitArray[x+1][y].getState() == unitArray[x][y].getState())
                {
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
        (unitArray[2][0].getState() != ' ')) // This part checks for 2nd diagonal
        {
        return true;
    }
    // If there is no win, then every check will
    // fail and nothing will be returned.
    return false;
}
