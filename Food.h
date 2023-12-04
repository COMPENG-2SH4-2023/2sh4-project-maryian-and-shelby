#ifndef FOOD_H
#define FOOD_H

#include <cstdlib>
#include <time.h>
#include "objPos.h"
#include "objPosArrayList.h"
#include "GameMechs.h"

using namespace std;

class Food
{
    private:
        objPos foodPos;
        int randx;
        int randy;

        GameMechs myGMRef;
    
    public:
        Food();
        Food(int x, int y, char symbol);
        ~Food();

<<<<<<< HEAD
        void generateFood(objPosArrayList* &blockOff);
=======
        void generateFood(objPosArrayList* &blockOff); 
>>>>>>> 165ce93b1195e1f417a1d8ef50d5edcd0be15825
        void getFoodPos(objPos &returnPos);
};

#endif