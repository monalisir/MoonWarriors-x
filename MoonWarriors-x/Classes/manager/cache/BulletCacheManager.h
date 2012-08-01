//
//  BulletCache.h
//  MoonWarriors-x
//
//  Created by Tom on 12-8-1.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#ifndef MoonWarriors_x_BulletCache_h
#define MoonWarriors_x_BulletCache_h

#include "cocos2d.h"
#include "Bullet.h"
#include "Constants.h"

USING_NS_CC;

// 子弹缓冲池的初始容量
#define BULLET_CACHE_CAPACITY 400

class BulletCacheManager
{
    
private:
    BulletCacheManager();
    
public:
    ~BulletCacheManager();
    
    static BulletCacheManager* sharedBulletCacheManager();
    
public:
    // 初始化
    bool init();
    // 射击
    // pStartPos    起始位置
    // pVelocity    速度
    // pBulletTag   子弹类型标签
    // pRotation    旋转角度
    void shoot(CCPoint pStartPos, CCPoint pVelocity, float pRotation, BULLET_TAG pBulletTag);
    
public:
    void update(ccTime dt);
    
private:
    // 子弹批处理
    CC_SYNTHESIZE_READONLY(CCSpriteBatchNode*, mBulletBatch, BulletBatch);
    // 下一个未使用的子弹索引
    int mNextInactiveBulletIndex;
    
};

#endif
