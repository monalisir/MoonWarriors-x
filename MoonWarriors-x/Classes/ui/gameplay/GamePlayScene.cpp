//
//  GamePlayScene.cpp
//  MoonWarriors-x
//
//  Created by Tom on 12-7-30.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#include "GamePlayScene.h"

GamePlayScene::GamePlayScene()
{
}

GamePlayScene::~GamePlayScene()
{
}

bool GamePlayScene::init()
{
    bool ret = false;
    
    do {
        CC_BREAK_IF(!CCScene::init());
        
        this->addChild(GamePlayBGLayer::node(), 0);
        
        ret = true;
    } while (0);
    
    return ret;
}