//
//  Ship.cpp
//  MoonWarriors-x
//
//  Created by Tom on 12-7-31.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#include "Ship.h"

void Ship::initGameCharacter()
{
    mCurrentState = CHARACTER_STATE_NONE;
    mHP = 10;
}

void Ship::changeState(CHARACTER_STATE pCharacterState)
{
    mCurrentState = pCharacterState;
    
    switch (mCurrentState) {
        case CHARACTER_STATE_SPAWNING:
            break;
        
        case CHARACTER_STATE_SHOOTING:
            break;
            
        case CHARACTER_STATE_HURT:
            break;
            
        case CHARACTER_STATE_DYING:
            break;
            
        default:
            break;
    }
}

CCRect Ship::getCollideRect()
{
    return CCRectMake(0, 0, 10, 10);
}


Ship* Ship::shipWithTexture(cocos2d::CCTexture2D *pTexture, const cocos2d::CCRect &rect)
{
    Ship *ship = new Ship();
	if (ship && ship->initWithTexture(pTexture, rect))
    {
        ship->initGameCharacter();
	    ship->autorelease();
        return ship;
    }
    
    CC_SAFE_DELETE(ship);
	return NULL;
}

