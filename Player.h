#ifndef PLAYER_H
#define PLAYER_H

#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"
#include "Food.h"

class Player
{

    public:
        enum Dir {UP, DOWN, LEFT, RIGHT, STOP};   // This is the direction state

        Player(GameMechs* thisGMRef, Food* thisFoodRef);  // Constructor
        ~Player();                                        // Destructor

        objPosArrayList* getPlayerPos();
        void updatePlayerDir();
        void movePlayer();

        bool checkFoodConsumption();
        void increasePlayerLength();
        bool checkSelfCollision();

    private:

        objPosArrayList *playerPosList; // Array list to hold the snake
        enum Dir myDir;
        enum Dir myPrevDir; 
        
        // Need references to the other classes
        GameMechs* mainGameMechsRef;
        Food* thisFoodRef;
};

#endif