#include "../include/o3dDataTypes.hpp"

#include <cassert>

namespace o3d{
    o3dDataType getDataType(char c)
{
    switch(c)
    {
        case 'i': return dtype_i;
       // case 'I': // Intensity Image only updated images
        case 'd': return dtype_d;
      //  case 'D': // Distance Image only updated images
        case 'x': return dtype_x;
        case 'y': return dtype_y;
        case 'z': return dtype_z;
        case 'e': return dtype_e;
        case 'f': return dtype_f;
        case 'g': return dtype_g;
        case 's': return dtype_s;
        default: return dtype_undefined;
    }

    assert(0);
}

char getDataTypeChar(o3dDataType data_type)
{
    switch(data_type)
    {
        case dtype_i: return 'i';
       // case 'I': // Intensity Image only updated images
        case dtype_d: return 'd';
      //  case 'D': // Distance Image only updated images
        case dtype_x: return 'x';
        case dtype_y: return 'y';
        case dtype_z: return 'z';
        case dtype_e: return 'e';
        case dtype_f: return 'f';
        case dtype_g: return 'g';
        case dtype_s: return 's';
        default: return '?';
    }
    assert(0);
}
}
