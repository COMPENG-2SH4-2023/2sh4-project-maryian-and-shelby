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

void Food::generateFood(objPosArrayList* &blockOff)
{
// The random food generation algorithm should be placed here. (copy from PPA3)
// blockOff should contain the player position, on which the new food should NOT be generated.
    
    bool overlap;
    int arraysize = blockOff->getSize();

    do
    {
        randx = (rand() % (myGMRef.getBoardSizeX() - 2)) + 1;
        randy = (rand() % (myGMRef.getBoardSizeY() - 2)) + 1;
        //foodPos.setObjPos(randx, randy, 'o');
        overlap = false;

        for (int i = 0; i < arraysize; i++)
        {
            objPos pos;
            blockOff->getElement(pos,i);
            if(randx == pos.x && randy == pos.y)
            {
                overlap = true;
                break;
            }
        }
        if (!overlap)
        {
            foodPos.setObjPos(randx, randy, 'o');
        }
    } while (overlap);
    
    //while (foodPos.isPosEqual(blockOff[count]));
    // while (foodPos.x != blockOff.x && foodPos.y != blockOff.y)
    
    
	
    //MacUILib_printf("\n generate food called");
	
}	

void Food::getFoodPos(objPos &returnPos)
{
// Getter method for obtaining the current position of the food.
// Return value is written into the returnPos via pass by reference.

	returnPos.setObjPos(foodPos);

}
