#include "ModelessDialogWindow.h"

using namespace sowl;

ModelessDialogWindow::ModelessDialogWindow(int resourceId)
    : pParentWindow(nullptr)
    , resourceId(resourceId)
{
}

ModelessDialogWindow::ModelessDialogWindow(const Window& parentWindow, int resourceId)
    : pParentWindow(&parentWindow)
    , resourceId(resourceId)
{
}

void ModelessDialogWindow::CreateAndShow()
{
    if (GetHandle() == nullptr)
    {
        HINSTANCE processHandle = pParentWindow == nullptr ? nullptr : pParentWindow->GetProcessHandle();
        HWND parentWindowHandle = pParentWindow == nullptr ? nullptr : pParentWindow->GetHandle();
        CreateDialogParam(processHandle, MAKEINTRESOURCE(resourceId), parentWindowHandle, DialogProc, (LPARAM)this);
    }
    Show(SW_SHOW);
}

bool ModelessDialogWindow::OnClose()
{
    Destroy();
    return true;
}
