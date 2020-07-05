#include "DeviceContext.h"

DeviceContext::DeviceContext(HDC hdc)
{
	this->hdc = hdc;
}

void DeviceContext::FillRect(const RECT* rect, HBRUSH hbr) const
{
	::FillRect(hdc, rect, hbr);
}

void DeviceContext::FillRect(const RECT* rect, int iSystemColorIndex) const
{
	FillRect(rect, (HBRUSH)(iSystemColorIndex + 1));
}
