#include "objPosArrayList.h"


// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.

objPosArrayList::objPosArrayList()
{
    aList = new objPos[ARRAY_MAX_CAP];   // 256 Elements on the Heap
    listSize = 0;                        // No valid element in the list upon startup
    arrayCapacity = ARRAY_MAX_CAP;       // Array capcity should be max
}

objPosArrayList::~objPosArrayList()
{
    delete[] aList;                      // Remember to use the [] the call destructor of all instancesin the array 
                                         // and not just the first
}

int objPosArrayList::getSize()
{
    return listSize;
}

void objPosArrayList::insertHead(objPos thisPos)
{
    if(listSize == arrayCapacity)
    {
        return;
    }

    for (int i=listSize; i>0; i--)
    {
        aList[i].setObjPos(aList[i-1]);  // Shiting all elements towards the tail to create space at the head
    }
    aList[0].setObjPos(thisPos); // Inserting the element at the head, index: 0
    listSize++;

}

void objPosArrayList::insertTail(objPos thisPos)
{
    if(listSize == arrayCapacity)
    {
        return;
    }

    aList[listSize].setObjPos(thisPos); // Inserting the element at the head, index: 0
    listSize++;
}

void objPosArrayList::removeHead()
{

    if (listSize == 0) // Check that list isn't 0, cause it will cause error
    {
        return;
    }
    
    // Shift every element starting from the second element

    for(int i = 0; i < (listSize -1); i++)
    {
        aList[i].setObjPos(aList[i+1]);
    }
    listSize--; 

}

void objPosArrayList::removeTail()
{
    if (listSize == 0) // Check that list isn't 0, cause it will cause error
    {
        return;
    }
    listSize--; 
}

void objPosArrayList::getHeadElement(objPos &returnPos)
{
    returnPos.setObjPos(aList[0]);
}

void objPosArrayList::getTailElement(objPos &returnPos)
{
    returnPos.setObjPos(aList[listSize-1]);
}

void objPosArrayList::getElement(objPos &returnPos, int index)
{
    returnPos.setObjPos(aList[index]);
}
