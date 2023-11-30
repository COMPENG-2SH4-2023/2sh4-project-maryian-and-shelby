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

        GameMechs* myGMRef;
    
    public:
        Food();
        Food(int x, int y, char symbol);
        ~Food(); // destructor

        void generateFood(objPos blockOff);
        void getFoodPos(objPos &returnPos);
};

#endif