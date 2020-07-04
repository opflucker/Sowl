#pragma once

#include "DeviceContext.h"

class PaintDeviceContext : public DeviceContext
{
public:
	PaintDeviceContext(HWND hwnd);
	~PaintDeviceContext();
	void FillRect(HBRUSH hbr) const;
	void FillRect(int iSystemColorIndex) const;

private:
	HWND hwnd;
	PAINTSTRUCT ps;
};

