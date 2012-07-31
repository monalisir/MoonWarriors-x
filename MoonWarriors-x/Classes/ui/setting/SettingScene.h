//
//  SettingScene.h
//  MoonWarriors-x
//
//  Created by Tom on 12-7-30.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#ifndef MoonWarriors_x_SettingScene_h
#define MoonWarriors_x_SettingScene_h

#include "cocos2d.h"
#include "SettingBGLayer.h"

USING_NS_CC;

class SettingScene: public CCScene
{
    
public:
    SettingScene();
    ~SettingScene();
    
    bool init();
    
    SCENE_NODE_FUNC(SettingScene);
    
};

#endif
