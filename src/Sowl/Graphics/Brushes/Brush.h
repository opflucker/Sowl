#pragma once
#include <windows.h>

class Brush
{
public:
	Brush(HBRUSH handle);
	HBRUSH GetHandle() const;

private:
	HBRUSH handle;
};
