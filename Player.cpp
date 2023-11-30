#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;
    myPrevDir = STOP;

    direction = 'N';

    // more actions to be included

    // Original Starting Player Position 
    // playerPos.setObjPos(mainGameMechsRef->getBoardSizeX()/2,
    //                     mainGameMechsRef->getBoardSizeY()/2,
    //                     '@');

    playerPos.setObjPos(5,5,'@');

    // no heap member yet - haven't used new 


}


Player::~Player()
{
    // delete any heap members here
    // (leave this empty for now: Iteration 1a)
}

void Player::getPlayerPos(objPos &returnPos)
{
    returnPos.setObjPos(playerPos.x, playerPos.y, playerPos.symbol);
    // return the reference to the playerPos arrray list
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
    
    switch(myDir)
    {
        case (UP):
            if (myPrevDir != DOWN)
            {
                playerPos.y--;
                myPrevDir = UP;
            }
            else
            {
                playerPos.y++;
            }
            break;
        case (DOWN):
            if (myPrevDir != UP)
            {
                playerPos.y++;
                myPrevDir = DOWN;
            }
            else
            {
                playerPos.y--;
            }
            break;
            
        case (LEFT):
            if (myPrevDir != RIGHT)
            {
                playerPos.x--;
                myPrevDir = LEFT;
            }
            else
            {
                playerPos.x++;
            }
            break;
        case (RIGHT):
            if (myPrevDir != LEFT)
            {
                playerPos.x++;
                myPrevDir = RIGHT;
            }
            else
            {
                playerPos.x--;
            }
            break;


       
        default:
            break;
    }

     // [TODO] : Heed the border wraparound!!!


    if (playerPos.y == 0)
    {
        playerPos.y = mainGameMechsRef->getBoardSizeY() - 2;
    }
    
    else if (playerPos.y == mainGameMechsRef->getBoardSizeY() - 1)
    {
        playerPos.y = 1;
    }

    if (playerPos.x == 0)
    {
        playerPos.x = mainGameMechsRef->getBoardSizeX() - 2;
    }

    else if (playerPos.x == mainGameMechsRef->getBoardSizeX() - 1)
    {
        playerPos.x = 1;
    }

}

