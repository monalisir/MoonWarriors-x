//
//  MainMenuBGLayer.h
//  MoonWarriors-x
//
//  Created by Tom on 12-7-30.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#ifndef MoonWarriors_x_MainMenuBGLayer_h
#define MoonWarriors_x_MainMenuBGLayer_h

#include "cocos2d.h"
USING_NS_CC;

// 主菜单背景层
class MainMenuBGLayer: public CCLayer
{
    
public:
    MainMenuBGLayer();
    ~MainMenuBGLayer();
    
    bool init();
    
    LAYER_NODE_FUNC(MainMenuBGLayer);
    
private:
    // 飞船动画回调
    void spriteAnimCallback(CCNode *pSender);
    
private:
    // 执行飞船动画
    void runShipAnim(CCNode *pShip);
    
};


#endif
