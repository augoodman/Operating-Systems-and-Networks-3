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
    return 4 - ((width * 3) % 4);
}

/**
 * calculate size of file.
 *
 * @param  file: A pointer to the file being read or written
 */
int calcFileSize(FILE* file){
    if(file){
        fseek(file, 0, SEEK_END);
        long size = ftell(file);
        fseek(file, 0, SEEK_SET);
        return size;
    }
}

/**
 * calculate decimal value for a pixel color sample.
 *
 * @param  b: Binary value to be converted
 */
int binaryToDecimal(char* b){
    if(b == 0)
        return 0;
    //if(b == )
}