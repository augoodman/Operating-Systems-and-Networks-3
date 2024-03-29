/**
* File:   Util.c
* Utilities for image processing.
*
* @author Goodman
*/

#include "Util.h"

/**
 * calculate size of BMP image array. Useful for converting files from BMP to PPM.
 *
 * @param  width: Number of pixels in each row of array
 * @param  height: Number of pixels in each column of array
 */
int calcImageSize(int width, int height){
    return ((width * 3) + calcPadding(width)) * height;
}

/**
 * calculate padding for each row of an image.
 *
 * @param  width: Number of pixels in each row of array
 */
int calcPadding(int width){
    int padding = 4 - ((width * 3) % 4);
    if(padding == 4)
        return 0;
    return padding;
}

