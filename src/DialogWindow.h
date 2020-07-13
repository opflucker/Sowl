#pragma once
#include "Window.h"

class DialogWindow : public Window
{
public:
	DialogWindow(int resourceId);
	DialogWindow(const Window& parentWindow, int resourceId);

	virtual bool Process(UINT uMsg, WPARAM wParam, LPARAM lParam);
	virtual bool OnInitDialog(HWND hFocusWindow);
	virtual bool OnCommand(int notificationCode, int senderId, HWND controlHandle);
	virtual bool OnClose() = 0;

protected:
	void SetParent(const Window& parentWindow);
	int CreateAndShowModal();
	void CreateModeless();

private:
	static BOOL CALLBACK DialogProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	HINSTANCE processHandle;
	LPCWSTR templateName;
	HWND parentHandle;
};
