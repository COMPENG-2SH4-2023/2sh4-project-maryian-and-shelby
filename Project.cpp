#include <iostream>
#include "MacUILib.h"
#include "objPos.h"


using namespace std;

#define DELAY_CONST 100000

#define ROW 10
#define COLUMN 20
char board[ROW][COLUMN] = {};

bool exitFlag;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(exitFlag == false)  
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

    exitFlag = false;
}

void GetInput(void)
{
   
}

void RunLogic(void)
{
    
}

void DrawScreen(void)
{
    MacUILib_clearScreen();   
    
    // draw border
    // additional ascii characters (iteration 0)
    objPos new1(1,2,'A');
    objPos new2(5,3,'B');
    objPos new3(3,14,'C');
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COLUMN; j++) 
        {
            if (i == 0 || i == 9)
            {
                board[i][j] = '#';
            }
            
            else if (j == 0 || j == 19)
            {
                board[i][j] = '#';
            }
            else
            {
                board[i][j] = ' ';
            }
            board[new1.x][new1.y] = new1.symbol;
            board[new2.x][new2.y] = new2.symbol;
            board[new3.x][new3.y] = new3.symbol;
            MacUILib_printf("%c", board[i][j]);
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
}
