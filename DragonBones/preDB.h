#ifndef __PRE_DB_H__
#define __PRE_DB_H__

#include "BytesType.h"
#include "Point.h"
#include "ColorTransform.h"
#include "Rectangle.h"

#define DB_SAFE_DELETE(p)            do { if(p) { delete (p); (p) = 0; } } while(0)

#endif // __PRE_DB_H__
