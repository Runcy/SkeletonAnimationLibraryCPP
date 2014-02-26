#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "Cocos2dxFactory.h"

class HelloWorld : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

	void createSkeletonBody();

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    
    // a selector callback
    void menuCloseCallback(CCObject* pSender);

	virtual void update(float dt);;

    // implement the "static node()" method manually
    CREATE_FUNC(HelloWorld);

protected:
	// 保存人物实例
	dragonBones::Armature *mArm;
};

#endif // __HELLOWORLD_SCENE_H__
