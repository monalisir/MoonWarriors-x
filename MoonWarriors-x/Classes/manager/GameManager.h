//
//  GameManager.h
//  MoonWarriors-x
//
//  Created by Tom on 12-7-30.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#ifndef MoonWarriors_x_GameManager_h
#define MoonWarriors_x_GameManager_h

#include "cocos2d.h"
#include "Constants.h"
#include "MainMenuScene.h"
#include "GamePlayScene.h"
#include "SettingScene.h"
#include "AboutScene.h"

USING_NS_CC;

class GameManager
{

private:
    GameManager();
    // 初始化数据
    void init();
    
public:
    ~GameManager();
    
public:
    static GameManager* sharedGameManager();
    
public:
    // 跳转场景
    void runSceneWithID(SCENE_ID pSceneID);
    
    // 当前场景
    CC_SYNTHESIZE_READONLY(SCENE_ID, mCurrentScene, CurrentScene);
    
};

#endif
