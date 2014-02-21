#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

int main(int argc, char * * argv)
{
	const char * filename = "/home/Tony/PA05/images/01-smile.ee264";
	printf("Hello, about to open file: '%s'\n", filename);
	
	FILE * fp = fopen(filename, "rb");
	if(fp == NULL){
		fprintf(stderr, "Failed to open the file\n");
		return EXIT_FAILURE;
	}
	printf("We're Winners!\n");
	
	//Now lets read things.....
	uint32_t value;
	//int value; no guarantee that it is 32 bits 
	size_t read = fread(&value, sizeof(uint32_t), 1, fp);
	printf("Just read %d chunks (expected 1)\n", read);
	printf("Value read = %0xx\n", value); 
	
	
	fclose(fp);
	
	return EXIT_SUCCESS;
}