#include "PredefinedCursors.h"

HCURSOR PredefinedCursors::ArrowHandle()
{
	return LoadCursor(NULL, IDC_ARROW);
}

HCURSOR PredefinedCursors::CrossHandle()
{
	return LoadCursor(NULL, IDC_CROSS);
}
