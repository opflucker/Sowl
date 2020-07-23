#pragma once
#include "DialogWindow.h"

namespace sowl
{
	class ModalDialogWindow : public DialogWindow
	{
	public:
		ModalDialogWindow(const Window& parentWindow, int resourceId);
		int CreateAndShow();
		bool End(int result);
		virtual bool OnClose() override;
	};
}