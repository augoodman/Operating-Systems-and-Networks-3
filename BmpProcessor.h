/**
* File:   BmpProcessor.h
* Header for BMP image processing.
*
* @author Goodman, Acuna
* @version 2020.08.25
*/

#ifndef BMPPROCESSOR_H
#define BMPPROCESSOR_H
#include "PixelProcessor.h"

typedef struct BMP_Header {
    //TODO:Finish struct
    char signature[2];      //ID field
    int size;               //Size of the BMP file
    short reserved1;        //Application specific
    short reserved2;        //Application specific
    int offset_pixel_array; //Offset where the pixel array can be found
}BMP_Header;

typedef struct DIB_Header{
    //TODO:Finish struct
    int size;               //Size of DIB header
    int width;              //Width of image
    int height;             //Height of image
    short planes;           //Number of color planes
    short bits_per_pixel;   //Number of bits per pixel
    int compression;        //Compression method used
    int image_size;         //Size of raw bitmap data
    int x_res;              //Horizontal resolution of image
    int y_res;              //Vertical resolution of image
    int color_table;        //Number of colors in color table
    int important_color;    //Number of important colors
}DIB_Header;

/**
 * read BMP header of a file. Useful for converting files from PPM to BMP.
 *
 * @param  file: A pointer to the file being read or written
 * @param  header: Pointer to the destination BMP header
 */
void readBMPHeader(FILE* file, struct BMP_Header* header);

/**
 * write BMP header of a file. Useful for converting files from PPM to BMP.
 *
 * @param  file: A pointer to the file being read or written
 * @param  header: The header made by makeBMPHeader function
 */
void writeBMPHeader(FILE* file, struct BMP_Header* header);

/**
 * read DIB header from a file. Useful for converting files from PPM to BMP.
 *
 * @param  file: A pointer to the file being read or written
 * @param  header: Pointer to the destination DIB header
 */
void readDIBHeader(FILE* file, struct DIB_Header* header);

/**
 * write DIB header of a file. Useful for converting files from PPM to BMP.
 *
 * @param  file: A pointer to the file being read or written
 * @param  header: The header made by makeDIBHeader function
 */
void writeDIBHeader(FILE* file, struct DIB_Header* header);

/**
 * make BMP header based on width and height. 
 * The purpose of this is to create a new BMPHeader struct using the information 
 * from a PPMHeader when converting from PPM to BMP.
 *
 * @param  header: Pointer to the destination DIB header
 * @param  width: Width of the image that this header is for
 * @param  height: Height of the image that this header is for
 */
void makeBMPHeader(struct BMP_Header* header, int width, int height);


/**
* Makes new DIB header based on width and height. Useful for converting files from PPM to BMP.
*
* @param  header: Pointer to the destination DIB header
* @param  width: Width of the image that this header is for
* @param  height: Height of the image that this header is for
*/
void makeDIBHeader(struct DIB_Header* header, int width, int height);


/**
 * read Pixels from BMP file based on width and height.
 *
 * @param  file: A pointer to the file being read or written
 * @param  pArr: Pixel array of the image that this header is for
 * @param  width: Width of the image that this header is for
 * @param  height: Height of the image that this header is for
 */
void readPixelsBMP(FILE* file, struct Pixel** pArr, int width, int height);


/**
 * write Pixels from BMP file based on width and height.
 *
 * @param  file: A pointer to the file being read or written
 * @param  pArr: Pixel array of the image that this header is for
 * @param  width: Width of the image that this header is for
 * @param  height: Height of the image that this header is for
 */
void writePixelsBMP(FILE* file, struct Pixel** pArr, int width, int height);

#endif