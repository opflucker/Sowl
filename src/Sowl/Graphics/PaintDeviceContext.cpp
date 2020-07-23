#include "PaintDeviceContext.h"
#include <utility>

using namespace sowl;

PaintDeviceContext::PaintDeviceContext(HWND hwnd)
	: DeviceContext(BeginPaint(hwnd, &ps))
{
	this->hwnd = hwnd;
}

PaintDeviceContext::~PaintDeviceContext()
{
	EndPaint();
}

void PaintDeviceContext::EndPaint()
{
	if (GetHandle() != NULL)
	{
		::EndPaint(hwnd, &ps);
		hwnd = NULL;
		ps.hdc = NULL;
		SetHandle(NULL);
	}
}

void PaintDeviceContext::FillRect(HBRUSH hbr) const
{
	DeviceContext::FillRect(&ps.rcPaint, hbr);
}

void PaintDeviceContext::FillRect(int iSystemColorIndex) const
{
	DeviceContext::FillRect(&ps.rcPaint, iSystemColorIndex);
}
