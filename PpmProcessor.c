/**
* File:   PpmProcessor.c
* Process PPM images.
*
* @author Goodman
* @version 2020.08.25
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "PpmProcessor.h"
#include "PixelProcessor.h"
#include "Util.h"


/**
 * read PPM header of a file. Useful for converting files from BMP to PPM.
 *
 * @param  file: A pointer to the file being read or written
 * @param  header: Pointer to the destination PPM header
 */
void readPPMHeader(FILE* file, struct PPM_Header* header){
    int i = 0;
    fscanf(file, "%s %d %d %d", header->signature, &header->width, &header->height, &header->max_value);
    //fseek(file, 1, SEEK_CUR);
}

/**
 * write PPM header of a file. Useful for converting files from BMP to PPM.
 *
 * @param  file: A pointer to the file being read or written
 * @param  header: The header made by makePPMHeader function

 */
void writePPMHeader(FILE* file, struct PPM_Header* header){
    char* whitespace = " ";
    fprintf(file, "%s %d %d %d", header->signature, header->width, header->height, header->max_value);
    fprintf(file, "%s", whitespace);
}

/**
 * make PPM header based on width and height. Useful for converting files from BMP to PPM.
 *
 * @param  header: Pointer to the destination PPM header
 * @param  width: Width of the image that this header is for
 * @param  height: Height of the image that this header is for
 */
void makePPMHeader(struct PPM_Header* header, int width, int height){
    strcpy("P6", header->signature);
    header->width = width;
    header->height = height;
    header->max_value = 255;
}

/**
 * read Pixels from PPM file based on width and height.
 *
 * @param  file: A pointer to the file being read or written
 * @param  pArr: Pixel array of the image that this header is for 
 * @param  width: Width of the image that this header is for
 * @param  height: Height of the image that this header is for
 */
void readPixelsPPM(FILE* file, struct Pixel** pArr, int width, int height){
    int i, j;
    fseek(file, 1, SEEK_CUR);
    for(i = 0; i < height; i++)
        for(j = 0; j < width; j++) {
            //fscanf(file, "%c %c %c", (char*)&pArr[i][j].red, (char*)&pArr[i][j].green, (char*)&pArr[i][j].blue);
            //fscanf(file, "%hhd %hhd %hhd", (char *)&pArr[i][j].red, (char *)&pArr[i][j].green, (char *)&pArr[i][j].blue);
            fread(&pArr[i][j].red, 1, 1, file);
            fread(&pArr[i][j].green, 1, 1, file);
            fread(&pArr[i][j].blue, 1, 1, file);
        }
}

/**
 * write Pixels from PPM file based on width and height.
 *
 * @param  file: A pointer to the file being read or written
 * @param  pArr: Pixel array of the image that this header is for
 * @param  width: Width of the image that this header is for
 * @param  height: Height of the image that this header is for
 */
void writePixelsPPM(FILE* file, struct Pixel** pArr, int width, int height){
    int i, j;
    for(i = 0; i < height; i++)
        for(j = 0; j < width; j++) {
            //fprintf(file, "%c %c %c", pArr[i][j].red, pArr[i][j].green, pArr[i][j].blue);
            fwrite(&pArr[i][j].red, 1, 1, file);
            fwrite(&pArr[i][j].green, 1, 1, file);
            fwrite(&pArr[i][j].blue, 1, 1, file);
        }
}