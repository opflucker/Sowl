#pragma once
#include "DialogWindow.h"

namespace sowl
{
	class ModelessDialogWindow : public DialogWindow
	{
	public:
		ModelessDialogWindow(int resourceId);
		ModelessDialogWindow(const Window& parentWindow, int resourceId);

		void CreateAndShow();
		virtual bool OnClose() override;
	};
}