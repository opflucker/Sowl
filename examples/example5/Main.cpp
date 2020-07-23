#ifndef UNICODE
#define UNICODE
#endif 

#include <windows.h>
#include <Sowl/Windows/MessageLoop.h>
#include "MainWindow.h"

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR pCmdLine, int nCmdShow)
{
    MainWindow window(hInstance);
    window.Show(nCmdShow);
    return sowl::MessageLoop().Run();
}
