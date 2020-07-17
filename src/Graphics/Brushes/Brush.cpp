#include "Brush.h"

Brush::Brush(HBRUSH handle)
{
    this->handle = handle;
}

HBRUSH Brush::GetHandle() const
{
    return handle;
}
