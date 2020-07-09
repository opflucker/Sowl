#pragma once
#include "Window.h"

class DialogWindow : public Window
{
public:
	DialogWindow(const Window& parentWindow, int resourceId);
	virtual BOOL Process(UINT uMsg, WPARAM wParam, LPARAM lParam);

	virtual BOOL OnInitDialog(HWND hFocusWindow);
	virtual BOOL OnCommand(int notificationCode, int senderId, HWND controlHandle);
	virtual BOOL OnClose() = 0;

protected:
	int CreateAndShowModal();
	HWND CreateAndShowModeless();

private:
	static BOOL CALLBACK DialogProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	HINSTANCE hInstance;
	LPCWSTR templateName;
	HWND hParentWindow;
};
