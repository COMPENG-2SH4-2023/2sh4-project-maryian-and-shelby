#include "Food.h"
#include "GameMechs.h"
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

/*
Food::~Food()
{

}
*/
void Food::generateFood(objPos blockOff)
{
// The random food generation algorithm should be placed here. (copy from PPA3)
// blockOff should contain the player position, on which the new food should NOT be generated.

	do
	{
		randx = (rand() % (30 - 2)) + 1;
        // randx = (rand() % (myGMRef->getBoardSizeX() - 2)) + 1;
		//MacUILib_printf("\n %d", randx);
		
		randy = (rand() % (15 - 2)) + 1;
        // randy = (rand() % (myGMRef->getBoardSizeY() - 2)) + 1;
		//MacUILib_printf("\n %d", randy);
		foodPos.setObjPos(randx, randy, 'o');
	}
	while (foodPos.isPosEqual(&blockOff) == true);
	
	// MacUILib_printf("\n generate food called");
	
}	

void Food::getFoodPos(objPos &returnPos)
{
// Getter method for obtaining the current position of the food.
// Return value is written into the returnPos via pass by reference.

	returnPos.setObjPos(foodPos);

}
