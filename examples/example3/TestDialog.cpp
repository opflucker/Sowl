#include "TestDialog.h"
#include "Resources.h"

TestDialog::TestDialog(const Window& parentWindow)
    : ModalDialogWindow(parentWindow, IDD_DIALOG1)
{
}

bool TestDialog::OnInitDialog(HWND hFocusWindow)
{
    okButton.SetHandle(*this, IDOK);
    return TRUE;
}

bool TestDialog::OnCommand(int notificationCode, int senderId, HWND controlHandle)
{
    switch (senderId)
    {
    case IDOK:
        okButton.Enable(false);
        okButton.SetText(L"Disabled");
        return true;
    case IDCANCEL:
        End(0);
        return true;
    default:
        return false;
    }
}
