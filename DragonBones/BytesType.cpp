#include "BytesType.h"

namespace dragonBones
{
	const String BytesType::SWF = "swf";
	const String BytesType::PNG = "png";
	const String BytesType::JPG = "jpg";
	const String BytesType::ATF = "atf";
	const String BytesType::ZIP = "zip";
	const String BytesType::BLANK;
	Number round(Number x)
	{
		return ((int)(x + 0.5));
	}

	bool isNaN( Number num )
	{
		return !(num > 0 || num < 0 || num == 0);
	}

};