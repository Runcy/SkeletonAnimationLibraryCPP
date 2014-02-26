#pragma once
#include "BytesType.h"
namespace dragonBones
{	
	class Point
	{
	public:
		Point(Number xx , Number yy)
			: x(xx)
			, y(yy)
		{

		}
		Point()
			: x(0)
			, y(0)
		{

		}
		Number x;
		Number y;
	};
};