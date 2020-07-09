#pragma once
#include "DialogWindow.h"

class ModelessDialogWindow : public DialogWindow
{
public:
	ModelessDialogWindow(const Window& parentWindow, int resourceId);
	void ShowModeless();
	virtual BOOL OnClose() override;
};

