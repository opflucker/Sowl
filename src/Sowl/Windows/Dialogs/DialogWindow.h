#pragma once
#include "../Window.h"

namespace sowl
{
	class DialogWindow : public Window
	{
	public:
		explicit DialogWindow(int resourceId);
		DialogWindow(const Window& parentWindow, int resourceId);
		virtual ~DialogWindow() = default;

		virtual bool Process(UINT uMsg, WPARAM wParam, LPARAM lParam);
		virtual bool OnInitDialog(HWND hFocusWindow);
		virtual bool OnCommand(int notificationCode, int senderId, HWND controlHandle);
		virtual bool OnClose() = 0;

	protected:
		int CreateAndShowModal();
		void CreateModeless();

	private:
		static INT_PTR CALLBACK DialogProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
		HINSTANCE processHandle = nullptr;
		HWND parentHandle = nullptr;
		LPCWSTR templateName;
	};
}