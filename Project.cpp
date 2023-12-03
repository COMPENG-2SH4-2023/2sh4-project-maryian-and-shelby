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
Food* myFood;  // pointer to Food Class
Player* Snake; // pointer to Player Class

// bool exitFlag;

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
    myFood = new Food();    // new object of Food Class
    Snake = new Player(myGM, myFood);   // new object of Snake class, takes in the game mech and food class objects

    objPosArrayList* playerPos = Snake->getPlayerPos();  // get reference of player position list 
    myFood->generateFood(playerPos); // generates food item where the snake isn't

}

void GetInput(void)
{

    myGM->getInput();

}

void RunLogic(void)
{

    Snake->updatePlayerDir();
    Snake->movePlayer();
    myGM->clearInput(); 

}

void DrawScreen(void)
{
    MacUILib_clearScreen();   

    bool drawn;

    objPosArrayList* playerBody = Snake->getPlayerPos();
    objPos tempBody; // temp body segment to get info

    objPos tempFood;
    myFood->getFoodPos(tempFood);

    //objPos tempPos;
    
    //Snake->getPlayerPos(tempPos);
    
    //myFood->generateFood(tempPos);
    //myFood->getFoodPos(tempFood);

    // generate food needs player reference
   //objPos tempPos(1,1,'o');
   // myFood->generateFood(tempPos); // change to array list operation !!!!!!
 
   // MacUILib_printf("\n");
   // myGM->boardData[tempFood.y][tempFood.x] = tempFood.symbol;

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

            else if (i==tempFood.y && j==tempFood.x)
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
    
    if(myGM->getLoseFlagStatus() == true)
    {
        MacUILib_printf("\nGame Over :(");
    }
    else if(myGM->getExitFlagStatus() == true)
    {
        MacUILib_printf("\nYou have exited the game.");
    }
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    //MacUILib_clearScreen();    // Leave last screen on the board before shutting down the program
  
    MacUILib_uninit();

    // remove heap instances
    delete myGM; // delete myGM created on heap by us
    delete Snake; // delete the player created by us on the heap
    delete myFood; // delete the food created by us on the heap
}



