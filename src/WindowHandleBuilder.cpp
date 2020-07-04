#include "WindowHandleBuilder.h"

WindowHandleBuilder::WindowHandleBuilder(HINSTANCE hInstance, LPCWSTR className)
{
	this->hInstance = hInstance;
	this->className = className;
    lpParam = NULL;
    title = L"";
}

WindowHandleBuilder& WindowHandleBuilder::WithParam(LPVOID lpParam)
{
    this->lpParam = lpParam;
    return *this;
}

WindowHandleBuilder& WindowHandleBuilder::WithTitle(LPCWSTR title)
{
    this->title = title;
    return *this;
}

HWND WindowHandleBuilder::Build()
{
    return CreateWindowEx(
        0,                       // Optional window styles.
        className,               // Window class
        title,                   // Window text
        WS_OVERLAPPEDWINDOW,     // Window style

        // Size and position
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

        NULL,       // Parent window    
        NULL,       // Menu
        hInstance,  // Instance handle
        lpParam     // Additional application data
    );
}
