#include "Player.h"


Player::Player(GameMechs* thisGMRef, Food* thisFood)
{
    mainGameMechsRef = thisGMRef;
    thisFoodRef = thisFood;
    myDir = STOP;
    myPrevDir = STOP;

    direction = 'N';

    // more actions to be included

    // Original Starting Player Position 
    objPos tempPos;
    tempPos.setObjPos(mainGameMechsRef->getBoardSizeX()/2,
                      mainGameMechsRef->getBoardSizeY()/2,
                      '@');

    //playerPos.setObjPos(5,5,'@');

    // no heap member yet - haven't used new 

    playerPosList = new objPosArrayList();
    playerPosList->insertHead(tempPos);

    /* for debugging purposes, insert another 4 segments
    playerPosList->insertHead(tempPos);
    playerPosList->insertHead(tempPos);
    playerPosList->insertHead(tempPos);
    playerPosList->insertHead(tempPos);
    */
}


Player::~Player()
{
    // delete any heap members here
    // (leave this empty for now: Iteration 1a)
    delete playerPosList;
}

//objPosArrayList* Player::getPlayerPos(objPosArrayList &playerPosList)
objPosArrayList* Player::getPlayerPos()
{
    //returnPos.setObjPos(playerPos.x, playerPos.y, playerPos.symbol);
    // return the reference to the playerPos arrray list
    return playerPosList;
}

void Player::updatePlayerDir()
{
    // PPA3 input processing logic

    char input = mainGameMechsRef->getInput();

    switch(input) // CHANGE THIS INPUT IN RELATION TO GAME MECHANICS
        {                          
            case 'w': 
                myDir = UP;
                direction = 'U';
                break;

            case 's':
                myDir = DOWN;
                direction = 'D';
                break;

            case 'a': 
                myDir = LEFT;
                direction = 'L';
                break;

            case 'd':
                myDir = RIGHT;
                direction = 'R';
                break;
            
            default:
                break;
        } 

}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
    objPos currHead; // holds pos info of current head
    objPos currFood; // holds pos of current food
    playerPosList->getHeadElement(currHead);
    thisFoodRef->getFoodPos(currFood);

    switch(myDir)
    {
        case (UP):
            if (myPrevDir != DOWN)
            {
                currHead.y--;
                myPrevDir = UP;
            }
            else
            {
                currHead.y++;
            }
            break;
        case (DOWN):
            if (myPrevDir != UP)
            {
                currHead.y++;
                myPrevDir = DOWN;
            }
            else
            {
                currHead.y--;
            }
            break;
            
        case (LEFT):
            if (myPrevDir != RIGHT)
            {
                currHead.x--;
                myPrevDir = LEFT;
            }
            else
            {
                currHead.x++;
            }
            break;
        case (RIGHT):
            if (myPrevDir != LEFT)
            {
                currHead.x++;
                myPrevDir = RIGHT;
            }
            else
            {
                currHead.x--;
            }
            break;


       
        default:
            break;
    }

     // [TODO] : Heed the border wraparound!!!


    if (currHead.y == 0)
    {
        currHead.y = mainGameMechsRef->getBoardSizeY() - 2;
    }
    
    else if (currHead.y == mainGameMechsRef->getBoardSizeY() - 1)
    {
        currHead.y = 1;
    }

    if (currHead.x == 0)
    {
        currHead.x = mainGameMechsRef->getBoardSizeX() - 2;
    }

    else if (currHead.x == mainGameMechsRef->getBoardSizeX() - 1)
    {
        currHead.x = 1;
    }

    // it3: check if newly positioned head overlaps w objPos of food
    if(currHead.x == currFood.x && currHead.y == currFood.y)
    {
        playerPosList->insertHead(currHead);
        thisFoodRef->generateFood(playerPosList); // issue?
    }
    else
    {
        // new current head should be inserted to the head of the list,
        playerPosList->insertHead(currHead);
        // then, remove the tail
        playerPosList->removeTail();
    }
    



}

