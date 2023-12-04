#include "GameMechs.h"
#include "MacUILib.h"

GameMechs::GameMechs()
{
	boardSizeX = 30;
    boardSizeY = 15;

	input = NULL;	
	exitFlag = false;
	loseFlag = false;

}

GameMechs::GameMechs(int boardX, int boardY)
{
    boardSizeX = boardX;
    boardSizeY = boardY;

	input = NULL;
	exitFlag = false;
	loseFlag = false;

}

// do you need a destructor?
GameMechs::~GameMechs()
{
    
}

bool GameMechs::getExitFlagStatus()
{
    return exitFlag; // game exited by user
}

bool GameMechs::getLoseFlagStatus()
{
    return loseFlag;
}

char GameMechs::getInput()
{
    if (MacUILib_hasChar())
	{
		input = MacUILib_getChar();
	}
	else if(input == ' ') // exit key ' '
	{
		exitFlag = true;
	}
	return input;
}

int GameMechs::getBoardSizeX()
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY()
{
    return boardSizeY;
}

int GameMechs::getScore()
{
    return score;
}

void GameMechs::setExitTrue()
{
	exitFlag = true;
}

void GameMechs::setExitFalse()
{
    exitFlag = false;
}

void GameMechs::setInput(char this_input)
{
    input = this_input;
}

void GameMechs::setLoseFlag()
{
	loseFlag = true;
}

void GameMechs::clearInput()
{
    input = NULL;
}

void GameMechs::incrementScore()
{
    score++;
}

