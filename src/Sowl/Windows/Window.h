#pragma once
#include <windows.h>

namespace sowl
{
	class Window
	{
	public:
		Window(HWND hwnd);
		Window(const Window& other) = delete;
		Window(Window&& other) noexcept;
		~Window();

		Window& operator=(const Window& other) = delete;
		Window& operator=(Window&& other) noexcept;

		void Destroy();
		HWND GetHandle() const;
		HINSTANCE GetProcessHandle() const;
		HWND GetDialogItem(int id) const;
		bool Show(int nCmdShow) const;
		void Enable(bool enable);
		bool IsEnabled();
		void SetClassCursor(HCURSOR hcursor);
		void SetText(LPCWSTR title);
		bool InvalidateRect(bool erase);
		bool InvalidateRect(const RECT& rect, bool erase);
		RECT GetClientRect();

	protected:
		HWND SetHandle(HWND hwnd);

	private:
		HWND hwnd;
	};
}