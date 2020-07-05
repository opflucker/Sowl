#pragma once
#include <windows.h>

class Cursor
{
public:
	Cursor(HCURSOR handle);
	HCURSOR GetHandle() const;

private:
	HCURSOR handle;
};
