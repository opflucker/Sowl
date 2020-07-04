#include "SolidBrush.h"

SolidBrush::SolidBrush(COLORREF color)
	: Brush(CreateSolidBrush(color))
{
}

SolidBrush::~SolidBrush()
{
	DeleteObject(GetHandle());
}
