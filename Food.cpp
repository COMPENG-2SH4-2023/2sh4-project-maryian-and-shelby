#include "Food.h"
#include "GameMechs.h"
#include "objPos.h"
#include "MacUILib.h"

Food::Food()
{
    
    foodPos.setObjPos(-1, -1, 'o'); // initialize foodPos outside of gameboard
    srand(time(NULL));
}

Food::Food(int x, int y, char symbol)
{
    foodPos.setObjPos(x, y, symbol);
    srand(time(NULL));
}


Food::~Food()
{

}

void Food::generateFood(objPos blockOff)
{
// The random food generation algorithm should be placed here. (copy from PPA3)
// blockOff should contain the player position, on which the new food should NOT be generated.

	do
	{
        randx = (rand() % (myGMRef.getBoardSizeX() - 2)) + 1;
		//MacUILib_printf("\n randx: %d", randx);
		//MacUILib_printf("board size x: %d", myGMRef->getBoardSizeX());
        randy = (rand() % (myGMRef.getBoardSizeY() - 2)) + 1;
		MacUILib_printf("\n randy: %d", randy);
		foodPos.setObjPos(randx, randy, 'o');
	}
	while (foodPos.isPosEqual(&blockOff));
	
	MacUILib_printf("\n generate food called");
	
}	

void Food::getFoodPos(objPos &returnPos)
{
// Getter method for obtaining the current position of the food.
// Return value is written into the returnPos via pass by reference.

	returnPos.setObjPos(foodPos);

}
