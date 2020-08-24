#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "BmpProcessor.h"
#include "PpmProcessor.h"
#include "PixelProcessor.h"

//main
int main(){
	FILE* file = fopen("test2.bmp", "rb");
	struct BMP_Header* header;
	//readBMPHeader(file, header);
	fread(header->signature, sizeof(char)*2, 1, file);
	printf("signature: %c%c\n", header->signature[0], header->signature[1]);
	fclose(file);
	return 0;
};
