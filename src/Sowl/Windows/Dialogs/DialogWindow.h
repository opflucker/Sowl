#pragma once
#include "../Window.h"

namespace sowl
{
	class DialogWindow : public Window
	{
	public:
		DialogWindow() = default;
		virtual ~DialogWindow() = default;

		virtual bool Process(UINT uMsg, WPARAM wParam, LPARAM lParam);
		virtual bool OnInitDialog(HWND hFocusWindow);
		virtual bool OnCommand(int notificationCode, int senderId, HWND controlHandle);
		virtual bool OnClose() = 0;

	protected:
		static INT_PTR CALLBACK DialogProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	private:
		HINSTANCE processHandle = nullptr;
		HWND parentHandle = nullptr;
		LPCWSTR templateName;
	};
}