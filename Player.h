#ifndef PLAYER_H
#define PLAYER_H

#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"

class Player
{
    // Construct the remaining declaration from the project manual.

    // Only some sample members are included here

    // You will include more data members and member functions to complete your design.

    public:
        enum Dir {UP, DOWN, LEFT, RIGHT, STOP};  // This is the direction state

        Player(GameMechs* thisGMRef);
        ~Player();

        void getPlayerPos(objPos &returnPos); // Upgrade this in iteration 3.
        void updatePlayerDir();
        void movePlayer();

        char direction; // TEMPORARY TO SEE FSM DIRECITON

        // iteration 3
        bool checkFoodConsumption();
        void increasePlayerLength();
        bool checkSelfCollision();

    private:
        //objPos playerPos;   // Upgrade this in iteration 3.      
        objPosArrayList* playerPosList; 
        enum Dir myDir;
        enum Dir myPrevDir; // Added in 
        

        // Need a reference to the Main Game Mechanisms
        GameMechs* mainGameMechsRef;
};

#endif