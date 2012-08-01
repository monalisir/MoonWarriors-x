//
//  Constants.h
//  MoonWarriors-x
//
//  Created by Tom on 12-7-30.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#ifndef MoonWarriors_x_Constants_h
#define MoonWarriors_x_Constants_h

// 场景ID
typedef enum 
{
    // 
    SCENE_ID_NONE       = -1,
    // 主菜单场景
    SCENE_ID_MAINMENU   = 0,
    // 游戏场景
    SCENE_ID_GAMEPLAY   = 1,
    // 游戏设置场景
    SCENE_ID_SETTING    = 2,
    // 关于场景
    SCENE_ID_ABOUT      = 3
} SCENE_ID;

// 角色状态
typedef enum
{
    //
    CHARACTER_STATE_NONE        = -1,
    // 初始状态
    CHARACTER_STATE_SPAWNING    = 0,
    // 射击状态
    CHARACTER_STATE_SHOOTING    = 1,
    // 被打击状态
    CHARACTER_STATE_HURT        = 2,
    // 死亡状态
    CHARACTER_STATE_DYING       = 3
} CHARACTER_STATE;

// 子弹状态
typedef enum
{
    //
    BULLET_STATE_NONE       = -1,
    // 初始状态
    BULLET_STATE_SPAWNING   = 0,
    // 正常状态
    BULLET_STATE_NORMAL     = 1,
    // 攻击状态
    BULLET_STATE_ATTACKING  = 2,
    // 结束状态
    BULLET_STATE_OVER       = 3
} BULLET_STATE;

// 子弹标签
typedef enum
{
    // 
    BULLET_TAG_NONE     = -1,
    // 玩家子弹
    BULLET_TAG_PLAYER   = 0,
    // 敌人子弹
    BULLET_TAG_ENEMY    = 1
} BULLET_TAG;

#endif
