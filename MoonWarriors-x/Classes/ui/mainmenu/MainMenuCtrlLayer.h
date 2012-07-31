//
//  MainMenuCtrlLayer.h
//  MoonWarriors-x
//
//  Created by Tom on 12-7-30.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#ifndef MoonWarriors_x_MainMenuCtrlLayer_h
#define MoonWarriors_x_MainMenuCtrlLayer_h

#include "cocos2d.h"
#include "GameManager.h"

USING_NS_CC;

// 菜单项
typedef enum
{
    MAINMENU_ID_NONE        = -1,
    // 新游戏
    MAINMENU_ID_NEW_GAME    = 0,
    // 游戏设置
    MAINMENU_ID_SETTING     = 1,
    // 关于
    MAINMENU_ID_ABOUT       = 2
} MAINMENU_ID;

class MainMenuCtrlLayer: public CCLayer
{
    
public:
    MainMenuCtrlLayer();
    ~MainMenuCtrlLayer();
    
    bool init();
    
    LAYER_NODE_FUNC(MainMenuCtrlLayer);
    
private:
    // 主菜单回调
    void mainMenuCallback(CCNode *pSender);
    
};


#endif
