#pragma once
#include <windows.h>

class DeviceContext
{
public:
	DeviceContext(HDC hdc);
	DeviceContext(const DeviceContext& other) = delete;
	DeviceContext& operator=(const DeviceContext& other) = delete;

	HDC GetHandle() const;
	void FillRect(const RECT* rect, HBRUSH hbr) const;
	void FillRect(const RECT* rect, int iSystemColorIndex) const;

protected:
	HDC SetHandle(HDC hdc);

private:
	HDC hdc;
};
