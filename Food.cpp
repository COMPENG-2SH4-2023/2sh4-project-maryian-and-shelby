#include "Food.h"
#include "GameMechs.h"
#include "objPos.h"
#include "MacUILib.h"

Food::Food()
{
    
    foodPos.setObjPos(-1, -1, 'o'); 
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
 
    bool overlap;
    int arraysize = blockOff->getSize();

    do
    {
        randx = (rand() % (myGMRef.getBoardSizeX() - 2)) + 1; // random x coord
        randy = (rand() % (myGMRef.getBoardSizeY() - 2)) + 1; // random y coord
        overlap = false;

        for (int i = 0; i < arraysize; i++) // loop through each body segment of snake
        {
            objPos pos;
            blockOff->getElement(pos,i);
            if(randx == pos.x && randy == pos.y) // check for overlap
            {
                overlap = true;
                break;
            }
        }
        if (!overlap) // if no overlap, generate food
        {
            foodPos.setObjPos(randx, randy, 'o');
        }
    } while (overlap);
    
}	

void Food::getFoodPos(objPos &returnPos)
{
	returnPos.setObjPos(foodPos);
}
