#pragma once
#include <Windows.h>
#include <type_traits>

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
		template<class TWindow> static TWindow* BindToHandle(HWND handle, LPVOID pAdditionalCreationData);
		template<class TWindow> static TWindow* BindedToHandle(HWND handle);
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

	/// @brief Bind a TWindow object with a window-handle.
	/// This method must be called inside a WNDPROC function when processing a creation message.
	/// This message must hold (as additonal data) a pointer to a Window-derived object, so this function can
	/// bind both, it is, Window-handle and Window-derived object pointing each other.
	/// @tparam TWindow A type derived from Window.
	/// @param handle The window-handle against a Window-derived object must be binded.
	/// @param pAdditionalCreationData The additional data received when processing a creation message.
	/// @return If parameters are valid and the Window-derived object is not already binded then it returns the binded Window-derived object pointer.
	/// If parameters are invalid, it returns nullptr. If Window-derived object is already binded, it raises an exception.
	template<class TWindow> static TWindow* Window::BindToHandle(HWND handle, LPVOID pAdditionalCreationData)
	{
		static_assert(std::is_base_of<Window, TWindow>::value, "Type parameter of this method must derive from Window class");

		if (handle == nullptr || pAdditionalCreationData == nullptr)
			return nullptr;

		auto* pWindow = reinterpret_cast<TWindow*>(pAdditionalCreationData);

		if (pWindow->hwnd != nullptr) // already binded
			RaiseException(1, 0, 0, nullptr);

		pWindow->hwnd = handle;
		SetWindowLongPtr(handle, GWLP_USERDATA, (LONG_PTR)pWindow);

		return pWindow;
	}

	/// @brief Return a pointer to the object binded with a handle.
	/// This method must be called inside a WNDPROC function when processing a message other than the creation one.
	/// @return If the window-handle was previously binded (with a call to Window::BindToHandle) then it returns the binded Window-derived object pointer,
	/// otherwise, returns nullptr.
	template<class TWindow> static TWindow* Window::BindedToHandle(HWND handle)
	{
		static_assert(std::is_base_of<Window, TWindow>::value, "Type parameter of this method must derive from Window class");

		LONG_PTR ptr = GetWindowLongPtr(handle, GWLP_USERDATA);
		return reinterpret_cast<TWindow*>(ptr);
	}
}