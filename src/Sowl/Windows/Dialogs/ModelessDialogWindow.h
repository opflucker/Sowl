#pragma once
#include "DialogWindow.h"

namespace sowl
{
	class ModelessDialogWindow : public DialogWindow
	{
	public:
		explicit ModelessDialogWindow(int resourceId);
		ModelessDialogWindow(const Window& parentWindow, int resourceId);

		void CreateAndShow();
		bool OnClose() override;

	private:
		const Window* const pParentWindow;
		const int resourceId;
	};
}