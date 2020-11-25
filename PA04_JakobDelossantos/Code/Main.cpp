/////////////////////////////////////////////////////////////////////////////
//
//	File: Main.cpp
//
//	$Header: $
//
//
/////////////////////////////////////////////////////////////////////////////


#include <signal.h>
#include <time.h>
#include "LeftLeaningRedBlack.h"

int main()
{
    LeftLeaningRedBlack testTree;
    int fourthVar=0;
    srand(time(NULL));
    for(int i=0; i<10; i++) //Loop to insert 10 random numbers.
    {
        int num = rand() % 100;
        LLTB_t newNode;
        newNode.Ref.Key=num;
        newNode.IsRed = true;
        testTree.Insert(newNode.Ref);
        if (i==3)
        {
            fourthVar=num;
        }
    }
     //Tree after inserting, before deletion
     std::cout<<"--------------------Tree after insertion, before deletion--------------------"<<std::endl;
    testTree.Traverse();

    //Deletion
    testTree.Delete(fourthVar);
    std::cout<<"Successfully deleted: "<<fourthVar<<std::endl<<std::endl;

    //Tree after deletion
    std::cout<<"--------------------Tree after deletion--------------------"<<std::endl;
    testTree.Traverse();
   
    return 0;
}




