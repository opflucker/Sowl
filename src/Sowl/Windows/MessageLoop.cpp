#include "MessageLoop.h"

using namespace sowl;

/// @brief Implements a generic message loop following a "template method pattern".
/// Variant parts (GetMessage, HandleErrorAndExit, ProcessMessage) are implemented as virtual methods, so they can be overriden on inherited classes.
/// @return Exit code of the loop that comes from a call to ::PostQuitMessage.
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
    return (int)msg.wParam; // exit code on WM_QUIT
}

/// @brief Encapsulates a call to ::GetMessage without filters.
/// @param message Receive information about the message retrieved.
/// @return If the call was successful, returns 1. If it fails, return -1. If loop must ends, returns 0.
int MessageLoop::GetMessage(MSG& message)
{
    return ::GetMessage(&message, NULL, 0, 0);
}

/// @brief Default implementation for handling errors. Do nothing and returns 'false'.
/// @return Indicates if the loop must exist: 'true' for exit. 'false' for continue.
bool MessageLoop::HandleErrorAndExit()
{
    return false;
}

/// @brief Default implementation of message processing. Calls TranslateMessage and DispatchMessage. 
/// @param message Information about the message to be processing.
void MessageLoop::ProcessMessage(MSG& message)
{
    TranslateMessage(&message);
    DispatchMessage(&message);
}
