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
    char* datafile;
    char* instructionfile;
    int opt;
    while((opt = getopt(argc, argv, ":d:i:")) != -1)
        switch(opt){
            case 'd':
                datafile = optarg;
                break;
            case 'i':
                instructionfile = optarg;
                break;
            case ':':
                printf("option needs a value\n");
                break;
            case '?':
                printf("unknown option: %c\n", optopt);
                break;
        }
    for (; optind < argc; optind++)
        printf("Given extra arguments: %s\n", argv[optind]);
    int dflen;
    if(datafile != NULL){
        dflen = strlen(datafile);
        if(dflen >= 5
           && (strcmp(&datafile[dflen-4], ".txt") == 0)
           && (access(datafile, F_OK) != -1)){
            printf("Importing data from %s\n\n", datafile);
            readFile(datafile);
        } else {
            printf("Data file has an invalid name or does not exist.\n");
            print_usage();
            exit(1);
        }
    } else {
        printf("No data file name provided. This is a required field.\n");
        print_usage();
        exit(1);
    }
    int iflen;
    int ifval;
    if(instructionfile != NULL){
        iflen = strlen(instructionfile);
        if(iflen >= 5
           && (strcmp(&instructionfile[iflen-4], ".txt") == 0)
           && (access(instructionfile, F_OK) != -1)){
            printf("Performing instructions defined in %s:\n", instructionfile);
            //uncomment below if doing this optional part of the assignment
            performInstructions(instructionfile);
        } else {
            printf("Instruction file has an invalid name or does not exist.\n");
            print_usage();
            exit(1);
        }
    } else {
        printf("No instruction file provided. Using CLI:\n");
        mainMenu();
    }
    return 0;
}
