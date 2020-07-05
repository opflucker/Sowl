#include "PredefinedCursors.h"

HCURSOR PredefinedCursors::GetHandle(LPWSTR id)
{
	return LoadCursor(NULL, id);
}
