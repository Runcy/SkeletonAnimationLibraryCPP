//
//  Scene_SwitchClothes.h
//  DragonBonesDemo
//
//  Created by zhu peijun on 2014/03/11.
//
//

#ifndef __DragonBonesDemo__Scene_SwitchClothes__
#define __DragonBonesDemo__Scene_SwitchClothes__

#include "cocos2d.h"

#include "Cocos2dxFactory.h"
#include "XMLDataParser.h"
#include "Cocos2dxTextureAtlas.h"

USING_NS_CC;

class Scene_SwitchClothes : public CCLayer
{
public:
    
    CREATE_FUNC(Scene_SwitchClothes);
    
    virtual bool init();
    void update(float dt);
    
    static CCScene* scene();
    
    virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
    

private:
    dragonBones::Armature * armature;
    dragonBones::Armature * clothesArmature;
    
    int clothesIndex = 2;
};



#endif /* defined(__DragonBonesDemo__Scene_SwitchClothes__) */
