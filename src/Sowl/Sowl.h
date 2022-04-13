#pragma once

#ifndef UNICODE
#define UNICODE
#endif 

#include <Windows.h>

#include "Windows/MessageLoop.h"
#include "Windows/Utilities.h"
#include "Windows/Window.h"
#include "Windows/WindowHandleCreator.h"

#include "Windows/Controls/ControlWindowCreator.h"
#include "Windows/Controls/ControlWindow.h"
#include "Windows/Controls/ButtonWindow.h"

#include "Windows/Customs/CustomWindow.h"
#include "Windows/Customs/WindowClassRegisterer.h"

#include "Windows/Dialogs/DialogWindow.h"
#include "Windows/Dialogs/ModalDialogWindow.h"
#include "Windows/Dialogs/ModelessDialogWindow.h"

#include "Graphics/DeviceContext.h"
#include "Graphics/PaintDeviceContext.h"

#include "Graphics/Brushes/Brush.h"
#include "Graphics/Brushes/SolidBrush.h"
#include "Graphics/Brushes/StockBrushesHandles.h"

#include "Graphics/Cursors/Cursor.h"
#include "Graphics/Cursors/PredefinedCursorHandles.h"
