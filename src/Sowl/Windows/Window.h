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
		Window(const Window& other) = delete; // avoid copy constructor
		Window(Window&& other) = delete; // avoid move constructor

		// destroy
		~Window();
		void Destroy();

		// bind		
		Window& operator=(const Window& other) = delete; // avoid copy assigment
		Window& operator=(Window&& other) = delete; // avoid move assignment
		HWND SetHandle(HWND newHandle);

		// other methods
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