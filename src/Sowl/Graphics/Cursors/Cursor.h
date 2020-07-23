#pragma once
#include <windows.h>

namespace sowl
{
	class Cursor
	{
	public:
		Cursor(HCURSOR handle);
		HCURSOR GetHandle() const;

	private:
		HCURSOR handle;
	};
}