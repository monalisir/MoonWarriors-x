//
//  GamePlayLayer.cpp
//  MoonWarriors-x
//
//  Created by Tom on 12-7-31.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#include "GamePlayLayer.h"

GamePlayLayer::GamePlayLayer()
{
    mShip = NULL;
    mIsTouching = false;
}

GamePlayLayer::~GamePlayLayer()
{
}

bool GamePlayLayer::init()
{
    bool ret = false;
    
    do {
        CC_BREAK_IF(!CCLayer::init());
        
        CCSize winSize = CCDirector::sharedDirector()->getWinSize();
        winRect = CCRectMake(30, 20, winSize.width - 60, winSize.height - 40);
        
        CCTextureCache::sharedTextureCache()->addImage("ship.png");
        mShip = Ship::shipWithTexture(CCTextureCache::sharedTextureCache()->textureForKey("ship.png"), CCRectMake(0, 0, 60, 38));
        mShip->setPosition(ccp(winSize.width / 2, winSize.height / 2));
        this->addChild(mShip);
        
        // 子弹测试
        // 添加子弹批处理
        this->addChild(BulletCacheManager::sharedBulletCacheManager()->getBulletBatch());
//        // 生成一颗子弹
        BulletCacheManager::sharedBulletCacheManager()->shoot(ccp(100, 100), ccp(0, 100), 0, BULLET_TAG_PLAYER);
        
        // 开启update
        this->scheduleUpdate();
        
        ret = true;
    } while (0);
    
    return ret;
}

void GamePlayLayer::onEnter()
{
    CCLayer::onEnter();
    CCTouchDispatcher::sharedDispatcher()->addTargetedDelegate(this, 0, true);
}

void GamePlayLayer::onExit()
{
    CCLOG("GamePlayLayer::onExit()");
    CCTouchDispatcher::sharedDispatcher()->removeDelegate(this);
    CCLayer::onExit();
}

bool GamePlayLayer::ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    // TEST 暂停
    this->getParent()->addChild(PauseLayer::node(), 100);
    
    mTouchPos = CCDirector::sharedDirector()->convertToGL(pTouch->locationInView());
    mIsTouching = true;
    
    return true;
}

void GamePlayLayer::ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    if (mIsTouching) {
        CCPoint touchPos = CCDirector::sharedDirector()->convertToGL(pTouch->locationInView());
        // 取当前触摸点和起始点的偏移量
        CCPoint moveDelta = ccpSub(touchPos, mTouchPos);
        CCPoint nextPos = ccpAdd(mShip->getPosition(), moveDelta);
        
        if (CCRect::CCRectContainsPoint(winRect, nextPos)) {
            mShip->setPosition(nextPos);
        }
        // 给当前触摸点重新赋值
        mTouchPos = touchPos;
    }
}

void GamePlayLayer::ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    mIsTouching = false;
}

void GamePlayLayer::ccTouchCancelled(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    mIsTouching = false;
}

void GamePlayLayer::update(ccTime dt)
{
    BulletCacheManager::sharedBulletCacheManager()->update(dt);
}

