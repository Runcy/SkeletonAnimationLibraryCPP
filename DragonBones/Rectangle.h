#pragma once
#include "BytesType.h"
namespace dragonBones
{	
	class Rectangle
	{
	public:
		Rectangle()
			: x(0)
			, y(0)
			, width(0)
			, height(0)
		{

		}
		int x;
		int y;
		int width;
		int height;
	};
};