#include "MessageLoop.h"

void MessageLoop::Run()
{
    MSG msg = { };
    BOOL result;
    while (result = GetMessage(&msg, NULL, 0, 0))
    {
        if (result == -1)
        {
            // Handle the error and possibly exit
        }
        else
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }
}

void MessageLoop::Run(const Window& dlgWindow)
{
    MSG msg = { };
    BOOL result;
    while (result = GetMessage(&msg, NULL, 0, 0))
    {
        if (result == -1)
        {
            // Handle the error and possibly exit
        }
        else
        {
            HWND dialogHandle = dlgWindow.GetHandle();
            if (!IsWindow(dialogHandle) || !IsDialogMessage(dialogHandle, &msg))
            {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        }
    }
}
