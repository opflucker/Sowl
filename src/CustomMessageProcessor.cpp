#include "CustomMessageProcessor.h"

LRESULT CALLBACK CustomMessageProcessor::WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    CustomMessageProcessor* pMessageProcessor;

    if (uMsg == WM_CREATE)
    {
        CREATESTRUCT* pCreate = reinterpret_cast<CREATESTRUCT*>(lParam);
        pMessageProcessor = reinterpret_cast<CustomMessageProcessor*>(pCreate->lpCreateParams);
        SetWindowLongPtr(hwnd, GWLP_USERDATA, (LONG_PTR)pMessageProcessor);
    }
    else
    {
        LONG_PTR ptr = GetWindowLongPtr(hwnd, GWLP_USERDATA);
        pMessageProcessor = reinterpret_cast<CustomMessageProcessor*>(ptr);
    }

    if (pMessageProcessor != NULL)
        return pMessageProcessor->Process(uMsg, wParam, lParam);

    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
