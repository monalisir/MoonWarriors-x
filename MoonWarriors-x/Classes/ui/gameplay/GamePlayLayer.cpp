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
    CCTouchDispatcher::sharedDispatcher()->removeDelegate(this);
    CCLayer::onExit();
}

bool GamePlayLayer::ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    mTouchPos = CCDirector::sharedDirector()->convertToGL(pTouch->locationInView());
    mIsTouching = true;
    
    return true;
}

void GamePlayLayer::ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    if (mIsTouching) {
        CCPoint touchPos = CCDirector::sharedDirector()->convertToGL(pTouch->locationInView());
        CCPoint moveDelta = ccpSub(touchPos, mTouchPos);
        CCPoint nextPos = ccpAdd(mShip->getPosition(), moveDelta);
        CCLOG("Next Pos: %f, %f", nextPos.x, nextPos.y);
        if (CCRect::CCRectContainsPoint(winRect, nextPos)) {
            mShip->setPosition(nextPos);
        }
        mTouchPos = touchPos;
    }
}

void GamePlayLayer::ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    mTouchPos = CCPointZero;
    mIsTouching = false;
}

void GamePlayLayer::ccTouchCancelled(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    mTouchPos = CCPointZero;
    mIsTouching = false;
}

