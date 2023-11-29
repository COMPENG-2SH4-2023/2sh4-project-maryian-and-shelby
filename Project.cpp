#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"


using namespace std;

#define DELAY_CONST 100000

GameMechs* pGameMechs = nullptr; // pointer to GameMechs class

Player* Snake = nullptr; // temporary

            

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

    while(pGameMechs->getExitFlagStatus() == false)  
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

    pGameMechs = new GameMechs(); // new oject of GameMechs class
    Snake = new Player(pGameMechs);

    pGameMechs->setExitFalse(); // QUESTION: initialize this in GameMechs???
    
}

void GetInput(void) // In tut 12 vid this was more optimized 
{
   if (MacUILib_hasChar())
    {
        pGameMechs->setInput(MacUILib_getChar());
        //pGameMechs->getInput(); 
    }

    pGameMechs->getInput(); 

}

void RunLogic(void)
{
    //pGameMechs->getInput(); // process input character ,choose correct actino

    Snake->updatePlayerDir();
    Snake->movePlayer();
    
    pGameMechs->clearInput(); // clear input field ingamemechs

    

    


}

void DrawScreen(void)
{
    MacUILib_clearScreen();   

    objPos tempPos;
    Snake->getPlayerPos(tempPos);
    
    // draw border
    for (int i = 0; i < pGameMechs->getBoardSizeY(); i++)
    {
        for (int j = 0; j < pGameMechs->getBoardSizeX(); j++) 
        {
            if (i == 0 || i == (pGameMechs->getBoardSizeY() - 1)) 
            {
                pGameMechs->boardData[i][j] = '#';
            }
            
            else if (j == 0 || j == (pGameMechs->getBoardSizeX() - 1))
            {
                pGameMechs->boardData[i][j] = '#';
            }
            
            
            /*
            else if (i==tempPos.y && j==tempPos.x)
            {
                pGameMechs->boardData[i][j] = tempPos.symbol;
            }
            */
            
            
            else
            {
                pGameMechs->boardData[i][j] = ' ';
            }

            pGameMechs->boardData[tempPos.y][tempPos.x] = tempPos.symbol;

            MacUILib_printf("%c", pGameMechs->boardData[i][j]);
        }

        MacUILib_printf("\n");

    } 



    MacUILib_printf("Player Direction: %c\n", Snake->direction);

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

    pGameMechs->~GameMechs(); // destructor
    delete pGameMechs; // delete pGameMechs created on heap by us
    delete Snake; // delete the player created by us on the heap
}
