#include "GameMechs.h"

GameMechs::GameMechs()
{
    boardSizeX = 30;
    boardSizeY = 15;

	boardData = new int*[boardSizeX];

	for(int i = 0; i < boardSizeX; i++)
	{
		boardData[i] = new int[boardSizeY];
	}

	for(int i = 0; i < boardSizeX; i++)
		for(int j = 0; j < boardSizeY; j++)
			boardData[i][j] = ' ';

}

GameMechs::GameMechs(int boardX, int boardY)
{
    boardSizeX = boardX;
    boardSizeY = boardY;

    boardData = new int*[boardSizeX];

	for(int i = 0; i < boardSizeX; i++)
	{
		boardData[i] = new int[boardSizeY];
	}

	for(int i = 0; i < boardSizeX; i++)
		for(int j = 0; j < boardSizeY; j++)
			boardData[i][j] = ' ';
}

// do you need a destructor?
GameMechs::~GameMechs()
{
    //delete in reverse order or allocation
    for (int i=0; i < boardSizeX; i++)
	{
		if(boardData[i] != NULL)
		{
			delete[] boardData[i];
		}
	}
	delete[] boardData;
}

bool GameMechs::getExitFlagStatus()
{
    return exitFlag;
}

bool GameMechs::getLoseFlagStatus()
{
    return loseFlag;
}

char GameMechs::getInput()
{
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
    // may need to change to allow score to increase by more than 1
}
