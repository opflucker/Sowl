#pragma once
#include "Window.h"
#include "WindowClassBuilder.h"
#include "WindowHandleBuilder.h"
#include "PaintDeviceContext.h"

class CustomWindow : public Window
{
public:
	static WindowClassBuilder CreateClassBuilder(HINSTANCE hInstance, LPCWSTR className);

	CustomWindow(WindowHandleBuilder builder);

	virtual LRESULT Process(UINT uMsg, WPARAM wParam, LPARAM lParam);

	virtual void OnPaint(const PaintDeviceContext& dc);
	virtual bool OnCommand(int notificationCode, int senderId, HWND controlHandle);

private:
	static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
};
