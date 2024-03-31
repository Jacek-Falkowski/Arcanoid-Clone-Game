#include "Objects/Shape.hpp"

bool operator==(const Rectangle& a, const Rectangle& b)
{
        return a.x() == b.x() and a.y() == b.y();
}

bool operator!=(const Rectangle& a, const Rectangle& b)
{
        return not operator==(a, b);
}

bool operator==(const Circle& a, const Circle& b)
{
        return a.radius() == b.radius();
}
bool operator!=(const Circle& a, const Circle& b)
{
        return not operator==(a, b);
}
