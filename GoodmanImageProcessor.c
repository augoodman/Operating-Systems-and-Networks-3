/**
* File:   GoodmanImageProcessor.c
* Process images in BMP and PPM formats.
*
* Completion time:  30 hours
*
* @author Goodman
* @version 2020.08.25
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "BmpProcessor.h"
#include "PpmProcessor.h"
#include "PixelProcessor.h"
#include "Util.h"

/**
* main
*/
int main(int argc, char* argv[]){
    int i, opt, length, red = 0, blue = 0, green = 0, argIndex = 0;
    int iFlag = 0, oFlag = 0, tFlag = 0, rFlag = 0, gFlag = 0, bFlag = 0;
    char* input_file;
    char* output_file;
    char* file_type;
    BMP_Header* input_bmp_header;
    DIB_Header* input_dib_header;
    PPM_Header* input_ppm_header;
    BMP_Header* output_bmp_header;
    DIB_Header* output_dib_header;
    PPM_Header* output_ppm_header;
    Pixel** pArr;
    while((opt = getopt(argc, argv, "i:o:t:r:g:b:")) != -1)
        //parse command line arguments
        switch(opt){
            case 'i':
                if(argIndex != 0){
                    printf("First argument must be for input file. Exiting\n\n");
                    exit(1);
                }
                if(iFlag == 1){
                    printf("Extra argument for input file: %s. Additional argument discarded.\n\n", optarg);
                    argIndex++;
                    break;
                }
                argIndex++;
                iFlag = 1;
                input_file = optarg;
                break;
            case 'o':
                if(argIndex == 0){
                    printf("First argument must be for input file. Exiting\n\n");
                    exit(1);
                }
                if(oFlag == 1){
                    printf("Extra argument for input file: %s.  Additional argument discarded.\n\n", optarg);
                    argIndex++;
                    break;
                }
                argIndex++;
                oFlag = 1;
                output_file = optarg;
                break;
            case 't':
                if(argIndex == 0){
                    printf("First argument must be for input file. Exiting\n\n");
                    exit(1);
                }
                if(tFlag == 1){
                    printf("Extra argument for file extension: .%s.  Additional argument discarded.\n\n", optarg);
                    argIndex++;
                    break;
                }
                argIndex++;
                tFlag = 1;
                file_type = optarg;
                break;
            case 'r':
                if(argIndex == 0){
                    printf("First argument must be for input file. Exiting\n\n");
                    exit(1);
                }
                if(rFlag == 1){
                    printf("Extra argument for red sample.  Additional argument discarded.\n\n");
                    argIndex++;
                    break;
                }
                argIndex++;
                rFlag = 1;
                red = atoi(optarg);
                break;
            case 'g':
                if(argIndex == 0){
                    printf("First argument must be for input file. Exiting\n\n");
                    exit(1);
                }
                if(gFlag == 1){
                    printf("Extra argument for green sample.  Additional argument discarded.\n\n");
                    argIndex++;
                    break;
                }
                argIndex++;
                gFlag = 1;
                green = atoi(optarg);
                break;
            case 'b':
                if(argIndex == 0){
                    printf("First argument must be for input file. Exiting\n\n");
                    exit(1);
                }
                if(bFlag == 1){
                    printf("Extra argument for blue sample.  Additional argument discarded.\n\n");
                    argIndex++;
                    break;
                }
                argIndex++;
                bFlag = 1;
                blue = atoi(optarg);
                break;
            case ':':
                printf("Option needs a value.\n");
                break;
            default:
                printf("Unknown option: %c.\n", optopt);
                break;
        }
    //verify input file is valid
    if(input_file != NULL){
        length = strlen(input_file);
        //read in bmp input file
        if(length >= 5
           && (strcmp(&input_file[length - 4], ".bmp") == 0)
           && (access(input_file, F_OK) != -1)){
            printf("Importing image from %s...\n", input_file);
            FILE* iFile = fopen(input_file, "rb");
            //read a bmp header from file
            input_bmp_header = (BMP_Header*)malloc(sizeof(BMP_Header));
            readBMPHeader(iFile, input_bmp_header);
            //read a dib header from file
            input_dib_header = (DIB_Header*)malloc(sizeof(DIB_Header));
            readDIBHeader(iFile, input_dib_header);
            //read a bmp pixel array from file
            fseek(iFile, input_bmp_header->offset_pixel_array, SEEK_SET);
            pArr = (Pixel**)malloc(input_dib_header->width * sizeof(Pixel*));
            for(i = 0; i < input_dib_header->width; i++){
                pArr[i] = (Pixel*) malloc(input_dib_header->height * sizeof(Pixel));
            }
            readPixelsBMP(iFile, pArr, input_dib_header->width, input_dib_header->height);
            //shift pixel color
            if((red != 0 || green != 0 || blue != 0) && oFlag != 0)
                printf("Shifting image color...\nRed: %d\nGreen: %d\nBlue: %d\n", red, green, blue);
            colorShiftPixels(pArr, input_dib_header->width, input_dib_header->height, red, green, blue);
            fclose(iFile);
        }
        //read in ppm input file
        else if(length >= 5
                && (strcmp(&input_file[length - 4], ".ppm") == 0)
                && (access(input_file, F_OK) != -1)){
            printf("Importing image from %s...\n", input_file);
            //read a ppm header from file
            FILE* iFile = fopen(input_file, "rb");
            input_ppm_header = (PPM_Header*)malloc(sizeof(PPM_Header));
            readPPMHeader(iFile, input_ppm_header);
            //read a ppm pixel array from file
            pArr = (Pixel**)malloc(input_ppm_header->width * sizeof(Pixel*));
            for(i = 0; i < input_ppm_header->width; i++){
                pArr[i] = (Pixel*) malloc(input_ppm_header->height * sizeof(Pixel));
            }
            readPixelsPPM(iFile, pArr, input_ppm_header->width, input_ppm_header->height);
            //shift pixel color
            if((red != 0 || green != 0 || blue != 0) && oFlag != 0)
                printf("Shifting image color...\nRed: %d\nGreen: %d\nBlue: %d\n", red, green, blue);
            colorShiftPixels(pArr, input_ppm_header->width, input_ppm_header->height, red, green, blue);
            fclose(iFile);
        }
        else {
            printf("Input file has an invalid name or is not accessible. Exiting.\n");
            exit(1);
        }
    }
    else {
        printf("No input file name provided. Exiting.\n");
        exit(1);
    }
    //produce an output file
    if(oFlag == 1){
        //check if output file type argument used
        if(tFlag == 1){
            //check if desired output is ppm
            if(strcmp(file_type, "PPM") == 0 || strcmp(file_type, "ppm") == 0){
                //convert to ppm if necessary
                if(strcmp(&input_file[length - 4], ".bmp") == 0){
                    //make ppm header from bmp
                    output_ppm_header = (PPM_Header*)malloc(sizeof(PPM_Header));
                    makePPMHeader(output_ppm_header, input_dib_header->width, input_dib_header->height);
                    //convert bmp to ppm
                    strcat(output_file, ".ppm");
                    FILE* oFile = fopen(output_file, "wb");
                    writePPMHeader(oFile, output_ppm_header);
                    writePixelsPPM(oFile, pArr, output_ppm_header->width, output_ppm_header->height);
                    fclose(oFile);
                    for(i = 0; i < output_ppm_header->width; i++)
                        free(pArr[i]);
                    free(pArr);
                    free(output_ppm_header);
                    free(input_bmp_header);
                    free(input_dib_header);
                    printf("File: %s created!\n", output_file);
                }
                //otherwise copy to new ppm
                else{
                    strcat(output_file, ".ppm");
                    FILE* oFile = fopen(output_file, "wb");
                    writePPMHeader(oFile, input_ppm_header);
                    writePixelsPPM(oFile, pArr, input_ppm_header->width, input_ppm_header->height);
                    fclose(oFile);
                    for(i = 0; i < input_ppm_header->width; i++)
                        free(pArr[i]);
                    free(pArr);
                    free(input_ppm_header);
                    printf("File: %s created!\n", output_file);
                }
            }
            //check if desired output is bmp
            else if(strcmp(file_type, "BMP") == 0 || strcmp(file_type, "bmp") == 0) {
                //convert to bpm if necessary
                if(strcmp(&input_file[length - 4], ".ppm") == 0){
                    //make bmp header from ppm
                    output_bmp_header = (BMP_Header*)malloc(sizeof(BMP_Header));
                    makeBMPHeader(output_bmp_header, input_ppm_header->width, input_ppm_header->height);
                    //make dib header from ppm
                    output_dib_header = (DIB_Header*)malloc(sizeof(DIB_Header));
                    makeDIBHeader(output_dib_header, input_ppm_header->width, input_ppm_header->height);
                    //convert ppm file to bmp
                    strcat(output_file, ".bmp");
                    FILE* oFile = fopen(output_file, "wb");
                    writeBMPHeader(oFile, output_bmp_header);
                    writeDIBHeader(oFile, output_dib_header);
                    writePixelsBMP(oFile, pArr, output_dib_header->width, output_dib_header->height);
                    fclose(oFile);
                    for(i = 0; i < output_dib_header->width; i++)
                        free(pArr[i]);
                    free(pArr);
                    free(output_bmp_header);
                    free(output_dib_header);
                    free(input_ppm_header);
                    printf("File: %s created!\n", output_file);
                }
                //otherwise copy to new bmp
                else{
                    strcat(output_file, ".bmp");
                    FILE* oFile = fopen(output_file, "wb");
                    writeBMPHeader(oFile, input_bmp_header);
                    writeDIBHeader(oFile, input_dib_header);
                    writePixelsBMP(oFile, pArr, input_dib_header->width, input_dib_header->height);
                    fclose(oFile);
                    for(i = 0; i < input_dib_header->width; i++)
                        free(pArr[i]);
                    free(pArr);
                    free(input_bmp_header);
                    free(input_dib_header);
                    printf("File: %s created!\n", output_file);
                }
            }
            else {
                tFlag = 1;
                printf("Invalid file extension.  Use only 'BMP' or 'PPM' extensions.  Exiting.\n");
                exit(1);
            }
        }
        //if no argument for output type, default to bmp
        else{
            printf("Defaulting to output file type of 'BMP'...\n");
            //convert to bpm if necessary
            if(strcmp(&input_file[length - 4], ".ppm") == 0){
                //make bmp header from ppm
                output_bmp_header = (BMP_Header*)malloc(sizeof(BMP_Header));
                makeBMPHeader(output_bmp_header, input_ppm_header->width, input_ppm_header->height);
                //make dib header from ppm
                output_dib_header = (DIB_Header*)malloc(sizeof(DIB_Header));
                makeDIBHeader(output_dib_header, input_ppm_header->width, input_ppm_header->height);
                //convert ppm file to bmp
                strcat(output_file, ".bmp");
                FILE* oFile = fopen(output_file, "wb");
                writeBMPHeader(oFile, output_bmp_header);
                writeDIBHeader(oFile, output_dib_header);
                writePixelsBMP(oFile, pArr, output_dib_header->width, output_dib_header->height);
                fclose(oFile);
                for(i = 0; i < output_dib_header->width; i++)
                    free(pArr[i]);
                free(pArr);
                free(output_bmp_header);
                free(output_dib_header);
                free(input_ppm_header);
                printf("File: %s created!\n", output_file);
            }
            //otherwise copy to new bmp
            else{
                strcat(output_file, ".bmp");
                FILE* oFile = fopen(output_file, "wb");
                writeBMPHeader(oFile, input_bmp_header);
                writeDIBHeader(oFile, input_dib_header);
                writePixelsBMP(oFile, pArr, input_dib_header->width, input_dib_header->height);
                fclose(oFile);
                for(i = 0; i < input_dib_header->width; i++)
                    free(pArr[i]);
                free(pArr);
                free(input_bmp_header);
                free(input_dib_header);
                printf("File: %s created!\n", output_file);
            }
        }
    }

    for(i = 0; i < argc; i++){
        if(strcmp(argv[i], "-i") == 0) {

        }
        if(strcmp(argv[i], "-o") == 0){
            //printf("output\n");
        }
    }
    return 0;
}
