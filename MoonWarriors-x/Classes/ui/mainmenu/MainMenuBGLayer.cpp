//
//  MainMenuBGLayer.cpp
//  MoonWarriors-x
//
//  Created by Tom on 12-7-30.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#include "MainMenuBGLayer.h"

MainMenuBGLayer::MainMenuBGLayer()
{
}

MainMenuBGLayer::~MainMenuBGLayer()
{
}

bool MainMenuBGLayer::init()
{
    bool ret = false;
    
    do {
        CC_BREAK_IF(!CCLayer::init());
        
        CCSize winSize = CCDirector::sharedDirector()->getWinSize();
        
        // 背景
        CCSprite *bgSprite = CCSprite::spriteWithFile("loading.png");
        bgSprite->setPosition(ccp(winSize.width / 2, winSize.height / 2));
        this->addChild(bgSprite);
        
        // Logo
        CCSprite *logoSprite = CCSprite::spriteWithFile("logo.png");
        logoSprite->setAnchorPoint(CCPointZero);
        logoSprite->setPosition(ccp(0, 250));
        this->addChild(logoSprite);
        
        // 动画飞船
        // CCImage是由不同平台不同实现的
        CCImage shipImage;
        shipImage.initWithImageFile("ship.png");
        CCTexture2D *shipTexture = new CCTexture2D();
        shipTexture->initWithImage(&shipImage);
        CCSprite *shipSprite = CCSprite::spriteWithTexture(shipTexture, CCRectMake(0, 45, 60, 38));
        shipTexture->release();
        // 设置在屏幕之外
        shipSprite->setPosition(ccp(-shipSprite->getContentSize().width, -shipSprite->getContentSize().height));
        this->addChild(shipSprite);
        
        // 执行动作
        runShipAnim(shipSprite);
        
        ret = true;
    } while (0);
    
    return ret;
}

void MainMenuBGLayer::runShipAnim(cocos2d::CCNode *pShip)
{
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    
    pShip->setPosition(ccp(CCRANDOM_0_1() * winSize.width, 0));
    // 从底部移动到顶部，执行回调继续执行移动动作
    pShip->runAction(CCSequence::actions(CCMoveTo::actionWithDuration(2, ccp(CCRANDOM_0_1() * winSize.width, winSize.height + pShip->getContentSize().height / 2)), CCCallFunc::actionWithTarget(this, callfunc_selector(MainMenuBGLayer::spriteAnimCallback)), NULL));
}

void MainMenuBGLayer::spriteAnimCallback(cocos2d::CCNode *pSender)
{
    runShipAnim(pSender);
}