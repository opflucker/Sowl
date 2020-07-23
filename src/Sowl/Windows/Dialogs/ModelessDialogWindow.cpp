#include "ModelessDialogWindow.h"

using namespace sowl;

ModelessDialogWindow::ModelessDialogWindow(int resourceId)
    : DialogWindow(resourceId)
{
}

ModelessDialogWindow::ModelessDialogWindow(const Window& parentWindow, int resourceId)
    : DialogWindow(parentWindow, resourceId)
{
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
