#pragma once
#include <Windows.h>

namespace sowl
{
	/// @brief Encapsulates a window handle (HWND).
	class Window
	{
	public:
		// create
		Window();
		explicit Window(HWND hwnd);
		HWND SetHandle(HWND hwnd);

		// destroy
		~Window();
		void Destroy();

		// avoid copy constructor and copy assigment
		Window(const Window& other) = delete;
		Window& operator=(const Window& other) = delete;

		// move constructor and move assignment
		Window(Window&& other) noexcept;
		Window& operator=(Window&& other) noexcept;

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

	private:
		HWND hwnd;
	};
}