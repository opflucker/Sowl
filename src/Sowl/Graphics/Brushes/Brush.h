#pragma once
#include <windows.h>

namespace sowl
{
	class Brush
	{
	public:
		Brush(HBRUSH handle);
		HBRUSH GetHandle() const;

	private:
		HBRUSH handle;
	};
}