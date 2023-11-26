#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"


using namespace std;

#define DELAY_CONST 100000

/* iteration 0:
#define ROW 10
#define COLUMN 20
char board[ROW][COLUMN] = {};
*/

GameMechs* pGameMechs = nullptr;

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

    pGameMechs = new GameMechs();
    pGameMechs->setExitFalse();

}

void GetInput(void)
{
   if (MacUILib_hasChar())
    {
        pGameMechs->setInput(MacUILib_getChar());
    }
}

void RunLogic(void)
{
    pGameMechs->getInput(); // process input character ,choose correct actino
    pGameMechs->clearInput(); // clear input field ingamemechs
}

void DrawScreen(void)
{
    MacUILib_clearScreen();   
    
    // draw border
    for (int i = 0; i < pGameMechs->getBoardSizeY(); i++)
    {
        for (int j = 0; j < pGameMechs->getBoardSizeX(); j++) 
        {
            if (i == 0 || i == (pGameMechs->getBoardSizeY() - 1)) 
            {
                pGameMechs->boardData[i][j] = 'X';
            }
            
            else if (j == 0 || j == (pGameMechs->getBoardSizeX() - 1))
            {
                pGameMechs->boardData[i][j] = 'Y';
            }
            else
            {
                pGameMechs->boardData[i][j] = ' ';
            }
            MacUILib_printf("%c", pGameMechs->boardData[i][j]);
        }
        MacUILib_printf("\n");
    } 
    
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
}
