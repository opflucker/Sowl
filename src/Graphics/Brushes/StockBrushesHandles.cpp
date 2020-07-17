#include "StockBrushesHandles.h"

HBRUSH StockBrushesHandles::White()
{
	return (HBRUSH)GetStockObject(WHITE_BRUSH);
}

HBRUSH StockBrushesHandles::Black()
{
	return (HBRUSH)GetStockObject(BLACK_BRUSH);
}

HBRUSH StockBrushesHandles::Gray()
{
	return (HBRUSH)GetStockObject(GRAY_BRUSH);
}

HBRUSH StockBrushesHandles::DarkGray()
{
	return (HBRUSH)GetStockObject(DKGRAY_BRUSH);
}

HBRUSH StockBrushesHandles::LightGray()
{
	return (HBRUSH)GetStockObject(LTGRAY_BRUSH);
}
