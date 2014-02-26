#pragma once
#include "BytesType.h"
namespace dragonBones
{	
	class TextureAtlasData
	{
	public:
		TextureAtlasData()
		{

		}
		typedef std::map<String , Rectangle> Rects;
		String imagePath;
		String name;
		Rects rects;

		void addRect(const String &name , const Rectangle &rect)
		{
			rects[name] = rect;
		}
	};
};