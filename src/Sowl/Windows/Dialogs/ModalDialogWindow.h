#pragma once
#include "DialogWindow.h"

namespace sowl
{
	class ModalDialogWindow : public DialogWindow
	{
	public:
		ModalDialogWindow(const Window& parentWindow, int resourceId);
		~ModalDialogWindow() override = default;

		int CreateAndShow();
		bool End(int result) const;
		bool OnClose() override;

	private:
		const Window& parentWindow;
		const int resourceId;
	};
}