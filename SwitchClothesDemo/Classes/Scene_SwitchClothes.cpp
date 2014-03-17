//
//  Scene_SwitchClothes.cpp
//  DragonBonesDemo
//
//  Created by zhu peijun on 2014/03/11.
//
//

#include "Scene_SwitchClothes.h"


CCScene* Scene_SwitchClothes::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    Scene_SwitchClothes *layer = Scene_SwitchClothes::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

bool Scene_SwitchClothes::init()
{
    if (!CCLayer::init()) {
        return false;
    }
    
    CCSize winSize = CCDirector::sharedDirector() ->getWinSize();
    
    dragonBones::XMLDataParser xmlParser;
    dragonBones::XMLDocument skeletonXml;
    dragonBones::XMLDocument textureXml;
    dragonBones::Cocos2dxFactory factory;
    
    
    const char * fullPathOfSkeletonXml = CCFileUtils::sharedFileUtils() \
        ->fullPathForFilename("skeleton.xml").c_str();
    const char * fullPathOfTextureXml = CCFileUtils::sharedFileUtils() \
        ->fullPathForFilename("texture.xml").c_str();
    
    
    //load skeleton data
    skeletonXml.LoadFile(fullPathOfSkeletonXml);
    factory.addSkeletonData(xmlParser.parseSkeletonData(skeletonXml.RootElement()));
    
    //load texture data
    textureXml.LoadFile(fullPathOfTextureXml);
    factory.addTextureAtlas(new dragonBones::Cocos2dxTextureAtlas
                            (xmlParser.parseTextureAtlasData(textureXml.RootElement())));
                            
                        
    //build armature
    armature = factory.buildArmature("Dragon", "", "Dragon");
    clothesArmature = factory.buildArmature("clothTextureTemp", "", "Dragon");
    
    
    //get he skeleton node
    CCNode * skeletonNode = static_cast<dragonBones::CocosNode*> \
                            (armature->getDisplay())->node;
    skeletonNode->setPosition(ccp(winSize.width / 2, winSize.height / 2));
    this->addChild(skeletonNode);
    
    armature->getAnimation()->gotoAndPlay("walk");
    
    //enable update
    this->scheduleUpdate();
    
    //enable touch
    this->setTouchEnabled(true);
    this->setTouchMode(kCCTouchesOneByOne);
    
    
    return true;
}

void Scene_SwitchClothes::update(float dt)
{
    CC_UNUSED_PARAM(dt);
    if (armature) {
        armature->advanceTime(dt);
    }
}


bool Scene_SwitchClothes::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
    
    return true;
}

void Scene_SwitchClothes::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent)
{
    
}

void Scene_SwitchClothes::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
{
    if(clothesIndex < 1 || clothesIndex > 4) clothesIndex = 1;
    
    const char * clothes = cocos2d::CCString::createWithFormat("clothes%d", clothesIndex)->getCString();
    
    dragonBones::Bone * bone = armature->getBone("clothes");
    dragonBones::Object * display = clothesArmature->getBone(clothes)->getDisplay();
    bone->setDisplay(display);
    
    clothesIndex++;
}

