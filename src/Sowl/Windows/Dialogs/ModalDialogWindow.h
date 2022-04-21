#pragma once
#include "DialogWindow.h"

namespace sowl
{
	/// @brief Encapsulates a modal dialog window handle.
	class ModalDialogWindow : public DialogWindow
	{
	public:
		ModalDialogWindow(const Window& parentWindow, int resourceId);

		int CreateAndShow();
		bool End(int result) const;
		bool OnClose() override;

	private:
		const Window& parentWindow;
		const int resourceId;
	};
}