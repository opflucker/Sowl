#include "Cursor.h"

using namespace sowl;

Cursor::Cursor(HCURSOR handle)
{
	this->handle = handle;
}

HCURSOR Cursor::GetHandle() const
{
	return handle;
}
