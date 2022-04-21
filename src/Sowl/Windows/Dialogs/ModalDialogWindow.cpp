#include "ModalDialogWindow.h"

using namespace sowl;

ModalDialogWindow::ModalDialogWindow(const Window& parentWindow, int resourceId)
    : parentWindow(parentWindow), resourceId(resourceId)
{
}

int ModalDialogWindow::CreateAndShow()
{
    if (GetHandle() == nullptr)
    {
        return (int)::DialogBoxParam(parentWindow.GetProcessHandle(), MAKEINTRESOURCE(resourceId), parentWindow.GetHandle(), BindAndProcess, (LPARAM)this);
    }
    return 0;
}

bool ModalDialogWindow::End(int result) const
{
    return EndDialog(GetHandle(), result);
}

bool ModalDialogWindow::OnClose()
{
    return End(IDCANCEL);
}
