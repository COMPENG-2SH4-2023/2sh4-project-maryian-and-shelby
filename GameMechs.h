#ifndef GAMEMECHS_H
#define GAMEMECHS_H

#include <cstdlib>

#include "objPos.h"
#include "objPosArrayList.h"

using namespace std;


class GameMechs
{
    
    private:
        char input;
        bool exitFlag;
        bool loseFlag; 
        int score;

        objPos foodPos;
        int randx;
        int randy;

        int boardSizeX;
        int boardSizeY;

    public:
        
        GameMechs();
        GameMechs(int boardX, int boardY);
        ~GameMechs();
        
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

};

#endif