#include "WindowClassBuilder.h"

WindowClassBuilder::WindowClassBuilder(HINSTANCE hInstance, LPCWSTR className)
{
    this->hInstance = hInstance;
    this->className = className;
    hbrush = NULL;
    hcursor = NULL;
    hicon = NULL;
    menuName = NULL;
    style = 0;
}

WindowClassBuilder& WindowClassBuilder::WithBackgroundBrush(HBRUSH handle)
{
    hbrush = handle;
    return *this;
}

WindowClassBuilder& WindowClassBuilder::WithCursor(HCURSOR handle)
{
    hcursor = handle;
    return *this;
}

WindowClassBuilder& WindowClassBuilder::WithIcon(HICON handle)
{
    hicon = handle;
    return *this;
}

WindowClassBuilder& WindowClassBuilder::WithMenu(LPCWSTR name)
{
    menuName = name;
    return *this;
}

WindowClassBuilder& WindowClassBuilder::WithStyle(UINT style)
{
    this->style = style;
    return *this;
}

WindowClass WindowClassBuilder::Build() const
{
    return WindowClass(hInstance, className, hbrush, hcursor, hicon, menuName, style);
}
