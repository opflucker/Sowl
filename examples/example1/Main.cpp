#ifndef UNICODE
#define UNICODE
#endif 

#include <windows.h>
#include <Windows\Customs\CustomWindow.h>
#include <Windows\MessageLoop.h>

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR pCmdLine, int nCmdShow)
{
    auto wc = CustomWindow::CreateClassBuilder(hInstance, L"MyClass").Register();
    auto window = CustomWindow(WindowHandleBuilder(wc).WithTitle(L"Hello World!!!"));
    window.Show(nCmdShow);
    MessageLoop::Run();
    return 0;
}
