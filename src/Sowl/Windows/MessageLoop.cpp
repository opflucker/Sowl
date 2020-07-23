#include "MessageLoop.h"

using namespace sowl;

int MessageLoop::Run()
{
    MSG msg;
    int getResult;
    while ((getResult = GetMessage(msg)) != 0)
    {
        if (getResult == -1)
        {
            if (HandleErrorAndExit())
                break;
        }
        else
            ProcessMessage(msg);
    }
    return msg.wParam; // exit code on WM_QUIT
}

int MessageLoop::GetMessage(MSG& message)
{
    return ::GetMessage(&message, NULL, 0, 0);
}

bool MessageLoop::HandleErrorAndExit()
{
    return false;
}

void MessageLoop::ProcessMessage(MSG& message)
{
    TranslateMessage(&message);
    DispatchMessage(&message);
}
