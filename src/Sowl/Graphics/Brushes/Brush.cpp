#include "Brush.h"

using namespace sowl;

Brush::Brush(HBRUSH handle)
{
    this->handle = handle;
}

HBRUSH Brush::GetHandle() const
{
    return handle;
}
