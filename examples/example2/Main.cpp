#ifndef UNICODE
#define UNICODE
#endif 

#include <windows.h>
#include "MainWindow.h"
#include "MessageLoop.h"

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR pCmdLine, int nCmdShow)
{
    MainWindow window(hInstance);
    window.Show(nCmdShow);
    MessageLoop::Run();
    return 0;
}
