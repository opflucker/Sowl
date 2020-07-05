#pragma once
#include "Window.h"
#include "WindowClass.h"
#include "WindowHandleBuilder.h"
#include "MessageTarget.h"
#include "PaintDeviceContext.h"

class CustomWindow : public Window, public MessageTarget
{
public:
	CustomWindow(WindowHandleBuilder builder);

	bool Show(int nCmdShow) const;
	virtual LRESULT Process(UINT uMsg, WPARAM wParam, LPARAM lParam) override;

	virtual void OnPaint(const PaintDeviceContext& dc);
	virtual bool OnCommand(int notificationCode, int senderId, HWND controlHandle);
};
