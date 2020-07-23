#pragma once
#include "Brush.h"

namespace sowl
{
	class SolidBrush : public Brush
	{
	public:
		SolidBrush(COLORREF color);
		~SolidBrush();
	};
}