#pragma once
#include "support/tinyxml2/tinyxml2.h"
#include "preDB.h"
#include "SkeletonData.h"
#include "TransformFrame.h"
#include "TextureAtlasData.h"
namespace dragonBones
{
	/**
	 * The XMLDataParser class parses xml data from dragonBones generated maps.
	 */
	class XMLDataParser
	{
	public:
		
		TextureAtlasData* parseTextureAtlasData(const tinyxml2::XMLElement *rootElement, Number scale = 1);
		
		/**
		 * Parse the SkeletonData.
		 * @param	xml The SkeletonData xml to parse.
		 * @return A SkeletonData instance.
		 */
		SkeletonData *parseSkeletonData(const tinyxml2::XMLElement *rootElement);
	private:
		
		ArmatureData *parseArmatureData(const tinyxml2::XMLElement *armatureXML, SkeletonData *data, uint frameRate);
		
		BoneData *parseBoneData(const tinyxml2::XMLElement *boneXML);
		
		SkinData *parseSkinData(const tinyxml2::XMLElement *skinXML, SkeletonData *data);
		
		SlotData *parseSlotData(const tinyxml2::XMLElement *slotXML, SkeletonData *data);
		
		DisplayData *parseDisplayData(const tinyxml2::XMLElement *displayXML, SkeletonData *data);
		
		/** @private */
		static AnimationData *parseAnimationData(const tinyxml2::XMLElement *animationXML, ArmatureData *armatureData, uint frameRate);
		
		typedef Frame* (*FrameParser)(const tinyxml2::XMLElement *,uint);


		static void parseTimeline(const tinyxml2::XMLElement *timelineXML, Timeline *timeline, FrameParser frameParser, uint frameRate);
		
		static TransformTimeline *parseTransformTimeline(const tinyxml2::XMLElement *timelineXML, Number duration, uint frameRate);
		
		static void parseFrame(const tinyxml2::XMLElement *frameXML, Frame *frame, uint frameRate);
		
		static Frame *parseMainFrame(const tinyxml2::XMLElement *frameXML, uint frameRate);
		
		static Frame *parseTransformFrame(const tinyxml2::XMLElement *frameXML, uint frameRate);
		
		static void parseTransform(const tinyxml2::XMLElement *transformXML, DBTransform *transform, Point *pivot = 0);
	};
};