#pragma once
#include "DialogWindow.h"

class ModalDialogWindow : public DialogWindow
{
public:
	ModalDialogWindow(const Window& parentWindow, int resourceId);
	int ShowModal();
	BOOL End(int result);
	virtual BOOL OnClose() override;
};
