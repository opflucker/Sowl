#pragma once
#include <functional>
#include "../Window.h"
#include "../WindowHandleCreator.h"
#include "WindowMessageProcessor.h"
#include "../../Graphics/PaintDeviceContext.h"

namespace sowl
{
	class CustomWindow : public Window, public WindowMessageProcessor
	{
	public:
		CustomWindow(HINSTANCE processHandle, LPCWSTR className);
		explicit CustomWindow(WindowHandleCreator& hwnd);

		LRESULT Process(UINT uMsg, WPARAM wParam, LPARAM lParam) override;

		virtual bool OnShow(bool show, int showStatus);
		virtual void OnPaint(const PaintDeviceContext& dc);
		virtual bool OnCommand(int notificationCode, int senderId, HWND controlHandle);
		virtual bool OnLButtonDown(int mouseKeys, int x, int y);
	};
}