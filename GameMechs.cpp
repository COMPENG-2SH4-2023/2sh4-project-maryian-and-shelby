#include "GameMechs.h"
#include "MacUILib.h"

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
	
	exitFlag = false;
	loseFlag = false;

	foodPos.setObjPos(-1, -1, 'o'); // initialize foodPos outside of gameboard

	srand(time(NULL));

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

	exitFlag = false;
	loseFlag = false;

	foodPos.setObjPos(-1, -1, 'o'); // initialize foodPos outside of gameboard

	srand(time(NULL));

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
    if (MacUILib_hasChar())
	{
		input = MacUILib_getChar();
	}
	else if(input == ' ')
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
	//MacUILib_printf("You lose :( Game Over."); // debug for lose flag
}

void GameMechs::clearInput()
{
    input = NULL;
}

void GameMechs::incrementScore()
{
    score++;
	//MacUILib_printf("Score has been incremented"); // debug for incscore
    // may need to change to allow score to increase by more than 1
}

// iteration 2b: random food generation

void GameMechs::generateFood(objPos blockOff)
{
// The random food generation algorithm should be placed here. (copy from PPA3)
// blockOff should contain the player position, on which the new food should NOT be generated.

	do
	{
		randx = (rand() % (boardSizeX - 2)) + 1;
		//MacUILib_printf("\n %d", randx);
		
		randy = (rand() % (boardSizeY - 2)) + 1;
		//MacUILib_printf("\n %d", randy);
		foodPos.setObjPos(randx, randy, 'o');
	}
	while (foodPos.isPosEqual(&blockOff) == true);
//	while (foodPos.x != blockOff.x && foodPos.y != blockOff.y);
	
	MacUILib_printf("\n generate food called");
	
}	

void GameMechs::getFoodPos(objPos &returnPos)
{
// Getter method for obtaining the current position of the food.
// Return value is written into the returnPos via pass by reference.

	returnPos.setObjPos(foodPos);

}
