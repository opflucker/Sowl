#include "StockObjects.h"

HBRUSH StockObjects::WhiteBrushHandle()
{
	return (HBRUSH)GetStockObject(WHITE_BRUSH);
}

HBRUSH StockObjects::BlackBrushHandle()
{
	return (HBRUSH)GetStockObject(BLACK_BRUSH);
}

HBRUSH StockObjects::GrayBrushHandle()
{
	return (HBRUSH)GetStockObject(GRAY_BRUSH);
}

HBRUSH StockObjects::DarkGrayBrushHandle()
{
	return (HBRUSH)GetStockObject(DKGRAY_BRUSH);
}

HBRUSH StockObjects::LightGrayBrushHandle()
{
	return (HBRUSH)GetStockObject(LTGRAY_BRUSH);
}
