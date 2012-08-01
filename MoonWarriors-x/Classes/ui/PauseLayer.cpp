//
//  PauseLayer.cpp
//  MoonWarriors-x
//
//  Created by Tom on 12-8-1.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#include "PauseLayer.h"

PauseLayer::PauseLayer()
{
}

PauseLayer::~PauseLayer()
{
}

bool PauseLayer::init()
{
    bool ret = false;
    
    do {
        CC_BREAK_IF(!CCLayerColor::initWithColor(ccc4f(255, 0, 0, 50)));
        
        CCArray *array = CCDirector::sharedDirector()->getRunningScene()->getChildren();
        CCObject *object = NULL;
        CCARRAY_FOREACH(array, object)
        {
            CCLayer *layer = (CCLayer*) object;
            layer->onExit();
        }
        
        ret = true;
    } while (0);
    
    return ret;
}

void PauseLayer::onEnter()
{
    CCLayerColor::onEnter();
    CCTouchDispatcher::sharedDispatcher()->addTargetedDelegate(this, 0, true);
}

void PauseLayer::onExit()
{
    CCTouchDispatcher::sharedDispatcher()->removeDelegate(this);
    CCLayerColor::onExit();
}

bool PauseLayer::ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    CCArray *array = CCDirector::sharedDirector()->getRunningScene()->getChildren();
    CCObject *object = NULL;
    CCARRAY_FOREACH(array, object)
    {
        CCLayer* layer = (CCLayer*) object;
        layer->onEnter();
    }
    
    this->removeFromParentAndCleanup(false);
    
    return true;
}

