#include "ModalDialogWindow.h"

ModalDialogWindow::ModalDialogWindow(const Window& parentWindow, int resourceId)
    : DialogWindow(parentWindow, resourceId)
{
}

int ModalDialogWindow::ShowModal()
{
    return CreateAndShowModal();
}

BOOL ModalDialogWindow::End(int result)
{
    return EndDialog(GetHandle(), result);
}

BOOL ModalDialogWindow::OnClose()
{
    return End(IDCANCEL);
}
