#pragma once

#include "BytesType.h"
#include "Point.h"
#include "ColorTransform.h"
#include "Rectangle.h"

#define DB_SAFE_DELETE(p)            do { if(p) { delete (p); (p) = 0; } } while(0)
