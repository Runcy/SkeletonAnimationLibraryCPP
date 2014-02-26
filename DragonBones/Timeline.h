#pragma once
#include "preDB.h"
#include "Frame.h"
namespace dragonBones
{
	class Timeline
	{
	public:
		std::vector<Frame*> frameList;		
		Number duration;		
		Number scale;
		
		Timeline()
		{
			duration = 0;
			scale = 1;
		}
		virtual ~Timeline()
		{
			dispose();
		}
		
		virtual void dispose()
		{
			for(size_t i = 0 ; i < frameList.size() ; i ++)
			{
				frameList[i]->dispose();
				delete frameList[i];
			}
			frameList.clear();
		}
		
		void addFrame(Frame *frame)
		{
			frameList.push_back(frame);
		}
	};
};