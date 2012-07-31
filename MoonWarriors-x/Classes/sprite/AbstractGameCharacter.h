//
//  GameCharacter.h
//  MoonWarriors-x
//
//  Created by Tom on 12-7-31.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#ifndef MoonWarriors_x_GameCharacter_h
#define MoonWarriors_x_GameCharacter_h

#include "cocos2d.h"
#include "Constants.h"

USING_NS_CC;

// 游戏角色公共属性抽象接口，实现子类包括玩家飞机和敌人飞机
class AbstractGameCharacter
{
    
public:
    // 初始化
    virtual void initGameCharacter() = 0;
    // 改变状态
    virtual void changeState(CHARACTER_STATE pCharacterState) = 0;
    // 碰撞区域(目前先做矩形)
    virtual CCRect getCollideRect() = 0;
    
protected:
    // 角色当前状态
    CC_SYNTHESIZE(CHARACTER_STATE, mCurrentState, CurrentState);
    // HP(血量)
    CC_SYNTHESIZE(int, mHP, HP);
    
};

#endif
