#pragma once
#include "DeviceContext.h"

namespace sowl
{
	class PaintDeviceContext : public DeviceContext
	{
	public:
		PaintDeviceContext(HWND hwnd);
		PaintDeviceContext(const PaintDeviceContext& other) = delete;
		PaintDeviceContext& operator=(const PaintDeviceContext& other) = delete;
		~PaintDeviceContext();

		void EndPaint();
		void FillRect(HBRUSH hbr) const;
		void FillRect(int iSystemColorIndex) const;

	private:
		HWND hwnd;
		PAINTSTRUCT ps;
	};
}