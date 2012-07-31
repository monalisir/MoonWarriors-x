//
//  GameManager.cpp
//  MoonWarriors-x
//
//  Created by Tom on 12-7-30.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#include "GameManager.h"

static GameManager *mInstance = NULL;

GameManager::GameManager()
{
}

GameManager::~GameManager()
{
}

void GameManager::init()
{
    mCurrentScene = SCENE_ID_NONE;
}

GameManager* GameManager::sharedGameManager()
{
    if (!mInstance) {
        mInstance = new GameManager();
        mInstance->init();
    }
    
    return mInstance;
}


void GameManager::runSceneWithID(SCENE_ID pSceneID)
{
    SCENE_ID oldSceneID = mCurrentScene;
    mCurrentScene = pSceneID;
    
    CCScene *sceneToRun = NULL;
    
    switch (mCurrentScene) {
        case SCENE_ID_MAINMENU:
            sceneToRun = MainMenuScene::node();
            break;
            
        case SCENE_ID_GAMEPLAY:
            sceneToRun = GamePlayScene::node();
            break;
            
        case SCENE_ID_SETTING:
            sceneToRun = SettingScene::node();
            break;
            
        case SCENE_ID_ABOUT:
            sceneToRun = AboutScene::node();
            break;
            
        default:
            // 异常
            CCAssert(0, "Unknown Scene ID");
            break;
    }
    
    if (!sceneToRun) {
        mCurrentScene = oldSceneID;
        return;
    }
    
    // 判断是否是第一次载入场景
    if (!CCDirector::sharedDirector()->getRunningScene()) {
        CCDirector::sharedDirector()->runWithScene(sceneToRun);
    }
    else {
        CCDirector::sharedDirector()->replaceScene(sceneToRun);
    }
}