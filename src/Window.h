#pragma once
#include <windows.h>
#include "MessageTarget.h"
#include "WindowClass.h"
#include "PaintDeviceContext.h"

class Window : MessageTarget
{
public:
	Window(WindowClass & wc, LPCWSTR title);
	bool IsCreated() const;
	bool Show(int nCmdShow) const;

	virtual LRESULT Process(UINT uMsg, WPARAM wParam, LPARAM lParam) override;
	virtual void OnPaint(const PaintDeviceContext& dc);

private:
	HWND hwnd;
};
