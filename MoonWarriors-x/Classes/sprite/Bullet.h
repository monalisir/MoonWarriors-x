//
//  Bullet.h
//  MoonWarriors-x
//
//  Created by Tom on 12-8-1.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#ifndef MoonWarriors_x_Bullet_h
#define MoonWarriors_x_Bullet_h

#include "cocos2d.h"
#include "Constants.h"

USING_NS_CC;

class Bullet: public CCSprite
{
    
public:
    // 静态初始化方法
    static Bullet* bulletWithTag(BULLET_TAG pBulletTag);
    // 带偏转角度的静态初始化方法
    static Bullet* bulletWithTagAndRotation(BULLET_TAG pBulletTag, float pRotation);
    
public:
    // 改变状态
    void changeState(BULLET_STATE pBulletState);
    // 碰撞区域
    CCRect getCollideRect();
    
public:
    // 更新
    void update(ccTime dt);
    
private:
    // 重置子弹属性
    void resetBullet();
    
protected:
    // 攻击伤害
    CC_SYNTHESIZE(int, mPower, Power);
    // 运行速度(考虑到之后的散弹情况，使用x,y表示x,y轴的速度)
    CC_SYNTHESIZE(CCPoint, mVelocity, Velocity);
    // 偏转角度
    CC_SYNTHESIZE(float, mRotation, Rotation);
    
};

#endif
