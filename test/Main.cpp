#ifndef UNICODE
#define UNICODE
#endif 

#include <windows.h>
#include "MessageLoop.h"
#include "TestCustomWindow.h"

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR pCmdLine, int nCmdShow)
{
    TestCustomWindow window(hInstance);
    if (window.GetHandle() == NULL)
        return 0;

    window.Show(nCmdShow);
    MessageLoop::Run(window.modelessDialog);
    return 0;
}
