#pragma once
#include "Window.h"
#include "CustomMessageProcessor.h"
#include "WindowHandleBuilder.h"
#include "WindowClassBuilder.h"
#include "PaintDeviceContext.h"

class CustomWindow : public Window, public CustomMessageProcessor
{
public:
	static WindowClassBuilder CreateClassBuilder(HINSTANCE hInstance, LPCWSTR className);

	CustomWindow(WindowHandleBuilder builder);

	bool Show(int nCmdShow) const;
	virtual LRESULT Process(UINT uMsg, WPARAM wParam, LPARAM lParam) override;

	virtual void OnPaint(const PaintDeviceContext& dc);
	virtual bool OnCommand(int notificationCode, int senderId, HWND controlHandle);
};
