#ifndef UNICODE
#define UNICODE
#endif 

#include <windows.h>
#include "WindowClass.h"
#include "Window.h"
#include "MessageLoop.h"

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR pCmdLine, int nCmdShow)
{
    WindowClass wc(hInstance, L"Sample Window Class");
    Window window(wc, L"Learn to Program Windows");
    if (!window.IsCreated())
        return 0;

    window.Show(nCmdShow);
    MessageLoop().Run();
    return 0;
}
