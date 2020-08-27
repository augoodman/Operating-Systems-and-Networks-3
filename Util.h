/**
* File:   Util.h
* Header for image processing utilities.
*
* @author Goodman
* @version 2020.08.25
*/

#ifndef UTIL_H
#define UTIL_H

/**
 * calculate size of BMP image array. Useful for converting files from BMP to PPM.
 *
 * @param  width: Number of pixels in each row of array
 * @param  height: Number of pixels in each column of array
 */
int calcImageSize(int width, int height);

/**
 * calculate padding for each row of an image.
 *
 * @param  width: Number of pixels in each row of array
 */
int calcPadding(int width);

/**
 * calculate decimal value for a pixel color sample.
 *
 * @param  b: String containing binary value to be converted
 */
int binaryToDecimal(char* b);

#endif
