#include "alglib_utils.h"

// Check if two arrays are the same size
void check_size(Array x, Array y)
{
    if (x.size() != y.size())
    {
        throw std::invalid_argument("x and y must be the same size");
    }
}