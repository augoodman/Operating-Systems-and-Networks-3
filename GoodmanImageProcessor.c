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
//#include "PpmProcessor.h"
//#include "PixelProcessor.h"
#include "Util.h"

/**
* main
*/
int main(int argc, char* argv[]){
    int i, iFlag = 0, oFlag = 0, tFlag = 0, rFlag = 0, gFlag = 0, bFlag = 0;
    printf("argc = %d\n", argc);
    for (i = 0; i < argc; i++)
        printf("arg[%d] = \"%s\"\n", i, argv[i]);
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
    BMP_Header* bmp_header;
    bmp_header = (BMP_Header*)malloc(sizeof(BMP_Header));
    readBMPHeader(file, bmp_header);
    printf("signature: %s\n", bmp_header->signature);
    printf("size: %d\n", bmp_header->size);
    printf("reserved1: %d\n", bmp_header->reserved1);
    printf("reserved2: %d\n", bmp_header->reserved2);
    printf("offset_pixel_array: %d\n\n", bmp_header->offset_pixel_array);
    DIB_Header* dib_header;
    dib_header = (DIB_Header*)malloc(sizeof(DIB_Header));
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
    //fseek(file, bmp_header->offset_pixel_array, SEEK_SET);
    Pixel** pArr = (Pixel**)malloc(dib_header->width * 3 * sizeof(Pixel));
    for(i = 0; i < dib_header->width; i++){
        pArr[i] = (Pixel*) malloc(dib_header->height);
    }
    printf("size of pArr: %d\n", (int)sizeof(**pArr));
    //int j, padding = calcPadding(dib_header->width);

    //fread(&pArr[0][0].blue, 1, 1, file);
    //fread(&pArr[0][0].green, 1, 1, file);
    //fread(&pArr[0][0].red, 1, 1, file);
    readPixelsBMP(file, pArr, dib_header->width, dib_header->height);
    int j, padding = calcPadding(dib_header->width);
    for(i = 0; i < dib_header->height; i++)
        for(j = 0; j < dib_header->width + padding; j++)
            if(j < dib_header->width) {
                printf("\npArr blue: %d\n", pArr[j][i].blue);
                printf("pArr green: %d\n", pArr[j][i].green);
                printf("pArr red: %d\n", pArr[j][i].red);
            }

    //readPixelsBMP(file, pArr, dib_header->width, dib_header->height);
    //int a, b;
    //for(a = 0; a < dib_header->width; a++) {
    //    for (int b = 0; b < dib_header->height; b++) {
            //printf("bitmap data: %d", pArr[i][j].blue);
    //    }
    //}
    free(bmp_header);
    free(dib_header);
    for(i = 0; i < dib_header->width; i++){
        free(pArr[i]);
    }
    free(pArr);
    //readBMPHeader(file, bmp_header);
    //printf("signature: %s\n", bmp_header->signature);
    //printf("size: %d\n", bmp_header->size);
    //printf("reserved1: %d\n", bmp_header->reserved1);


    /*for (; optind < argc; optind++)
        printf("Given extra arguments: %s\n", argv[optind]);
    int dflen;
    if(input_file != NULL){
        dflen = strlen(input_file);
        if(dflen >= 5
           && (strcmp(&input_file[dflen - 4], ".txt") == 0)
           && (access(input_file, F_OK) != -1)
           ){
            printf("Importing data from %s\n\n", input_file);
            //readFile(input_file);
        } else {
            printf("Data file has an invalid name or does not exist.\n");
            //print_usage();
            fclose(file);
            exit(1);
        }
    } else {
        printf("No data file name provided. This is a required field.\n");
        //print_usage();
        fclose(file);
        exit(1);
    }
    int iflen;
    int ifval;
    if(input_file != NULL){
        iflen = strlen(output_file);
        if(iflen >= 5
           && (strcmp(&output_file[iflen - 4], ".txt") == 0)
           && (access(output_file, F_OK) != -1)
           ){
            printf("Performing instructions defined in %s:\n", input_file);
            //uncomment below if doing this optional part of the assignment
            //performInstructions(output_file);
        } else {
            printf("Instruction file has an invalid name or does not exist.\n");
            //print_usage();
            exit(1);
        }
    }*/
    fclose(file);
    return 0;
}
