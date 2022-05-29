#include "I_Printable.h"

std::ostream &operator<<(std::ostream &os, const I_Printable &obj)
{
    obj.Print(os);
    return os;
}

