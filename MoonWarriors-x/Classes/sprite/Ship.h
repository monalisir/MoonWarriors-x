//
//  Ship.h
//  MoonWarriors-x
//
//  Created by Tom on 12-7-31.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#ifndef MoonWarriors_x_Ship_h
#define MoonWarriors_x_Ship_h

#include "cocos2d.h"
#include "AbstractGameCharacter.h"

USING_NS_CC;

class Ship: public CCSprite, public AbstractGameCharacter
{
    
public:
    void initGameCharacter();
    void changeState(CHARACTER_STATE pCharacterState);
    CCRect getCollideRect();
    
public:
    // 静态初始化方法
    static Ship* shipWithTexture(CCTexture2D *pTexture, const CCRect& rect);
    
};

#endif
