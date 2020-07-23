#include "PredefinedCursorHandles.h"

using namespace sowl;

HCURSOR PredefinedCursorHandles::Arrow()
{
	return LoadCursor(NULL, IDC_ARROW);
}

HCURSOR PredefinedCursorHandles::Cross()
{
	return LoadCursor(NULL, IDC_CROSS);
}
