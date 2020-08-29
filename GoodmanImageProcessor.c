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
    //printf("size of pArr: %d\n", (int)sizeof(pArr));
    //printf("size of pixel: %d\n", (int)sizeof(pArr[0][0]));

    readPixelsBMP(file, pArr, dib_header->width, dib_header->height);
    int j;
    for(i = 0; i < dib_header->height; i++)
        for(j = 0; j < dib_header->width; j++){
            printf("\npArr[%d][%d] blue: %d\n", j, i, pArr[j][i].blue);
            printf("pArr[%d][%d] green: %d\n", j, i, pArr[j][i].green);
            printf("pArr[%d][%d] red: %d\n", j, i, pArr[j][i].red);
        }

    FILE* ppm_file = fopen("nehoymenoy.ppm", "rb");

    //read a ppm header from file
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
        for(j = 0; j < 5; j++){
            printf("\npArrPPM red: %d\n", pArrPPM[i][j].red);
            printf("pArrPPM green: %d\n", pArrPPM[i][j].green);
            printf("pArrPPM blue: %d\n", pArrPPM[i][j].blue);
        }
    fclose(file);
    fclose(ppm_file);
    FILE* bmp_output = fopen("test3.bmp", "w");
    //copy test2.bmp into new file test3.bmp
    writeBMPHeader(bmp_output, bmp_header);
    writeDIBHeader(bmp_output, dib_header);
    writePixelsBMP(bmp_output, pArr, dib_header->width, dib_header->height);
    //for(i = 0; i < dib_header->width; i++){
    //    free(pArr[i]);
    //}
    //free(pArr);
    //for(i = 0; i < ppm_header->width; i++){
    //    free(pArrPPM[i]);
    //}
    //free(pArrPPM);
    //free(bmp_header);
    //free(dib_header);
    //free(ppm_header);
    //fclose(file);
    //fclose(bmp_output);
    //BMP_Header* bmp_written = (BMP_Header*)malloc(sizeof(BMP_Header));
    //DIB_Header* dib_written = (DIB_Header*)malloc(sizeof(DIB_Header));
    //Pixel** pArr_written = (Pixel**)malloc(dib_header->width * 3 * sizeof(Pixel));
    //for(i = 0; i < dib_header->width; i++){
    //    pArr_written[i] = (Pixel*) malloc(dib_header->height);
    //}
    //strcpy(bmp_written->signature, "BM");
    //bmp_written->size = calcFileSize(file);
    //bmp_written->reserved1 = 0;
    //bmp_written->reserved2 = 0;
    //bmp_written->offset_pixel_array = 54;

    //printf("\nsignature: %s\n", bmp_written->signature);
    //printf("size: %d\n", bmp_written->size);
    //printf("reserved1: %d\n", bmp_written->reserved1);
    //printf("reserved2: %d\n", bmp_written->reserved2);
    //printf("offset_pixel_array: %d\n\n", bmp_written->offset_pixel_array);

    //PPM_Header* ppm_header = (PPM_Header*)malloc(sizeof(PPM_Header));
    //fscanf(ppm_file, "%s %d %d %d", ppm_header->signature, &ppm_header->width, &ppm_header->height, &ppm_header->max_value);
    //fread(&ppm_header->signature, sizeof(char) * 2, 1, ppm_file);
    //fread(&ppm_header->width, sizeof(int), 1, ppm_file);
    //fread(&ppm_header->height, sizeof(int), 1, ppm_file);
    //fread(&ppm_header->max_value, sizeof(int), 1, ppm_file);
    //printf("\nsignature: %s\n", ppm_header->signature);
    //printf("width: %d\n", ppm_header->width);
    //printf("height: %d\n", ppm_header->height);
    //printf("max_value: %d\n", ppm_header->max_value);
    //Pixel** pArr = NULL;

    //readPixelsPPM(ppm_file, pArr, ppm_header->width, ppm_header->width);
    //fseek(ppm_file,1,SEEK_CUR);
    //fread(&pArr[0][0].red, 1, 1, ppm_file);
    //fread(&pArr[0][0].green, 1, 1, ppm_file);
    //fread(&pArr[0][0].blue, 1, 1, ppm_file);
    //for(i = 0; i < 1; i++)
        //for(j = 0; j < ppm_header->width; j++)
            //if(j < ppm_header->width) {
                //printf("\npArr red: %d\n", pArr[0][0].red);
                //printf("pArr green: %d\n", pArr[0][0].green);
                //printf("pArr blue: %d\n", pArr[0][0].blue);
            //}


    //free(bmp_header);
    //free(dib_header);
    //for(i = 0; i < dib_header->width; i++){
    //    free(pArr[i]);
    //}
    //free(pArr);
    //free(ppm_header);



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
    //fclose(file);
    //fclose(ppm_file);
    return 0;
}
