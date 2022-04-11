#include <Sowl/Sowl.h>

int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE, _In_ PWSTR, _In_ int nCmdShow)
{
    sowl::CustomWindow window(hInstance, L"MyWindowClass");
    window.Show(nCmdShow);
    return sowl::MessageLoop().Run();
}
