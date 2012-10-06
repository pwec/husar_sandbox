/* 
 * File:   o3dDataTypes.hpp
 * Author: Maciek
 *
 * Created on 29 październik 2010, 18:05
 */

#ifndef O3DDATATYPES_HPP
#define	O3DDATATYPES_HPP

namespace o3d{
    #define IMG_WIDTH 64
    #define IMG_HEIGHT 50
    

    enum o3dDataType{
        dtype_i = 'i', // Intensity Image
    //    dtype_I = 'I', // Intensity Image only updated images
        dtype_d = 'd', // Distance Image
    //    dtype_i = 'D', // Distance Image only updated images
        dtype_x = 'x', // Cartesian X-Coordinates
        dtype_y = 'y', // Cartesian Y-Coordinates
        dtype_z = 'z', // Cartesian Z-Coordinates
        dtype_e = 'e', // Normal Vector x
        dtype_f = 'f', // Normal Vector y
        dtype_g = 'g', // Normal Vector z
        dtype_s = 's', // Standard deviation Image
        dtype_undefined
    };


    o3dDataType getDataType(char c);
    char getDataTypeChar(o3dDataType data_type);
}

#endif	/* O3DDATATYPES_HPP */

