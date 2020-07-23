#pragma once
#include <windows.h>

namespace sowl
{
	class StockBrushesHandles
	{
	public:
		static HBRUSH White();
		static HBRUSH Black();
		static HBRUSH Gray();
		static HBRUSH DarkGray();
		static HBRUSH LightGray();
	};
}