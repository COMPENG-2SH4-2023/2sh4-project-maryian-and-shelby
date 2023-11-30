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

Player* Snake; // temporary

Food* myFood;

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
    myFood = new Food();
    Snake = new Player(myGM, myFood);
   // myFood = new Food();
    
    // where to generate new food - generateFood() needs player reference (run logic?)
    // will need player reference AFTER player obj is instantiated
    objPos tempFood;
     
    //objPos tempPos;
    //Snake->getPlayerPos(tempPos);
    //myFood->generateFood(tempPos);
    //myFood->getFoodPos(tempFood);

    // generate food needs player reference
    //objPos tempPos(1,1,'o');
    objPosArrayList* playerPos = Snake->getPlayerPos();
    myFood->generateFood(playerPos); // change to array list operation !!!!!!

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

    bool drawn;

    objPosArrayList* playerBody = Snake->getPlayerPos();
    objPos tempBody; // temp body segment to get info

    //objPos tempPos;
    objPos tempFood;
    //Snake->getPlayerPos(tempPos);
    myFood->getFoodPos(tempFood);
    //myFood->generateFood(tempPos);
    //myFood->getFoodPos(tempFood);

    // generate food needs player reference
    objPos tempPos(1,1,'o');
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
                    //myGM->boardData[i][j] = tempBody.symbol;
                    drawn = true;
                    break;
                }
            }
            if(drawn) continue; // if player body drawn, don't draw anything below

            if (i == 0 || i == (myGM->getBoardSizeY() - 1) || j == 0 || j == (myGM->getBoardSizeX() - 1)) 
            {
                MacUILib_printf("%c", '#');
                //myGM->boardData[i][j] = '#';
            }
                        
       /*     else if (i==tempPos.y && j==tempPos.x)
            {
                myGM->boardData[i][j] = tempPos.symbol;
            }
*/
            else if (i==tempFood.y && j==tempFood.x)
            {
                MacUILib_printf("%c", tempFood.symbol);
                //myGM->boardData[i][j] = tempFood.symbol;
            }
            
            else
            {
                MacUILib_printf("%c", ' ');
                //myGM->boardData[i][j] = ' ';
            }

            //MacUILib_printf("%c", myGM->boardData[i][j]);
        }

        MacUILib_printf("\n");

    } 

    // MacUILib_printf("Player Direction: %c\n", Snake->direction);
    MacUILib_printf("Score: %d\n", myGM->getScore());

    //MacUILib_printf("Position x: %d  Position y: %d  Character", Position.x, Position.y);
    MacUILib_printf("Player positions: \n");
    for(int l = 0; l < playerBody->getSize();l++)
    {
        playerBody->getElement(tempBody, l);
        MacUILib_printf("<%d, %d> ", tempBody.x, tempBody.y);
    }
    MacUILib_printf("\n Food Pos: <%d, %d> ",
                    tempFood.x, tempFood.y);
    
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
    delete myFood;
}
