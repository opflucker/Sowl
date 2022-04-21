#pragma once
#include "../WindowBindableByWndProc.h"

namespace sowl
{
	class DialogWindow : public WindowBindableByWndProc
	{
	public:
		DialogWindow() = default;

		LRESULT Process(UINT uMsg, WPARAM wParam, LPARAM lParam) override;
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