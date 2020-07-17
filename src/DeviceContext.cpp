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

void DeviceContext::Ellipse(const RECT& rect) const
{
	::Ellipse(hdc, rect.left, rect.top, rect.right, rect.bottom);
}

int DeviceContext::DrawText(LPCWSTR text, const RECT& rect, unsigned int format) const
{
	return ::DrawText(hdc, text, lstrlenW(text), (LPRECT)&rect, format);
}

int DeviceContext::SetBackgroundMode(int mode) const
{
	return ::SetBkMode(hdc, mode);
}
