#pragma once
#include "preDB.h"
#include "DBTransform.h"
#include "TransformUtil.h"
namespace dragonBones
{
	class ArmatureData;
	class TransformTimeline;
	class AnimationData;
	/** @private */
	class DBDataUtil
	{
	private:
		static DBTransform _helpTransform1;
		static DBTransform _helpTransform2;
	public:
		
		static void transformArmatureData(ArmatureData *armatureData);
		
		static void transformArmatureDataAnimations(ArmatureData *armatureData);
		
		static void transformAnimationData(AnimationData *animationData, ArmatureData *armatureData);
		
		static void getTimelineTransform(TransformTimeline *timeline, Number position, DBTransform &retult);
		
		static void addHideTimeline(AnimationData *animationData, ArmatureData *armatureData);
	};
};