#include "SolidBrush.h"

using namespace sowl;

SolidBrush::SolidBrush(COLORREF color)
	: Brush(CreateSolidBrush(color))
{
}

SolidBrush::~SolidBrush()
{
	DeleteObject(GetHandle());
}
