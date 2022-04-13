#pragma once
#include "../WindowHandleCreator.h"
#include "../Window.h"

namespace sowl
{
	template<class TControl>
	class ControlWindowCreator : private sowl::WindowHandleCreator
	{
	public:
		ControlWindowCreator(const Window& parentWindow, LPCWSTR className, WORD id, DWORD style)
			: WindowHandleCreator(parentWindow.GetProcessHandle(), className)
		{
			WithParent(parentWindow.GetHandle());
			WithMenu((HMENU)(uintptr_t)id);
			WithStyle(style);
		}

		inline ControlWindowCreator& WithTitle(LPCWSTR title) { WindowHandleCreator::WithTitle(title); return *this; }
		inline ControlWindowCreator& AndStyle(DWORD style) { WindowHandleCreator::AndStyle(style); return *this; }
		inline ControlWindowCreator& WithRect(int x, int y, int width, int height) { WindowHandleCreator::WithRect(x, y, width, height); return *this; }
		inline ControlWindowCreator& WithParams(LPVOID lpParam) { WindowHandleCreator::WithParams(lpParam); return *this; }
		inline HWND CreateHandle() const { return WindowHandleCreator::Create(); }
		inline TControl Create() const { return TControl(WindowHandleCreator::Create()); }
	};
}