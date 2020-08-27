/**
* File:   PixelProcessor.h
* Header pixel RGB sample shifting.
*
* @author Goodman
* @version 2020.08.25
*/

#ifndef PIXELPROCESSOR_H
#define PIXELPROCESSOR_H

typedef struct Pixel{
    //TODO:Finish struct
    int red;    //Red pixel sample
    int green;  //Green pixel sample
    int blue;   //Blue pixel sample
}Pixel;

/**
 * Shift color of Pixel array. The dimension of the array is width * height. The shift value of RGB is 
 * rShift, gShift，bShift. Useful for color shift.
 *
 * @param  pArr: Pixel array of the image that this header is for
 * @param  width: Width of the image that this header is for
 * @param  height: Height of the image that this header is for
 * @param  rShift: the shift value of color r shift
 * @param  gShift: the shift value of color g shift 
 * @param  bShift: the shift value of color b shift 
 */
void colorShiftPixels(struct Pixel** pArr, int width, int height, int rShift, int gShift, int bShift);

#endif