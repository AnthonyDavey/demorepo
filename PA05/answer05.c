#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"answer05.h"

#define FALSE 0
#define TRUE 1

Image * Image_load(const char * filename)
{
	ImageHeader header;
	size_t read;
	Image *tmp_im = NULL, *im = NULL;
	
	FILE *fp = fopen(filename, "rb");
	int err = fp == NULL;
	if(err) fprintf(stderr, "unable to open file %s!\n", filename);
	
	//read the header
	if (!err){
		read = fread(&header, sizeof(ImageHeader), 1, fp);
		err = read != 1 ||
			header.magic_number != ECE264_IMAGE_MAGIC_NUMBER ||
			header.width == 0 ||
			header.height == 0 ||
			header.comment_len == 0;		
		if(err) fprintf(stderr, "corrupt header\n");
	}
	
	//Allocate memory 
	if(!err){
		tmp_im = malloc(sizeof(Image));
		err = tmp_im = NULL;
		if(err) fprintf(stderr, "unable to allocate memory\n");
	}
	
	
	//Allocate memory for the comments and pixels
	if(!err){
		tmp_im -> width = header.width;
		tmp_im -> height = header.height;
		tmp_im -> comment = malloc(sizeof(char) * header.comment_len);
		tmp_im -> data = malloc(sizeof(char) * header.width * header.height);
		err = tmp_im -> comment == NULL ||
			tmp_im -> data == NULL;
		if(err) fprintf(stderr, "unable of allocate memory\n");
	}
	
	//Read the Comment 
	if(!err){
		read = fread(tmp_im -> comment, sizeof(char), header.comment_len, fp);
		err = read != header.comment_len ||
			tmp_im -> comment[header.comment_len -1] != '\0';
		if(err) fprintf(stderr, "unable to read comment\n");
	}
	
	//Read the Pixels 
	if(!err){
		read = fread(tmp_im -> data, sizeof(char), header.width * header.height, fp);
		err = read != header.width * header.height;
	if(err) fprintf(stderr, "unable to read pixels\n");
	}
	
	//Make sure we reached the end of the file!
	if(!err){
		fgetc(fp);
		err = !feof(fp);
		if(err) fprintf(stderr, "not at end of file, file may be corrupt\n");
	}
	
	if (!err){
		im = tmp_im;
		tmp_im = NULL;
	}
	
	//Clenup if needed 
	if(tmp_im != NULL){
		Image_free(tmp_im);
	}
	
	if(fp != NULL){
		fclose(fp);
	}

	return im;
}

int Image_save(const char * filename, Image * image)
{
	int err = FALSE;
	FILE * fp = NULL;
	size_t written = 0;
	uint8_t * buffer = NULL;  
	ImageHeader header;
	
	//Open the file 
	fp = fopen(filename, "wb");
	if(fp == NULL){
		fprintf(stderr, "Failed to open '%s' for writing\n", filename);
		return FALSE; 
	}
	
	//Number of bytes stored on each row
	size_t bytes_per_row = ((24 * image -> width + 31)/32) * 4;
	
	
	//Prepare the header
    header.width = image->width;
    header.height = image->height;
    	
	if(!err){
		written = fwrite(&header, sizeof(ImageHeader), 1, fp);
		if(written != 1){
			fprintf(stderr, "Error: only wrote %zd of %zd of file header to '%s'\n", written, sizeof(ImageHeader), filename);
			err = TRUE;
		}
	}
	
	if(!err) {
		buffer = malloc(bytes_per_row);
		if(buffer == NULL) {
			fprintf(stderr, "Error: failed to allocate write buffer\n");
			err = TRUE;
		}
	}
	
	if(!err){
		uint8_t * read_ptr = image -> data;
		int row, col;
		for(row=0; row < header.height && !err; ++row){
			uint8_t * write_ptr = buffer;
			for(col = 0; col < header.width; ++col){
				*write_ptr++ = *read_ptr; // blue
				*write_ptr++ = *read_ptr; // green
				*write_ptr++ = *read_ptr; // red
				read_ptr++; 
			}
			written = fwrite(buffer, sizeof(uint8_t), bytes_per_row, fp);
			if(written != bytes_per_row) {
				fprintf(stderr, "Failed to write pixel data to file\n");
				err = TRUE;
			}
		}
	}
	
	free(buffer);
	if(fp){
		fclose(fp);
	}
	
	return !err;
}

void Image_free(Image * image)
{
	if(image != NULL){
		free(image);
	}
}

void linearNormalization(int width, int height, uint8_t * intensity)
{
	int i = 0;
	int min = intensity[i];
	int max = intensity[i]; 
	for(i = 1; i < width * height; i++){
		if (intensity[i] < min){
			min = intensity[i];
		}
		
		if(intensity[i] > max){
			max = intensity[i];
		}
	}
	
	for(i = 0; i < width*height; i++){
		intensity[i] = (intensity[i] - min) * 255.0 / (max - min);
	}

}