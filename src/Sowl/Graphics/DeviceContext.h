#pragma once
#include <windows.h>

namespace sowl
{
	class DeviceContext
	{
	public:
		DeviceContext(HDC hdc);
		DeviceContext(const DeviceContext& other) = delete;
		DeviceContext& operator=(const DeviceContext& other) = delete;

		HDC GetHandle() const;
		void FillRect(const RECT* rect, HBRUSH hbr) const;
		void FillRect(const RECT* rect, int iSystemColorIndex) const;
		void Ellipse(const RECT& rect) const;
		int DrawText(LPCWSTR text, const RECT& rect, unsigned int format) const;
		int SetBackgroundMode(int mode) const;

	protected:
		HDC SetHandle(HDC hdc);

	private:
		HDC hdc;
	};
}