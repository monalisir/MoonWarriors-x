//
//  MainMenuCtrlLayer.cpp
//  MoonWarriors-x
//
//  Created by Tom on 12-7-30.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#include "MainMenuCtrlLayer.h"

MainMenuCtrlLayer::MainMenuCtrlLayer()
{
}

MainMenuCtrlLayer::~MainMenuCtrlLayer()
{
}

bool MainMenuCtrlLayer::init()
{
    bool ret = false;
    
    do {
        CC_BREAK_IF(!CCLayer::init());
        
        CCSize winSize = CCDirector::sharedDirector()->getWinSize();
        
        // 菜单
        // 菜单纹理
        CCImage menuImage;
        menuImage.initWithImageFile("menu.png");
        CCTexture2D *menuTexture = new CCTexture2D();
        menuTexture->initWithImage(&menuImage);
        
        // 菜单选项
        CCMenuItemSprite *newGameMenuItem = CCMenuItemSprite::itemFromNormalSprite(CCSprite::spriteWithTexture(menuTexture, CCRectMake(0, 0, 126, 33)), CCSprite::spriteWithTexture(menuTexture, CCRectMake(0, 33, 126, 33)), CCSprite::spriteWithTexture(menuTexture, CCRectMake(0, 33 * 2, 126, 33)), this, menu_selector(MainMenuCtrlLayer::mainMenuCallback));
        newGameMenuItem->setTag(MAINMENU_ID_NEW_GAME);
        
        CCMenuItemSprite *settingMenuItem = CCMenuItemSprite::itemFromNormalSprite(CCSprite::spriteWithTexture(menuTexture, CCRectMake(126, 0, 126, 33)), CCSprite::spriteWithTexture(menuTexture, CCRectMake(126, 33, 126, 33)), CCSprite::spriteWithTexture(menuTexture, CCRectMake(126, 33 * 2, 126, 33)), this, menu_selector(MainMenuCtrlLayer::mainMenuCallback));
        settingMenuItem->setTag(MAINMENU_ID_SETTING);
        
        CCMenuItemSprite *aboutMenuItem = CCMenuItemSprite::itemFromNormalSprite(CCSprite::spriteWithTexture(menuTexture, CCRectMake(252, 0, 126, 33)), CCSprite::spriteWithTexture(menuTexture, CCRectMake(252, 33, 126, 33)), CCSprite::spriteWithTexture(menuTexture, CCRectMake(252, 33 * 2, 126, 33)), this, menu_selector(MainMenuCtrlLayer::mainMenuCallback));
        aboutMenuItem->setTag(MAINMENU_ID_ABOUT);
        
        CCMenu *mainMenu = CCMenu::menuWithItems(newGameMenuItem, settingMenuItem, aboutMenuItem, NULL);
        mainMenu->alignItemsVerticallyWithPadding(10);
        mainMenu->setPosition(ccp(winSize.width / 2, winSize.height / 2 - 80));
        this->addChild(mainMenu);
        
        ret = true;
    } while (0);
    
    return ret;
}

void MainMenuCtrlLayer::mainMenuCallback(cocos2d::CCNode *pSender)
{
    switch (pSender->getTag()) {
        case MAINMENU_ID_NEW_GAME:
            CCLOG("New Game");
            GameManager::sharedGameManager()->runSceneWithID(SCENE_ID_GAMEPLAY);
            break;
        case MAINMENU_ID_SETTING:
            CCLOG("Setting");
            GameManager::sharedGameManager()->runSceneWithID(SCENE_ID_SETTING);
            break;
        case MAINMENU_ID_ABOUT:
            GameManager::sharedGameManager()->runSceneWithID(SCENE_ID_ABOUT);
            CCLOG("About");
            break;
        default:
            break;
    }
}