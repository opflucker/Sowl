#include "DeviceContext.h"

DeviceContext::DeviceContext(HDC hdc)
{
	this->hdc = hdc;
}

HDC DeviceContext::GetHandle() const
{
	return hdc;
}

HDC DeviceContext::SetHandle(HDC hdc)
{
	HDC oldHandle = this->hdc;
	this->hdc = hdc;
	return oldHandle;
}

void DeviceContext::FillRect(const RECT* rect, HBRUSH hbr) const
{
	::FillRect(hdc, rect, hbr);
}

void DeviceContext::FillRect(const RECT* rect, int iSystemColorIndex) const
{
	FillRect(rect, (HBRUSH)(iSystemColorIndex + 1));
}
