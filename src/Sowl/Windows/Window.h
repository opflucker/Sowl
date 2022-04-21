#pragma once
#include <Windows.h>
#include <type_traits>

namespace sowl
{
	/// @brief Encapsulates a <a href="https://docs.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-createwindowa#returns">window handle</a>.
	class Window
	{
	public:
		// create
		Window();
		explicit Window(HWND hwnd);
		Window(const Window& other) = delete; // avoid copy constructor
		Window(Window&& other) noexcept; // control move constructor

		// destroy
		~Window();
		void Destroy();

		// assignment operator overloads
		Window& operator=(const Window& other) = delete; // avoid copy assignment
		Window& operator=(Window&& other) noexcept; // control move assignment

	protected:
		void SetHandle(HWND handle);
		void UnsetHandle();

	public:
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