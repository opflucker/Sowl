#pragma once

#include "Window.h"
#include <functional>

namespace sowl
{
    class WindowBindableByWndProc : public Window
    {
    public:
        virtual ~WindowBindableByWndProc() = default;

        virtual LRESULT Process(UINT uMsg, WPARAM wParam, LPARAM lParam) = 0;

        static LRESULT WindowProcedure(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam,
            UINT messageWhereBind,
            const std::function<WindowBindableByWndProc* (LPARAM)>& extractWindowPointer);
    };
}
