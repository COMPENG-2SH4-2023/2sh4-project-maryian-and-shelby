#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "objPosArrayList.h"
#include "GameMechs.h"
#include "Player.h"
#include "Food.h"

using namespace std;

#define DELAY_CONST 100000

GameMechs* myGM; // pointer to GameMechs class

Player* Snake; // pointer to Player class

Food* myFood; /// pointer to Food class

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(myGM->getExitFlagStatus() == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

    myGM = new GameMechs(); // new object of GameMechs class
    myFood = new Food();
    Snake = new Player(myGM, myFood);

    objPos tempFood;
    objPosArrayList* playerPos = Snake->getPlayerPos(); // upgraded to array list
    myFood->generateFood(playerPos); // block off player pos (all snake body segment positions)

}

void GetInput(void)
{
    myGM->getInput(); 
}

void RunLogic(void)
{
    Snake->updatePlayerDir();
    Snake->movePlayer();

    myGM->clearInput(); // clear input after action is processed
}

void DrawScreen(void)
{
    MacUILib_clearScreen();   

    bool drawn; // flag for whether player is drawn or not 

    objPosArrayList* playerBody = Snake->getPlayerPos();
    objPos tempBody; 

    objPos tempFood;
    myFood->getFoodPos(tempFood);
    
   // draw border
    for (int i = 0; i < myGM->getBoardSizeY(); i++)
    {
        for (int j = 0; j < myGM->getBoardSizeX(); j++) 
        {
            drawn = false;

            for(int k = 0; k < playerBody->getSize(); k++)
            {
                playerBody->getElement(tempBody, k);
                if(tempBody.x == j && tempBody.y == i)
                {
                    MacUILib_printf("%c", tempBody.symbol);
                    drawn = true;
                    break;
                }
            }
            if(drawn) continue; // if player body drawn, don't draw anything below

            if (i == 0 || i == (myGM->getBoardSizeY() - 1) || j == 0 || j == (myGM->getBoardSizeX() - 1)) 
            {
                MacUILib_printf("%c", '#');
            }
            else if (i==tempFood.y && j==tempFood.x) // draw food
            {
                MacUILib_printf("%c", tempFood.symbol);
            }
            else
            {
                MacUILib_printf("%c", ' ');
            }
        }
        MacUILib_printf("\n");
    } 

    MacUILib_printf("Score: %d\n", myGM->getScore());
    
    /* Debug messages

    // MacUILib_printf("\n Player positions: \n"); // player position
 
    for(int l = 0; l < playerBody->getSize();l++) // snake head + body segments
    {
        playerBody->getElement(tempBody, l);
        MacUILib_printf("<%d, %d> ", tempBody.x, tempBody.y);
    }
    MacUILib_printf("\n Food Pos: <%d, %d> ", // food position
                    tempFood.x, tempFood.y);
    */
    

    // exit/lose statements
    if(myGM->getLoseFlagStatus() == true)
    {
        MacUILib_printf("\n You lose :( Game Over");
    }
    else if(myGM->getExitFlagStatus() == true)
    {
        MacUILib_printf("\n You have exited the game. \n");
    }
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    //MacUILib_clearScreen();    
  
    MacUILib_uninit();

    // remove heap instances
    delete myGM; // delete myGM created on heap by us
    delete Snake; // delete the player created by us on the heap
    delete myFood; // delete food created by us
}



