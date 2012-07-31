//
//  AboutScene.cpp
//  MoonWarriors-x
//
//  Created by Tom on 12-7-30.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#include "AboutScene.h"

AboutScene::AboutScene()
{
}

AboutScene::~AboutScene()
{
}

bool AboutScene::init()
{
    bool ret = false;
    
    do {
        CC_BREAK_IF(!CCScene::init());
        
        this->addChild(AboutBGLayer::node(), 0);
        
        ret = true;
    } while (0);
    
    return ret;
}