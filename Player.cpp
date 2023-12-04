#include "Player.h"


Player::Player(GameMechs* thisGMRef, Food* thisFood)
{
    mainGameMechsRef = thisGMRef;
    thisFoodRef = thisFood;
    
    myDir = STOP;
    myPrevDir = STOP;
    direction = 'N';

    // Original Starting Player Position 
    objPos tempPos;
    tempPos.setObjPos(mainGameMechsRef->getBoardSizeX()/2,
                      mainGameMechsRef->getBoardSizeY()/2,
                      '*');

    playerPosList = new objPosArrayList(); // Create space on heap for our snake
    playerPosList->insertHead(tempPos);    // Insert snake head at the starting position declared
}

Player::~Player()
{
    delete playerPosList;  // Deallocate memory created for snake
}


objPosArrayList* Player::getPlayerPos()
{
    return playerPosList; 
}

void Player::updatePlayerDir()
{
    char input = mainGameMechsRef->getInput(); 

    switch(input) // Input received from keybaord from the game mechanics class, change direction accordingly 
        {                          
            case 'w': 
                myDir = UP;
                break;

            case 's':
                myDir = DOWN;
                break;

            case 'a': 
                myDir = LEFT;
                break;

            case 'd':
                myDir = RIGHT;
                break;
            
            default:
                break;
        } 

}

void Player::movePlayer()
{
    objPos currHead; // will hold pos info of current head
    objPos currFood; // will hold pos of current food
    playerPosList->getHeadElement(currHead);
    thisFoodRef->getFoodPos(currFood);

    if (checkSelfCollision()) // If snake collied with itself set proper end game conditions
    {
        mainGameMechsRef->setLoseFlag();
        mainGameMechsRef->setExitTrue();
    }

    else // Move snake head
    {
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

        // iteration 3: check if newly positioned head overlaps w objPos of food
        if(currHead.x == currFood.x && currHead.y == currFood.y) // Add to snake length 
        {
            playerPosList->insertHead(currHead);
            thisFoodRef->generateFood(playerPosList);
            mainGameMechsRef->incrementScore();
        }
        else // Move snake normally
        {
            // new current head should be inserted to the head of the list,
            playerPosList->insertHead(currHead);
            // then remove the tail
            playerPosList->removeTail();
        }
    }
    
}

bool Player::checkSelfCollision()
{
    int arraysize = playerPosList->getSize();

    objPos headPos;
    playerPosList->getHeadElement(headPos);

    for (int i = 1; i < arraysize; i++) // start at 1 because head is at 0
    {
        objPos bodySegment;
        playerPosList->getElement(bodySegment, i);

        if (headPos.isPosEqual(&bodySegment)) // check head collision with each body segment
        {
            return true;
        }
    }
    return false;
}