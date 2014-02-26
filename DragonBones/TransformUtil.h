#pragma once
#include "preDB.h"
#include "DBTransform.h"
namespace dragonBones
{
	
	class TransformUtil
	{
	public:
		static const Number PI;
		static const Number HALF_PI;
		static const Number DOUBLE_PI;
		
		static void transformPointWithParent(DBTransform &transform, DBTransform &parent);
		
		//static void transformToMatrix(DBTransform &transform, Matrix &matrix);
		
		static Number formatRadian(Number radian);
	};
};