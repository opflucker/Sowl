#include "WindowClassRegistered.h"
#include <wtypes.h>

WindowClassRegistered::WindowClassRegistered(HINSTANCE hInstance, LPCWSTR className)
{
    this->hInstance = hInstance;
    this->className = className;
}

WindowHandleBuilder WindowClassRegistered::CreateHandleBuilder() const
{
    return WindowHandleBuilder(hInstance, className);
}
