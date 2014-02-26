#pragma once
#include "preDB.h"
namespace dragonBones
{
	/** @private */
	class Frame
	{
	public:
		Number position;
		Number duration;
		
		String action;
		String event;
		String sound;
		
		Frame()
		{
			position = 0;
			duration = 0;
		}
		
		virtual void dispose()
		{
		}
	};
};