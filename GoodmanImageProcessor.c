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
#include <string.h>
#include <unistd.h>
#include "BmpProcessor.h"
#include "PpmProcessor.h"
#include "PixelProcessor.h"

/**
* main
*/
int main(int argc, char* argv[]){
    int iFlag = 0, oFlag = 0, tFlag = 0, rFlag = 0, gFlag = 0, bFlag = 0;
    /*printf("argc = %d\n", argc);
    for (i = 0; i < argc; i++)
        printf("arg[%d] = \"%s\"\n", i, argv[i]);*/
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
            case '?':
                printf("Unknown option: %c.\n", optopt);
                break;
        }
    for (; optind < argc; optind++)
        printf("Given extra arguments: %s\n", argv[optind]);
    int dflen;
    if(input_file != NULL){
        dflen = strlen(input_file);
        if(dflen >= 5
           && (strcmp(&input_file[dflen - 4], ".txt") == 0)
           && (access(input_file, F_OK) != -1)){
            printf("Importing data from %s\n\n", input_file);
            //readFile(input_file);
        } else {
            printf("Data file has an invalid name or does not exist.\n");
            //print_usage();
            exit(1);
        }
    } else {
        printf("No data file name provided. This is a required field.\n");
        //print_usage();
        exit(1);
    }
    int iflen;
    int ifval;
    if(input_file != NULL){
        iflen = strlen(output_file);
        if(iflen >= 5
           && (strcmp(&output_file[iflen - 4], ".txt") == 0)
           && (access(output_file, F_OK) != -1)){
            printf("Performing instructions defined in %s:\n", input_file);
            //uncomment below if doing this optional part of the assignment
            //performInstructions(output_file);
        } else {
            printf("Instruction file has an invalid name or does not exist.\n");
            //print_usage();
            exit(1);
        }
    } else {
        printf("No instruction file provided. Using CLI:\n");
        //mainMenu();
    }
    return 0;
}
