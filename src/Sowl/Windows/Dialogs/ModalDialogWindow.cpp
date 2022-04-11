#include "ModalDialogWindow.h"

using namespace sowl;

ModalDialogWindow::ModalDialogWindow(const Window& parentWindow, int resourceId)
    : DialogWindow(parentWindow, resourceId)
{
}

int ModalDialogWindow::CreateAndShow()
{
    return CreateAndShowModal();
}

bool ModalDialogWindow::End(int result) const
{
    return EndDialog(GetHandle(), result);
}

bool ModalDialogWindow::OnClose()
{
    return End(IDCANCEL);
}
