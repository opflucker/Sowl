#ifndef UNICODE
#define UNICODE
#endif 

#include <windows.h>
#include <Sowl/Windows/Customs/CustomWindow.h>
#include <Sowl/Windows/MessageLoop.h>

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR pCmdLine, int nCmdShow)
{
    CustomWindow window(hInstance, L"CustomWindow");
    window.Show(nCmdShow);
    return MessageLoop().Run();
}
