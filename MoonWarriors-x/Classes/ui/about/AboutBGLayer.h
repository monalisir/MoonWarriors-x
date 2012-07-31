//
//  AboutBGLayer.h
//  MoonWarriors-x
//
//  Created by Tom on 12-7-30.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#ifndef MoonWarriors_x_AboutBGLayer_h
#define MoonWarriors_x_AboutBGLayer_h

#include "cocos2d.h"

USING_NS_CC;

class AboutBGLayer: public CCLayer
{
    
public:
    AboutBGLayer();
    ~AboutBGLayer();
    
    bool init();
    
    LAYER_NODE_FUNC(AboutBGLayer);
    
};

#endif
