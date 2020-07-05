#include "Cursor.h"

Cursor::Cursor(HCURSOR handle)
{
	this->handle = handle;
}

HCURSOR Cursor::GetHandle() const
{
	return handle;
}
