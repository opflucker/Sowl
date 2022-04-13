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
		template<class TWindow> void BindToHandle(HWND handle);
		template<class TWindow> static TWindow* BindedWindow(HWND handle);
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

	template<class TWindow> void Window::BindToHandle(HWND handle)
	{
		if (hwnd != nullptr)
			RaiseException(1, 0, 0, nullptr);
		if (handle == nullptr)
			RaiseException(2, 0, 0, nullptr);

		hwnd = handle;
		SetWindowLongPtr(hwnd, GWLP_USERDATA, (LONG_PTR)static_cast<TWindow*>(this));
	}

	template<class TWindow> static TWindow* Window::BindedWindow(HWND handle)
	{
		LONG_PTR ptr = GetWindowLongPtr(handle, GWLP_USERDATA);
		return reinterpret_cast<TWindow*>(ptr);
	}
}