#pragma once
#include <windows.h>

class DeviceContext
{
public:
	DeviceContext(HDC hdc);
	void FillRect(const RECT* rect, HBRUSH hbr) const;
	void FillRect(const RECT* rect, int iSystemColorIndex) const;

private:
	HDC hdc;
};

