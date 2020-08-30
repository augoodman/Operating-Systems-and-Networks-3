/**
* File:   GoodmanImageProcessor.c
* Process images in BMP and PPM formats.
*
* Completion time:  20 hours
*
* @author Goodman
* @version 2020.08.25
*/

#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
//#include <unistd.h>
#include "BmpProcessor.h"
#include "PpmProcessor.h"
#include "PixelProcessor.h"
#include "Util.h"

/**
* main
*/
int main(int argc, char* argv[]){
    int i, iFlag = 0, oFlag = 0, tFlag = 0, rFlag = 0, gFlag = 0, bFlag = 0;
    printf("argc = %d\n", argc);
    for (i = 0; i < argc; i++)
        printf("arg[%d] = \"%s\"\n", i, argv[i]);
    printf("\n");
    char* input_file;
    char* output_file;
    char* file_type;
    char* red;
    char* green;
    char* blue;
    int opt;
    while((opt = getopt(argc, argv, "i:o:t:r:g:b:")) != -1)
        switch(opt){
            case 'i':
                if(iFlag == 1){
                    printf("Extra argument for input file: %s.  Argument Discarded.\n\n", optarg);
                    break;
                }
                iFlag = 1;
                input_file = optarg;
                break;
            case 'o':
                if(oFlag == 1){
                    printf("Extra argument for input file: %s.  Argument Discarded.\n\n", optarg);
                    break;
                }
                oFlag = 1;
                output_file = optarg;
                break;
            case 't':
                if(tFlag == 1){
                    printf("Extra argument for file extension: .%s.  Argument Discarded.\n\n", optarg);
                    break;
                }
                if(strcmp(optarg, "bmp") != 0 && strcmp(optarg, "ppm") != 0){
                    tFlag = 1;
                    printf("Invalid file extension.  Default file extension of .bmp used.\n\n");
                    file_type = optarg;
                    break;
                }
                tFlag = 1;
                file_type = optarg;
                break;
            case 'r':
                if(rFlag == 1){
                    printf("Extra argument for red sample.  Argument Discarded.\n\n");
                    break;
                }
                rFlag = 1;
                red = optarg;
                break;
            case 'g':
                if(gFlag == 1){
                    printf("Extra argument for green sample.  Argument Discarded.\n\n");
                    break;
                }
                gFlag = 1;
                green = optarg;
                break;
            case 'b':

                bFlag = 1;
                blue = optarg;
                break;
            case ':':
                printf("Option needs a value.\n");
                break;
            default:
                printf("Unknown option: %c.\n", optopt);
                break;
        }

    FILE* file = fopen("test2.bmp", "r");

    //read a bmp header from file
    BMP_Header* bmp_header = (BMP_Header*)malloc(sizeof(BMP_Header));
    readBMPHeader(file, bmp_header);
    printf("signature: %s\n", bmp_header->signature);
    printf("size: %d\n", bmp_header->size);
    printf("reserved1: %d\n", bmp_header->reserved1);
    printf("reserved2: %d\n", bmp_header->reserved2);
    printf("offset_pixel_array: %d\n\n", bmp_header->offset_pixel_array);

    //read a dib header from file
    DIB_Header* dib_header = (DIB_Header*)malloc(sizeof(DIB_Header));
    readDIBHeader(file, dib_header);
    printf("size: %d\n", dib_header->size);
    printf("width: %d\n", dib_header->width);
    printf("height: %d\n", dib_header->height);
    printf("planes: %d\n", dib_header->planes);
    printf("bits_per_pixel: %d\n", dib_header->bits_per_pixel);
    printf("compression: %d\n", dib_header->compression);
    printf("image_size: %d\n", dib_header->image_size);
    printf("x_res: %d\n", dib_header->x_res);
    printf("y_res: %d\n", dib_header->y_res);
    printf("color_table: %d\n", dib_header->color_table);
    printf("important_color: %d\n", dib_header->important_color);

    //read a bmp pixel array from file
    fseek(file, bmp_header->offset_pixel_array, SEEK_SET);
    Pixel** pArr = NULL;
            pArr = (Pixel**)malloc(dib_header->width * sizeof(Pixel*));
    for(i = 0; i < dib_header->width; i++){
        pArr[i] = (Pixel*) malloc(dib_header->height * sizeof(Pixel));
    }
    readPixelsBMP(file, pArr, dib_header->width, dib_header->height);
    int j;
    for(i = 0; i < dib_header->height; i++)
        for(j = 0; j < dib_header->width; j++){
            printf("\npArr[%d][%d] blue: %d\n", j, i, pArr[j][i].blue);
            printf("pArr[%d][%d] green: %d\n", j, i, pArr[j][i].green);
            printf("pArr[%d][%d] red: %d\n", j, i, pArr[j][i].red);
        }

    //read a ppm header from file
    FILE* ppm_file = fopen("nehoymenoy.ppm", "rb");
    PPM_Header * ppm_header = (PPM_Header*)malloc(sizeof(PPM_Header));
    readPPMHeader(ppm_file, ppm_header);
    printf("\nsignature: %s\n", ppm_header->signature);
    printf("width: %d\n", ppm_header->width);
    printf("height: %d\n", ppm_header->height);
    printf("max_value: %d\n", ppm_header->max_value);

    //read a ppm pixel array from file
    Pixel** pArrPPM = (Pixel**)malloc(ppm_header->width * sizeof(Pixel));
    for(i = 0; i < ppm_header->width; i++){
        pArrPPM[i] = (Pixel*) malloc(ppm_header->height);
    }
    readPixelsPPM(ppm_file, pArrPPM, ppm_header->width, ppm_header->height);
    for(i = 0; i < 1; i++)
        for(j = 0; j < 6; j++){
            printf("\npArrPPM red: %d\n", pArrPPM[i][j].red);
            printf("pArrPPM green: %d\n", pArrPPM[i][j].green);
            printf("pArrPPM blue: %d\n", pArrPPM[i][j].blue);
        }
    fclose(file);

    //copy test2.bmp into new file test3.bmp
    FILE* bmp_output = fopen("test3.bmp", "wb");
    writeBMPHeader(bmp_output, bmp_header);
    writeDIBHeader(bmp_output, dib_header);
    writePixelsBMP(bmp_output, pArr, dib_header->width, dib_header->height);
    fclose(bmp_output);

    //make bmp header from ppm
    BMP_Header* make_bmp_header = (BMP_Header*)malloc(sizeof(BMP_Header));
    makeBMPHeader(make_bmp_header, ppm_header->width, ppm_header->height);
    printf("\nsignature: %c%c\n", make_bmp_header->signature[0], make_bmp_header->signature[1]);
    printf("size: %d\n", make_bmp_header->size);
    printf("reserved1: %d\n", make_bmp_header->reserved1);
    printf("reserved2: %d\n", make_bmp_header->reserved2);
    printf("offset_pixel_array: %d\n\n", make_bmp_header->offset_pixel_array);

    //make dib header from ppm
    DIB_Header* make_dib_header = (DIB_Header*)malloc(sizeof(DIB_Header));
    makeDIBHeader(make_dib_header, ppm_header->width, ppm_header->height);
    printf("size: %d\n", make_dib_header->size);
    printf("width: %d\n", make_dib_header->width);
    printf("height: %d\n", make_dib_header->height);
    printf("planes: %d\n", make_dib_header->planes);
    printf("bits_per_pixel: %d\n", make_dib_header->bits_per_pixel);
    printf("compression: %d\n", make_dib_header->compression);
    printf("image_size: %d\n", make_dib_header->image_size);
    printf("x_res: %d\n", make_dib_header->x_res);
    printf("y_res: %d\n", make_dib_header->y_res);
    printf("color_table: %d\n", make_dib_header->color_table);
    printf("important_color: %d\n", make_dib_header->important_color);

    fclose(ppm_file);

    //copy nehoymenoy.ppm into new file test1.ppm
    FILE* ppm_output = fopen("test1.ppm", "wb");
    writePPMHeader(ppm_output, ppm_header);
    writePixelsPPM(ppm_output, pArrPPM, ppm_header->width, ppm_header->height);
    fclose(ppm_output);




    return 0;
}
