#include "ModelessDialogWindow.h"

ModelessDialogWindow::ModelessDialogWindow(int resourceId)
    : DialogWindow(resourceId)
{
}

ModelessDialogWindow::ModelessDialogWindow(const Window& parentWindow, int resourceId)
    : DialogWindow(parentWindow, resourceId)
{
}

void ModelessDialogWindow::SetParent(const Window& parentWindow)
{
    if (GetHandle() == NULL)
    {
        DialogWindow::SetParent(parentWindow);
    }
}

void ModelessDialogWindow::CreateAndShow()
{
    CreateModeless();
    Show(SW_SHOW);
}

bool ModelessDialogWindow::OnClose()
{
    Destroy();
    return true;
}
