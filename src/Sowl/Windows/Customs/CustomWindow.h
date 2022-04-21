#pragma once

#include "WindowClassRegisterer.h"
#include "../WindowWithMessages.h"
#include "../WindowHandleCreator.h"
#include "../../Graphics/PaintDeviceContext.h"
#include <functional>

namespace sowl
{
	/// @brief A Window with its own <a href="https://docs.microsoft.com/en-us/windows/win32/winmsg/window-procedures">window procedure</a> and <a href="https://docs.microsoft.com/en-us/windows/win32/winmsg/about-window-classes">window class</a>.
	class CustomWindow : public WindowWithMessages
	{
	public:
		CustomWindow(HINSTANCE processHandle, LPCWSTR className);
		explicit CustomWindow(const WindowHandleCreator& handleCreator);
		explicit CustomWindow(const WindowClassRegisterer& classRegisterer);
		CustomWindow(const WindowClassRegisterer& classRegisterer, WindowHandleCreator handleCreator);

		LRESULT Process(UINT uMsg, WPARAM wParam, LPARAM lParam) override;

		virtual bool OnShow(bool show, int showStatus);
		virtual void OnPaint(const PaintDeviceContext& dc);
		virtual bool OnCommand(int notificationCode, int senderId, HWND controlHandle);
		virtual bool OnLButtonDown(int mouseKeys, int x, int y);

		static WindowClassRegisterer ClassRegisterer(HINSTANCE processHandle, LPCWSTR className);
		static LRESULT CALLBACK BindAndProcess(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	};
}