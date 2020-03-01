#pragma once
#include "Structures.h"
#include "Object.h"

//Version:          0.1
//Date Created:     02/26/2020
//Date Modified:    02/26/2020
//Creator:          Jonathan Oakes (darth62969/TheWired)
//Credits:          (add your name here if you modify this file)

/* This class handels Movement of objects in terms of contraints, collisions and other variables. 
 * The Goal of this structure is to make it easier to Make and modify the movements of objects
 * within the game. you should be able to create a class called "gravityAffected" which should
 * modify the standard movement of an object such that it is atracted to other objects or the
 * ground. 
 */
class movementPlan
{
public:
    const std::string name = "Default Movement Plan";
    const std::string description = "This class does nothing to your objects movement.";

    virtual point movement(point in);
    virtual point movement(point in, object* o);

    virtual bool colissionDetection(point in, object* o);
};

