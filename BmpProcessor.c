/**
* File:   BmpProcessor.c
* Process BMP images.
*
* @author Goodman, Acuna
* @version 2020.08.25
*/

#include <stdio.h>
#include "BmpProcessor.h"
#include "PixelProcessor.h"
#include "Util.h"

/**
 * read BMP header of a file. Useful for converting files from PPM to BMP.
 *
 * @param  file: A pointer to the file being read or written
 * @param  header: Pointer to the destination BMP header
 */
void readBMPHeader(FILE* file, struct BMP_Header* header){
    fread(header->signature, sizeof(char)*2, 1, file);
    fread(&header->size, sizeof(int), 1, file);
    fread(&header->reserved1, sizeof(short), 1, file);
    fread(&header->reserved2, sizeof(short), 1, file);
    fread(&header->offset_pixel_array, sizeof(int), 1, file);
}

/**
 * write BMP header of a file. Useful for converting files from PPM to BMP.
 *
 * @param  file: A pointer to the file being read or written
 * @param  header: The header made by makeBMPHeader function
 */
void writeBMPHeader(FILE* file, struct BMP_Header* header){
    fwrite(header->signature, sizeof(char)*2, 1, file);
    fwrite(&header->size, sizeof(int), 1, file);
    fwrite(&header->reserved1, sizeof(short), 1, file);
    fwrite(&header->reserved2, sizeof(short), 1, file);
    fwrite(&header->offset_pixel_array, sizeof(int), 1, file);
}

/**
 * read DIB header from a file. Useful for converting files from PPM to BMP.
 *
 * @param  file: A pointer to the file being read or written
 * @param  header: Pointer to the destination DIB header
 */
void readDIBHeader(FILE* file, struct DIB_Header* header){
    fread(&header->size, sizeof(int), 1, file);
    fread(&header->width, sizeof(int), 1, file);
    fread(&header->height, sizeof(int), 1, file);
    fread(&header->planes, sizeof(short), 1, file);
    fread(&header->bits_per_pixel, sizeof(short), 1, file);
    fread(&header->compression, sizeof(int), 1, file);
    fread(&header->image_size, sizeof(int), 1, file);
    fread(&header->x_res, sizeof(int), 1, file);
    fread(&header->y_res, sizeof(int), 1, file);
    fread(&header->color_table, sizeof(int), 1, file);
    fread(&header->important_color, sizeof(int), 1, file);
}

/**
 * write DIB header of a file. Useful for converting files from PPM to BMP.
 *
 * @param  file: A pointer to the file being read or written
 * @param  header: The header made by makeDIBHeader function
 */
void writeDIBHeader(FILE* file, struct DIB_Header* header){
    fwrite(&header->size, sizeof(int), 1, file);
    fwrite(&header->width, sizeof(int), 1, file);
    fwrite(&header->height, sizeof(int), 1, file);
    fwrite(&header->planes, sizeof(short), 1, file);
    fwrite(&header->bits_per_pixel, sizeof(short), 1, file);
    fwrite(&header->compression, sizeof(int), 1, file);
    fwrite(&header->image_size, sizeof(int), 1, file);
    fwrite(&header->x_res, sizeof(int), 1, file);
    fwrite(&header->y_res, sizeof(int), 1, file);
    fwrite(&header->color_table, sizeof(int), 1, file);
    fwrite(&header->important_color, sizeof(int), 1, file);
}

/**
 * make BMP header based on width and height. 
 * The purpose of this is to create a new BMPHeader struct using the information 
 * from a PPMHeader when converting from PPM to BMP.
 *
 * @param  header: Pointer to the destination DIB header
 * @param  width: Width of the image that this header is for
 * @param  height: Height of the image that this header is for
 */
void makeBMPHeader(struct BMP_Header* header, int width, int height){
    header->signature[0] = 'B';
    header->signature[1] = 'M';
    header->size = (calcImageSize(width, height) + 54);
    header->reserved1 = 0;
    header->reserved2 = 0;
    header->offset_pixel_array = 54;
}

 /**
 * Makes new DIB header based on width and height. Useful for converting files from PPM to BMP.
 *
 * @param  header: Pointer to the destination DIB header
 * @param  width: Width of the image that this header is for
 * @param  height: Height of the image that this header is for
 */
void makeDIBHeader(struct DIB_Header* header, int width, int height){
    header->size = 40;
    header->width = width;
    header->height = height;
    header->planes = 1;
    header->bits_per_pixel = 24;
    header->compression = 0;
    header->image_size = calcImageSize(width, height);
    header->x_res = 3780;
    header->y_res = 3780;
    header->color_table = 0;
    header->important_color = 0;
}

/**
 * read Pixels from BMP file based on width and height.
 *
 * @param  file: A pointer to the file being read or written
 * @param  pArr: Pixel array of the image that this header is for
 * @param  width: Width of the image that this header is for
 * @param  height: Height of the image that this header is for
 */
void readPixelsBMP(FILE* file, struct Pixel** pArr, int width, int height){
    int i, j, padding = calcPadding(width);
    for(i = 0; i < height; i++)
        for(j = 0; j < width + padding; j++)
            if (j < width) {
                fread(&pArr[height - i - 1][j].blue, 1, 1, file);
                fread(&pArr[height - i - 1][j].green, 1, 1, file);
                fread(&pArr[height - i - 1][j].red, 1, 1, file);
            }
            else fseek(file,1,SEEK_CUR);
}

/**
 * write Pixels from BMP file based on width and height.
 *
 * @param  file: A pointer to the file being read or written
 * @param  pArr: Pixel array of the image that this header is for
 * @param  width: Width of the image that this header is for
 * @param  height: Height of the image that this header is for
 */
void writePixelsBMP(FILE* file, struct Pixel** pArr, int width, int height){
    int i, j, padding = calcPadding(width);
    int empty = 0;
    fseek(file, -2, SEEK_SET);
    for(i = 0; i < height; i++)
        for(j = 0; j < width + padding; j++) {
            if(i == height - 1 && j == width - 1){
                fwrite(&pArr[height - i - 1][j].blue, 1, 1, file);
                fwrite(&pArr[height - i - 1][j].green, 1, 1, file);
                fwrite(&pArr[height - i - 1][j].red, 1, 1, file);
                fwrite(&empty, 1, 1, file);
            }
            if(j < width) {
                fwrite(&pArr[height - i - 1][j].blue, 1, 1, file);
                fwrite(&pArr[height - i - 1][j].green, 1, 1, file);
                fwrite(&pArr[height - i - 1][j].red, 1, 1, file);
            } else fseek(file, 1, SEEK_CUR);
        }
}