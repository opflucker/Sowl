#include "ModelessDialogWindow.h"

ModelessDialogWindow::ModelessDialogWindow(const Window& parentWindow, int resourceId)
    : DialogWindow(parentWindow, resourceId)
{
}

void ModelessDialogWindow::ShowModeless()
{
    if (GetHandle() == NULL)
    {
        SetHandle(CreateAndShowModeless());
        Show(SW_SHOW);
    }
}

BOOL ModelessDialogWindow::OnClose()
{
    Destroy();
    return TRUE;
}
