#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"


using namespace std;

#define DELAY_CONST 100000

GameMechs* myGM; // pointer to GameMechs class

Player* Snake; // temporary

// Food* pFood = nullptr; // pointer to food class

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

    myGM = new GameMechs(); // new oject of GameMechs class
    Snake = new Player(myGM);
    
    // where to generate new food - generateFood() needs player reference (run logic?)
    // will need player reference AFTER player obj is instantiated
    objPos tempFood;
    objPos tempPos;
    Snake->getPlayerPos(tempPos);
    myGM->generateFood(tempPos);
    myGM->getFoodPos(tempFood);
    

}

void GetInput(void)
{

    myGM->getInput();


}

void RunLogic(void)
{
    //myGM->getInput(); // process input character ,choose correct actino

    Snake->updatePlayerDir();
    Snake->movePlayer();
    
    myGM->clearInput(); // clear input field in gamemechs

    

    


}

void DrawScreen(void)
{
    MacUILib_clearScreen();   

    objPos tempPos;
    objPos tempFood;
    Snake->getPlayerPos(tempPos);
    myGM->getFoodPos(tempFood);

    //myGM->generateFood(tempPos);
   // myGM->getFoodPos(tempFood);
 
   // MacUILib_printf("\n");
   // myGM->boardData[tempFood.y][tempFood.x] = tempFood.symbol;

    // draw border
    for (int i = 0; i < myGM->getBoardSizeY(); i++)
    {
        for (int j = 0; j < myGM->getBoardSizeX(); j++) 
        {
            if (i == 0 || i == (myGM->getBoardSizeY() - 1) || j == 0 || j == (myGM->getBoardSizeX() - 1)) 
            {
                myGM->boardData[i][j] = '#';
            }
                        
            else if (i==tempPos.y && j==tempPos.x)
            {
                myGM->boardData[i][j] = tempPos.symbol;
            }

            else if (i==tempFood.y && j==tempFood.x)
            {
                myGM->boardData[i][j] = tempFood.symbol;
            }
            
            else
            {
                myGM->boardData[i][j] = ' ';
            }

            MacUILib_printf("%c", myGM->boardData[i][j]);
        }

        MacUILib_printf("\n");

    } 

    // MacUILib_printf("Player Direction: %c\n", Snake->direction);

    //MacUILib_printf("Position x: %d  Position y: %d  Character", Position.x, Position.y);

    
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    
  
    MacUILib_uninit();

    // remove heap instances
    delete myGM; // delete myGM created on heap by us
    delete Snake; // delete the player created by us on the heap
}
