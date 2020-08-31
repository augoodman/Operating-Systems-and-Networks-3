/**
* File:   PixelProcessor.c
* Shift pixel RGB samples.
*
* @author Goodman
* @version 2020.08.25
*/

#include "PixelProcessor.h"
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
void colorShiftPixels(struct Pixel** pArr, int width, int height, int rShift, int gShift, int bShift){
    int i, j;
    for(i = 0; i < height; i++)
        for(j = 0; j < width; j++) {
            pArr[i][j].red += rShift;
            pArr[i][j].green += gShift;
            pArr[i][j].blue += bShift;
            if(pArr[i][j].red > 255)
                pArr[i][j].red = 255;
            if(pArr[i][j].red < 0)
                pArr[i][j].red = 0;
            if(pArr[i][j].green > 255)
                pArr[i][j].green = 255;
            if(pArr[i][j].green < 0)
                pArr[i][j].green = 0;
            if(pArr[i][j].blue > 255)
                pArr[i][j].blue = 255;
            if(pArr[i][j].blue < 0)
                pArr[i][j].blue = 0;
        }
}