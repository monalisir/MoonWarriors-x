//
//  BulletCache.cpp
//  MoonWarriors-x
//
//  Created by Tom on 12-8-1.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#include "BulletCacheManager.h"

static BulletCacheManager* mInstance = NULL;

BulletCacheManager::BulletCacheManager()
{
}

BulletCacheManager::~BulletCacheManager()
{
}

BulletCacheManager* BulletCacheManager::sharedBulletCacheManager()
{
    if (!mInstance) {
        mInstance = new BulletCacheManager();
        if (!mInstance->init()) {
            CCAssert(0, "BulletCacheManager init failed!");
        }
    }
    
    return mInstance;
}

bool BulletCacheManager::init()
{
    bool ret = false;
    
    do {
        // 将子弹图片资源根据索引plist文件加载到内存中
        CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("bullet.plist");
        // 构造子弹批处理
        mBulletBatch = CCSpriteBatchNode::batchNodeWithFile("bullet.png");
        
        for (int i=0; i<BULLET_CACHE_CAPACITY; ++i) {
            Bullet *bullet = Bullet::bulletWithTag(BULLET_TAG_PLAYER);
            bullet->setIsVisible(false);
            mBulletBatch->addChild(bullet);
        }
        
        mNextInactiveBulletIndex = 0;
        
        ret = true;
    } while (0);
    
    return ret;
}

void BulletCacheManager::shoot(CCPoint pStartPos, CCPoint pVelocity, float pRotation, BULLET_TAG pBulletTag)
{
    // TODO 获取一个不在当前显示的子弹，设置其起始位置，速度，旋转角度等属性
    CCArray *bullets = mBulletBatch->getChildren();
    CCObject *object = bullets->objectAtIndex(mNextInactiveBulletIndex);
    Bullet *bullet = (Bullet*) object;
    
    // 设置子弹属性
    int power = 0;
    switch (pBulletTag) {
        case BULLET_TAG_PLAYER:
            power = 2;
            break;
        
        case BULLET_TAG_ENEMY:
            power = 1;
            break;
            
        default:
            CCAssert(0, "Bad BulletTag");
            break;
    }
    
    bullet->setPower(power);
    bullet->setPosition(pStartPos);
    bullet->setVelocity(pVelocity);
    bullet->setRotation(pRotation);
    bullet->setIsVisible(true);
    
    // 
    ++mNextInactiveBulletIndex;
    if (mNextInactiveBulletIndex >= mBulletBatch->getChildrenCount()) {
        mNextInactiveBulletIndex = 0;
    }
}

void BulletCacheManager::update(ccTime dt)
{
    CCArray *array = mBulletBatch->getChildren();
    CCObject *object = NULL;
    
    CCARRAY_FOREACH(array, object)
    {
        Bullet *bullet = (Bullet*) object;
        bullet->update(dt);
    }
}

