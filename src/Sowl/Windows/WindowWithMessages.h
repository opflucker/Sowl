#pragma once

#include "Window.h"
#include <functional>

namespace sowl
{
    class WindowWithMessages : public Window
    {
    public:
        virtual ~WindowWithMessages() = default;

        virtual LRESULT Process(UINT uMsg, WPARAM wParam, LPARAM lParam) = 0;

        static LRESULT BindAndProcess(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam,
            UINT bindingMessage,
            const std::function<WindowWithMessages* (LPARAM)>& extractWindowPointer);
    };
}
