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
		Window(Window&& other) noexcept; // control move constructor

		// destroy
		~Window();
		void Destroy();

		// assignment operator overloads
		Window& operator=(const Window& other) = delete; // avoid copy assignment
		Window& operator=(Window&& other) noexcept; // control move assignment

	protected:
		// binding/unbinding Window object to HWND in WindowProcedure
		void BindToHandle(HWND newHandle, LONG_PTR lpRealWindowType);
		void UnbindHandle();

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