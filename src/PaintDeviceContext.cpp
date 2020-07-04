#include "PaintDeviceContext.h"

PaintDeviceContext::PaintDeviceContext(HWND hwnd)
	: DeviceContext(BeginPaint(hwnd, &ps))
{
	this->hwnd = hwnd;
}

PaintDeviceContext::~PaintDeviceContext()
{
	EndPaint(hwnd, &ps);
}

void PaintDeviceContext::FillRect(HBRUSH hbr) const
{
	DeviceContext::FillRect(&ps.rcPaint, hbr);
}

void PaintDeviceContext::FillRect(int iSystemColorIndex) const
{
	DeviceContext::FillRect(&ps.rcPaint, iSystemColorIndex);
}
