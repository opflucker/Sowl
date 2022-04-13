#pragma once
#include "../WindowHandleCreator.h"
#include "../Window.h"

namespace sowl
{
	template<class TControl>
	class ControlCreator : private sowl::WindowHandleCreator
	{
	public:
		ControlCreator(const Window& parentWindow, LPCWSTR className, WORD id, DWORD style)
			: WindowHandleCreator(parentWindow.GetProcessHandle(), className)
		{
			WithParent(parentWindow.GetHandle());
			WithMenu((HMENU)(uintptr_t)id);
			WithStyle(style);
		}

		inline ControlCreator& WithTitle(LPCWSTR title) { WindowHandleCreator::WithTitle(title); return *this; }
		inline ControlCreator& AndStyle(DWORD style) { WindowHandleCreator::AndStyle(style); return *this; }
		inline ControlCreator& WithRect(int x, int y, int width, int height) { WindowHandleCreator::WithRect(x, y, width, height); return *this; }
		inline ControlCreator& WithParams(LPVOID lpParam) { WindowHandleCreator::WithParams(lpParam); return *this; }
		inline HWND CreateHandle() const { return WindowHandleCreator::Create(); }
		inline TControl Create() const { return TControl(WindowHandleCreator::Create()); }
	};
}