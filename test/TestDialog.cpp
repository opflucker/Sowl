#include "TestDialog.h"
#include "resource.h"

TestDialog::TestDialog(const Window& parentWindow)
    : DialogWindow(parentWindow, IDD_DIALOG1)
{
}

BOOL TestDialog::OnInitDialog(HWND hFocusWindow)
{
    okButton.Attach(*this, IDOK);
    return TRUE;
}

BOOL TestDialog::OnCommand(int notificationCode, int senderId, HWND controlHandle)
{
    if (senderId == okButton.GetId())
    {
        okButton.Enable(false);
        return true;
    }
    return false;
}
