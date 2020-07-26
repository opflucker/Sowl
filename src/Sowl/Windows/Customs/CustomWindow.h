#pragma once
#include <functional>
#include "../Window.h"
#include "../WindowClassBuilder.h"
#include "../WindowHandleBuilder.h"
#include "../../Graphics/PaintDeviceContext.h"

namespace sowl
{
	class CustomWindow : public Window
	{
	public:
		static WindowClassBuilder CreateClassBuilder(HINSTANCE processHandle, LPCWSTR className);
		static WindowHandleBuilder CreateHandleBuilder(HINSTANCE processHandle, LPCWSTR className);

		CustomWindow(WindowHandleBuilder& builder);
		CustomWindow(HINSTANCE processHandle, LPCWSTR className);

		virtual LRESULT Process(UINT uMsg, WPARAM wParam, LPARAM lParam);

		virtual bool OnShow(bool show, int showStatus);
		virtual void OnPaint(const PaintDeviceContext& dc);
		virtual bool OnCommand(int notificationCode, int senderId, HWND controlHandle);
		virtual bool OnLButtonDown(int mouseKeys, int x, int y);

	private:
		static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	};
}