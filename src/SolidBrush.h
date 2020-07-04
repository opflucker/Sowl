#pragma once
#include "Brush.h"

class SolidBrush : public Brush
{
public:
	SolidBrush(COLORREF color);
	~SolidBrush();
};

