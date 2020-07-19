#include "MessageLoop.h"

MessageLoop::MessageLoop()
{
    result = 0;
}

int MessageLoop::Run()
{
    MSG msg = { };
    while (GetMessage(msg))
    {
        ProcessMessage(msg);
    }
    return result;
}

bool MessageLoop::GetMessage(MSG& message)
{
    switch (::GetMessage(&message, NULL, 0, 0))
    {
    case -1:
        return HandleErrorAndExit();
    case 0: // because WM_QUIT
        return false;
    default:
        return true;
    }
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

void MessageLoop::SetResult(int result)
{
    this->result = result;
}
