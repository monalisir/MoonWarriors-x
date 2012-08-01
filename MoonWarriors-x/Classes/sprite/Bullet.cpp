//
//  Bullet.cpp
//  MoonWarriors-x
//
//  Created by Tom on 12-8-1.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#include "Bullet.h"

void Bullet::changeState(BULLET_STATE pBulletState)
{
}

CCRect Bullet::getCollideRect()
{
    return CCRectMake(0, 0, 10, 10);
}

Bullet* Bullet::bulletWithTag(BULLET_TAG pBulletTag)
{
    return bulletWithTagAndRotation(pBulletTag, 0);
}

Bullet* Bullet::bulletWithTagAndRotation(BULLET_TAG pBulletTag, float pRotation)
{
    char frameName[256] = { 0 };
    int power = 0;
    
    // 根据不同子弹标签构造不同子弹
    switch (pBulletTag) 
    {
        case BULLET_TAG_PLAYER:
            sprintf(frameName, "W1.png");
            power = 2;
            break;
            
        case BULLET_TAG_ENEMY:
            sprintf(frameName, "W2.png");
            power = 1;
            break;
            
        default:
            CCAssert(0, "错误子弹类型");
            break;
    }
    
    Bullet *bullet = new Bullet();
    bullet->setPower(power);
    if (bullet && bullet->initWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(frameName)))
    {
        bullet->resetBullet();
	    bullet->autorelease();
        return bullet;
    }
    
    CC_SAFE_DELETE(bullet);
	return NULL;
}

void Bullet::resetBullet()
{
    mPower = 0;
    mVelocity = CCPointZero;
    mRotation = 0;
}


void Bullet::update(ccTime dt)
{
    this->setPosition(ccpAdd(this->getPosition(), ccpMult(mVelocity, dt)));
}






