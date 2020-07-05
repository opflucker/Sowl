#pragma once
#include <windows.h>

class Window
{
public:
	Window(HWND hwnd);
	HWND GetHandle() const;
	HINSTANCE GetInstanceHandle() const;
	void Enable(bool enable);
	bool IsEnabled();
	void SetClassCursor(HCURSOR hcursor);
	void Destroy();

protected:
	void SetHandle(HWND hwnd);

private:
	HWND hwnd;
};
