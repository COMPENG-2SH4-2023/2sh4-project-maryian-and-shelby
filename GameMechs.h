#ifndef GAMEMECHS_H
#define GAMEMECHS_H

#include <cstdlib>
#include <time.h>

#include "objPos.h"
#include "objPosArrayList.h"

using namespace std;


class GameMechs
{
    // Construct the remaining declaration from the project manual.

    // Only some sample members are included here

    // You will include more data members and member functions to complete your design.

    private:
        char input;
        bool exitFlag;
        bool loseFlag; // not true if player presses exit key, determine message to display
        int score;

        objPos foodPos;
        int randx;
        int randy;

        int boardSizeX;
        int boardSizeY;

    public:

        int **boardData; // heap data members
        
        GameMechs();
        GameMechs(int boardX, int boardY);
        ~GameMechs(); // destructor
        
        bool getExitFlagStatus();
        void setExitTrue();
        void setExitFalse();
        bool getLoseFlagStatus();
        void setLoseFlag();

        char getInput();
        void setInput(char this_input);
        void clearInput();

        int getBoardSizeX();
        int getBoardSizeY();
        int getScore();
        void incrementScore();

        // iteration 2b
        void generateFood(objPos blockOff);
        void getFoodPos(objPos &returnPos);
};

#endif