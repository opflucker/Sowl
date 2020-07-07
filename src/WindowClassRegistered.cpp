#include "WindowClassRegistered.h"
#include "CustomMessageProcessor.h"
#include <wtypes.h>

WindowClassRegistered::WindowClassRegistered(const WNDCLASS& wc)
{
    WNDCLASS wcFound;
    if (GetClassInfo(wc.hInstance, wc.lpszClassName, &wcFound) == FALSE)
        RegisterClass(&wc);
    
    hInstance = wc.hInstance;
    className = wc.lpszClassName;
}

WindowHandleBuilder WindowClassRegistered::CreateHandleBuilder() const
{
    return WindowHandleBuilder(hInstance, className);
}
