#pragma once
#include <functional>
#include "../Window.h"
#include "../WindowHandleCreator.h"
#include "../../Graphics/PaintDeviceContext.h"

namespace sowl
{
	class CustomWindow : public Window
	{
	public:
		CustomWindow(HINSTANCE processHandle, LPCWSTR className);
		explicit CustomWindow(WindowHandleCreator& hwnd);

		virtual LRESULT Process(UINT uMsg, WPARAM wParam, LPARAM lParam);

		virtual bool OnShow(bool show, int showStatus);
		virtual void OnPaint(const PaintDeviceContext& dc);
		virtual bool OnCommand(int notificationCode, int senderId, HWND controlHandle);
		virtual bool OnLButtonDown(int mouseKeys, int x, int y);
	};
}