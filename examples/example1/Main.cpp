#ifndef UNICODE
#define UNICODE
#endif 

#include <windows.h>
#include <Windows\Customs\CustomWindow.h>
#include <Windows\MessageLoop.h>

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR pCmdLine, int nCmdShow)
{
    auto window = CustomWindow(hInstance, L"CustomWindow");
    window.Show(nCmdShow);
    return MessageLoop().Run();
}
