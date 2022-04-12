#include "MainWindow.h"

int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE, _In_ PWSTR, _In_ int nCmdShow)
{
    MainWindow window(hInstance);
    window.Show(nCmdShow);
    return window.Run();
}
