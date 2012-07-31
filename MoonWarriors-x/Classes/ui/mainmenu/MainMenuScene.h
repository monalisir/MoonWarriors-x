//
//  MainMenu.h
//  MoonWarriors-x
//
//  Created by Tom on 12-7-30.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#ifndef MoonWarriors_x_MainMenu_h
#define MoonWarriors_x_MainMenu_h

#include "cocos2d.h"
#include "MainMenuBGLayer.h"
#include "MainMenuCtrlLayer.h"

USING_NS_CC;

class MainMenuScene: public CCScene
{
    
public:
    MainMenuScene();
    ~MainMenuScene();
    
    bool init();
    
    SCENE_NODE_FUNC(MainMenuScene);
    
};

#endif
