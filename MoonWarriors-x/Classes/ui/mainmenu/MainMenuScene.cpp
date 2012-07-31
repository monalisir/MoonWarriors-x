//
//  MainMenuScene.cpp
//  MoonWarriors-x
//
//  Created by Tom on 12-7-30.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#include "MainMenuScene.h"

MainMenuScene::MainMenuScene()
{
}

MainMenuScene::~MainMenuScene()
{
}

bool MainMenuScene::init()
{
    bool ret = false;
    
    do {
        CC_BREAK_IF(!CCScene::init());
        
        // 添加主菜单背景层
        this->addChild(MainMenuBGLayer::node(), 0);
        // 添加主菜单控制层（菜单层）
        this->addChild(MainMenuCtrlLayer::node(), 1);
        
        ret = true;
    } while (0);
    
    return ret;
}
