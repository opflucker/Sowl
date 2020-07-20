#include "WindowClassBuilder.h"

WindowClassBuilder::WindowClassBuilder(HINSTANCE hInstance, LPCWSTR className, WNDPROC wndProc)
{
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hbrBackground = NULL;
    wc.hCursor = NULL;
    wc.hIcon = NULL;
    wc.lpszClassName = className;
    wc.lpszMenuName = NULL;
    wc.style = 0;
    wc.hInstance = hInstance;
    wc.lpfnWndProc = wndProc;
}

WindowClassBuilder& WindowClassBuilder::WithBackgroundBrush(HBRUSH handle)
{
    wc.hbrBackground = handle;
    return *this;
}

WindowClassBuilder& WindowClassBuilder::WithCursor(HCURSOR handle)
{
    wc.hCursor = handle;
    return *this;
}

WindowClassBuilder& WindowClassBuilder::WithIcon(HICON handle)
{
    wc.hCursor = handle;
    return *this;
}

WindowClassBuilder& WindowClassBuilder::WithMenu(LPCWSTR name)
{
    wc.lpszMenuName = name;
    return *this;
}

WindowClassBuilder& WindowClassBuilder::WithStyle(UINT style)
{
    wc.style = style;
    return *this;
}

WNDCLASS WindowClassBuilder::Register() const
{
    WNDCLASS wcFound;
    if (GetClassInfo(wc.hInstance, wc.lpszClassName, &wcFound) == FALSE)
        RegisterClass(&wc);

    return wc;
}

WindowHandleBuilder WindowClassBuilder::RegisterAndCreateHandleBuilder() const
{
    Register();
    return WindowHandleBuilder(wc.hInstance, wc.lpszClassName);
}
