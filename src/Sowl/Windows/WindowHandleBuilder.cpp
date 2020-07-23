#include "WindowHandleBuilder.h"

using namespace sowl;

WindowHandleBuilder::WindowHandleBuilder(HINSTANCE hInstance, LPCWSTR className)
{
    this->className = className;
    title = L"";
    style = WS_OVERLAPPEDWINDOW;
    x = CW_USEDEFAULT;
    y = CW_USEDEFAULT;
    width = CW_USEDEFAULT;
    height = CW_USEDEFAULT;
    hParentWindow = NULL;
    hMenu = NULL;
    this->hInstance = hInstance;
    lpParam = NULL;
}

WindowHandleBuilder::WindowHandleBuilder(const WNDCLASS& wc)
    : WindowHandleBuilder(wc.hInstance, wc.lpszClassName)
{
}

WindowHandleBuilder& WindowHandleBuilder::WithTitle(LPCWSTR title)
{
    this->title = title;
    return *this;
}

WindowHandleBuilder& WindowHandleBuilder::WithStyle(DWORD style)
{
    this->style = style;
    return *this;
}

WindowHandleBuilder& WindowHandleBuilder::WithAddStyle(DWORD style)
{
    this->style |= style;
    return *this;
}

WindowHandleBuilder& WindowHandleBuilder::WithRect(int x, int y, int width, int height)
{
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    return *this;
}

WindowHandleBuilder& WindowHandleBuilder::WithParent(HWND hParentWindow)
{
    this->hParentWindow = hParentWindow;
    return *this;
}

WindowHandleBuilder& WindowHandleBuilder::WithMenu(HMENU hMenu)
{
    this->hMenu = hMenu;
    return *this;
}

WindowHandleBuilder& WindowHandleBuilder::WithParam(LPVOID lpParam)
{
    this->lpParam = lpParam;
    return *this;
}

HWND WindowHandleBuilder::Build()
{
    return CreateWindowEx(
        0,          // Optional window styles.
        className,
        title,
        style,
        x, y, width, height,
        hParentWindow,
        hMenu,
        hInstance,  // Instance handle
        lpParam     // Additional application data
    );
}
